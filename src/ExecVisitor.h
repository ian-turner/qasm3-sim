#pragma once
#include "qasm3ParserBaseVisitor.h"
#include "qasm3Parser.h"
#include "Runtime.h"
#include <string>
#include <stdexcept>
#include <optional>
#include <algorithm>

class ExecVisitor : public qasm3ParserBaseVisitor {
public:
  explicit ExecVisitor(Runtime& rt) : rt_(rt) {}

  // program: version? statementOrScope* EOF;
  antlrcpp::Any visitProgram(qasm3Parser::ProgramContext* ctx) override {
    for (auto child : ctx->statementOrScope()) visit(child);
    return {};
  }

  // { ... } blocks
  antlrcpp::Any visitScope(qasm3Parser::ScopeContext* ctx) override {
    for (auto ss : ctx->statementOrScope()) visit(ss);
    return {};
  }

  // qubitType Identifier ';'
  antlrcpp::Any visitQuantumDeclarationStatement(qasm3Parser::QuantumDeclarationStatementContext* ctx) override {
    auto name = ctx->Identifier()->getText();
    int n = 1; // default qubit
    if (auto* qt = ctx->qubitType()) {
      if (auto* d = qt->designator()) {
        n = (int)evalInt(d->expression());
      }
    }
    rt_.allocQubits(name, n);
    return {};
  }

  // (scalarType | arrayType) Identifier ( '=' declarationExpression )? ';'
  // Support: bit[?] x; bool b; int[?] n; (int only scalar here)
  antlrcpp::Any visitClassicalDeclarationStatement(qasm3Parser::ClassicalDeclarationStatementContext* ctx) override {
    if (auto* st = ctx->scalarType()) {
      auto name = ctx->Identifier()->getText();
      if (st->BIT()) {
        int n = 1;
        if (auto* d = st->designator()) n = (int)evalInt(d->expression());
        rt_.declareBits(name, n);
      } else if (st->BOOL()) {
        rt_.declareBool(name);
      } else if (st->INT()) {
        rt_.declareInt(name, 0);
      } else {
        // minimal slice: ignore others for now
        throw std::runtime_error("unsupported scalar type in declaration (only bit/bool/int supported in this slice)");
      }
      // Optional initializer (declarationExpression): handle simple int/bool literals
      if (auto* de = ctx->declarationExpression()) {
        if (st->BOOL()) {
          if (auto* e = de->expression()) rt_.setBool(name, evalBool(e));
          else throw std::runtime_error("bool initializer must be an expression");
        } else if (st->INT()) {
          rt_.setInt(name, evalIntFromDecl(de));
        } else {
          // bit[...] init not handled in this slice
        }
      }

    } else {
      throw std::runtime_error("arrayType not yet supported in this slice");
    }
    return {};
  }

  // gateModifier* Identifier (...) designator? gateOperandList ';'
  antlrcpp::Any visitGateCallStatement(qasm3Parser::GateCallStatementContext* ctx) override {
    const std::string g = ctx->Identifier() ? ctx->Identifier()->getText() : "gphase";
    auto qubits = collectGateOperands(ctx->gateOperandList());
    if (g == "x") {
      for (int q : qubits) rt_.x(q);
    } else if (g == "h") {
      for (int q : qubits) rt_.h(q);
    } else if (g == "cx" || g == "CX") {
      if (qubits.size() != 2) throw std::runtime_error("cx needs 2 operands");
      rt_.cx(qubits[0], qubits[1]);
    } else {
      throw std::runtime_error("unsupported gate in this slice: " + g);
    }
    return {};
  }

  // measureExpression (ARROW indexedIdentifier)? ';'
  antlrcpp::Any visitMeasureArrowAssignmentStatement(qasm3Parser::MeasureArrowAssignmentStatementContext* ctx) override {
    int q = gateOperandToIndex(ctx->measureExpression()->gateOperand());
    int r = rt_.measure(q);
    if (auto* tgt = ctx->indexedIdentifier()) {
      writeIndexedIdentifier(tgt, r);
    }
    return {};
  }

