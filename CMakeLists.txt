cmake_minimum_required(VERSION 3.16)
project(qasm3sim CXX)

# If you installed the runtime via a package manager, this should work:
find_package(antlr4-runtime CONFIG REQUIRED)

add_executable(q3sim
  src/main.cpp
  gen/qasm3Lexer.cpp
  gen/qasm3Parser.cpp
  gen/qasm3ParserBaseVisitor.cpp
  gen/qasm3ParserVisitor.cpp)

target_include_directories(q3sim PRIVATE gen /usr/include/antlr4-runtime)
target_link_libraries(q3sim PRIVATE antlr4-runtime)
set_property(TARGET q3sim PROPERTY CXX_STANDARD 17)
