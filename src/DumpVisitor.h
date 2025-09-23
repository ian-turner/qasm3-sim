#pragma once
#include "antlr4-runtime.h"
#include "qasm3ParserBaseVisitor.h"
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class DumpVisitor : public qasm3ParserBaseVisitor {
public:
  explicit DumpVisitor(const std::vector<std::string> &ruleNames,
                       const antlr4::dfa::Vocabulary &vocab,
                       std::ostream &out = std::cout)
      : ruleNames_(ruleNames), vocab_(vocab), out_(out) {}

  antlrcpp::Any visitChildren(antlr4::tree::ParseTree *node) override {
    if (auto *ctx = dynamic_cast<antlr4::ParserRuleContext *>(node)) {
      printIndent();
      out_ << ruleName(ctx) << " ";
      auto *start = ctx->getStart();
      auto *stop = ctx->getStop();
      if (start && stop) {
        out_ << "[" << start->getLine() << ":" << start->getCharPositionInLine()
             << " - " << stop->getLine() << ":" << stop->getCharPositionInLine()
             << "]";
      }
      out_ << "\n";

      ++indent_;
      auto result = qasm3ParserBaseVisitor::visitChildren(node);
      --indent_;
      return result;
    }
    return qasm3ParserBaseVisitor::visitChildren(node);
  }

  antlrcpp::Any visitTerminal(antlr4::tree::TerminalNode *node) override {
    printIndent();
    auto *sym = node->getSymbol();
    int type = sym->getType();

    // Make an explicit copy from string_view for portability.
    auto name_sv = vocab_.getSymbolicName(type);
    std::string name(name_sv.data(), name_sv.size());
    if (name.empty()) {
      auto disp_sv = vocab_.getDisplayName(type);
      name.assign(disp_sv.data(), disp_sv.size());
    }

    out_ << "TOKEN " << name << " \"" << escape(sym->getText()) << "\""
         << " (" << sym->getLine() << ":" << sym->getCharPositionInLine() << ")"
         << "\n";
    return antlrcpp::Any();
  }

  antlrcpp::Any visitErrorNode(antlr4::tree::ErrorNode *node) override {
    printIndent();
    out_ << "ERROR \"" << escape(node->getText()) << "\"\n";
    return antlrcpp::Any();
  }

private:
  void printIndent() {
    for (int i = 0; i < indent_; ++i)
      out_ << "  ";
  }

  std::string ruleName(antlr4::ParserRuleContext *ctx) const {
    int idx = ctx->getRuleIndex();
    if (idx >= 0 && idx < static_cast<int>(ruleNames_.size()))
      return ruleNames_[idx];
    return std::string("<rule ") + std::to_string(idx) + ">";
  }

  static std::string escape(const std::string &s) {
    std::string r;
    r.reserve(s.size());
    for (char c : s) {
      if (c == '\n')
        r += "\\n";
      else if (c == '\t')
        r += "\\t";
      else if (c == '\"')
        r += "\\\"";
      else
        r += c;
    }
    return r;
  }

  const std::vector<std::string> &ruleNames_;
  const antlr4::dfa::Vocabulary &vocab_;
  std::ostream &out_;
  int indent_ = 0;
};