  // reset gateOperand ';'
  antlrcpp::Any visitResetStatement(qasm3Parser::ResetStatementContext* ctx) override {
    int q = gateOperandToIndex(ctx->gateOperand());
    rt_.reset(q);
    return {};
  }

  // if (expr) stmt [else stmt]
  antlrcpp::Any visitIfStatement(qasm3Parser::IfStatementContext* ctx) override {
    bool cond = evalBool(ctx->expression());
    if (cond) visit(ctx->if_body);
    else if (ctx->else_body) visit(ctx->else_body);
    return {};
  }

  // Fallback: descend
  antlrcpp::Any visitStatement(qasm3Parser::StatementContext* ctx) override {
    return qasm3ParserBaseVisitor::visitStatement(ctx);
  }

private:
  // ----- helpers -----
  // gateOperandList: gateOperand (',' gateOperand)* ','
  std::vector<int> collectGateOperands(qasm3Parser::GateOperandListContext* gl) {
    std::vector<int> out;
    for (auto* go : gl->gateOperand()) out.push_back(gateOperandToIndex(go));
    return out;
  }

  // gateOperand: indexedIdentifier | HardwareQubit
  int gateOperandToIndex(qasm3Parser::GateOperandContext* go) {
    if (auto* iq = go->indexedIdentifier()) {
      const std::string qname = iq->Identifier()->getText();
      // Only single index like q[i]; multi-index/slices TODO
      int idx = 0;
      if (!iq->indexOperator().empty()) {
        auto* op = iq->indexOperator(0);
        // indexOperator: '[' (expression | rangeExpression | setExpression …) ']'
        // Minimal: assume single scalar expression first.
        idx = (int)evalInt(op->expression(0));
      }
      return rt_.qubitIndex(qname, idx);
    }
    // HardwareQubit like $0 (rare in sim); map $k to absolute index k
    if (auto* hq = go->HardwareQubit()) {
      const std::string t = hq->getText(); // like "$7"
      return std::stoi(t.substr(1));
    }
    throw std::runtime_error("unsupported gate operand form");
  }

  // Write a value into an indexedIdentifier (bit arrays or scalars)
  void writeIndexedIdentifier(qasm3Parser::IndexedIdentifierContext* id, int v) {
    const std::string name = id->Identifier()->getText();
    if (!id->indexOperator().empty()) {
      int i = (int)evalInt(id->indexOperator(0)->expression(0));
      if (rt_.hasBit(name)) rt_.setBit(name, i, v);
      else throw std::runtime_error("only bit[...] assignment supported here");
    } else {
      if (rt_.hasBit(name)) rt_.setBit(name, 0, v);
      else if (rt_.hasBool(name)) rt_.setBool(name, v != 0);
      else if (rt_.hasInt(name))  rt_.setInt(name, v);
      else throw std::runtime_error("unknown classical lvalue '" + name + "'");
    }
  }

  // ---------- expression evaluation (minimal) ----------
  // Supports integer literals, identifiers (bit/bool/int), unary -, +, comparisons, logical &&, ||.

  Runtime& rt_;

  private:
    
