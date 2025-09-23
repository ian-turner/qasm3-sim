#include <fstream>
#include <iostream>
#include "antlr4-runtime/antlr4-runtime.h"
#include "qasm3Lexer.h"
#include "qasm3Parser.h"

int main(int argc, char** argv) {
  if (argc < 2) { std::cerr << "usage: oq3 <file.qasm>\n"; return 1; }
  std::ifstream stream(argv[1]);
  if (!stream) { std::cerr << "could not open " << argv[1] << "\n"; return 1; }

  antlr4::ANTLRInputStream input(stream);
  qasm3Lexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qasm3Parser parser(&tokens);

  auto tree = parser.program();                 // top-level rule from the spec grammar
  if (parser.getNumberOfSyntaxErrors() > 0) return 2;

  // TODO: implement a qasm3Visitor to build your AST / IR.
  std::cout << "Parsed OK\n";
  return 0;
}
