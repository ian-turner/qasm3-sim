#include "ExecVisitor.h"
#include "Runtime.h"
#include "antlr4-runtime.h"
#include "qasm3Lexer.h"
#include "qasm3Parser.h"
#include <cstring> // for strcmp
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  bool trace = false;
  bool dump_state = false;
  const char *filename = nullptr;

  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--trace") == 0)
      trace = true;
    else if (std::strcmp(argv[i], "--dump-state") == 0)
      dump_state = true;
    else
      filename = argv[i];
  }
  if (!filename) {
    std::cerr << "usage: q3sim [--trace] [--dump-state] file.qasm\n";
    return 1;
  }

  std::ifstream stream(filename);
  if (!stream) {
    std::cerr << "could not open " << filename << "\n";
    return 1;
  }

  antlr4::ANTLRInputStream input(stream);
  qasm3Lexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qasm3Parser parser(&tokens);

  auto *tree = parser.program();
  if (parser.getNumberOfSyntaxErrors() > 0) {
    std::cerr << "parse errors\n";
    return 2;
  }

  Runtime rt;
  ExecVisitor exec(rt, trace, std::cout);

  try {
    exec.visit(tree);
  } catch (const std::exception &ex) {
    std::cerr << "runtime error: " << ex.what() << "\n";
    return 3;
  }

  if (dump_state || rt.numQubits() <= 3) {
    rt.dumpState(std::cout);
  }
  return 0;
}
