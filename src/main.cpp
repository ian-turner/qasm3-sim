#include <fstream>
#include <iostream>
#include "antlr4-runtime.h"
#include "qasm3Lexer.h"
#include "qasm3Parser.h"
#include "DumpVisitor.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: dumpqasm <file.qasm>\n";
    return 1;
  }
  std::ifstream stream(argv[1]);
  if (!stream) {
    std::cerr << "could not open " << argv[1] << "\n";
    return 1;
  }

  antlr4::ANTLRInputStream input(stream);
  qasm3Lexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qasm3Parser parser(&tokens);

  auto* tree = parser.program();             // top-level rule in qasm3Parser.g4
  if (parser.getNumberOfSyntaxErrors() > 0) return 2;

  // Quick alternative (no visitor) if you ever need it:
  // std::cout << tree->toStringTree(&parser) << "\n";

  DumpVisitor dump(parser.getRuleNames(), parser.getVocabulary());
  dump.visit(tree);
  return 0;
}

