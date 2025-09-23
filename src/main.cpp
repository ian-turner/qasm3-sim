#include <fstream>
#include <iostream>
#include "antlr4-runtime.h"
#include "qasm3Lexer.h"
#include "qasm3Parser.h"
#include "ExecVisitor.h"
#include "Runtime.h"

int main(int argc, char** argv) {
  if (argc < 2) { std::cerr << "usage: q3sim <file.qasm>\n"; return 1; }
  std::ifstream stream(argv[1]);
  if (!stream) { std::cerr << "could not open " << argv[1] << "\n"; return 1; }

  antlr4::ANTLRInputStream input(stream);
  qasm3Lexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qasm3Parser parser(&tokens);

  auto* tree = parser.program();
  if (parser.getNumberOfSyntaxErrors() > 0) {
    std::cerr << "parse errors\n"; return 2;
  }

  Runtime rt;
  ExecVisitor exec(rt);
  try {
    exec.visit(tree);
  } catch (const std::exception& ex) {
    std::cerr << "runtime error: " << ex.what() << "\n";
    return 3;
  }

  // Optional: print final amplitudes for tiny states
  if (rt.numQubits() <= 3) {
    const auto& psi = rt.state();
    for (size_t i = 0; i < psi.size(); ++i) {
      std::cout << i << ": " << psi[i] << "\n";
    }
  }
  return 0;
}
