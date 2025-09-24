#pragma once
/**
 * @file ExecVisitor.h
 * @brief Parse-tree executor for a minimal-but-growing OpenQASM 3 simulator.
 *
 * This visitor walks the ANTLR-generated qasm3 parse tree and executes statements
 * directly against a lightweight statevector backend (`Runtime`). It currently supports:
 *
 *  - Declarations:
 *      * `qubit[n] q;`
 *      * `bit[n] b;`, `bool x;`, `int i;` (with simple expression initializers for bool/int)
 *  - Gates (with broadcasting and slices/sets):
 *      * 1-qubit: `x`, `h`, `rx(theta)`, `ry(theta)`, `rz(theta)`, `u(theta,phi,lambda)`,
 *                 `u1(lambda)`, `sx`, `sxdg`
 *      * 2-qubit: `cx` (pairwise mapping: `cx q[0:2], r[5:7]`)
 *  - Measurement & reset:
 *      * `measure q[i] -> b[j];`
 *      * `b[k] = measure q[i];`
 *      * `reset q[i];`
 *      * A bare `measure q[i];` collapses and traces when tracing is enabled.
 *  - Control flow:
 *      * `if (expr) { ... } else { ... }` with a small expression evaluator
 *
 * Indexing supported on gate operands includes single index `q[e]`, ranges `q[a:b(:s)]`,
 * explicit lists `q[e0, e1, ...]`, and sets `q[{i,j,k}]`. Operands may be hardware qubits
 * like `$7`. Whole-register broadcast is also supported (`h q;` applies H to all wires in `q`).
 *
 * The design intentionally favors a small, header-only executor with clear error messages.
 * As you expand language coverage, prefer adding small helpers that keep `visit*` methods concise.
 */

