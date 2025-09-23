
// Generated from qasm3Lexer.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

class qasm3Lexer : public antlr4::Lexer {
public:
  enum {
    OPENQASM = 1,
    INCLUDE = 2,
    DEFCALGRAMMAR = 3,
    DEF = 4,
    CAL = 5,
    DEFCAL = 6,
    GATE = 7,
    EXTERN = 8,
    BOX = 9,
    LET = 10,
    BREAK = 11,
    CONTINUE = 12,
    IF = 13,
    ELSE = 14,
    END = 15,
    RETURN = 16,
    FOR = 17,
    WHILE = 18,
    IN = 19,
    SWITCH = 20,
    CASE = 21,
    DEFAULT = 22,
    NOP = 23,
    PRAGMA = 24,
    AnnotationKeyword = 25,
    INPUT = 26,
    OUTPUT = 27,
    CONST = 28,
    READONLY = 29,
    MUTABLE = 30,
    QREG = 31,
    QUBIT = 32,
    CREG = 33,
    BOOL = 34,
    BIT = 35,
    INT = 36,
    UINT = 37,
    FLOAT = 38,
    ANGLE = 39,
    COMPLEX = 40,
    ARRAY = 41,
    VOID = 42,
    DURATION = 43,
    STRETCH = 44,
    GPHASE = 45,
    INV = 46,
    POW = 47,
    CTRL = 48,
    NEGCTRL = 49,
    DIM = 50,
    DURATIONOF = 51,
    DELAY = 52,
    RESET = 53,
    MEASURE = 54,
    BARRIER = 55,
    BooleanLiteral = 56,
    LBRACKET = 57,
    RBRACKET = 58,
    LBRACE = 59,
    RBRACE = 60,
    LPAREN = 61,
    RPAREN = 62,
    COLON = 63,
    SEMICOLON = 64,
    DOT = 65,
    COMMA = 66,
    EQUALS = 67,
    ARROW = 68,
    PLUS = 69,
    DOUBLE_PLUS = 70,
    MINUS = 71,
    ASTERISK = 72,
    DOUBLE_ASTERISK = 73,
    SLASH = 74,
    PERCENT = 75,
    PIPE = 76,
    DOUBLE_PIPE = 77,
    AMPERSAND = 78,
    DOUBLE_AMPERSAND = 79,
    CARET = 80,
    AT = 81,
    TILDE = 82,
    EXCLAMATION_POINT = 83,
    EqualityOperator = 84,
    CompoundAssignmentOperator = 85,
    ComparisonOperator = 86,
    BitshiftOperator = 87,
    IMAG = 88,
    ImaginaryLiteral = 89,
    BinaryIntegerLiteral = 90,
    OctalIntegerLiteral = 91,
    DecimalIntegerLiteral = 92,
    HexIntegerLiteral = 93,
    Identifier = 94,
    HardwareQubit = 95,
    FloatLiteral = 96,
    TimingLiteral = 97,
    BitstringLiteral = 98,
    Whitespace = 99,
    Newline = 100,
    LineComment = 101,
    BlockComment = 102,
    VERSION_IDENTIFER_WHITESPACE = 103,
    VersionSpecifier = 104,
    ARBITRARY_STRING_WHITESPACE = 105,
    StringLiteral = 106,
    EAT_INITIAL_SPACE = 107,
    EAT_LINE_END = 108,
    RemainingLineContent = 109,
    CAL_PRELUDE_WHITESPACE = 110,
    CAL_PRELUDE_COMMENT = 111,
    DEFCAL_PRELUDE_WHITESPACE = 112,
    DEFCAL_PRELUDE_COMMENT = 113,
    CalibrationBlock = 114
  };

  enum {
    VERSION_IDENTIFIER = 1,
    ARBITRARY_STRING = 2,
    EAT_TO_LINE_END = 3,
    CAL_PRELUDE = 4,
    DEFCAL_PRELUDE = 5,
    CAL_BLOCK = 6
  };

  explicit qasm3Lexer(antlr4::CharStream *input);

  ~qasm3Lexer() override;

  std::string getGrammarFileName() const override;

  const std::vector<std::string> &getRuleNames() const override;

  const std::vector<std::string> &getChannelNames() const override;

  const std::vector<std::string> &getModeNames() const override;

  const antlr4::dfa::Vocabulary &getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN &getATN() const override;

  // By default the static state used to implement the lexer is lazily
  // initialized during the first call to the constructor. You can call this
  // function if you wish to initialize the static state ahead of time.
  static void initialize();

private:
  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.
};
