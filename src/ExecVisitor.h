#pragma once
#include "Runtime.h"
#include "qasm3Parser.h"
#include "qasm3ParserBaseVisitor.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <optional>
#include <stdexcept>
#include <string>

class ExecVisitor : public qasm3ParserBaseVisitor {
public:
  explicit ExecVisitor(Runtime &rt, bool trace = false,
                       std::ostream &out = std::cout)
      : rt_(rt), trace_(trace), out_(out) {}

  // program: version? statementOrScope* EOF;
  antlrcpp::Any visitProgram(qasm3Parser::ProgramContext *ctx) override {
    for (auto child : ctx->statementOrScope())
      visit(child);
    return {};
  }

  // { ... } blocks
  antlrcpp::Any visitScope(qasm3Parser::ScopeContext *ctx) override {
    for (auto ss : ctx->statementOrScope())
      visit(ss);
    return {};
  }

  // qubitType Identifier ';'
  antlrcpp::Any visitQuantumDeclarationStatement(
      qasm3Parser::QuantumDeclarationStatementContext *ctx) override {
    auto name = ctx->Identifier()->getText();
    int n = 1; // default qubit
    if (auto *qt = ctx->qubitType()) {
      if (auto *d = qt->designator()) {
        n = (int)evalInt(d->expression());
      }
    }
    rt_.allocQubits(name, n);
    return {};
  }