#include "Runtime.h"
#include "qasm3Parser.h"
#include "qasm3ParserBaseVisitor.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class ExecVisitor : public qasm3ParserBaseVisitor {
public:
  /**
   * @param rt    Reference to the quantum/classical runtime state.
   * @param trace If true, prints a compact execution log to @p out.
   * @param out   Stream used for tracing (defaults to std::cout).
   */
  explicit ExecVisitor(Runtime &rt, bool trace = false, std::ostream &out = std::cout)
      : rt_(rt), trace_(trace), out_(out) {}

  // --------------------------------------------------------------------------
  // Top-level & scopes
  // --------------------------------------------------------------------------

  /// program: version? statementOrScope* EOF;
  antlrcpp::Any visitProgram(qasm3Parser::ProgramContext *ctx) override {
    for (auto *child : ctx->statementOrScope())
      visit(child);
    return {};
  }

  /// scope: LBRACE statementOrScope* RBRACE;
  antlrcpp::Any visitScope(qasm3Parser::ScopeContext *ctx) override {
    for (auto *ss : ctx->statementOrScope())
      visit(ss);
    return {};
  }

  // --------------------------------------------------------------------------
  // Declarations
  // --------------------------------------------------------------------------

  /// qubitType Identifier ';'
  antlrcpp::Any
  visitQuantumDeclarationStatement(qasm3Parser::QuantumDeclarationStatementContext *ctx) override {
    const std::string name = ctx->Identifier()->getText();
    int n = 1;
    if (auto *qt = ctx->qubitType()) {
      if (auto *d = qt->designator())
        n = static_cast<int>(evalInt(d->expression()));
    }
    rt_.allocQubits(name, n);
    return {};
  }

  /// (scalarType | arrayType) Identifier ( '=' declarationExpression )? ';'
  /// Supported scalar types in this slice: bit[?], bool, int
  antlrcpp::Any visitClassicalDeclarationStatement(
      qasm3Parser::ClassicalDeclarationStatementContext *ctx) override {
    if (auto *st = ctx->scalarType()) {
      const std::string name = ctx->Identifier()->getText();
      if (st->BIT()) {
        int n = 1;
        if (auto *d = st->designator())
          n = static_cast<int>(evalInt(d->expression()));
        rt_.declareBits(name, n);
      } else if (st->BOOL()) {
        rt_.declareBool(name);
      } else if (st->INT()) {
        rt_.declareInt(name, 0);
      } else {
        throw std::runtime_error(
            "unsupported scalar type in declaration (only bit/bool/int supported in this slice)");
      }

      if (auto *de = ctx->declarationExpression()) {
        // Only handle bool/int scalar initializers in this slice
        if (st->BOOL()) {
          if (auto *e = de->expression())
            rt_.setBool(name, evalBool(e));
          else
            throw std::runtime_error("bool initializer must be an expression");
        } else if (st->INT()) {
          rt_.setInt(name, evalIntFromDecl(de));
        }
      }
    } else {
      throw std::runtime_error("arrayType declarations not yet supported in this slice");
    }
    return {};
  }

  // --------------------------------------------------------------------------
  // Gate calls
  // --------------------------------------------------------------------------

  /// gateModifier* Identifier (designator | expressionList)? gateOperandList ';'
  antlrcpp::Any
  visitGateCallStatement(qasm3Parser::GateCallStatementContext *ctx) override {
    const std::string g = lower(ctx->Identifier() ? ctx->Identifier()->getText() : "gphase");
    auto ops = collectOperandVectors(ctx->gateOperandList());

    // trace operands as absolute wires
    if (trace_) {
      out_ << "gate " << g << " ";
      for (size_t i = 0; i < ops.size(); ++i) {
        out_ << (i ? ", " : "");
        out_ << "{";
        for (size_t j = 0; j < ops[i].size(); ++j) {
          if (j) out_ << ",";
          out_ << ops[i][j];
        }
        out_ << "}";
      }
      out_ << "\n";
    }

    // helpers for arity/broadcast checks
    auto apply_1q = [&](auto fn_per_wire) {
      if (ops.size() != 1)
        throw std::runtime_error(g + " expects 1 operand");
      for (int q : ops[0]) fn_per_wire(q);
    };
    auto apply_2q_pairwise = [&](auto fn_pair) {
      if (ops.size() != 2)
        throw std::runtime_error(g + " expects 2 operands");
      if (ops[0].size() != ops[1].size())
        throw std::runtime_error("mismatched arity for pairwise 2-qubit op");
      for (size_t i = 0; i < ops[0].size(); ++i) fn_pair(ops[0][i], ops[1][i]);
    };

    using cd = std::complex<double>;
    const cd I(0, 1);

    if (g == "x") {
      apply_1q([&](int q) { rt_.x(q); });

    } else if (g == "h") {
      apply_1q([&](int q) { rt_.h(q); });

    } else if (g == "cx") {
      apply_2q_pairwise([&](int c, int t) { rt_.cx(c, t); });

    } else if (g == "rz") {
      const double th = singleAngleParam(ctx);
      const cd e_m = std::exp(-I * (th / 2.0));
      const cd e_p = std::exp(+I * (th / 2.0));
      apply_1q([&](int q) { rt_.apply1(q, e_m, 0.0, 0.0, e_p); });

    } else if (g == "ry") {
      const double th = singleAngleParam(ctx);
      const double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      apply_1q([&](int q) { rt_.apply1(q, c, -s, s, c); });

    } else if (g == "rx") {
      const double th = singleAngleParam(ctx);
      const double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      apply_1q([&](int q) { rt_.apply1(q, c, -I * s, -I * s, c); });

    } else if (g == "u" || g == "u3") {
      // u(theta,phi,lambda)
      auto *el = ctx->expressionList();
      if (!el || el->expression().size() != 3)
        throw std::runtime_error("u(theta,phi,lambda) requires 3 parameters");
      const double th = evalReal(el->expression(0));
      const double ph = evalReal(el->expression(1));
      const double la = evalReal(el->expression(2));
      const double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      const cd eip = std::exp(I * ph), eil = std::exp(I * la);
      apply_1q([&](int q) { rt_.apply1(q, c, -eil * s, eip * s, eip * eil * c); });

    } else if (g == "u1" || g == "p" || g == "phase") {
      // u1(lambda) == diag(1, e^{i*lambda}) ; aliases p/phase
      const double lam = singleAngleParam(ctx);
      const cd e = std::exp(I * lam);
      apply_1q([&](int q) { rt_.apply1(q, 1.0, 0.0, 0.0, e); });

    } else if (g == "sx") {
      // sqrt(X) = (1/2) * [[1+i, 1-i],[1-i, 1+i]]
      const cd a = cd(1, 1) * 0.5;  // (1+i)/2
      const cd b = cd(1,-1) * 0.5;  // (1-i)/2
      apply_1q([&](int q) { rt_.apply1(q, a, b, b, a); });

    } else if (g == "sxdg" || g == "sxdg") {
      // inverse of sx: (1/2) * [[1-i, 1+i],[1+i, 1-i]]
      const cd a = cd(1,-1) * 0.5;  // (1-i)/2
      const cd b = cd(1, 1) * 0.5;  // (1+i)/2
      apply_1q([&](int q) { rt_.apply1(q, a, b, b, a); });

    } else {
      throw std::runtime_error("unsupported gate in this slice: " + g);
    }

    return {};
  }

  // --------------------------------------------------------------------------
  // Measurement, reset, assignment, control
  // --------------------------------------------------------------------------

  /// measureExpression (ARROW indexedIdentifier)? ';'
  antlrcpp::Any visitMeasureArrowAssignmentStatement(
      qasm3Parser::MeasureArrowAssignmentStatementContext *ctx) override {
    const int q = gateOperandToSingleIndex(ctx->measureExpression()->gateOperand());
    const int r = rt_.measure(q);
    if (auto *tgt = ctx->indexedIdentifier())
      writeIndexedIdentifier(tgt, r);
    if (trace_)
      out_ << "measure -> " << r
           << (ctx->indexedIdentifier() ? "  (stored in " + ctx->indexedIdentifier()->getText() + ")" : "")
           << "\n";
    return {};
  }

  /// reset gateOperand ';'
  antlrcpp::Any visitResetStatement(qasm3Parser::ResetStatementContext *ctx) override {
    const int q = gateOperandToSingleIndex(ctx->gateOperand());
    rt_.reset(q);
    if (trace_) out_ << "reset\n";
    return {};
  }

  /// if (expr) stmt [else stmt]
  antlrcpp::Any visitIfStatement(qasm3Parser::IfStatementContext *ctx) override {
    const bool cond = evalBool(ctx->expression());
    if (cond) visit(ctx->if_body);
    else if (ctx->else_body) visit(ctx->else_body);
    return {};
  }

  /// <lvalue> '=' <rhs>;  Supports:  bs[i] = measure q[j];  and plain classical exprs.
  antlrcpp::Any visitAssignmentStatement(qasm3Parser::AssignmentStatementContext *ctx) override {
    using P = qasm3Parser;

    // LHS (bit/bool/int, possibly indexed)
    auto *lhs = ctx->indexedIdentifier();
    if (!lhs) {
      // Some grammar variants nest the LHS; find it conservatively.
      lhs = findDescendantSkipping<P::IndexedIdentifierContext>(ctx, nullptr);
      if (!lhs) throw std::runtime_error("assignment LHS not found");
    }

    // Dedicated measure alt available?
    if (auto *me = findDescendantSkipping<P::MeasureExpressionContext>(ctx, lhs)) {
      const int q = gateOperandToSingleIndex(me->gateOperand());
      const int r = rt_.measure(q);
      writeIndexedIdentifier(lhs, r);
      if (trace_) out_ << "measure -> " << r << "  (stored in " << lhs->getText() << ")\n";
      return {};
    }

    // Otherwise, grab the first expression on the RHS side (skipping the LHS subtree)
    auto *rhs = findDescendantSkipping<P::ExpressionContext>(ctx, lhs);
    if (!rhs) throw std::runtime_error("assignment RHS missing");

    const std::string rhsText = rhs->getText();
    if (rhsText.rfind("measure", 0) == 0) {
      if (auto *go = findDescendantSkipping<P::GateOperandContext>(rhs, nullptr)) {
        const int q = gateOperandToSingleIndex(go);
        const int r = rt_.measure(q);
        writeIndexedIdentifier(lhs, r);
        if (trace_) out_ << "measure -> " << r << "  (stored in " << lhs->getText() << ")\n";
        return {};
      }
      throw std::runtime_error("measure RHS: could not locate gate operand");
    }

    // Plain classical assignment
    const int v = static_cast<int>(evalInt(rhs));
    writeIndexedIdentifier(lhs, v);
    if (trace_) out_ << "assign " << lhs->getText() << " = " << v << "\n";
    return {};
  }

  // Fallback: descend into statements we don't handle explicitly.
  antlrcpp::Any visitStatement(qasm3Parser::StatementContext *ctx) override {
    using P = qasm3Parser;
    // Detect a bare "measure q[i];" statement in grammars that don't expose a dedicated MeasureStatement rule.
    if (auto *me = findDescendantSkipping<P::MeasureExpressionContext>(ctx, nullptr)) {
      const int q = gateOperandToSingleIndex(me->gateOperand());
      const int r = rt_.measure(q);
      if (trace_) out_ << "measure -> " << r << "\n";
      return {};
    }
    return qasm3ParserBaseVisitor::visitStatement(ctx);
  }