    // ---------- generic identifier probe ----------
static bool exprIsBareIdentifier(qasm3Parser::ExpressionContext* e, std::string& out) {
  // Many OpenQASM3 grammar variants express a lone identifier as an expression
  // with a single TerminalNode child.
  if (e && e->children.size() == 1) {
    auto* node = e->children[0];
    if (auto* term = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
      auto* tok = term->getSymbol();
      if (tok && tok->getType() == qasm3Parser::Identifier) {
        out = tok->getText();
        return true;
      }
    }
  }
  return false;
}

// ---------- tiny integer literal parser (10/16/2 with underscores) ----------
static long long parseIntegerLiteral(std::string s) {
  s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
  int base = 10; size_t pos = 0;
  if (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0) { base = 16; pos = 2; }
  else if (s.rfind("0b", 0) == 0 || s.rfind("0B", 0) == 0) { base = 2; pos = 2; }
  return std::stoll(s.substr(pos), nullptr, base);
}

// ---------- expression evaluation (minimal) ----------
long long evalInt(qasm3Parser::ExpressionContext* e) {
  using P = qasm3Parser;

  // literal expression (true/false/integers). If your grammar doesn't expose
  // LiteralExpressionContext, this branch is simply skipped.
  if (auto* lit = dynamic_cast<P::LiteralExpressionContext*>(e)) {
    const std::string s = lit->getText();
    if (s == "true")  return 1;
    if (s == "false") return 0;
    return parseIntegerLiteral(s);
  }

  // bare identifier like `x`
  {
    std::string name;
    if (exprIsBareIdentifier(e, name)) {
      if      (rt_.hasInt(name))  return rt_.getInt(name);
      else if (rt_.hasBool(name)) return rt_.getBool(name) ? 1 : 0;
      else if (rt_.hasBit(name))  return rt_.getBit(name, 0);
      throw std::runtime_error("unknown identifier in expression: " + name);
    }
  }

  // (expr)
  if (auto* par = dynamic_cast<P::ParenthesisExpressionContext*>(e)) {
    return evalInt(par->expression());
  }

  // unary
  if (auto* un = dynamic_cast<P::UnaryExpressionContext*>(e)) {
    long long a = evalInt(un->expression());
    const std::string op = un->op->getText();
    if (op == "-") return -a;
    if (op == "+") return  a;
    if (op == "!") return !a;
    throw std::runtime_error("unsupported unary op: " + op);
  }

  // a + b | a - b
  if (auto* add = dynamic_cast<P::AdditiveExpressionContext*>(e)) {
    long long a = evalInt(add->expression(0));
    long long b = evalInt(add->expression(1));
    return (add->op->getText() == "+") ? (a + b) : (a - b);
  }

  // a * b | a / b | a % b
  if (auto* mul = dynamic_cast<P::MultiplicativeExpressionContext*>(e)) {
    long long a = evalInt(mul->expression(0));
    long long b = evalInt(mul->expression(1));
    const std::string op = mul->op->getText();
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    if (op == "%") return a % b;
  }

  // comparisons
  if (auto* cmp = dynamic_cast<P::ComparisonExpressionContext*>(e)) {
    long long a = evalInt(cmp->expression(0));
    long long b = evalInt(cmp->expression(1));
    const std::string op = cmp->op->getText();
    if (op == "<")  return a <  b;
    if (op == "<=") return a <= b;
    if (op == ">")  return a >  b;
    if (op == ">=") return a >= b;
  }

  // equality
  if (auto* eq = dynamic_cast<P::EqualityExpressionContext*>(e)) {
    long long a = evalInt(eq->expression(0));
    long long b = evalInt(eq->expression(1));
    const std::string op = eq->op->getText();
    if (op == "==") return a == b;
    if (op == "!=") return a != b;
  }

  // logical and / or
  if (auto* land = dynamic_cast<P::LogicalAndExpressionContext*>(e))
    return evalBool(land->expression(0)) && evalBool(land->expression(1));
  if (auto* lor  = dynamic_cast<P::LogicalOrExpressionContext*>(e))
    return evalBool(lor->expression(0))  || evalBool(lor->expression(1));

  throw std::runtime_error("unsupported expression form: " + e->getText());
}

long long evalIntFromDecl(qasm3Parser::DeclarationExpressionContext* de) {
  if (auto* e = de->expression()) return evalInt(e);
  throw std::runtime_error("initializer must be an expression in this slice");
}

bool evalBool(qasm3Parser::ExpressionContext* e) { return evalInt(e) != 0; }

};