  // (scalarType | arrayType) Identifier ( '=' declarationExpression )? ';'
  // Support: bit[?] x; bool b; int[?] n; (int only scalar here)
  antlrcpp::Any visitClassicalDeclarationStatement(
      qasm3Parser::ClassicalDeclarationStatementContext *ctx) override {
    if (auto *st = ctx->scalarType()) {
      auto name = ctx->Identifier()->getText();
      if (st->BIT()) {
        int n = 1;
        if (auto *d = st->designator())
          n = (int)evalInt(d->expression());
        rt_.declareBits(name, n);
      } else if (st->BOOL()) {
        rt_.declareBool(name);
      } else if (st->INT()) {
        rt_.declareInt(name, 0);
      } else {
        // minimal slice: ignore others for now
        throw std::runtime_error("unsupported scalar type in declaration (only "
                                 "bit/bool/int supported in this slice)");
      }
      // Optional initializer (declarationExpression): handle simple int/bool
      // literals
      if (auto *de = ctx->declarationExpression()) {
        if (st->BOOL()) {
          if (auto *e = de->expression())
            rt_.setBool(name, evalBool(e));
          else
            throw std::runtime_error("bool initializer must be an expression");
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

  antlrcpp::Any visitAssignmentStatement(
      qasm3Parser::AssignmentStatementContext *ctx) override {
    using P = qasm3Parser;

    // LHS
    auto *lhs = ctx->indexedIdentifier();
    if (!lhs) {
      // Fallback: some grammars nest it — find it in the subtree.
      lhs = findDescendantSkipping<P::IndexedIdentifierContext>(ctx, nullptr);
      if (!lhs)
        throw std::runtime_error("assignment LHS not found");
    }

    // Prefer a dedicated measure node if present (outside the LHS subtree)
    if (auto *me =
            findDescendantSkipping<P::MeasureExpressionContext>(ctx, lhs)) {
      int q = gateOperandToSingleIndex(me->gateOperand());
      int r = rt_.measure(q);
      writeIndexedIdentifier(lhs, r);
      if (trace_)
        out_ << "measure -> " << r << "  (stored in " << lhs->getText()
             << ")\n";
      return {};
    }

    // Fallback: grab the first ExpressionContext that is not inside the LHS
    // subtree
    auto *rhs = findDescendantSkipping<P::ExpressionContext>(ctx, lhs);
    if (!rhs)
      throw std::runtime_error(
          "assignment RHS missing"); // <- your previous error

    // If the RHS text starts with "measure", try to locate its operand and
    // treat it as a measure
    const std::string rhsText = rhs->getText();
    if (rhsText.rfind("measure", 0) == 0) {
      if (auto *go =
              findDescendantSkipping<P::GateOperandContext>(rhs, nullptr)) {
        int q = gateOperandToSingleIndex(go);
        int r = rt_.measure(q);
        writeIndexedIdentifier(lhs, r);
        if (trace_)
          out_ << "measure -> " << r << "  (stored in " << lhs->getText()
               << ")\n";
        return {};
      }
      throw std::runtime_error("measure RHS: could not locate gate operand");
    }

    // Otherwise plain classical assignment (evaluate RHS as int/bool)
    int v = (int)evalInt(rhs);
    writeIndexedIdentifier(lhs, v);
    if (trace_)
      out_ << "assign " << lhs->getText() << " = " << v << "\n";
    return {};
  }

  // gateModifier* Identifier (...) designator? gateOperandList ';'
  antlrcpp::Any
  visitGateCallStatement(qasm3Parser::GateCallStatementContext *ctx) override {
    const std::string g =
        lower(ctx->Identifier() ? ctx->Identifier()->getText() : "gphase");
    auto ops = collectOperandVectors(ctx->gateOperandList());

    if (trace_) {
      out_ << "gate " << g << " ";
      for (size_t i = 0; i < ops.size(); ++i) {
        out_ << (i ? ", " : "");
        out_ << "{";
        for (size_t j = 0; j < ops[i].size(); ++j) {
          if (j)
            out_ << ",";
          out_ << ops[i][j];
        }
        out_ << "}";
      }
      out_ << "\n";
    }

    // Helpers for arity/broadcast checks
    auto apply_1q = [&](auto fn_per_wire) {
      if (ops.size() != 1)
        throw std::runtime_error(g + " expects 1 operand");
      for (int q : ops[0])
        fn_per_wire(q);
    };
    auto apply_2q_pairwise = [&](auto fn_pair) {
      if (ops.size() != 2)
        throw std::runtime_error(g + " expects 2 operands");
      if (ops[0].size() != ops[1].size())
        throw std::runtime_error("mismatched arity for pairwise 2-qubit op");
      for (size_t i = 0; i < ops[0].size(); ++i)
        fn_pair(ops[0][i], ops[1][i]);
    };

    using cd = std::complex<double>;
    const cd I(0, 1);

    if (g == "x") {
      apply_1q([&](int q) { rt_.x(q); });

    } else if (g == "h") {
      apply_1q([&](int q) { rt_.h(q); });

    } else if (g == "cx" || g == "cx") {
      apply_2q_pairwise([&](int c, int t) { rt_.cx(c, t); });

    } else if (g == "rz") {
      double th = singleAngleParam(ctx);
      cd e_m = std::exp(-I * (th / 2.0));
      cd e_p = std::exp(I * (th / 2.0));
      apply_1q([&](int q) { rt_.apply1(q, e_m, 0.0, 0.0, e_p); });

    } else if (g == "ry") {
      double th = singleAngleParam(ctx);
      double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      apply_1q([&](int q) { rt_.apply1(q, c, -s, s, c); });

    } else if (g == "rx") {
      double th = singleAngleParam(ctx);
      double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      apply_1q([&](int q) { rt_.apply1(q, c, -I * s, -I * s, c); });

    } else if (g == "u" || g == "u") {
      // u(theta,phi,lambda)
      auto *el = ctx->expressionList();
      if (!el || el->expression().size() != 3)
        throw std::runtime_error("u(theta,phi,lambda) requires 3 parameters");
      double th = evalReal(el->expression(0));
      double ph = evalReal(el->expression(1));
      double la = evalReal(el->expression(2));
      double c = std::cos(th / 2.0), s = std::sin(th / 2.0);
      cd eip = std::exp(I * ph), eil = std::exp(I * la);
      apply_1q(
          [&](int q) { rt_.apply1(q, c, -eil * s, eip * s, eip * eil * c); });

    } else {
      throw std::runtime_error("unsupported gate in this slice: " + g);
    }
    return {};
  }

  // measureExpression (ARROW indexedIdentifier)? ';'
  antlrcpp::Any visitMeasureArrowAssignmentStatement(
      qasm3Parser::MeasureArrowAssignmentStatementContext *ctx) override {
    int q = gateOperandToIndex(ctx->measureExpression()->gateOperand());
    int r = rt_.measure(q);
    if (auto *tgt = ctx->indexedIdentifier()) {
      writeIndexedIdentifier(tgt, r);
    }
    if (trace_) {
      out_ << "measure -> " << r;
      if (auto *tgt = ctx->indexedIdentifier()) {
        out_ << "  (stored in " << tgt->getText() << ")";
      }
      out_ << "\n";
    }

    return {};
  }

  // reset gateOperand ';'
  antlrcpp::Any
  visitResetStatement(qasm3Parser::ResetStatementContext *ctx) override {
    int q = gateOperandToIndex(ctx->gateOperand());
    rt_.reset(q);
    if (trace_)
      out_ << "reset\n";

    return {};
  }

  // if (expr) stmt [else stmt]
  antlrcpp::Any
  visitIfStatement(qasm3Parser::IfStatementContext *ctx) override {
    bool cond = evalBool(ctx->expression());
    if (cond)
      visit(ctx->if_body);
    else if (ctx->else_body)
      visit(ctx->else_body);
    return {};
  }

  // Fallback: descend
  antlrcpp::Any visitStatement(qasm3Parser::StatementContext *ctx) override {
    return qasm3ParserBaseVisitor::visitStatement(ctx);
  }

private:
  // Find the first descendant of type T, skipping an entire subtree (e.g., the
  // LHS)
  template <typename T>
  T *findDescendantSkipping(antlr4::tree::ParseTree *n,
                            antlr4::tree::ParseTree *skip) {
    if (!n || n == skip)
      return nullptr;
    if (auto *t = dynamic_cast<T *>(n))
      return t;
    for (auto *c : n->children) {
      if (auto *r = findDescendantSkipping<T>(c, skip))
        return r;
    }
    return nullptr;
  }

  // Convenience wrapper: find a GateOperand anywhere under n
  qasm3Parser::GateOperandContext *findGateOperand(antlr4::tree::ParseTree *n) {
    return findDescendantSkipping<qasm3Parser::GateOperandContext>(n, nullptr);
  }

  // ----- helpers -----
  // gateOperandList: gateOperand (',' gateOperand)* ','
  std::vector<int>
  collectGateOperands(qasm3Parser::GateOperandListContext *gl) {
    std::vector<int> out;
    for (auto *go : gl->gateOperand())
      out.push_back(gateOperandToIndex(go));
    return out;
  }

  // gateOperand: indexedIdentifier | HardwareQubit
  int gateOperandToIndex(qasm3Parser::GateOperandContext *go) {
    if (auto *iq = go->indexedIdentifier()) {
      const std::string qname = iq->Identifier()->getText();
      // Only single index like q[i]; multi-index/slices TODO
      int idx = 0;
      if (!iq->indexOperator().empty()) {
        auto *op = iq->indexOperator(0);
        // indexOperator: '[' (expression | rangeExpression | setExpression …)
        // ']' Minimal: assume single scalar expression first.
        idx = (int)evalInt(op->expression(0));
      }
      return rt_.qubitIndex(qname, idx);
    }
    // HardwareQubit like $0 (rare in sim); map $k to absolute index k
    if (auto *hq = go->HardwareQubit()) {
      const std::string t = hq->getText(); // like "$7"
      return std::stoi(t.substr(1));
    }
    throw std::runtime_error("unsupported gate operand form");
  }

  // Write a value into an indexedIdentifier (bit arrays or scalars)
  void writeIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *id,
                              int v) {
    const std::string name = id->Identifier()->getText();
    if (!id->indexOperator().empty()) {
      int i = (int)evalInt(id->indexOperator(0)->expression(0));
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

  // ---------- expression evaluation (minimal) ----------
  // Supports integer literals, identifiers (bit/bool/int), unary -, +,
  // comparisons, logical &&, ||.

  Runtime &rt_;
  bool trace_ = false;
  std::ostream &out_;

  // ---------- generic identifier probe ----------
  static bool exprIsBareIdentifier(qasm3Parser::ExpressionContext *e,
                                   std::string &out) {
    // Many OpenQASM3 grammar variants express a lone identifier as an
    // expression with a single TerminalNode child.
    if (e && e->children.size() == 1) {
      auto *node = e->children[0];
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

  // ---------- tiny integer literal parser (10/16/2 with underscores)
  // ----------
  static long long parseIntegerLiteral(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
    int base = 10;
    size_t pos = 0;
    if (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0) {
      base = 16;
      pos = 2;
    } else if (s.rfind("0b", 0) == 0 || s.rfind("0B", 0) == 0) {
      base = 2;
      pos = 2;
    }
    return std::stoll(s.substr(pos), nullptr, base);
  }

  // ---------- expression evaluation (minimal) ----------
  long long evalInt(qasm3Parser::ExpressionContext *e) {
    using P = qasm3Parser;

    // literal expression (true/false/integers). If your grammar doesn't expose
    // LiteralExpressionContext, this branch is simply skipped.
    if (auto *lit = dynamic_cast<P::LiteralExpressionContext *>(e)) {
      const std::string s = lit->getText();
      if (s == "true")
        return 1;
      if (s == "false")
        return 0;
      return parseIntegerLiteral(s);
    }

    // bare identifier like `x`
    {
      std::string name;
      if (exprIsBareIdentifier(e, name)) {
        if (rt_.hasInt(name))
          return rt_.getInt(name);
        else if (rt_.hasBool(name))
          return rt_.getBool(name) ? 1 : 0;
        else if (rt_.hasBit(name))
          return rt_.getBit(name, 0);
        throw std::runtime_error("unknown identifier in expression: " + name);
      }
    }

    // (expr)
    if (auto *par = dynamic_cast<P::ParenthesisExpressionContext *>(e)) {
      return evalInt(par->expression());
    }

    // unary
    if (auto *un = dynamic_cast<P::UnaryExpressionContext *>(e)) {
      long long a = evalInt(un->expression());
      const std::string op = un->op->getText();
      if (op == "-")
        return -a;
      if (op == "+")
        return a;
      if (op == "!")
        return !a;
      throw std::runtime_error("unsupported unary op: " + op);
    }

    // a + b | a - b
    if (auto *add = dynamic_cast<P::AdditiveExpressionContext *>(e)) {
      long long a = evalInt(add->expression(0));
      long long b = evalInt(add->expression(1));
      return (add->op->getText() == "+") ? (a + b) : (a - b);
    }

    // a * b | a / b | a % b
    if (auto *mul = dynamic_cast<P::MultiplicativeExpressionContext *>(e)) {
      long long a = evalInt(mul->expression(0));
      long long b = evalInt(mul->expression(1));
      const std::string op = mul->op->getText();
      if (op == "*")
        return a * b;
      if (op == "/")
        return a / b;
      if (op == "%")
        return a % b;
    }

    // comparisons
    if (auto *cmp = dynamic_cast<P::ComparisonExpressionContext *>(e)) {
      long long a = evalInt(cmp->expression(0));
      long long b = evalInt(cmp->expression(1));
      const std::string op = cmp->op->getText();
      if (op == "<")
        return a < b;
      if (op == "<=")
        return a <= b;
      if (op == ">")
        return a > b;
      if (op == ">=")
        return a >= b;
    }

    // equality
    if (auto *eq = dynamic_cast<P::EqualityExpressionContext *>(e)) {
      long long a = evalInt(eq->expression(0));
      long long b = evalInt(eq->expression(1));
      const std::string op = eq->op->getText();
      if (op == "==")
        return a == b;
      if (op == "!=")
        return a != b;
    }

    // logical and / or
    if (auto *land = dynamic_cast<P::LogicalAndExpressionContext *>(e))
      return evalBool(land->expression(0)) && evalBool(land->expression(1));
    if (auto *lor = dynamic_cast<P::LogicalOrExpressionContext *>(e))
      return evalBool(lor->expression(0)) || evalBool(lor->expression(1));

    throw std::runtime_error("unsupported expression form: " + e->getText());
  }

  long long evalIntFromDecl(qasm3Parser::DeclarationExpressionContext *de) {
    if (auto *e = de->expression())
      return evalInt(e);
    throw std::runtime_error("initializer must be an expression in this slice");
  }

  bool evalBool(qasm3Parser::ExpressionContext *e) { return evalInt(e) != 0; }

  // returns absolute wire indices for q[...] (handles single index, range a:b,
  // set {i,j,...}) returns absolute wire indices for q[...] (handles single
  // index, range a:b, set {i,j,...}, and lists) returns absolute wire indices
  // for q[...] (handles single index, range a:b[:s], set {i,j,...}, and lists)
  std::vector<int>
  expandIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *iq) {
    const std::string qname = iq->Identifier()->getText();

    if (iq->indexOperator().empty()) {
      throw std::runtime_error(
          "array operand without index not supported yet: " + qname);
    }
    auto *op = iq->indexOperator(0);

    // Case 1: range q[a:b] (or q[a:b:s] if your grammar provides 3 exprs)
    {
      const auto &ranges = op->rangeExpression(); // NOTE: vector<...>
      if (!ranges.empty()) {
        auto *r = ranges[0];
        int a = (int)evalInt(r->expression(0));
        int b = (int)evalInt(r->expression(1));
        int s = (r->expression().size() >= 3) ? (int)evalInt(r->expression(2))
                                              : (a <= b ? 1 : -1);
        if (s == 0)
          throw std::runtime_error("range step cannot be 0");
        std::vector<int> out;
        if (s > 0) {
          out.reserve((b - a) / s + 1);
          for (int k = a; k <= b; k += s)
            out.push_back(rt_.qubitIndex(qname, k));
        } else {
          out.reserve((a - b) / (-s) + 1);
          for (int k = a; k >= b; k += s)
            out.push_back(rt_.qubitIndex(qname, k));
        }
        return out;
      }
    }

    // Case 2: set q[{i,j,k}]  (NOTE: pointer, nullptr if absent)
    if (auto *s = op->setExpression()) {
      std::vector<int> out;
      out.reserve(s->expression().size());
      for (auto *e : s->expression())
        out.push_back(rt_.qubitIndex(qname, (int)evalInt(e)));
      return out;
    }

    // Case 3: explicit list q[e0, e1, e2] (no braces)
    if (op->expression().size() > 1) {
      std::vector<int> out;
      out.reserve(op->expression().size());
      for (auto *e : op->expression())
        out.push_back(rt_.qubitIndex(qname, (int)evalInt(e)));
      return out;
    }

    // Case 4: single scalar q[e]
    if (op->expression().size() == 1) {
      int idx = (int)evalInt(op->expression(0));
      return {rt_.qubitIndex(qname, idx)};
    }

    throw std::runtime_error("unsupported/empty index operator on " + qname);
  }

  // Expand a single gateOperand to zero or more absolute wire indices.
  std::vector<int> gateOperandToIndices(qasm3Parser::GateOperandContext *go) {
    if (auto *iq = go->indexedIdentifier()) {
      // Handles q[e], q[a:b(:s)], q[{...}], and q[e0, e1, ...]
      return expandIndexedIdentifier(iq);
    }
    if (auto *hq = go->HardwareQubit()) {
      const std::string t = hq->getText(); // like "$7"
      return {std::stoi(t.substr(1))};
    }
    throw std::runtime_error("unsupported gate operand");
  }

  // Require exactly one index; useful for measure/reset etc.
  int gateOperandToSingleIndex(qasm3Parser::GateOperandContext *go) {
    auto v = gateOperandToIndices(go);
    if (v.size() != 1)
      throw std::runtime_error("operand must refer to exactly 1 qubit here");
    return v[0];
  }

  // Flatten a list of operands into vectors (each element may be 1+ wires).
  std::vector<std::vector<int>>
  collectOperandVectors(qasm3Parser::GateOperandListContext *gl) {
    std::vector<std::vector<int>> out;
    for (auto *go : gl->gateOperand())
      out.push_back(gateOperandToIndices(go));
    return out;
  }

  double evalReal(qasm3Parser::ExpressionContext *e) {
    // reuse evalInt when possible
    using P = qasm3Parser;
    // numeric literal (may contain '.' or exponent)
    if (auto *lit = dynamic_cast<P::LiteralExpressionContext *>(e)) {
      const std::string s = lit->getText();
      if (s == "pi")
        return M_PI;
      if (s == "true")
        return 1.0;
      if (s == "false")
        return 0.0;
      std::string t = s;
      t.erase(std::remove(t.begin(), t.end(), '_'), t.end());
      return std::stod(t);
    }
    // bare identifier: allow ints/bools
    {
      std::string name;
      if (exprIsBareIdentifier(e, name)) {
        if (rt_.hasInt(name))
          return (double)rt_.getInt(name);
        else if (rt_.hasBool(name))
          return rt_.getBool(name) ? 1.0 : 0.0;
        // fallthrough -> error
      }
    }
    // (expr)
    if (auto *par = dynamic_cast<P::ParenthesisExpressionContext *>(e))
      return evalReal(par->expression());
    // unary
    if (auto *un = dynamic_cast<P::UnaryExpressionContext *>(e)) {
      double a = evalReal(un->expression());
      const std::string op = un->op->getText();
      if (op == "-")
        return -a;
      if (op == "+")
        return a;
      if (op == "!")
        return (a == 0.0) ? 1.0 : 0.0;
    }
    // +,-
    if (auto *add = dynamic_cast<P::AdditiveExpressionContext *>(e)) {
      double a = evalReal(add->expression(0));
      double b = evalReal(add->expression(1));
      return (add->op->getText() == "+") ? (a + b) : (a - b);
    }
    // *,/,%
    if (auto *mul = dynamic_cast<P::MultiplicativeExpressionContext *>(e)) {
      double a = evalReal(mul->expression(0));
      double b = evalReal(mul->expression(1));
      const std::string op = mul->op->getText();
      if (op == "*")
        return a * b;
      if (op == "/")
        return a / b;
      if (op == "%")
        return std::fmod(a, b);
    }
    // comparisons -> boolean 0/1
    if (auto *cmp = dynamic_cast<P::ComparisonExpressionContext *>(e)) {
      double a = evalReal(cmp->expression(0));
      double b = evalReal(cmp->expression(1));
      const std::string op = cmp->op->getText();
      if (op == "<")
        return a < b;
      if (op == "<=")
        return a <= b;
      if (op == ">")
        return a > b;
      if (op == ">=")
        return a >= b;
    }
    if (auto *eq = dynamic_cast<P::EqualityExpressionContext *>(e)) {
      double a = evalReal(eq->expression(0));
      double b = evalReal(eq->expression(1));
      const std::string op = eq->getText();
      if (op == "==")
        return a == b;
      if (op == "!=")
        return a != b;
    }
    // logical and/or
    if (auto *land = dynamic_cast<P::LogicalAndExpressionContext *>(e))
      return evalBool(land->expression(0)) && evalBool(land->expression(1));
    if (auto *lor = dynamic_cast<P::LogicalOrExpressionContext *>(e))
      return evalBool(lor->expression(0)) || evalBool(lor->expression(1));

    // constant 'pi' if grammar doesn’t classify it as literal
    if (e->getText() == "pi")
      return M_PI;

    throw std::runtime_error("unsupported real expression: " + e->getText());
  }

  // lowercasing helper for gate names
  static std::string lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
  }

  // Get a single angle parameter for gates like rx/ry/rz.
  // Accepts either: Identifier ( designator )  OR  Identifier ( expressionList
  // )
  double singleAngleParam(qasm3Parser::GateCallStatementContext *ctx) {
    if (auto *des = ctx->designator()) {
      return evalReal(des->expression());
    }
    if (auto *el = ctx->expressionList()) {
      if (el->expression().size() == 1)
        return evalReal(el->expression(0));
    }
    throw std::runtime_error(ctx->Identifier()->getText() +
                             " needs one angle parameter");
  }
};