private:
  // --------------------------------------------------------------------------
  // Gate-operand expansion helpers
  // --------------------------------------------------------------------------

  /// Expand q[ ... ] into absolute wire indices (supports single index, range a:b(:s), set {i,j}, list e0,e1,...).
  std::vector<int>
  expandIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *iq) {
    const std::string qname = iq->Identifier()->getText();

    // Whole-register broadcast: q;
    if (iq->indexOperator().empty())
      return rt_.allQubits(qname);

    auto *op = iq->indexOperator(0);

    // Range: q[a:b(:s)]
    {
      const auto &ranges = op->rangeExpression(); // vector<RangeExpressionContext*>
      if (!ranges.empty()) {
        auto *r = ranges[0];
        const int a = static_cast<int>(evalInt(r->expression(0)));
        const int b = static_cast<int>(evalInt(r->expression(1)));
        const int s = (r->expression().size() >= 3)
                          ? static_cast<int>(evalInt(r->expression(2)))
                          : (a <= b ? 1 : -1);
        if (s == 0) throw std::runtime_error("range step cannot be 0");

        std::vector<int> out;
        if (s > 0) { out.reserve((b - a) / s + 1); for (int k = a; k <= b; k += s) out.push_back(rt_.qubitIndex(qname, k)); }
        else       { out.reserve((a - b) / (-s) + 1); for (int k = a; k >= b; k += s) out.push_back(rt_.qubitIndex(qname, k)); }
        return out;
      }
    }

    // Set: q[{i,j,k}] (pointer, nullptr if absent)
    if (auto *s = op->setExpression()) {
      std::vector<int> out; out.reserve(s->expression().size());
      for (auto *e : s->expression())
        out.push_back(rt_.qubitIndex(qname, static_cast<int>(evalInt(e))));
      return out;
    }

    // Explicit list: q[e0, e1, e2]
    if (op->expression().size() > 1) {
      std::vector<int> out; out.reserve(op->expression().size());
      for (auto *e : op->expression())
        out.push_back(rt_.qubitIndex(qname, static_cast<int>(evalInt(e))));
      return out;
    }

    // Single scalar: q[e]
    if (op->expression().size() == 1) {
      const int idx = static_cast<int>(evalInt(op->expression(0)));
      return {rt_.qubitIndex(qname, idx)};
    }

    throw std::runtime_error("unsupported/empty index operator on " + qname);
  }

  /// Expand a single gateOperand to zero or more absolute wire indices.
  std::vector<int>
  gateOperandToIndices(qasm3Parser::GateOperandContext *go) {
    if (auto *iq = go->indexedIdentifier())
      return expandIndexedIdentifier(iq);
    if (auto *hq = go->HardwareQubit()) {
      const std::string t = hq->getText(); // like "$7"
      return {std::stoi(t.substr(1))};
    }
    throw std::runtime_error("unsupported gate operand");
  }

  /// Require exactly one index; used by measure/reset paths.
  int gateOperandToSingleIndex(qasm3Parser::GateOperandContext *go) {
    auto v = gateOperandToIndices(go);
    if (v.size() != 1)
      throw std::runtime_error("operand must refer to exactly 1 qubit here");
    return v[0];
  }

  /// Flatten a list of operands into vectors (one vector per operand).
  std::vector<std::vector<int>>
  collectOperandVectors(qasm3Parser::GateOperandListContext *gl) {
    std::vector<std::vector<int>> out;
    for (auto *go : gl->gateOperand())
      out.push_back(gateOperandToIndices(go));
    return out;
  }

  // --------------------------------------------------------------------------
  // Write classical lvalues
  // --------------------------------------------------------------------------

  /// Write an integer value into an indexedIdentifier (bit arrays or scalars).
  void writeIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *id, int v) {
    const std::string name = id->Identifier()->getText();
    if (!id->indexOperator().empty()) {
      // Only single scalar index in this slice
      const int i =
          static_cast<int>(evalInt(id->indexOperator(0)->expression(0)));
      if (rt_.hasBit(name))
        rt_.setBit(name, i, v);
      else
        throw std::runtime_error("only bit[...] assignment supported here");
    } else {
      if (rt_.hasBit(name))
        rt_.setBit(name, 0, v);
      else if (rt_.hasBool(name))
        rt_.setBool(name, v != 0);
      else if (rt_.hasInt(name))
        rt_.setInt(name, v);
      else
        throw std::runtime_error("unknown classical lvalue '" + name + "'");
    }
  }

  // --------------------------------------------------------------------------
  // Expression utilities
  // --------------------------------------------------------------------------

  /// Lowercase copy of a string (ASCII).
  static std::string lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
  }

  /// Get a single angle parameter for rx/ry/rz/u1 (either via designator or a 1-elt expressionList).
  double singleAngleParam(qasm3Parser::GateCallStatementContext *ctx) {
    if (auto *des = ctx->designator())
      return evalReal(des->expression());
    if (auto *el = ctx->expressionList())
      if (el->expression().size() == 1) return evalReal(el->expression(0));
    throw std::runtime_error(ctx->Identifier()->getText() + " needs one angle parameter");
  }

  /// Detect a bare identifier expression (grammar-agnostic, via single TerminalNode).
  static bool exprIsBareIdentifier(qasm3Parser::ExpressionContext *e, std::string &out) {
    if (!e || e->children.size() != 1) return false;
    if (auto *node = e->children[0]) {
      if (auto *term = dynamic_cast<antlr4::tree::TerminalNode *>(node)) {
        auto *tok = term->getSymbol();
        if (tok && tok->getType() == qasm3Parser::Identifier) {
          out = tok->getText();
          return true;
        }
      }
    }
    return false;
  }

  /// Parse integer literal with optional underscores and base prefixes 0x/0b.
  static long long parseIntegerLiteral(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
    int base = 10;
    size_t pos = 0;
    if (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0) { base = 16; pos = 2; }
    else if (s.rfind("0b", 0) == 0 || s.rfind("0B", 0) == 0) { base = 2; pos = 2; }
    return std::stoll(s.substr(pos), nullptr, base);
  }

  // ----- expression evaluation (minimal but practical) -----------------------

  long long evalInt(qasm3Parser::ExpressionContext *e) {
    using P = qasm3Parser;

    // literal (true/false/integers)
    if (auto *lit = dynamic_cast<P::LiteralExpressionContext *>(e)) {
      const std::string s = lit->getText();
      if (s == "true") return 1;
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

    // parenthesis
    if (auto *par = dynamic_cast<P::ParenthesisExpressionContext *>(e))
      return evalInt(par->expression());

    // unary
    if (auto *un = dynamic_cast<P::UnaryExpressionContext *>(e)) {
      const long long a = evalInt(un->expression());
      const std::string op = un->op->getText();
      if (op == "-") return -a;
      if (op == "+") return  a;
      if (op == "!") return !a;
      throw std::runtime_error("unsupported unary op: " + op);
    }

    // a + b | a - b
    if (auto *add = dynamic_cast<P::AdditiveExpressionContext *>(e)) {
      const long long a = evalInt(add->expression(0));
      const long long b = evalInt(add->expression(1));
      return (add->op->getText() == "+") ? (a + b) : (a - b);
    }

    // a * b | a / b | a % b
    if (auto *mul = dynamic_cast<P::MultiplicativeExpressionContext *>(e)) {
      const long long a = evalInt(mul->expression(0));
      const long long b = evalInt(mul->expression(1));
      const std::string op = mul->op->getText();
      if (op == "*") return a * b;
      if (op == "/") return a / b;
      if (op == "%") return a % b;
    }

    // comparisons
    if (auto *cmp = dynamic_cast<P::ComparisonExpressionContext *>(e)) {
      const long long a = evalInt(cmp->expression(0));
      const long long b = evalInt(cmp->expression(1));
      const std::string op = cmp->op->getText();
      if (op == "<")  return a <  b;
      if (op == "<=") return a <= b;
      if (op == ">")  return a >  b;
      if (op == ">=") return a >= b;
    }

    // equality
    if (auto *eq = dynamic_cast<P::EqualityExpressionContext *>(e)) {
      const long long a = evalInt(eq->expression(0));
      const long long b = evalInt(eq->expression(1));
      const std::string op = eq->op->getText();
      if (op == "==") return a == b;
      if (op == "!=") return a != b;
    }

    // logical and / or (return 0/1)
    if (auto *land = dynamic_cast<P::LogicalAndExpressionContext *>(e))
      return evalBool(land->expression(0)) && evalBool(land->expression(1));
    if (auto *lor  = dynamic_cast<P::LogicalOrExpressionContext  *>(e))
      return evalBool(lor->expression(0))  || evalBool(lor->expression(1));

    throw std::runtime_error("unsupported expression form: " + e->getText());
  }

  long long evalIntFromDecl(qasm3Parser::DeclarationExpressionContext *de) {
    if (auto *e = de->expression()) return evalInt(e);
    throw std::runtime_error("initializer must be an expression in this slice");
  }

  double evalReal(qasm3Parser::ExpressionContext *e) {
    using P = qasm3Parser;

    // numeric literal (allow underscores, 'pi', true/false)
    if (auto *lit = dynamic_cast<P::LiteralExpressionContext *>(e)) {
      const std::string s = lit->getText();
      if (s == "pi")    return M_PI;
      if (s == "true")  return 1.0;
      if (s == "false") return 0.0;
      std::string t = s; t.erase(std::remove(t.begin(), t.end(), '_'), t.end());
      return std::stod(t);
    }

    // bare identifier
    {
      std::string name;
      if (exprIsBareIdentifier(e, name)) {
        if      (rt_.hasInt(name))  return static_cast<double>(rt_.getInt(name));
        else if (rt_.hasBool(name)) return rt_.getBool(name) ? 1.0 : 0.0;
      }
    }

    // (expr)
    if (auto *par = dynamic_cast<P::ParenthesisExpressionContext *>(e))
      return evalReal(par->expression());

    // unary
    if (auto *un = dynamic_cast<P::UnaryExpressionContext *>(e)) {
      const double a = evalReal(un->expression());
      const std::string op = un->op->getText();
      if (op == "-") return -a;
      if (op == "+") return  a;
      if (op == "!") return (a == 0.0) ? 1.0 : 0.0;
    }

    // +,-
    if (auto *add = dynamic_cast<P::AdditiveExpressionContext *>(e)) {
      const double a = evalReal(add->expression(0));
      const double b = evalReal(add->expression(1));
      return (add->op->getText() == "+") ? (a + b) : (a - b);
    }

    // *,/,%
    if (auto *mul = dynamic_cast<P::MultiplicativeExpressionContext *>(e)) {
      const double a = evalReal(mul->expression(0));
      const double b = evalReal(mul->expression(1));
      const std::string op = mul->op->getText();
      if (op == "*") return a * b;
      if (op == "/") return a / b;
      if (op == "%") return std::fmod(a, b);
    }

    // comparisons -> boolean 0/1
    if (auto *cmp = dynamic_cast<P::ComparisonExpressionContext *>(e)) {
      const double a = evalReal(cmp->expression(0));
      const double b = evalReal(cmp->expression(1));
      const std::string op = cmp->op->getText();
      if (op == "<")  return a <  b;
      if (op == "<=") return a <= b;
      if (op == ">")  return a >  b;
      if (op == ">=") return a >= b;
    }
    if (auto *eq = dynamic_cast<P::EqualityExpressionContext *>(e)) {
      const double a = evalReal(eq->expression(0));
      const double b = evalReal(eq->expression(1));
      const std::string op = eq->op->getText();
      if (op == "==") return a == b;
      if (op == "!=") return a != b;
    }

    // logical and/or
    if (auto *land = dynamic_cast<P::LogicalAndExpressionContext *>(e))
      return evalBool(land->expression(0)) && evalBool(land->expression(1));
    if (auto *lor  = dynamic_cast<P::LogicalOrExpressionContext *>(e))
      return evalBool(lor->expression(0))  || evalBool(lor->expression(1));

    // constant 'pi' if grammar doesn't classify it as a literal
    if (e && e->getText() == "pi") return M_PI;

    throw std::runtime_error("unsupported real expression: " + e->getText());
  }
  bool evalBool(qasm3Parser::ExpressionContext *e) { return evalInt(e) != 0; }

  // --------------------------------------------------------------------------
  // Parse-tree search helpers
  // --------------------------------------------------------------------------

  /// Find the first descendant of type T, skipping the entire `skip` subtree.
  template <typename T>
  T *findDescendantSkipping(antlr4::tree::ParseTree *n, antlr4::tree::ParseTree *skip) {
    if (!n || n == skip) return nullptr;
    if (auto *t = dynamic_cast<T *>(n)) return t;
    for (auto *c : n->children)
      if (auto *r = findDescendantSkipping<T>(c, skip)) return r;
    return nullptr;
  }

  /// Convenience wrapper: find a GateOperand anywhere under `n`.
  qasm3Parser::GateOperandContext *findGateOperand(antlr4::tree::ParseTree *n) {
    return findDescendantSkipping<qasm3Parser::GateOperandContext>(n, nullptr);
  }

private:
  Runtime &rt_;
  bool trace_ = false;
  std::ostream &out_;
};

