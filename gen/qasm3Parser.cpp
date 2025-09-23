
// Generated from qasm3Parser.g4 by ANTLR 4.13.2


#include "qasm3ParserVisitor.h"

#include "qasm3Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Qasm3ParserStaticData final {
  Qasm3ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Qasm3ParserStaticData(const Qasm3ParserStaticData&) = delete;
  Qasm3ParserStaticData(Qasm3ParserStaticData&&) = delete;
  Qasm3ParserStaticData& operator=(const Qasm3ParserStaticData&) = delete;
  Qasm3ParserStaticData& operator=(Qasm3ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag qasm3parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Qasm3ParserStaticData> qasm3parserParserStaticData = nullptr;

void qasm3parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (qasm3parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(qasm3parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Qasm3ParserStaticData>(
    std::vector<std::string>{
      "program", "version", "statement", "annotation", "scope", "pragma", 
      "statementOrScope", "calibrationGrammarStatement", "includeStatement", 
      "breakStatement", "continueStatement", "endStatement", "forStatement", 
      "ifStatement", "returnStatement", "whileStatement", "switchStatement", 
      "switchCaseItem", "barrierStatement", "boxStatement", "delayStatement", 
      "nopStatement", "gateCallStatement", "measureArrowAssignmentStatement", 
      "resetStatement", "aliasDeclarationStatement", "classicalDeclarationStatement", 
      "constDeclarationStatement", "ioDeclarationStatement", "oldStyleDeclarationStatement", 
      "quantumDeclarationStatement", "defStatement", "externStatement", 
      "gateStatement", "assignmentStatement", "expressionStatement", "calStatement", 
      "defcalStatement", "expression", "aliasExpression", "declarationExpression", 
      "measureExpression", "rangeExpression", "setExpression", "arrayLiteral", 
      "indexOperator", "indexedIdentifier", "returnSignature", "gateModifier", 
      "scalarType", "qubitType", "arrayType", "arrayReferenceType", "designator", 
      "defcalTarget", "defcalArgumentDefinition", "defcalOperand", "gateOperand", 
      "externArgument", "argumentDefinition", "argumentDefinitionList", 
      "defcalArgumentDefinitionList", "defcalOperandList", "expressionList", 
      "identifierList", "gateOperandList", "externArgumentList"
    },
    std::vector<std::string>{
      "", "'OPENQASM'", "'include'", "'defcalgrammar'", "'def'", "'cal'", 
      "'defcal'", "'gate'", "'extern'", "'box'", "'let'", "'break'", "'continue'", 
      "'if'", "'else'", "'end'", "'return'", "'for'", "'while'", "'in'", 
      "'switch'", "'case'", "'default'", "'nop'", "", "", "'input'", "'output'", 
      "'const'", "'readonly'", "'mutable'", "'qreg'", "'qubit'", "'creg'", 
      "'bool'", "'bit'", "'int'", "'uint'", "'float'", "'angle'", "'complex'", 
      "'array'", "'void'", "'duration'", "'stretch'", "'gphase'", "'inv'", 
      "'pow'", "'ctrl'", "'negctrl'", "'#dim'", "'durationof'", "'delay'", 
      "'reset'", "'measure'", "'barrier'", "", "'['", "']'", "'{'", "'}'", 
      "'('", "')'", "':'", "';'", "'.'", "','", "'='", "'->'", "'+'", "'++'", 
      "'-'", "'*'", "'**'", "'/'", "'%'", "'|'", "'||'", "'&'", "'&&'", 
      "'^'", "'@'", "'~'", "'!'", "", "", "", "", "'im'"
    },
    std::vector<std::string>{
      "", "OPENQASM", "INCLUDE", "DEFCALGRAMMAR", "DEF", "CAL", "DEFCAL", 
      "GATE", "EXTERN", "BOX", "LET", "BREAK", "CONTINUE", "IF", "ELSE", 
      "END", "RETURN", "FOR", "WHILE", "IN", "SWITCH", "CASE", "DEFAULT", 
      "NOP", "PRAGMA", "AnnotationKeyword", "INPUT", "OUTPUT", "CONST", 
      "READONLY", "MUTABLE", "QREG", "QUBIT", "CREG", "BOOL", "BIT", "INT", 
      "UINT", "FLOAT", "ANGLE", "COMPLEX", "ARRAY", "VOID", "DURATION", 
      "STRETCH", "GPHASE", "INV", "POW", "CTRL", "NEGCTRL", "DIM", "DURATIONOF", 
      "DELAY", "RESET", "MEASURE", "BARRIER", "BooleanLiteral", "LBRACKET", 
      "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COLON", "SEMICOLON", 
      "DOT", "COMMA", "EQUALS", "ARROW", "PLUS", "DOUBLE_PLUS", "MINUS", 
      "ASTERISK", "DOUBLE_ASTERISK", "SLASH", "PERCENT", "PIPE", "DOUBLE_PIPE", 
      "AMPERSAND", "DOUBLE_AMPERSAND", "CARET", "AT", "TILDE", "EXCLAMATION_POINT", 
      "EqualityOperator", "CompoundAssignmentOperator", "ComparisonOperator", 
      "BitshiftOperator", "IMAG", "ImaginaryLiteral", "BinaryIntegerLiteral", 
      "OctalIntegerLiteral", "DecimalIntegerLiteral", "HexIntegerLiteral", 
      "Identifier", "HardwareQubit", "FloatLiteral", "TimingLiteral", "BitstringLiteral", 
      "Whitespace", "Newline", "LineComment", "BlockComment", "VERSION_IDENTIFER_WHITESPACE", 
      "VersionSpecifier", "ARBITRARY_STRING_WHITESPACE", "StringLiteral", 
      "EAT_INITIAL_SPACE", "EAT_LINE_END", "RemainingLineContent", "CAL_PRELUDE_WHITESPACE", 
      "CAL_PRELUDE_COMMENT", "DEFCAL_PRELUDE_WHITESPACE", "DEFCAL_PRELUDE_COMMENT", 
      "CalibrationBlock"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,114,835,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,1,0,3,0,136,8,0,1,0,5,0,139,8,0,10,0,
  	12,0,142,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,5,2,152,8,2,10,2,12,2,155,
  	9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,187,8,2,3,2,
  	189,8,2,1,3,1,3,3,3,193,8,3,1,4,1,4,5,4,197,8,4,10,4,12,4,200,9,4,1,4,
  	1,4,1,5,1,5,1,5,1,6,1,6,3,6,209,8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,
  	9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,3,12,238,8,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,3,13,249,8,13,1,14,1,14,1,14,3,14,254,8,14,1,14,1,14,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,5,16,270,8,16,10,
  	16,12,16,273,9,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,3,17,283,8,
  	17,1,18,1,18,3,18,287,8,18,1,18,1,18,1,19,1,19,3,19,293,8,19,1,19,1,19,
  	1,20,1,20,1,20,3,20,300,8,20,1,20,1,20,1,21,1,21,3,21,306,8,21,1,21,1,
  	21,1,22,5,22,311,8,22,10,22,12,22,314,9,22,1,22,1,22,1,22,3,22,319,8,
  	22,1,22,3,22,322,8,22,1,22,3,22,325,8,22,1,22,1,22,1,22,1,22,5,22,331,
  	8,22,10,22,12,22,334,9,22,1,22,1,22,1,22,3,22,339,8,22,1,22,3,22,342,
  	8,22,1,22,3,22,345,8,22,1,22,3,22,348,8,22,1,22,3,22,351,8,22,1,23,1,
  	23,1,23,3,23,356,8,23,1,23,1,23,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,26,1,26,3,26,372,8,26,1,26,1,26,1,26,3,26,377,8,26,1,26,
  	1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,3,28,391,8,28,
  	1,28,1,28,1,28,1,29,1,29,1,29,3,29,399,8,29,1,29,1,29,1,30,1,30,1,30,
  	1,30,1,31,1,31,1,31,1,31,3,31,411,8,31,1,31,1,31,3,31,415,8,31,1,31,1,
  	31,1,32,1,32,1,32,1,32,3,32,423,8,32,1,32,1,32,3,32,427,8,32,1,32,1,32,
  	1,33,1,33,1,33,1,33,3,33,435,8,33,1,33,3,33,438,8,33,1,33,1,33,1,33,1,
  	34,1,34,1,34,1,34,3,34,447,8,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,
  	36,3,36,457,8,36,1,36,1,36,1,37,1,37,1,37,1,37,3,37,465,8,37,1,37,3,37,
  	468,8,37,1,37,1,37,3,37,472,8,37,1,37,1,37,3,37,476,8,37,1,37,1,37,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,3,38,489,8,38,1,38,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,3,38,503,8,38,1,38,1,
  	38,3,38,507,8,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,5,38,544,8,38,10,
  	38,12,38,547,9,38,1,39,1,39,1,39,5,39,552,8,39,10,39,12,39,555,9,39,1,
  	40,1,40,1,40,3,40,560,8,40,1,41,1,41,1,41,1,42,3,42,566,8,42,1,42,1,42,
  	3,42,570,8,42,1,42,1,42,3,42,574,8,42,1,43,1,43,1,43,1,43,5,43,580,8,
  	43,10,43,12,43,583,9,43,1,43,3,43,586,8,43,1,43,1,43,1,44,1,44,1,44,3,
  	44,593,8,44,1,44,1,44,1,44,3,44,598,8,44,5,44,600,8,44,10,44,12,44,603,
  	9,44,1,44,3,44,606,8,44,3,44,608,8,44,1,44,1,44,1,45,1,45,1,45,1,45,3,
  	45,616,8,45,1,45,1,45,1,45,3,45,621,8,45,5,45,623,8,45,10,45,12,45,626,
  	9,45,1,45,3,45,629,8,45,3,45,631,8,45,1,45,1,45,1,46,1,46,5,46,637,8,
  	46,10,46,12,46,640,9,46,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,1,48,
  	1,48,1,48,1,48,1,48,1,48,3,48,656,8,48,3,48,658,8,48,1,48,1,48,1,49,1,
  	49,3,49,664,8,49,1,49,1,49,3,49,668,8,49,1,49,1,49,3,49,672,8,49,1,49,
  	1,49,3,49,676,8,49,1,49,1,49,3,49,680,8,49,1,49,1,49,1,49,1,49,1,49,1,
  	49,1,49,1,49,3,49,690,8,49,3,49,692,8,49,1,50,1,50,3,50,696,8,50,1,51,
  	1,51,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,
  	1,52,3,52,714,8,52,1,52,1,52,1,53,1,53,1,53,1,53,1,54,1,54,1,55,1,55,
  	3,55,726,8,55,1,56,1,56,1,57,1,57,3,57,732,8,57,1,58,1,58,1,58,1,58,3,
  	58,738,8,58,3,58,740,8,58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,
  	3,59,751,8,59,1,59,1,59,1,59,3,59,756,8,59,1,60,1,60,1,60,5,60,761,8,
  	60,10,60,12,60,764,9,60,1,60,3,60,767,8,60,1,61,1,61,1,61,5,61,772,8,
  	61,10,61,12,61,775,9,61,1,61,3,61,778,8,61,1,62,1,62,1,62,5,62,783,8,
  	62,10,62,12,62,786,9,62,1,62,3,62,789,8,62,1,63,1,63,1,63,5,63,794,8,
  	63,10,63,12,63,797,9,63,1,63,3,63,800,8,63,1,64,1,64,1,64,5,64,805,8,
  	64,10,64,12,64,808,9,64,1,64,3,64,811,8,64,1,65,1,65,1,65,5,65,816,8,
  	65,10,65,12,65,819,9,65,1,65,3,65,822,8,65,1,66,1,66,1,66,5,66,827,8,
  	66,10,66,12,66,830,9,66,1,66,3,66,833,8,66,1,66,0,1,76,67,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,
  	58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,
  	104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,0,11,1,0,
  	26,27,2,0,31,31,33,33,2,0,67,67,85,85,2,0,71,71,82,83,2,0,56,56,89,98,
  	2,0,72,72,74,75,2,0,69,69,71,71,1,0,48,49,1,0,29,30,2,0,52,54,94,94,1,
  	0,94,95,921,0,135,1,0,0,0,2,145,1,0,0,0,4,188,1,0,0,0,6,190,1,0,0,0,8,
  	194,1,0,0,0,10,203,1,0,0,0,12,208,1,0,0,0,14,210,1,0,0,0,16,214,1,0,0,
  	0,18,218,1,0,0,0,20,221,1,0,0,0,22,224,1,0,0,0,24,227,1,0,0,0,26,241,
  	1,0,0,0,28,250,1,0,0,0,30,257,1,0,0,0,32,263,1,0,0,0,34,282,1,0,0,0,36,
  	284,1,0,0,0,38,290,1,0,0,0,40,296,1,0,0,0,42,303,1,0,0,0,44,350,1,0,0,
  	0,46,352,1,0,0,0,48,359,1,0,0,0,50,363,1,0,0,0,52,371,1,0,0,0,54,380,
  	1,0,0,0,56,387,1,0,0,0,58,395,1,0,0,0,60,402,1,0,0,0,62,406,1,0,0,0,64,
  	418,1,0,0,0,66,430,1,0,0,0,68,442,1,0,0,0,70,450,1,0,0,0,72,453,1,0,0,
  	0,74,460,1,0,0,0,76,506,1,0,0,0,78,548,1,0,0,0,80,559,1,0,0,0,82,561,
  	1,0,0,0,84,565,1,0,0,0,86,575,1,0,0,0,88,589,1,0,0,0,90,611,1,0,0,0,92,
  	634,1,0,0,0,94,641,1,0,0,0,96,657,1,0,0,0,98,691,1,0,0,0,100,693,1,0,
  	0,0,102,697,1,0,0,0,104,704,1,0,0,0,106,717,1,0,0,0,108,721,1,0,0,0,110,
  	725,1,0,0,0,112,727,1,0,0,0,114,731,1,0,0,0,116,739,1,0,0,0,118,755,1,
  	0,0,0,120,757,1,0,0,0,122,768,1,0,0,0,124,779,1,0,0,0,126,790,1,0,0,0,
  	128,801,1,0,0,0,130,812,1,0,0,0,132,823,1,0,0,0,134,136,3,2,1,0,135,134,
  	1,0,0,0,135,136,1,0,0,0,136,140,1,0,0,0,137,139,3,12,6,0,138,137,1,0,
  	0,0,139,142,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,0,141,143,1,0,0,0,142,
  	140,1,0,0,0,143,144,5,0,0,1,144,1,1,0,0,0,145,146,5,1,0,0,146,147,5,104,
  	0,0,147,148,5,64,0,0,148,3,1,0,0,0,149,189,3,10,5,0,150,152,3,6,3,0,151,
  	150,1,0,0,0,152,155,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,186,1,
  	0,0,0,155,153,1,0,0,0,156,187,3,50,25,0,157,187,3,68,34,0,158,187,3,36,
  	18,0,159,187,3,38,19,0,160,187,3,18,9,0,161,187,3,72,36,0,162,187,3,14,
  	7,0,163,187,3,52,26,0,164,187,3,54,27,0,165,187,3,20,10,0,166,187,3,62,
  	31,0,167,187,3,74,37,0,168,187,3,40,20,0,169,187,3,22,11,0,170,187,3,
  	70,35,0,171,187,3,64,32,0,172,187,3,24,12,0,173,187,3,44,22,0,174,187,
  	3,66,33,0,175,187,3,26,13,0,176,187,3,16,8,0,177,187,3,56,28,0,178,187,
  	3,46,23,0,179,187,3,42,21,0,180,187,3,58,29,0,181,187,3,60,30,0,182,187,
  	3,48,24,0,183,187,3,28,14,0,184,187,3,32,16,0,185,187,3,30,15,0,186,156,
  	1,0,0,0,186,157,1,0,0,0,186,158,1,0,0,0,186,159,1,0,0,0,186,160,1,0,0,
  	0,186,161,1,0,0,0,186,162,1,0,0,0,186,163,1,0,0,0,186,164,1,0,0,0,186,
  	165,1,0,0,0,186,166,1,0,0,0,186,167,1,0,0,0,186,168,1,0,0,0,186,169,1,
  	0,0,0,186,170,1,0,0,0,186,171,1,0,0,0,186,172,1,0,0,0,186,173,1,0,0,0,
  	186,174,1,0,0,0,186,175,1,0,0,0,186,176,1,0,0,0,186,177,1,0,0,0,186,178,
  	1,0,0,0,186,179,1,0,0,0,186,180,1,0,0,0,186,181,1,0,0,0,186,182,1,0,0,
  	0,186,183,1,0,0,0,186,184,1,0,0,0,186,185,1,0,0,0,187,189,1,0,0,0,188,
  	149,1,0,0,0,188,153,1,0,0,0,189,5,1,0,0,0,190,192,5,25,0,0,191,193,5,
  	109,0,0,192,191,1,0,0,0,192,193,1,0,0,0,193,7,1,0,0,0,194,198,5,59,0,
  	0,195,197,3,12,6,0,196,195,1,0,0,0,197,200,1,0,0,0,198,196,1,0,0,0,198,
  	199,1,0,0,0,199,201,1,0,0,0,200,198,1,0,0,0,201,202,5,60,0,0,202,9,1,
  	0,0,0,203,204,5,24,0,0,204,205,5,109,0,0,205,11,1,0,0,0,206,209,3,4,2,
  	0,207,209,3,8,4,0,208,206,1,0,0,0,208,207,1,0,0,0,209,13,1,0,0,0,210,
  	211,5,3,0,0,211,212,5,106,0,0,212,213,5,64,0,0,213,15,1,0,0,0,214,215,
  	5,2,0,0,215,216,5,106,0,0,216,217,5,64,0,0,217,17,1,0,0,0,218,219,5,11,
  	0,0,219,220,5,64,0,0,220,19,1,0,0,0,221,222,5,12,0,0,222,223,5,64,0,0,
  	223,21,1,0,0,0,224,225,5,15,0,0,225,226,5,64,0,0,226,23,1,0,0,0,227,228,
  	5,17,0,0,228,229,3,98,49,0,229,230,5,94,0,0,230,237,5,19,0,0,231,238,
  	3,86,43,0,232,233,5,57,0,0,233,234,3,84,42,0,234,235,5,58,0,0,235,238,
  	1,0,0,0,236,238,3,76,38,0,237,231,1,0,0,0,237,232,1,0,0,0,237,236,1,0,
  	0,0,238,239,1,0,0,0,239,240,3,12,6,0,240,25,1,0,0,0,241,242,5,13,0,0,
  	242,243,5,61,0,0,243,244,3,76,38,0,244,245,5,62,0,0,245,248,3,12,6,0,
  	246,247,5,14,0,0,247,249,3,12,6,0,248,246,1,0,0,0,248,249,1,0,0,0,249,
  	27,1,0,0,0,250,253,5,16,0,0,251,254,3,76,38,0,252,254,3,82,41,0,253,251,
  	1,0,0,0,253,252,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,0,255,256,5,64,
  	0,0,256,29,1,0,0,0,257,258,5,18,0,0,258,259,5,61,0,0,259,260,3,76,38,
  	0,260,261,5,62,0,0,261,262,3,12,6,0,262,31,1,0,0,0,263,264,5,20,0,0,264,
  	265,5,61,0,0,265,266,3,76,38,0,266,267,5,62,0,0,267,271,5,59,0,0,268,
  	270,3,34,17,0,269,268,1,0,0,0,270,273,1,0,0,0,271,269,1,0,0,0,271,272,
  	1,0,0,0,272,274,1,0,0,0,273,271,1,0,0,0,274,275,5,60,0,0,275,33,1,0,0,
  	0,276,277,5,21,0,0,277,278,3,126,63,0,278,279,3,8,4,0,279,283,1,0,0,0,
  	280,281,5,22,0,0,281,283,3,8,4,0,282,276,1,0,0,0,282,280,1,0,0,0,283,
  	35,1,0,0,0,284,286,5,55,0,0,285,287,3,130,65,0,286,285,1,0,0,0,286,287,
  	1,0,0,0,287,288,1,0,0,0,288,289,5,64,0,0,289,37,1,0,0,0,290,292,5,9,0,
  	0,291,293,3,106,53,0,292,291,1,0,0,0,292,293,1,0,0,0,293,294,1,0,0,0,
  	294,295,3,8,4,0,295,39,1,0,0,0,296,297,5,52,0,0,297,299,3,106,53,0,298,
  	300,3,130,65,0,299,298,1,0,0,0,299,300,1,0,0,0,300,301,1,0,0,0,301,302,
  	5,64,0,0,302,41,1,0,0,0,303,305,5,23,0,0,304,306,3,130,65,0,305,304,1,
  	0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,308,5,64,0,0,308,43,1,0,0,0,
  	309,311,3,96,48,0,310,309,1,0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,
  	313,1,0,0,0,313,315,1,0,0,0,314,312,1,0,0,0,315,321,5,94,0,0,316,318,
  	5,61,0,0,317,319,3,126,63,0,318,317,1,0,0,0,318,319,1,0,0,0,319,320,1,
  	0,0,0,320,322,5,62,0,0,321,316,1,0,0,0,321,322,1,0,0,0,322,324,1,0,0,
  	0,323,325,3,106,53,0,324,323,1,0,0,0,324,325,1,0,0,0,325,326,1,0,0,0,
  	326,327,3,130,65,0,327,328,5,64,0,0,328,351,1,0,0,0,329,331,3,96,48,0,
  	330,329,1,0,0,0,331,334,1,0,0,0,332,330,1,0,0,0,332,333,1,0,0,0,333,335,
  	1,0,0,0,334,332,1,0,0,0,335,341,5,45,0,0,336,338,5,61,0,0,337,339,3,126,
  	63,0,338,337,1,0,0,0,338,339,1,0,0,0,339,340,1,0,0,0,340,342,5,62,0,0,
  	341,336,1,0,0,0,341,342,1,0,0,0,342,344,1,0,0,0,343,345,3,106,53,0,344,
  	343,1,0,0,0,344,345,1,0,0,0,345,347,1,0,0,0,346,348,3,130,65,0,347,346,
  	1,0,0,0,347,348,1,0,0,0,348,349,1,0,0,0,349,351,5,64,0,0,350,312,1,0,
  	0,0,350,332,1,0,0,0,351,45,1,0,0,0,352,355,3,82,41,0,353,354,5,68,0,0,
  	354,356,3,92,46,0,355,353,1,0,0,0,355,356,1,0,0,0,356,357,1,0,0,0,357,
  	358,5,64,0,0,358,47,1,0,0,0,359,360,5,53,0,0,360,361,3,114,57,0,361,362,
  	5,64,0,0,362,49,1,0,0,0,363,364,5,10,0,0,364,365,5,94,0,0,365,366,5,67,
  	0,0,366,367,3,78,39,0,367,368,5,64,0,0,368,51,1,0,0,0,369,372,3,98,49,
  	0,370,372,3,102,51,0,371,369,1,0,0,0,371,370,1,0,0,0,372,373,1,0,0,0,
  	373,376,5,94,0,0,374,375,5,67,0,0,375,377,3,80,40,0,376,374,1,0,0,0,376,
  	377,1,0,0,0,377,378,1,0,0,0,378,379,5,64,0,0,379,53,1,0,0,0,380,381,5,
  	28,0,0,381,382,3,98,49,0,382,383,5,94,0,0,383,384,5,67,0,0,384,385,3,
  	80,40,0,385,386,5,64,0,0,386,55,1,0,0,0,387,390,7,0,0,0,388,391,3,98,
  	49,0,389,391,3,102,51,0,390,388,1,0,0,0,390,389,1,0,0,0,391,392,1,0,0,
  	0,392,393,5,94,0,0,393,394,5,64,0,0,394,57,1,0,0,0,395,396,7,1,0,0,396,
  	398,5,94,0,0,397,399,3,106,53,0,398,397,1,0,0,0,398,399,1,0,0,0,399,400,
  	1,0,0,0,400,401,5,64,0,0,401,59,1,0,0,0,402,403,3,100,50,0,403,404,5,
  	94,0,0,404,405,5,64,0,0,405,61,1,0,0,0,406,407,5,4,0,0,407,408,5,94,0,
  	0,408,410,5,61,0,0,409,411,3,120,60,0,410,409,1,0,0,0,410,411,1,0,0,0,
  	411,412,1,0,0,0,412,414,5,62,0,0,413,415,3,94,47,0,414,413,1,0,0,0,414,
  	415,1,0,0,0,415,416,1,0,0,0,416,417,3,8,4,0,417,63,1,0,0,0,418,419,5,
  	8,0,0,419,420,5,94,0,0,420,422,5,61,0,0,421,423,3,132,66,0,422,421,1,
  	0,0,0,422,423,1,0,0,0,423,424,1,0,0,0,424,426,5,62,0,0,425,427,3,94,47,
  	0,426,425,1,0,0,0,426,427,1,0,0,0,427,428,1,0,0,0,428,429,5,64,0,0,429,
  	65,1,0,0,0,430,431,5,7,0,0,431,437,5,94,0,0,432,434,5,61,0,0,433,435,
  	3,128,64,0,434,433,1,0,0,0,434,435,1,0,0,0,435,436,1,0,0,0,436,438,5,
  	62,0,0,437,432,1,0,0,0,437,438,1,0,0,0,438,439,1,0,0,0,439,440,3,128,
  	64,0,440,441,3,8,4,0,441,67,1,0,0,0,442,443,3,92,46,0,443,446,7,2,0,0,
  	444,447,3,76,38,0,445,447,3,82,41,0,446,444,1,0,0,0,446,445,1,0,0,0,447,
  	448,1,0,0,0,448,449,5,64,0,0,449,69,1,0,0,0,450,451,3,76,38,0,451,452,
  	5,64,0,0,452,71,1,0,0,0,453,454,5,5,0,0,454,456,5,59,0,0,455,457,5,114,
  	0,0,456,455,1,0,0,0,456,457,1,0,0,0,457,458,1,0,0,0,458,459,5,60,0,0,
  	459,73,1,0,0,0,460,461,5,6,0,0,461,467,3,108,54,0,462,464,5,61,0,0,463,
  	465,3,122,61,0,464,463,1,0,0,0,464,465,1,0,0,0,465,466,1,0,0,0,466,468,
  	5,62,0,0,467,462,1,0,0,0,467,468,1,0,0,0,468,469,1,0,0,0,469,471,3,124,
  	62,0,470,472,3,94,47,0,471,470,1,0,0,0,471,472,1,0,0,0,472,473,1,0,0,
  	0,473,475,5,59,0,0,474,476,5,114,0,0,475,474,1,0,0,0,475,476,1,0,0,0,
  	476,477,1,0,0,0,477,478,5,60,0,0,478,75,1,0,0,0,479,480,6,38,-1,0,480,
  	481,5,61,0,0,481,482,3,76,38,0,482,483,5,62,0,0,483,507,1,0,0,0,484,485,
  	7,3,0,0,485,507,3,76,38,15,486,489,3,98,49,0,487,489,3,102,51,0,488,486,
  	1,0,0,0,488,487,1,0,0,0,489,490,1,0,0,0,490,491,5,61,0,0,491,492,3,76,
  	38,0,492,493,5,62,0,0,493,507,1,0,0,0,494,495,5,51,0,0,495,496,5,61,0,
  	0,496,497,3,8,4,0,497,498,5,62,0,0,498,507,1,0,0,0,499,500,5,94,0,0,500,
  	502,5,61,0,0,501,503,3,126,63,0,502,501,1,0,0,0,502,503,1,0,0,0,503,504,
  	1,0,0,0,504,507,5,62,0,0,505,507,7,4,0,0,506,479,1,0,0,0,506,484,1,0,
  	0,0,506,488,1,0,0,0,506,494,1,0,0,0,506,499,1,0,0,0,506,505,1,0,0,0,507,
  	545,1,0,0,0,508,509,10,16,0,0,509,510,5,73,0,0,510,544,3,76,38,16,511,
  	512,10,14,0,0,512,513,7,5,0,0,513,544,3,76,38,15,514,515,10,13,0,0,515,
  	516,7,6,0,0,516,544,3,76,38,14,517,518,10,12,0,0,518,519,5,87,0,0,519,
  	544,3,76,38,13,520,521,10,11,0,0,521,522,5,86,0,0,522,544,3,76,38,12,
  	523,524,10,10,0,0,524,525,5,84,0,0,525,544,3,76,38,11,526,527,10,9,0,
  	0,527,528,5,78,0,0,528,544,3,76,38,10,529,530,10,8,0,0,530,531,5,80,0,
  	0,531,544,3,76,38,9,532,533,10,7,0,0,533,534,5,76,0,0,534,544,3,76,38,
  	8,535,536,10,6,0,0,536,537,5,79,0,0,537,544,3,76,38,7,538,539,10,5,0,
  	0,539,540,5,77,0,0,540,544,3,76,38,6,541,542,10,17,0,0,542,544,3,90,45,
  	0,543,508,1,0,0,0,543,511,1,0,0,0,543,514,1,0,0,0,543,517,1,0,0,0,543,
  	520,1,0,0,0,543,523,1,0,0,0,543,526,1,0,0,0,543,529,1,0,0,0,543,532,1,
  	0,0,0,543,535,1,0,0,0,543,538,1,0,0,0,543,541,1,0,0,0,544,547,1,0,0,0,
  	545,543,1,0,0,0,545,546,1,0,0,0,546,77,1,0,0,0,547,545,1,0,0,0,548,553,
  	3,76,38,0,549,550,5,70,0,0,550,552,3,76,38,0,551,549,1,0,0,0,552,555,
  	1,0,0,0,553,551,1,0,0,0,553,554,1,0,0,0,554,79,1,0,0,0,555,553,1,0,0,
  	0,556,560,3,88,44,0,557,560,3,76,38,0,558,560,3,82,41,0,559,556,1,0,0,
  	0,559,557,1,0,0,0,559,558,1,0,0,0,560,81,1,0,0,0,561,562,5,54,0,0,562,
  	563,3,114,57,0,563,83,1,0,0,0,564,566,3,76,38,0,565,564,1,0,0,0,565,566,
  	1,0,0,0,566,567,1,0,0,0,567,569,5,63,0,0,568,570,3,76,38,0,569,568,1,
  	0,0,0,569,570,1,0,0,0,570,573,1,0,0,0,571,572,5,63,0,0,572,574,3,76,38,
  	0,573,571,1,0,0,0,573,574,1,0,0,0,574,85,1,0,0,0,575,576,5,59,0,0,576,
  	581,3,76,38,0,577,578,5,66,0,0,578,580,3,76,38,0,579,577,1,0,0,0,580,
  	583,1,0,0,0,581,579,1,0,0,0,581,582,1,0,0,0,582,585,1,0,0,0,583,581,1,
  	0,0,0,584,586,5,66,0,0,585,584,1,0,0,0,585,586,1,0,0,0,586,587,1,0,0,
  	0,587,588,5,60,0,0,588,87,1,0,0,0,589,607,5,59,0,0,590,593,3,76,38,0,
  	591,593,3,88,44,0,592,590,1,0,0,0,592,591,1,0,0,0,593,601,1,0,0,0,594,
  	597,5,66,0,0,595,598,3,76,38,0,596,598,3,88,44,0,597,595,1,0,0,0,597,
  	596,1,0,0,0,598,600,1,0,0,0,599,594,1,0,0,0,600,603,1,0,0,0,601,599,1,
  	0,0,0,601,602,1,0,0,0,602,605,1,0,0,0,603,601,1,0,0,0,604,606,5,66,0,
  	0,605,604,1,0,0,0,605,606,1,0,0,0,606,608,1,0,0,0,607,592,1,0,0,0,607,
  	608,1,0,0,0,608,609,1,0,0,0,609,610,5,60,0,0,610,89,1,0,0,0,611,630,5,
  	57,0,0,612,631,3,86,43,0,613,616,3,76,38,0,614,616,3,84,42,0,615,613,
  	1,0,0,0,615,614,1,0,0,0,616,624,1,0,0,0,617,620,5,66,0,0,618,621,3,76,
  	38,0,619,621,3,84,42,0,620,618,1,0,0,0,620,619,1,0,0,0,621,623,1,0,0,
  	0,622,617,1,0,0,0,623,626,1,0,0,0,624,622,1,0,0,0,624,625,1,0,0,0,625,
  	628,1,0,0,0,626,624,1,0,0,0,627,629,5,66,0,0,628,627,1,0,0,0,628,629,
  	1,0,0,0,629,631,1,0,0,0,630,612,1,0,0,0,630,615,1,0,0,0,631,632,1,0,0,
  	0,632,633,5,58,0,0,633,91,1,0,0,0,634,638,5,94,0,0,635,637,3,90,45,0,
  	636,635,1,0,0,0,637,640,1,0,0,0,638,636,1,0,0,0,638,639,1,0,0,0,639,93,
  	1,0,0,0,640,638,1,0,0,0,641,642,5,68,0,0,642,643,3,98,49,0,643,95,1,0,
  	0,0,644,658,5,46,0,0,645,646,5,47,0,0,646,647,5,61,0,0,647,648,3,76,38,
  	0,648,649,5,62,0,0,649,658,1,0,0,0,650,655,7,7,0,0,651,652,5,61,0,0,652,
  	653,3,76,38,0,653,654,5,62,0,0,654,656,1,0,0,0,655,651,1,0,0,0,655,656,
  	1,0,0,0,656,658,1,0,0,0,657,644,1,0,0,0,657,645,1,0,0,0,657,650,1,0,0,
  	0,658,659,1,0,0,0,659,660,5,81,0,0,660,97,1,0,0,0,661,663,5,35,0,0,662,
  	664,3,106,53,0,663,662,1,0,0,0,663,664,1,0,0,0,664,692,1,0,0,0,665,667,
  	5,36,0,0,666,668,3,106,53,0,667,666,1,0,0,0,667,668,1,0,0,0,668,692,1,
  	0,0,0,669,671,5,37,0,0,670,672,3,106,53,0,671,670,1,0,0,0,671,672,1,0,
  	0,0,672,692,1,0,0,0,673,675,5,38,0,0,674,676,3,106,53,0,675,674,1,0,0,
  	0,675,676,1,0,0,0,676,692,1,0,0,0,677,679,5,39,0,0,678,680,3,106,53,0,
  	679,678,1,0,0,0,679,680,1,0,0,0,680,692,1,0,0,0,681,692,5,34,0,0,682,
  	692,5,43,0,0,683,692,5,44,0,0,684,689,5,40,0,0,685,686,5,57,0,0,686,687,
  	3,98,49,0,687,688,5,58,0,0,688,690,1,0,0,0,689,685,1,0,0,0,689,690,1,
  	0,0,0,690,692,1,0,0,0,691,661,1,0,0,0,691,665,1,0,0,0,691,669,1,0,0,0,
  	691,673,1,0,0,0,691,677,1,0,0,0,691,681,1,0,0,0,691,682,1,0,0,0,691,683,
  	1,0,0,0,691,684,1,0,0,0,692,99,1,0,0,0,693,695,5,32,0,0,694,696,3,106,
  	53,0,695,694,1,0,0,0,695,696,1,0,0,0,696,101,1,0,0,0,697,698,5,41,0,0,
  	698,699,5,57,0,0,699,700,3,98,49,0,700,701,5,66,0,0,701,702,3,126,63,
  	0,702,703,5,58,0,0,703,103,1,0,0,0,704,705,7,8,0,0,705,706,5,41,0,0,706,
  	707,5,57,0,0,707,708,3,98,49,0,708,713,5,66,0,0,709,714,3,126,63,0,710,
  	711,5,50,0,0,711,712,5,67,0,0,712,714,3,76,38,0,713,709,1,0,0,0,713,710,
  	1,0,0,0,714,715,1,0,0,0,715,716,5,58,0,0,716,105,1,0,0,0,717,718,5,57,
  	0,0,718,719,3,76,38,0,719,720,5,58,0,0,720,107,1,0,0,0,721,722,7,9,0,
  	0,722,109,1,0,0,0,723,726,3,76,38,0,724,726,3,118,59,0,725,723,1,0,0,
  	0,725,724,1,0,0,0,726,111,1,0,0,0,727,728,7,10,0,0,728,113,1,0,0,0,729,
  	732,3,92,46,0,730,732,5,95,0,0,731,729,1,0,0,0,731,730,1,0,0,0,732,115,
  	1,0,0,0,733,740,3,98,49,0,734,740,3,104,52,0,735,737,5,33,0,0,736,738,
  	3,106,53,0,737,736,1,0,0,0,737,738,1,0,0,0,738,740,1,0,0,0,739,733,1,
  	0,0,0,739,734,1,0,0,0,739,735,1,0,0,0,740,117,1,0,0,0,741,742,3,98,49,
  	0,742,743,5,94,0,0,743,756,1,0,0,0,744,745,3,100,50,0,745,746,5,94,0,
  	0,746,756,1,0,0,0,747,748,7,1,0,0,748,750,5,94,0,0,749,751,3,106,53,0,
  	750,749,1,0,0,0,750,751,1,0,0,0,751,756,1,0,0,0,752,753,3,104,52,0,753,
  	754,5,94,0,0,754,756,1,0,0,0,755,741,1,0,0,0,755,744,1,0,0,0,755,747,
  	1,0,0,0,755,752,1,0,0,0,756,119,1,0,0,0,757,762,3,118,59,0,758,759,5,
  	66,0,0,759,761,3,118,59,0,760,758,1,0,0,0,761,764,1,0,0,0,762,760,1,0,
  	0,0,762,763,1,0,0,0,763,766,1,0,0,0,764,762,1,0,0,0,765,767,5,66,0,0,
  	766,765,1,0,0,0,766,767,1,0,0,0,767,121,1,0,0,0,768,773,3,110,55,0,769,
  	770,5,66,0,0,770,772,3,110,55,0,771,769,1,0,0,0,772,775,1,0,0,0,773,771,
  	1,0,0,0,773,774,1,0,0,0,774,777,1,0,0,0,775,773,1,0,0,0,776,778,5,66,
  	0,0,777,776,1,0,0,0,777,778,1,0,0,0,778,123,1,0,0,0,779,784,3,112,56,
  	0,780,781,5,66,0,0,781,783,3,112,56,0,782,780,1,0,0,0,783,786,1,0,0,0,
  	784,782,1,0,0,0,784,785,1,0,0,0,785,788,1,0,0,0,786,784,1,0,0,0,787,789,
  	5,66,0,0,788,787,1,0,0,0,788,789,1,0,0,0,789,125,1,0,0,0,790,795,3,76,
  	38,0,791,792,5,66,0,0,792,794,3,76,38,0,793,791,1,0,0,0,794,797,1,0,0,
  	0,795,793,1,0,0,0,795,796,1,0,0,0,796,799,1,0,0,0,797,795,1,0,0,0,798,
  	800,5,66,0,0,799,798,1,0,0,0,799,800,1,0,0,0,800,127,1,0,0,0,801,806,
  	5,94,0,0,802,803,5,66,0,0,803,805,5,94,0,0,804,802,1,0,0,0,805,808,1,
  	0,0,0,806,804,1,0,0,0,806,807,1,0,0,0,807,810,1,0,0,0,808,806,1,0,0,0,
  	809,811,5,66,0,0,810,809,1,0,0,0,810,811,1,0,0,0,811,129,1,0,0,0,812,
  	817,3,114,57,0,813,814,5,66,0,0,814,816,3,114,57,0,815,813,1,0,0,0,816,
  	819,1,0,0,0,817,815,1,0,0,0,817,818,1,0,0,0,818,821,1,0,0,0,819,817,1,
  	0,0,0,820,822,5,66,0,0,821,820,1,0,0,0,821,822,1,0,0,0,822,131,1,0,0,
  	0,823,828,3,116,58,0,824,825,5,66,0,0,825,827,3,116,58,0,826,824,1,0,
  	0,0,827,830,1,0,0,0,828,826,1,0,0,0,828,829,1,0,0,0,829,832,1,0,0,0,830,
  	828,1,0,0,0,831,833,5,66,0,0,832,831,1,0,0,0,832,833,1,0,0,0,833,133,
  	1,0,0,0,98,135,140,153,186,188,192,198,208,237,248,253,271,282,286,292,
  	299,305,312,318,321,324,332,338,341,344,347,350,355,371,376,390,398,410,
  	414,422,426,434,437,446,456,464,467,471,475,488,502,506,543,545,553,559,
  	565,569,573,581,585,592,597,601,605,607,615,620,624,628,630,638,655,657,
  	663,667,671,675,679,689,691,695,713,725,731,737,739,750,755,762,766,773,
  	777,784,788,795,799,806,810,817,821,828,832
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  qasm3parserParserStaticData = std::move(staticData);
}

}

qasm3Parser::qasm3Parser(TokenStream *input) : qasm3Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

qasm3Parser::qasm3Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  qasm3Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *qasm3parserParserStaticData->atn, qasm3parserParserStaticData->decisionToDFA, qasm3parserParserStaticData->sharedContextCache, options);
}

qasm3Parser::~qasm3Parser() {
  delete _interpreter;
}

const atn::ATN& qasm3Parser::getATN() const {
  return *qasm3parserParserStaticData->atn;
}

std::string qasm3Parser::getGrammarFileName() const {
  return "qasm3Parser.g4";
}

const std::vector<std::string>& qasm3Parser::getRuleNames() const {
  return qasm3parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& qasm3Parser::getVocabulary() const {
  return qasm3parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView qasm3Parser::getSerializedATN() const {
  return qasm3parserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

qasm3Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ProgramContext::EOF() {
  return getToken(qasm3Parser::EOF, 0);
}

qasm3Parser::VersionContext* qasm3Parser::ProgramContext::version() {
  return getRuleContext<qasm3Parser::VersionContext>(0);
}

std::vector<qasm3Parser::StatementOrScopeContext *> qasm3Parser::ProgramContext::statementOrScope() {
  return getRuleContexts<qasm3Parser::StatementOrScopeContext>();
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::ProgramContext::statementOrScope(size_t i) {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(i);
}


size_t qasm3Parser::ProgramContext::getRuleIndex() const {
  return qasm3Parser::RuleProgram;
}


std::any qasm3Parser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramContext* qasm3Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, qasm3Parser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::OPENQASM) {
      setState(134);
      version();
    }
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3025288650022174716) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 268179457) != 0)) {
      setState(137);
      statementOrScope();
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    match(qasm3Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

qasm3Parser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::VersionContext::OPENQASM() {
  return getToken(qasm3Parser::OPENQASM, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::VersionSpecifier() {
  return getToken(qasm3Parser::VersionSpecifier, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::VersionContext::getRuleIndex() const {
  return qasm3Parser::RuleVersion;
}


std::any qasm3Parser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::VersionContext* qasm3Parser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 2, qasm3Parser::RuleVersion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(qasm3Parser::OPENQASM);
    setState(146);
    match(qasm3Parser::VersionSpecifier);
    setState(147);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

qasm3Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::PragmaContext* qasm3Parser::StatementContext::pragma() {
  return getRuleContext<qasm3Parser::PragmaContext>(0);
}

qasm3Parser::AliasDeclarationStatementContext* qasm3Parser::StatementContext::aliasDeclarationStatement() {
  return getRuleContext<qasm3Parser::AliasDeclarationStatementContext>(0);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::StatementContext::assignmentStatement() {
  return getRuleContext<qasm3Parser::AssignmentStatementContext>(0);
}

qasm3Parser::BarrierStatementContext* qasm3Parser::StatementContext::barrierStatement() {
  return getRuleContext<qasm3Parser::BarrierStatementContext>(0);
}

qasm3Parser::BoxStatementContext* qasm3Parser::StatementContext::boxStatement() {
  return getRuleContext<qasm3Parser::BoxStatementContext>(0);
}

qasm3Parser::BreakStatementContext* qasm3Parser::StatementContext::breakStatement() {
  return getRuleContext<qasm3Parser::BreakStatementContext>(0);
}

qasm3Parser::CalStatementContext* qasm3Parser::StatementContext::calStatement() {
  return getRuleContext<qasm3Parser::CalStatementContext>(0);
}

qasm3Parser::CalibrationGrammarStatementContext* qasm3Parser::StatementContext::calibrationGrammarStatement() {
  return getRuleContext<qasm3Parser::CalibrationGrammarStatementContext>(0);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::StatementContext::classicalDeclarationStatement() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationStatementContext>(0);
}

qasm3Parser::ConstDeclarationStatementContext* qasm3Parser::StatementContext::constDeclarationStatement() {
  return getRuleContext<qasm3Parser::ConstDeclarationStatementContext>(0);
}

qasm3Parser::ContinueStatementContext* qasm3Parser::StatementContext::continueStatement() {
  return getRuleContext<qasm3Parser::ContinueStatementContext>(0);
}

qasm3Parser::DefStatementContext* qasm3Parser::StatementContext::defStatement() {
  return getRuleContext<qasm3Parser::DefStatementContext>(0);
}

qasm3Parser::DefcalStatementContext* qasm3Parser::StatementContext::defcalStatement() {
  return getRuleContext<qasm3Parser::DefcalStatementContext>(0);
}

qasm3Parser::DelayStatementContext* qasm3Parser::StatementContext::delayStatement() {
  return getRuleContext<qasm3Parser::DelayStatementContext>(0);
}

qasm3Parser::EndStatementContext* qasm3Parser::StatementContext::endStatement() {
  return getRuleContext<qasm3Parser::EndStatementContext>(0);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::StatementContext::expressionStatement() {
  return getRuleContext<qasm3Parser::ExpressionStatementContext>(0);
}

qasm3Parser::ExternStatementContext* qasm3Parser::StatementContext::externStatement() {
  return getRuleContext<qasm3Parser::ExternStatementContext>(0);
}

qasm3Parser::ForStatementContext* qasm3Parser::StatementContext::forStatement() {
  return getRuleContext<qasm3Parser::ForStatementContext>(0);
}

qasm3Parser::GateCallStatementContext* qasm3Parser::StatementContext::gateCallStatement() {
  return getRuleContext<qasm3Parser::GateCallStatementContext>(0);
}

qasm3Parser::GateStatementContext* qasm3Parser::StatementContext::gateStatement() {
  return getRuleContext<qasm3Parser::GateStatementContext>(0);
}

qasm3Parser::IfStatementContext* qasm3Parser::StatementContext::ifStatement() {
  return getRuleContext<qasm3Parser::IfStatementContext>(0);
}

qasm3Parser::IncludeStatementContext* qasm3Parser::StatementContext::includeStatement() {
  return getRuleContext<qasm3Parser::IncludeStatementContext>(0);
}

qasm3Parser::IoDeclarationStatementContext* qasm3Parser::StatementContext::ioDeclarationStatement() {
  return getRuleContext<qasm3Parser::IoDeclarationStatementContext>(0);
}

qasm3Parser::MeasureArrowAssignmentStatementContext* qasm3Parser::StatementContext::measureArrowAssignmentStatement() {
  return getRuleContext<qasm3Parser::MeasureArrowAssignmentStatementContext>(0);
}

qasm3Parser::NopStatementContext* qasm3Parser::StatementContext::nopStatement() {
  return getRuleContext<qasm3Parser::NopStatementContext>(0);
}

qasm3Parser::OldStyleDeclarationStatementContext* qasm3Parser::StatementContext::oldStyleDeclarationStatement() {
  return getRuleContext<qasm3Parser::OldStyleDeclarationStatementContext>(0);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::StatementContext::quantumDeclarationStatement() {
  return getRuleContext<qasm3Parser::QuantumDeclarationStatementContext>(0);
}

qasm3Parser::ResetStatementContext* qasm3Parser::StatementContext::resetStatement() {
  return getRuleContext<qasm3Parser::ResetStatementContext>(0);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::StatementContext::returnStatement() {
  return getRuleContext<qasm3Parser::ReturnStatementContext>(0);
}

qasm3Parser::SwitchStatementContext* qasm3Parser::StatementContext::switchStatement() {
  return getRuleContext<qasm3Parser::SwitchStatementContext>(0);
}

qasm3Parser::WhileStatementContext* qasm3Parser::StatementContext::whileStatement() {
  return getRuleContext<qasm3Parser::WhileStatementContext>(0);
}

std::vector<qasm3Parser::AnnotationContext *> qasm3Parser::StatementContext::annotation() {
  return getRuleContexts<qasm3Parser::AnnotationContext>();
}

qasm3Parser::AnnotationContext* qasm3Parser::StatementContext::annotation(size_t i) {
  return getRuleContext<qasm3Parser::AnnotationContext>(i);
}


size_t qasm3Parser::StatementContext::getRuleIndex() const {
  return qasm3Parser::RuleStatement;
}


std::any qasm3Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::StatementContext* qasm3Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, qasm3Parser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::PRAGMA: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        pragma();
        break;
      }

      case qasm3Parser::INCLUDE:
      case qasm3Parser::DEFCALGRAMMAR:
      case qasm3Parser::DEF:
      case qasm3Parser::CAL:
      case qasm3Parser::DEFCAL:
      case qasm3Parser::GATE:
      case qasm3Parser::EXTERN:
      case qasm3Parser::BOX:
      case qasm3Parser::LET:
      case qasm3Parser::BREAK:
      case qasm3Parser::CONTINUE:
      case qasm3Parser::IF:
      case qasm3Parser::END:
      case qasm3Parser::RETURN:
      case qasm3Parser::FOR:
      case qasm3Parser::WHILE:
      case qasm3Parser::SWITCH:
      case qasm3Parser::NOP:
      case qasm3Parser::AnnotationKeyword:
      case qasm3Parser::INPUT:
      case qasm3Parser::OUTPUT:
      case qasm3Parser::CONST:
      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT:
      case qasm3Parser::CREG:
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::DELAY:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == qasm3Parser::AnnotationKeyword) {
          setState(150);
          annotation();
          setState(155);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(186);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(156);
          aliasDeclarationStatement();
          break;
        }

        case 2: {
          setState(157);
          assignmentStatement();
          break;
        }

        case 3: {
          setState(158);
          barrierStatement();
          break;
        }

        case 4: {
          setState(159);
          boxStatement();
          break;
        }

        case 5: {
          setState(160);
          breakStatement();
          break;
        }

        case 6: {
          setState(161);
          calStatement();
          break;
        }

        case 7: {
          setState(162);
          calibrationGrammarStatement();
          break;
        }

        case 8: {
          setState(163);
          classicalDeclarationStatement();
          break;
        }

        case 9: {
          setState(164);
          constDeclarationStatement();
          break;
        }

        case 10: {
          setState(165);
          continueStatement();
          break;
        }

        case 11: {
          setState(166);
          defStatement();
          break;
        }

        case 12: {
          setState(167);
          defcalStatement();
          break;
        }

        case 13: {
          setState(168);
          delayStatement();
          break;
        }

        case 14: {
          setState(169);
          endStatement();
          break;
        }

        case 15: {
          setState(170);
          expressionStatement();
          break;
        }

        case 16: {
          setState(171);
          externStatement();
          break;
        }

        case 17: {
          setState(172);
          forStatement();
          break;
        }

        case 18: {
          setState(173);
          gateCallStatement();
          break;
        }

        case 19: {
          setState(174);
          gateStatement();
          break;
        }

        case 20: {
          setState(175);
          ifStatement();
          break;
        }

        case 21: {
          setState(176);
          includeStatement();
          break;
        }

        case 22: {
          setState(177);
          ioDeclarationStatement();
          break;
        }

        case 23: {
          setState(178);
          measureArrowAssignmentStatement();
          break;
        }

        case 24: {
          setState(179);
          nopStatement();
          break;
        }

        case 25: {
          setState(180);
          oldStyleDeclarationStatement();
          break;
        }

        case 26: {
          setState(181);
          quantumDeclarationStatement();
          break;
        }

        case 27: {
          setState(182);
          resetStatement();
          break;
        }

        case 28: {
          setState(183);
          returnStatement();
          break;
        }

        case 29: {
          setState(184);
          switchStatement();
          break;
        }

        case 30: {
          setState(185);
          whileStatement();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

qasm3Parser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AnnotationContext::AnnotationKeyword() {
  return getToken(qasm3Parser::AnnotationKeyword, 0);
}

tree::TerminalNode* qasm3Parser::AnnotationContext::RemainingLineContent() {
  return getToken(qasm3Parser::RemainingLineContent, 0);
}


size_t qasm3Parser::AnnotationContext::getRuleIndex() const {
  return qasm3Parser::RuleAnnotation;
}


std::any qasm3Parser::AnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAnnotation(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnnotationContext* qasm3Parser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 6, qasm3Parser::RuleAnnotation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(qasm3Parser::AnnotationKeyword);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::RemainingLineContent) {
      setState(191);
      match(qasm3Parser::RemainingLineContent);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

qasm3Parser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ScopeContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ScopeContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementOrScopeContext *> qasm3Parser::ScopeContext::statementOrScope() {
  return getRuleContexts<qasm3Parser::StatementOrScopeContext>();
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::ScopeContext::statementOrScope(size_t i) {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(i);
}


size_t qasm3Parser::ScopeContext::getRuleIndex() const {
  return qasm3Parser::RuleScope;
}


std::any qasm3Parser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ScopeContext* qasm3Parser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, qasm3Parser::RuleScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(qasm3Parser::LBRACE);
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3025288650022174716) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 268179457) != 0)) {
      setState(195);
      statementOrScope();
      setState(200);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(201);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

qasm3Parser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::PragmaContext::PRAGMA() {
  return getToken(qasm3Parser::PRAGMA, 0);
}

tree::TerminalNode* qasm3Parser::PragmaContext::RemainingLineContent() {
  return getToken(qasm3Parser::RemainingLineContent, 0);
}


size_t qasm3Parser::PragmaContext::getRuleIndex() const {
  return qasm3Parser::RulePragma;
}


std::any qasm3Parser::PragmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PragmaContext* qasm3Parser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 10, qasm3Parser::RulePragma);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(qasm3Parser::PRAGMA);
    setState(204);
    match(qasm3Parser::RemainingLineContent);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementOrScopeContext ------------------------------------------------------------------

qasm3Parser::StatementOrScopeContext::StatementOrScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::StatementContext* qasm3Parser::StatementOrScopeContext::statement() {
  return getRuleContext<qasm3Parser::StatementContext>(0);
}

qasm3Parser::ScopeContext* qasm3Parser::StatementOrScopeContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}


size_t qasm3Parser::StatementOrScopeContext::getRuleIndex() const {
  return qasm3Parser::RuleStatementOrScope;
}


std::any qasm3Parser::StatementOrScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitStatementOrScope(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::statementOrScope() {
  StatementOrScopeContext *_localctx = _tracker.createInstance<StatementOrScopeContext>(_ctx, getState());
  enterRule(_localctx, 12, qasm3Parser::RuleStatementOrScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INCLUDE:
      case qasm3Parser::DEFCALGRAMMAR:
      case qasm3Parser::DEF:
      case qasm3Parser::CAL:
      case qasm3Parser::DEFCAL:
      case qasm3Parser::GATE:
      case qasm3Parser::EXTERN:
      case qasm3Parser::BOX:
      case qasm3Parser::LET:
      case qasm3Parser::BREAK:
      case qasm3Parser::CONTINUE:
      case qasm3Parser::IF:
      case qasm3Parser::END:
      case qasm3Parser::RETURN:
      case qasm3Parser::FOR:
      case qasm3Parser::WHILE:
      case qasm3Parser::SWITCH:
      case qasm3Parser::NOP:
      case qasm3Parser::PRAGMA:
      case qasm3Parser::AnnotationKeyword:
      case qasm3Parser::INPUT:
      case qasm3Parser::OUTPUT:
      case qasm3Parser::CONST:
      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT:
      case qasm3Parser::CREG:
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::DELAY:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(206);
        statement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(207);
        scope();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarStatementContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarStatementContext::CalibrationGrammarStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::DEFCALGRAMMAR() {
  return getToken(qasm3Parser::DEFCALGRAMMAR, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::CalibrationGrammarStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammarStatement;
}


std::any qasm3Parser::CalibrationGrammarStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarStatementContext* qasm3Parser::calibrationGrammarStatement() {
  CalibrationGrammarStatementContext *_localctx = _tracker.createInstance<CalibrationGrammarStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, qasm3Parser::RuleCalibrationGrammarStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(qasm3Parser::DEFCALGRAMMAR);
    setState(211);
    match(qasm3Parser::StringLiteral);
    setState(212);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeStatementContext ------------------------------------------------------------------

qasm3Parser::IncludeStatementContext::IncludeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::INCLUDE() {
  return getToken(qasm3Parser::INCLUDE, 0);
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::IncludeStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIncludeStatement;
}


std::any qasm3Parser::IncludeStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIncludeStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IncludeStatementContext* qasm3Parser::includeStatement() {
  IncludeStatementContext *_localctx = _tracker.createInstance<IncludeStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, qasm3Parser::RuleIncludeStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(qasm3Parser::INCLUDE);
    setState(215);
    match(qasm3Parser::StringLiteral);
    setState(216);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

qasm3Parser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BreakStatementContext::BREAK() {
  return getToken(qasm3Parser::BREAK, 0);
}

tree::TerminalNode* qasm3Parser::BreakStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::BreakStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBreakStatement;
}


std::any qasm3Parser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BreakStatementContext* qasm3Parser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, qasm3Parser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(qasm3Parser::BREAK);
    setState(219);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

qasm3Parser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ContinueStatementContext::CONTINUE() {
  return getToken(qasm3Parser::CONTINUE, 0);
}

tree::TerminalNode* qasm3Parser::ContinueStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ContinueStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleContinueStatement;
}


std::any qasm3Parser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ContinueStatementContext* qasm3Parser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm3Parser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(qasm3Parser::CONTINUE);
    setState(222);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndStatementContext ------------------------------------------------------------------

qasm3Parser::EndStatementContext::EndStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::EndStatementContext::END() {
  return getToken(qasm3Parser::END, 0);
}

tree::TerminalNode* qasm3Parser::EndStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::EndStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleEndStatement;
}


std::any qasm3Parser::EndStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEndStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EndStatementContext* qasm3Parser::endStatement() {
  EndStatementContext *_localctx = _tracker.createInstance<EndStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, qasm3Parser::RuleEndStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(qasm3Parser::END);
    setState(225);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

qasm3Parser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ForStatementContext::FOR() {
  return getToken(qasm3Parser::FOR, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ForStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::IN() {
  return getToken(qasm3Parser::IN, 0);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::ForStatementContext::statementOrScope() {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(0);
}

qasm3Parser::SetExpressionContext* qasm3Parser::ForStatementContext::setExpression() {
  return getRuleContext<qasm3Parser::SetExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::RangeExpressionContext* qasm3Parser::ForStatementContext::rangeExpression() {
  return getRuleContext<qasm3Parser::RangeExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ForStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ForStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleForStatement;
}


std::any qasm3Parser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ForStatementContext* qasm3Parser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, qasm3Parser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(qasm3Parser::FOR);
    setState(228);
    scalarType();
    setState(229);
    match(qasm3Parser::Identifier);
    setState(230);
    match(qasm3Parser::IN);
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        setState(231);
        setExpression();
        break;
      }

      case qasm3Parser::LBRACKET: {
        setState(232);
        match(qasm3Parser::LBRACKET);
        setState(233);
        rangeExpression();
        setState(234);
        match(qasm3Parser::RBRACKET);
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(236);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(239);
    antlrcpp::downCast<ForStatementContext *>(_localctx)->body = statementOrScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

qasm3Parser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IfStatementContext::IF() {
  return getToken(qasm3Parser::IF, 0);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::IfStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<qasm3Parser::StatementOrScopeContext *> qasm3Parser::IfStatementContext::statementOrScope() {
  return getRuleContexts<qasm3Parser::StatementOrScopeContext>();
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::IfStatementContext::statementOrScope(size_t i) {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(i);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::ELSE() {
  return getToken(qasm3Parser::ELSE, 0);
}


size_t qasm3Parser::IfStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIfStatement;
}


std::any qasm3Parser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IfStatementContext* qasm3Parser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, qasm3Parser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(qasm3Parser::IF);
    setState(242);
    match(qasm3Parser::LPAREN);
    setState(243);
    expression(0);
    setState(244);
    match(qasm3Parser::RPAREN);
    setState(245);
    antlrcpp::downCast<IfStatementContext *>(_localctx)->if_body = statementOrScope();
    setState(248);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(246);
      match(qasm3Parser::ELSE);
      setState(247);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->else_body = statementOrScope();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

qasm3Parser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ReturnStatementContext::RETURN() {
  return getToken(qasm3Parser::RETURN, 0);
}

tree::TerminalNode* qasm3Parser::ReturnStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ReturnStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::ReturnStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::ReturnStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnStatement;
}


std::any qasm3Parser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, qasm3Parser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(qasm3Parser::RETURN);
    setState(253);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(251);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        setState(252);
        measureExpression();
        break;
      }

      case qasm3Parser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(255);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

qasm3Parser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::WHILE() {
  return getToken(qasm3Parser::WHILE, 0);
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::WhileStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::WhileStatementContext::statementOrScope() {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(0);
}


size_t qasm3Parser::WhileStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleWhileStatement;
}


std::any qasm3Parser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::WhileStatementContext* qasm3Parser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, qasm3Parser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(qasm3Parser::WHILE);
    setState(258);
    match(qasm3Parser::LPAREN);
    setState(259);
    expression(0);
    setState(260);
    match(qasm3Parser::RPAREN);
    setState(261);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->body = statementOrScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

qasm3Parser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SwitchStatementContext::SWITCH() {
  return getToken(qasm3Parser::SWITCH, 0);
}

tree::TerminalNode* qasm3Parser::SwitchStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::SwitchStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::SwitchStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::SwitchStatementContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::SwitchStatementContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::SwitchCaseItemContext *> qasm3Parser::SwitchStatementContext::switchCaseItem() {
  return getRuleContexts<qasm3Parser::SwitchCaseItemContext>();
}

qasm3Parser::SwitchCaseItemContext* qasm3Parser::SwitchStatementContext::switchCaseItem(size_t i) {
  return getRuleContext<qasm3Parser::SwitchCaseItemContext>(i);
}


size_t qasm3Parser::SwitchStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleSwitchStatement;
}


std::any qasm3Parser::SwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SwitchStatementContext* qasm3Parser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, qasm3Parser::RuleSwitchStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(qasm3Parser::SWITCH);
    setState(264);
    match(qasm3Parser::LPAREN);
    setState(265);
    expression(0);
    setState(266);
    match(qasm3Parser::RPAREN);
    setState(267);
    match(qasm3Parser::LBRACE);
    setState(271);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::CASE

    || _la == qasm3Parser::DEFAULT) {
      setState(268);
      switchCaseItem();
      setState(273);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(274);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchCaseItemContext ------------------------------------------------------------------

qasm3Parser::SwitchCaseItemContext::SwitchCaseItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SwitchCaseItemContext::CASE() {
  return getToken(qasm3Parser::CASE, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::SwitchCaseItemContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

qasm3Parser::ScopeContext* qasm3Parser::SwitchCaseItemContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

tree::TerminalNode* qasm3Parser::SwitchCaseItemContext::DEFAULT() {
  return getToken(qasm3Parser::DEFAULT, 0);
}


size_t qasm3Parser::SwitchCaseItemContext::getRuleIndex() const {
  return qasm3Parser::RuleSwitchCaseItem;
}


std::any qasm3Parser::SwitchCaseItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSwitchCaseItem(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SwitchCaseItemContext* qasm3Parser::switchCaseItem() {
  SwitchCaseItemContext *_localctx = _tracker.createInstance<SwitchCaseItemContext>(_ctx, getState());
  enterRule(_localctx, 34, qasm3Parser::RuleSwitchCaseItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(276);
        match(qasm3Parser::CASE);
        setState(277);
        expressionList();
        setState(278);
        scope();
        break;
      }

      case qasm3Parser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(280);
        match(qasm3Parser::DEFAULT);
        setState(281);
        scope();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BarrierStatementContext ------------------------------------------------------------------

qasm3Parser::BarrierStatementContext::BarrierStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BarrierStatementContext::BARRIER() {
  return getToken(qasm3Parser::BARRIER, 0);
}

tree::TerminalNode* qasm3Parser::BarrierStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::BarrierStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}


size_t qasm3Parser::BarrierStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBarrierStatement;
}


std::any qasm3Parser::BarrierStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBarrierStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BarrierStatementContext* qasm3Parser::barrierStatement() {
  BarrierStatementContext *_localctx = _tracker.createInstance<BarrierStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, qasm3Parser::RuleBarrierStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(qasm3Parser::BARRIER);
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit) {
      setState(285);
      gateOperandList();
    }
    setState(288);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoxStatementContext ------------------------------------------------------------------

qasm3Parser::BoxStatementContext::BoxStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BoxStatementContext::BOX() {
  return getToken(qasm3Parser::BOX, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::BoxStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::BoxStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::BoxStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBoxStatement;
}


std::any qasm3Parser::BoxStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBoxStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BoxStatementContext* qasm3Parser::boxStatement() {
  BoxStatementContext *_localctx = _tracker.createInstance<BoxStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, qasm3Parser::RuleBoxStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(qasm3Parser::BOX);
    setState(292);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(291);
      designator();
    }
    setState(294);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DelayStatementContext ------------------------------------------------------------------

qasm3Parser::DelayStatementContext::DelayStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DelayStatementContext::DELAY() {
  return getToken(qasm3Parser::DELAY, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::DelayStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::DelayStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::DelayStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}


size_t qasm3Parser::DelayStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDelayStatement;
}


std::any qasm3Parser::DelayStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDelayStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DelayStatementContext* qasm3Parser::delayStatement() {
  DelayStatementContext *_localctx = _tracker.createInstance<DelayStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, qasm3Parser::RuleDelayStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(qasm3Parser::DELAY);
    setState(297);
    designator();
    setState(299);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit) {
      setState(298);
      gateOperandList();
    }
    setState(301);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NopStatementContext ------------------------------------------------------------------

qasm3Parser::NopStatementContext::NopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::NopStatementContext::NOP() {
  return getToken(qasm3Parser::NOP, 0);
}

tree::TerminalNode* qasm3Parser::NopStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::NopStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}


size_t qasm3Parser::NopStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleNopStatement;
}


std::any qasm3Parser::NopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitNopStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NopStatementContext* qasm3Parser::nopStatement() {
  NopStatementContext *_localctx = _tracker.createInstance<NopStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, qasm3Parser::RuleNopStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(qasm3Parser::NOP);
    setState(305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit) {
      setState(304);
      gateOperandList();
    }
    setState(307);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateCallStatementContext ------------------------------------------------------------------

qasm3Parser::GateCallStatementContext::GateCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::GateCallStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

std::vector<qasm3Parser::GateModifierContext *> qasm3Parser::GateCallStatementContext::gateModifier() {
  return getRuleContexts<qasm3Parser::GateModifierContext>();
}

qasm3Parser::GateModifierContext* qasm3Parser::GateCallStatementContext::gateModifier(size_t i) {
  return getRuleContext<qasm3Parser::GateModifierContext>(i);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::GateCallStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::GateCallStatementContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::GPHASE() {
  return getToken(qasm3Parser::GPHASE, 0);
}


size_t qasm3Parser::GateCallStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGateCallStatement;
}


std::any qasm3Parser::GateCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateCallStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateCallStatementContext* qasm3Parser::gateCallStatement() {
  GateCallStatementContext *_localctx = _tracker.createInstance<GateCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, qasm3Parser::RuleGateCallStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(350);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1055531162664960) != 0)) {
        setState(309);
        gateModifier();
        setState(314);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(315);
      match(qasm3Parser::Identifier);
      setState(321);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LPAREN) {
        setState(316);
        match(qasm3Parser::LPAREN);
        setState(318);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2380183172211015680) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & 268179457) != 0)) {
          setState(317);
          expressionList();
        }
        setState(320);
        match(qasm3Parser::RPAREN);
      }
      setState(324);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LBRACKET) {
        setState(323);
        designator();
      }
      setState(326);
      gateOperandList();
      setState(327);
      match(qasm3Parser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1055531162664960) != 0)) {
        setState(329);
        gateModifier();
        setState(334);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(335);
      match(qasm3Parser::GPHASE);
      setState(341);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LPAREN) {
        setState(336);
        match(qasm3Parser::LPAREN);
        setState(338);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2380183172211015680) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & 268179457) != 0)) {
          setState(337);
          expressionList();
        }
        setState(340);
        match(qasm3Parser::RPAREN);
      }
      setState(344);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LBRACKET) {
        setState(343);
        designator();
      }
      setState(347);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier

      || _la == qasm3Parser::HardwareQubit) {
        setState(346);
        gateOperandList();
      }
      setState(349);
      match(qasm3Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureArrowAssignmentStatementContext ------------------------------------------------------------------

qasm3Parser::MeasureArrowAssignmentStatementContext::MeasureArrowAssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::MeasureArrowAssignmentStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::MeasureArrowAssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::MeasureArrowAssignmentStatementContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::MeasureArrowAssignmentStatementContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}


size_t qasm3Parser::MeasureArrowAssignmentStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleMeasureArrowAssignmentStatement;
}


std::any qasm3Parser::MeasureArrowAssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMeasureArrowAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::MeasureArrowAssignmentStatementContext* qasm3Parser::measureArrowAssignmentStatement() {
  MeasureArrowAssignmentStatementContext *_localctx = _tracker.createInstance<MeasureArrowAssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 46, qasm3Parser::RuleMeasureArrowAssignmentStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    measureExpression();
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(353);
      match(qasm3Parser::ARROW);
      setState(354);
      indexedIdentifier();
    }
    setState(357);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResetStatementContext ------------------------------------------------------------------

qasm3Parser::ResetStatementContext::ResetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ResetStatementContext::RESET() {
  return getToken(qasm3Parser::RESET, 0);
}

qasm3Parser::GateOperandContext* qasm3Parser::ResetStatementContext::gateOperand() {
  return getRuleContext<qasm3Parser::GateOperandContext>(0);
}

tree::TerminalNode* qasm3Parser::ResetStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ResetStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleResetStatement;
}


std::any qasm3Parser::ResetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitResetStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ResetStatementContext* qasm3Parser::resetStatement() {
  ResetStatementContext *_localctx = _tracker.createInstance<ResetStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, qasm3Parser::RuleResetStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(qasm3Parser::RESET);
    setState(360);
    gateOperand();
    setState(361);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::AliasDeclarationStatementContext::AliasDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::LET() {
  return getToken(qasm3Parser::LET, 0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::AliasExpressionContext* qasm3Parser::AliasDeclarationStatementContext::aliasExpression() {
  return getRuleContext<qasm3Parser::AliasExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::AliasDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasDeclarationStatement;
}


std::any qasm3Parser::AliasDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasDeclarationStatementContext* qasm3Parser::aliasDeclarationStatement() {
  AliasDeclarationStatementContext *_localctx = _tracker.createInstance<AliasDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, qasm3Parser::RuleAliasDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    match(qasm3Parser::LET);
    setState(364);
    match(qasm3Parser::Identifier);
    setState(365);
    match(qasm3Parser::EQUALS);
    setState(366);
    aliasExpression();
    setState(367);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::ClassicalDeclarationStatementContext::ClassicalDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ClassicalDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::ClassicalDeclarationStatementContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::ClassicalDeclarationStatementContext::declarationExpression() {
  return getRuleContext<qasm3Parser::DeclarationExpressionContext>(0);
}


size_t qasm3Parser::ClassicalDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclarationStatement;
}


std::any qasm3Parser::ClassicalDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::classicalDeclarationStatement() {
  ClassicalDeclarationStatementContext *_localctx = _tracker.createInstance<ClassicalDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, qasm3Parser::RuleClassicalDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        setState(369);
        scalarType();
        break;
      }

      case qasm3Parser::ARRAY: {
        setState(370);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(373);
    match(qasm3Parser::Identifier);
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(374);
      match(qasm3Parser::EQUALS);
      setState(375);
      declarationExpression();
    }
    setState(378);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::ConstDeclarationStatementContext::ConstDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::CONST() {
  return getToken(qasm3Parser::CONST, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ConstDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::ConstDeclarationStatementContext::declarationExpression() {
  return getRuleContext<qasm3Parser::DeclarationExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ConstDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleConstDeclarationStatement;
}


std::any qasm3Parser::ConstDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitConstDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ConstDeclarationStatementContext* qasm3Parser::constDeclarationStatement() {
  ConstDeclarationStatementContext *_localctx = _tracker.createInstance<ConstDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, qasm3Parser::RuleConstDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(qasm3Parser::CONST);
    setState(381);
    scalarType();
    setState(382);
    match(qasm3Parser::Identifier);
    setState(383);
    match(qasm3Parser::EQUALS);
    setState(384);
    declarationExpression();
    setState(385);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::IoDeclarationStatementContext::IoDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::INPUT() {
  return getToken(qasm3Parser::INPUT, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::OUTPUT() {
  return getToken(qasm3Parser::OUTPUT, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::IoDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::IoDeclarationStatementContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}


size_t qasm3Parser::IoDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIoDeclarationStatement;
}


std::any qasm3Parser::IoDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIoDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IoDeclarationStatementContext* qasm3Parser::ioDeclarationStatement() {
  IoDeclarationStatementContext *_localctx = _tracker.createInstance<IoDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, qasm3Parser::RuleIoDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::INPUT

    || _la == qasm3Parser::OUTPUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        setState(388);
        scalarType();
        break;
      }

      case qasm3Parser::ARRAY: {
        setState(389);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(392);
    match(qasm3Parser::Identifier);
    setState(393);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OldStyleDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::OldStyleDeclarationStatementContext::OldStyleDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::OldStyleDeclarationStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::OldStyleDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleOldStyleDeclarationStatement;
}


std::any qasm3Parser::OldStyleDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitOldStyleDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::OldStyleDeclarationStatementContext* qasm3Parser::oldStyleDeclarationStatement() {
  OldStyleDeclarationStatementContext *_localctx = _tracker.createInstance<OldStyleDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, qasm3Parser::RuleOldStyleDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::QREG

    || _la == qasm3Parser::CREG)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(396);
    match(qasm3Parser::Identifier);
    setState(398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(397);
      designator();
    }
    setState(400);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationStatementContext::QuantumDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QubitTypeContext* qasm3Parser::QuantumDeclarationStatementContext::qubitType() {
  return getRuleContext<qasm3Parser::QubitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::QuantumDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclarationStatement;
}


std::any qasm3Parser::QuantumDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::quantumDeclarationStatement() {
  QuantumDeclarationStatementContext *_localctx = _tracker.createInstance<QuantumDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, qasm3Parser::RuleQuantumDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    qubitType();
    setState(403);
    match(qasm3Parser::Identifier);
    setState(404);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefStatementContext ------------------------------------------------------------------

qasm3Parser::DefStatementContext::DefStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefStatementContext::DEF() {
  return getToken(qasm3Parser::DEF, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::DefStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

qasm3Parser::ArgumentDefinitionListContext* qasm3Parser::DefStatementContext::argumentDefinitionList() {
  return getRuleContext<qasm3Parser::ArgumentDefinitionListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::DefStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::DefStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDefStatement;
}


std::any qasm3Parser::DefStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefStatementContext* qasm3Parser::defStatement() {
  DefStatementContext *_localctx = _tracker.createInstance<DefStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, qasm3Parser::RuleDefStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    match(qasm3Parser::DEF);
    setState(407);
    match(qasm3Parser::Identifier);
    setState(408);
    match(qasm3Parser::LPAREN);
    setState(410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28586765451264) != 0)) {
      setState(409);
      argumentDefinitionList();
    }
    setState(412);
    match(qasm3Parser::RPAREN);
    setState(414);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(413);
      returnSignature();
    }
    setState(416);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternStatementContext ------------------------------------------------------------------

qasm3Parser::ExternStatementContext::ExternStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::EXTERN() {
  return getToken(qasm3Parser::EXTERN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ExternArgumentListContext* qasm3Parser::ExternStatementContext::externArgumentList() {
  return getRuleContext<qasm3Parser::ExternArgumentListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::ExternStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::ExternStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleExternStatement;
}


std::any qasm3Parser::ExternStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternStatementContext* qasm3Parser::externStatement() {
  ExternStatementContext *_localctx = _tracker.createInstance<ExternStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, qasm3Parser::RuleExternStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(qasm3Parser::EXTERN);
    setState(419);
    match(qasm3Parser::Identifier);
    setState(420);
    match(qasm3Parser::LPAREN);
    setState(422);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28580323000320) != 0)) {
      setState(421);
      externArgumentList();
    }
    setState(424);
    match(qasm3Parser::RPAREN);
    setState(426);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(425);
      returnSignature();
    }
    setState(428);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateStatementContext ------------------------------------------------------------------

qasm3Parser::GateStatementContext::GateStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateStatementContext::GATE() {
  return getToken(qasm3Parser::GATE, 0);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::GateStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

std::vector<qasm3Parser::IdentifierListContext *> qasm3Parser::GateStatementContext::identifierList() {
  return getRuleContexts<qasm3Parser::IdentifierListContext>();
}

qasm3Parser::IdentifierListContext* qasm3Parser::GateStatementContext::identifierList(size_t i) {
  return getRuleContext<qasm3Parser::IdentifierListContext>(i);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::GateStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGateStatement;
}


std::any qasm3Parser::GateStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateStatementContext* qasm3Parser::gateStatement() {
  GateStatementContext *_localctx = _tracker.createInstance<GateStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, qasm3Parser::RuleGateStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(qasm3Parser::GATE);
    setState(431);
    match(qasm3Parser::Identifier);
    setState(437);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(432);
      match(qasm3Parser::LPAREN);
      setState(434);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier) {
        setState(433);
        antlrcpp::downCast<GateStatementContext *>(_localctx)->params = identifierList();
      }
      setState(436);
      match(qasm3Parser::RPAREN);
    }
    setState(439);
    antlrcpp::downCast<GateStatementContext *>(_localctx)->qubits = identifierList();
    setState(440);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

qasm3Parser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::AssignmentStatementContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::CompoundAssignmentOperator() {
  return getToken(qasm3Parser::CompoundAssignmentOperator, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::AssignmentStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::AssignmentStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::AssignmentStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentStatement;
}


std::any qasm3Parser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, qasm3Parser::RuleAssignmentStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    indexedIdentifier();
    setState(443);
    antlrcpp::downCast<AssignmentStatementContext *>(_localctx)->op = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::EQUALS

    || _la == qasm3Parser::CompoundAssignmentOperator)) {
      antlrcpp::downCast<AssignmentStatementContext *>(_localctx)->op = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(444);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        setState(445);
        measureExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(448);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

qasm3Parser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ExpressionStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionStatement;
}


std::any qasm3Parser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, qasm3Parser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    expression(0);
    setState(451);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalStatementContext ------------------------------------------------------------------

qasm3Parser::CalStatementContext::CalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalStatementContext::CAL() {
  return getToken(qasm3Parser::CAL, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::CalibrationBlock() {
  return getToken(qasm3Parser::CalibrationBlock, 0);
}


size_t qasm3Parser::CalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleCalStatement;
}


std::any qasm3Parser::CalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalStatementContext* qasm3Parser::calStatement() {
  CalStatementContext *_localctx = _tracker.createInstance<CalStatementContext>(_ctx, getState());
  enterRule(_localctx, 72, qasm3Parser::RuleCalStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    match(qasm3Parser::CAL);
    setState(454);
    match(qasm3Parser::LBRACE);
    setState(456);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::CalibrationBlock) {
      setState(455);
      match(qasm3Parser::CalibrationBlock);
    }
    setState(458);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalStatementContext ------------------------------------------------------------------

qasm3Parser::DefcalStatementContext::DefcalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::DEFCAL() {
  return getToken(qasm3Parser::DEFCAL, 0);
}

qasm3Parser::DefcalTargetContext* qasm3Parser::DefcalStatementContext::defcalTarget() {
  return getRuleContext<qasm3Parser::DefcalTargetContext>(0);
}

qasm3Parser::DefcalOperandListContext* qasm3Parser::DefcalStatementContext::defcalOperandList() {
  return getRuleContext<qasm3Parser::DefcalOperandListContext>(0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::DefcalStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::CalibrationBlock() {
  return getToken(qasm3Parser::CalibrationBlock, 0);
}

qasm3Parser::DefcalArgumentDefinitionListContext* qasm3Parser::DefcalStatementContext::defcalArgumentDefinitionList() {
  return getRuleContext<qasm3Parser::DefcalArgumentDefinitionListContext>(0);
}


size_t qasm3Parser::DefcalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalStatement;
}


std::any qasm3Parser::DefcalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalStatementContext* qasm3Parser::defcalStatement() {
  DefcalStatementContext *_localctx = _tracker.createInstance<DefcalStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, qasm3Parser::RuleDefcalStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    match(qasm3Parser::DEFCAL);
    setState(461);
    defcalTarget();
    setState(467);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(462);
      match(qasm3Parser::LPAREN);
      setState(464);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2380183188854013952) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & 268179457) != 0)) {
        setState(463);
        defcalArgumentDefinitionList();
      }
      setState(466);
      match(qasm3Parser::RPAREN);
    }
    setState(469);
    defcalOperandList();
    setState(471);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(470);
      returnSignature();
    }
    setState(473);
    match(qasm3Parser::LBRACE);
    setState(475);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::CalibrationBlock) {
      setState(474);
      match(qasm3Parser::CalibrationBlock);
    }
    setState(477);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::ExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleExpression;
}

void qasm3Parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseXorExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseXorExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseXorExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseXorExpressionContext::CARET() {
  return getToken(qasm3Parser::CARET, 0);
}

qasm3Parser::BitwiseXorExpressionContext::BitwiseXorExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::BitwiseXorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseXorExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::AdditiveExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::AdditiveExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::PLUS() {
  return getToken(qasm3Parser::PLUS, 0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}

qasm3Parser::AdditiveExpressionContext::AdditiveExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DurationofExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::DURATIONOF() {
  return getToken(qasm3Parser::DURATIONOF, 0);
}

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::DurationofExpressionContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::DurationofExpressionContext::DurationofExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::DurationofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDurationofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::ParenthesisExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ParenthesisExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ParenthesisExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ParenthesisExpressionContext::ParenthesisExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::ParenthesisExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitParenthesisExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ComparisonExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ComparisonExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::ComparisonExpressionContext::ComparisonOperator() {
  return getToken(qasm3Parser::ComparisonOperator, 0);
}

qasm3Parser::ComparisonExpressionContext::ComparisonExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::MultiplicativeExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::MultiplicativeExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::ASTERISK() {
  return getToken(qasm3Parser::ASTERISK, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::SLASH() {
  return getToken(qasm3Parser::SLASH, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::PERCENT() {
  return getToken(qasm3Parser::PERCENT, 0);
}

qasm3Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::LogicalOrExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::LogicalOrExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::LogicalOrExpressionContext::DOUBLE_PIPE() {
  return getToken(qasm3Parser::DOUBLE_PIPE, 0);
}

qasm3Parser::LogicalOrExpressionContext::LogicalOrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CastExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::CastExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::CastExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::CastExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::CastExpressionContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::CastExpressionContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}

qasm3Parser::CastExpressionContext::CastExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::PowerExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::PowerExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::PowerExpressionContext::DOUBLE_ASTERISK() {
  return getToken(qasm3Parser::DOUBLE_ASTERISK, 0);
}

qasm3Parser::PowerExpressionContext::PowerExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseOrExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseOrExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseOrExpressionContext::PIPE() {
  return getToken(qasm3Parser::PIPE, 0);
}

qasm3Parser::BitwiseOrExpressionContext::BitwiseOrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::BitwiseOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::CallExpressionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::CallExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::CallExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::CallExpressionContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

qasm3Parser::CallExpressionContext::CallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::CallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCallExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitshiftExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitshiftExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitshiftExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitshiftExpressionContext::BitshiftOperator() {
  return getToken(qasm3Parser::BitshiftOperator, 0);
}

qasm3Parser::BitshiftExpressionContext::BitshiftExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::BitshiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitshiftExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseAndExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseAndExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseAndExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseAndExpressionContext::AMPERSAND() {
  return getToken(qasm3Parser::AMPERSAND, 0);
}

qasm3Parser::BitwiseAndExpressionContext::BitwiseAndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::BitwiseAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::EqualityExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::EqualityExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::EqualityExpressionContext::EqualityOperator() {
  return getToken(qasm3Parser::EqualityOperator, 0);
}

qasm3Parser::EqualityExpressionContext::EqualityExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::LogicalAndExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::LogicalAndExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::LogicalAndExpressionContext::DOUBLE_AMPERSAND() {
  return getToken(qasm3Parser::DOUBLE_AMPERSAND, 0);
}

qasm3Parser::LogicalAndExpressionContext::LogicalAndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext* qasm3Parser::IndexExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::IndexOperatorContext* qasm3Parser::IndexExpressionContext::indexOperator() {
  return getRuleContext<qasm3Parser::IndexOperatorContext>(0);
}

qasm3Parser::IndexExpressionContext::IndexExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::IndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext* qasm3Parser::UnaryExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::TILDE() {
  return getToken(qasm3Parser::TILDE, 0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::EXCLAMATION_POINT() {
  return getToken(qasm3Parser::EXCLAMATION_POINT, 0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}

qasm3Parser::UnaryExpressionContext::UnaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BinaryIntegerLiteral() {
  return getToken(qasm3Parser::BinaryIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::OctalIntegerLiteral() {
  return getToken(qasm3Parser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::DecimalIntegerLiteral() {
  return getToken(qasm3Parser::DecimalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::HexIntegerLiteral() {
  return getToken(qasm3Parser::HexIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::FloatLiteral() {
  return getToken(qasm3Parser::FloatLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::ImaginaryLiteral() {
  return getToken(qasm3Parser::ImaginaryLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BooleanLiteral() {
  return getToken(qasm3Parser::BooleanLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BitstringLiteral() {
  return getToken(qasm3Parser::BitstringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::TimingLiteral() {
  return getToken(qasm3Parser::TimingLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}

qasm3Parser::LiteralExpressionContext::LiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any qasm3Parser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionContext* qasm3Parser::expression() {
   return expression(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  qasm3Parser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 76;
  enterRecursionRule(_localctx, 76, qasm3Parser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(506);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(480);
      match(qasm3Parser::LPAREN);
      setState(481);
      expression(0);
      setState(482);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(484);
      antlrcpp::downCast<UnaryExpressionContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & 6145) != 0))) {
        antlrcpp::downCast<UnaryExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(485);
      expression(15);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CastExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(488);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::BOOL:
        case qasm3Parser::BIT:
        case qasm3Parser::INT:
        case qasm3Parser::UINT:
        case qasm3Parser::FLOAT:
        case qasm3Parser::ANGLE:
        case qasm3Parser::COMPLEX:
        case qasm3Parser::DURATION:
        case qasm3Parser::STRETCH: {
          setState(486);
          scalarType();
          break;
        }

        case qasm3Parser::ARRAY: {
          setState(487);
          arrayType();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(490);
      match(qasm3Parser::LPAREN);
      setState(491);
      expression(0);
      setState(492);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DurationofExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(494);
      match(qasm3Parser::DURATIONOF);
      setState(495);
      match(qasm3Parser::LPAREN);
      setState(496);
      scope();
      setState(497);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CallExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(499);
      match(qasm3Parser::Identifier);
      setState(500);
      match(qasm3Parser::LPAREN);
      setState(502);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2380183172211015680) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & 268179457) != 0)) {
        setState(501);
        expressionList();
      }
      setState(504);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(505);
      _la = _input->LA(1);
      if (!(((((_la - 56) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 56)) & 8787503087617) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(545);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(543);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(508);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(509);
          antlrcpp::downCast<PowerExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_ASTERISK);
          setState(510);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiplicativeExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(511);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(512);
          antlrcpp::downCast<MultiplicativeExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & 13) != 0))) {
            antlrcpp::downCast<MultiplicativeExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(513);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(514);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(515);
          antlrcpp::downCast<AdditiveExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == qasm3Parser::PLUS

          || _la == qasm3Parser::MINUS)) {
            antlrcpp::downCast<AdditiveExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(516);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BitshiftExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(517);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(518);
          antlrcpp::downCast<BitshiftExpressionContext *>(_localctx)->op = match(qasm3Parser::BitshiftOperator);
          setState(519);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ComparisonExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(520);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(521);
          antlrcpp::downCast<ComparisonExpressionContext *>(_localctx)->op = match(qasm3Parser::ComparisonOperator);
          setState(522);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<EqualityExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(523);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(524);
          antlrcpp::downCast<EqualityExpressionContext *>(_localctx)->op = match(qasm3Parser::EqualityOperator);
          setState(525);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseAndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(526);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(527);
          antlrcpp::downCast<BitwiseAndExpressionContext *>(_localctx)->op = match(qasm3Parser::AMPERSAND);
          setState(528);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseXorExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(529);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(530);
          antlrcpp::downCast<BitwiseXorExpressionContext *>(_localctx)->op = match(qasm3Parser::CARET);
          setState(531);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BitwiseOrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(532);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(533);
          antlrcpp::downCast<BitwiseOrExpressionContext *>(_localctx)->op = match(qasm3Parser::PIPE);
          setState(534);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalAndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(535);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(536);
          antlrcpp::downCast<LogicalAndExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_AMPERSAND);
          setState(537);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<LogicalOrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(538);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(539);
          antlrcpp::downCast<LogicalOrExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_PIPE);
          setState(540);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<IndexExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(541);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(542);
          indexOperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(547);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AliasExpressionContext ------------------------------------------------------------------

qasm3Parser::AliasExpressionContext::AliasExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::AliasExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::AliasExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::AliasExpressionContext::DOUBLE_PLUS() {
  return getTokens(qasm3Parser::DOUBLE_PLUS);
}

tree::TerminalNode* qasm3Parser::AliasExpressionContext::DOUBLE_PLUS(size_t i) {
  return getToken(qasm3Parser::DOUBLE_PLUS, i);
}


size_t qasm3Parser::AliasExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasExpression;
}


std::any qasm3Parser::AliasExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasExpressionContext* qasm3Parser::aliasExpression() {
  AliasExpressionContext *_localctx = _tracker.createInstance<AliasExpressionContext>(_ctx, getState());
  enterRule(_localctx, 78, qasm3Parser::RuleAliasExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(548);
    expression(0);
    setState(553);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::DOUBLE_PLUS) {
      setState(549);
      match(qasm3Parser::DOUBLE_PLUS);
      setState(550);
      expression(0);
      setState(555);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationExpressionContext ------------------------------------------------------------------

qasm3Parser::DeclarationExpressionContext::DeclarationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::DeclarationExpressionContext::arrayLiteral() {
  return getRuleContext<qasm3Parser::ArrayLiteralContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::DeclarationExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::DeclarationExpressionContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::DeclarationExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleDeclarationExpression;
}


std::any qasm3Parser::DeclarationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDeclarationExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::declarationExpression() {
  DeclarationExpressionContext *_localctx = _tracker.createInstance<DeclarationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 80, qasm3Parser::RuleDeclarationExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(559);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(556);
        arrayLiteral();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(557);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        enterOuterAlt(_localctx, 3);
        setState(558);
        measureExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureExpressionContext ------------------------------------------------------------------

qasm3Parser::MeasureExpressionContext::MeasureExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::MeasureExpressionContext::MEASURE() {
  return getToken(qasm3Parser::MEASURE, 0);
}

qasm3Parser::GateOperandContext* qasm3Parser::MeasureExpressionContext::gateOperand() {
  return getRuleContext<qasm3Parser::GateOperandContext>(0);
}


size_t qasm3Parser::MeasureExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleMeasureExpression;
}


std::any qasm3Parser::MeasureExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMeasureExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::measureExpression() {
  MeasureExpressionContext *_localctx = _tracker.createInstance<MeasureExpressionContext>(_ctx, getState());
  enterRule(_localctx, 82, qasm3Parser::RuleMeasureExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(561);
    match(qasm3Parser::MEASURE);
    setState(562);
    gateOperand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeExpressionContext ------------------------------------------------------------------

qasm3Parser::RangeExpressionContext::RangeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::RangeExpressionContext::COLON() {
  return getTokens(qasm3Parser::COLON);
}

tree::TerminalNode* qasm3Parser::RangeExpressionContext::COLON(size_t i) {
  return getToken(qasm3Parser::COLON, i);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::RangeExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::RangeExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}


size_t qasm3Parser::RangeExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleRangeExpression;
}


std::any qasm3Parser::RangeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitRangeExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RangeExpressionContext* qasm3Parser::rangeExpression() {
  RangeExpressionContext *_localctx = _tracker.createInstance<RangeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 84, qasm3Parser::RuleRangeExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2380183172211015680) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 268179457) != 0)) {
      setState(564);
      expression(0);
    }
    setState(567);
    match(qasm3Parser::COLON);
    setState(569);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2380183172211015680) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 268179457) != 0)) {
      setState(568);
      expression(0);
    }
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COLON) {
      setState(571);
      match(qasm3Parser::COLON);
      setState(572);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetExpressionContext ------------------------------------------------------------------

qasm3Parser::SetExpressionContext::SetExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::SetExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::SetExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::SetExpressionContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::SetExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleSetExpression;
}


std::any qasm3Parser::SetExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSetExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SetExpressionContext* qasm3Parser::setExpression() {
  SetExpressionContext *_localctx = _tracker.createInstance<SetExpressionContext>(_ctx, getState());
  enterRule(_localctx, 86, qasm3Parser::RuleSetExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(qasm3Parser::LBRACE);
    setState(576);
    expression(0);
    setState(581);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(577);
        match(qasm3Parser::COMMA);
        setState(578);
        expression(0); 
      }
      setState(583);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    }
    setState(585);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(584);
      match(qasm3Parser::COMMA);
    }
    setState(587);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

qasm3Parser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ArrayLiteralContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayLiteralContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::ArrayLiteralContext *> qasm3Parser::ArrayLiteralContext::arrayLiteral() {
  return getRuleContexts<qasm3Parser::ArrayLiteralContext>();
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::ArrayLiteralContext::arrayLiteral(size_t i) {
  return getRuleContext<qasm3Parser::ArrayLiteralContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ArrayLiteralContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ArrayLiteralContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayLiteral;
}


std::any qasm3Parser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 88, qasm3Parser::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(qasm3Parser::LBRACE);
    setState(607);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2956643924514439168) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 268179457) != 0)) {
      setState(592);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::BOOL:
        case qasm3Parser::BIT:
        case qasm3Parser::INT:
        case qasm3Parser::UINT:
        case qasm3Parser::FLOAT:
        case qasm3Parser::ANGLE:
        case qasm3Parser::COMPLEX:
        case qasm3Parser::ARRAY:
        case qasm3Parser::DURATION:
        case qasm3Parser::STRETCH:
        case qasm3Parser::DURATIONOF:
        case qasm3Parser::BooleanLiteral:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::TILDE:
        case qasm3Parser::EXCLAMATION_POINT:
        case qasm3Parser::ImaginaryLiteral:
        case qasm3Parser::BinaryIntegerLiteral:
        case qasm3Parser::OctalIntegerLiteral:
        case qasm3Parser::DecimalIntegerLiteral:
        case qasm3Parser::HexIntegerLiteral:
        case qasm3Parser::Identifier:
        case qasm3Parser::HardwareQubit:
        case qasm3Parser::FloatLiteral:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::BitstringLiteral: {
          setState(590);
          expression(0);
          break;
        }

        case qasm3Parser::LBRACE: {
          setState(591);
          arrayLiteral();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(601);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(594);
          match(qasm3Parser::COMMA);
          setState(597);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case qasm3Parser::BOOL:
            case qasm3Parser::BIT:
            case qasm3Parser::INT:
            case qasm3Parser::UINT:
            case qasm3Parser::FLOAT:
            case qasm3Parser::ANGLE:
            case qasm3Parser::COMPLEX:
            case qasm3Parser::ARRAY:
            case qasm3Parser::DURATION:
            case qasm3Parser::STRETCH:
            case qasm3Parser::DURATIONOF:
            case qasm3Parser::BooleanLiteral:
            case qasm3Parser::LPAREN:
            case qasm3Parser::MINUS:
            case qasm3Parser::TILDE:
            case qasm3Parser::EXCLAMATION_POINT:
            case qasm3Parser::ImaginaryLiteral:
            case qasm3Parser::BinaryIntegerLiteral:
            case qasm3Parser::OctalIntegerLiteral:
            case qasm3Parser::DecimalIntegerLiteral:
            case qasm3Parser::HexIntegerLiteral:
            case qasm3Parser::Identifier:
            case qasm3Parser::HardwareQubit:
            case qasm3Parser::FloatLiteral:
            case qasm3Parser::TimingLiteral:
            case qasm3Parser::BitstringLiteral: {
              setState(595);
              expression(0);
              break;
            }

            case qasm3Parser::LBRACE: {
              setState(596);
              arrayLiteral();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(603);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
      }
      setState(605);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::COMMA) {
        setState(604);
        match(qasm3Parser::COMMA);
      }
    }
    setState(609);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexOperatorContext ------------------------------------------------------------------

qasm3Parser::IndexOperatorContext::IndexOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

qasm3Parser::SetExpressionContext* qasm3Parser::IndexOperatorContext::setExpression() {
  return getRuleContext<qasm3Parser::SetExpressionContext>(0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::IndexOperatorContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::IndexOperatorContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::RangeExpressionContext *> qasm3Parser::IndexOperatorContext::rangeExpression() {
  return getRuleContexts<qasm3Parser::RangeExpressionContext>();
}

qasm3Parser::RangeExpressionContext* qasm3Parser::IndexOperatorContext::rangeExpression(size_t i) {
  return getRuleContext<qasm3Parser::RangeExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IndexOperatorContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IndexOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexOperator;
}


std::any qasm3Parser::IndexOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexOperatorContext* qasm3Parser::indexOperator() {
  IndexOperatorContext *_localctx = _tracker.createInstance<IndexOperatorContext>(_ctx, getState());
  enterRule(_localctx, 90, qasm3Parser::RuleIndexOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(611);
    match(qasm3Parser::LBRACKET);
    setState(630);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        setState(612);
        setExpression();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::COLON:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(615);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
        case 1: {
          setState(613);
          expression(0);
          break;
        }

        case 2: {
          setState(614);
          rangeExpression();
          break;
        }

        default:
          break;
        }
        setState(624);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(617);
            match(qasm3Parser::COMMA);
            setState(620);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
            case 1: {
              setState(618);
              expression(0);
              break;
            }

            case 2: {
              setState(619);
              rangeExpression();
              break;
            }

            default:
              break;
            } 
          }
          setState(626);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
        }
        setState(628);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::COMMA) {
          setState(627);
          match(qasm3Parser::COMMA);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(632);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexedIdentifierContext ------------------------------------------------------------------

qasm3Parser::IndexedIdentifierContext::IndexedIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexedIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

std::vector<qasm3Parser::IndexOperatorContext *> qasm3Parser::IndexedIdentifierContext::indexOperator() {
  return getRuleContexts<qasm3Parser::IndexOperatorContext>();
}

qasm3Parser::IndexOperatorContext* qasm3Parser::IndexedIdentifierContext::indexOperator(size_t i) {
  return getRuleContext<qasm3Parser::IndexOperatorContext>(i);
}


size_t qasm3Parser::IndexedIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexedIdentifier;
}


std::any qasm3Parser::IndexedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexedIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::indexedIdentifier() {
  IndexedIdentifierContext *_localctx = _tracker.createInstance<IndexedIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 92, qasm3Parser::RuleIndexedIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(qasm3Parser::Identifier);
    setState(638);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::LBRACKET) {
      setState(635);
      indexOperator();
      setState(640);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnSignatureContext ------------------------------------------------------------------

qasm3Parser::ReturnSignatureContext::ReturnSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ReturnSignatureContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ReturnSignatureContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}


size_t qasm3Parser::ReturnSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnSignature;
}


std::any qasm3Parser::ReturnSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitReturnSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::returnSignature() {
  ReturnSignatureContext *_localctx = _tracker.createInstance<ReturnSignatureContext>(_ctx, getState());
  enterRule(_localctx, 94, qasm3Parser::RuleReturnSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    match(qasm3Parser::ARROW);
    setState(642);
    scalarType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateModifierContext ------------------------------------------------------------------

qasm3Parser::GateModifierContext::GateModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateModifierContext::AT() {
  return getToken(qasm3Parser::AT, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::INV() {
  return getToken(qasm3Parser::INV, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::POW() {
  return getToken(qasm3Parser::POW, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::GateModifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::CTRL() {
  return getToken(qasm3Parser::CTRL, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::NEGCTRL() {
  return getToken(qasm3Parser::NEGCTRL, 0);
}


size_t qasm3Parser::GateModifierContext::getRuleIndex() const {
  return qasm3Parser::RuleGateModifier;
}


std::any qasm3Parser::GateModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateModifierContext* qasm3Parser::gateModifier() {
  GateModifierContext *_localctx = _tracker.createInstance<GateModifierContext>(_ctx, getState());
  enterRule(_localctx, 96, qasm3Parser::RuleGateModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(657);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INV: {
        setState(644);
        match(qasm3Parser::INV);
        break;
      }

      case qasm3Parser::POW: {
        setState(645);
        match(qasm3Parser::POW);
        setState(646);
        match(qasm3Parser::LPAREN);
        setState(647);
        expression(0);
        setState(648);
        match(qasm3Parser::RPAREN);
        break;
      }

      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL: {
        setState(650);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::CTRL

        || _la == qasm3Parser::NEGCTRL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(655);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LPAREN) {
          setState(651);
          match(qasm3Parser::LPAREN);
          setState(652);
          expression(0);
          setState(653);
          match(qasm3Parser::RPAREN);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(659);
    match(qasm3Parser::AT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeContext ------------------------------------------------------------------

qasm3Parser::ScalarTypeContext::ScalarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::BIT() {
  return getToken(qasm3Parser::BIT, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ScalarTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::INT() {
  return getToken(qasm3Parser::INT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::UINT() {
  return getToken(qasm3Parser::UINT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::FLOAT() {
  return getToken(qasm3Parser::FLOAT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::ANGLE() {
  return getToken(qasm3Parser::ANGLE, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::BOOL() {
  return getToken(qasm3Parser::BOOL, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::DURATION() {
  return getToken(qasm3Parser::DURATION, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::STRETCH() {
  return getToken(qasm3Parser::STRETCH, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::COMPLEX() {
  return getToken(qasm3Parser::COMPLEX, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ScalarTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ScalarTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleScalarType;
}


std::any qasm3Parser::ScalarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitScalarType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::scalarType() {
  ScalarTypeContext *_localctx = _tracker.createInstance<ScalarTypeContext>(_ctx, getState());
  enterRule(_localctx, 98, qasm3Parser::RuleScalarType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(691);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(661);
        match(qasm3Parser::BIT);
        setState(663);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(662);
          designator();
        }
        break;
      }

      case qasm3Parser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(665);
        match(qasm3Parser::INT);
        setState(667);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(666);
          designator();
        }
        break;
      }

      case qasm3Parser::UINT: {
        enterOuterAlt(_localctx, 3);
        setState(669);
        match(qasm3Parser::UINT);
        setState(671);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(670);
          designator();
        }
        break;
      }

      case qasm3Parser::FLOAT: {
        enterOuterAlt(_localctx, 4);
        setState(673);
        match(qasm3Parser::FLOAT);
        setState(675);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(674);
          designator();
        }
        break;
      }

      case qasm3Parser::ANGLE: {
        enterOuterAlt(_localctx, 5);
        setState(677);
        match(qasm3Parser::ANGLE);
        setState(679);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(678);
          designator();
        }
        break;
      }

      case qasm3Parser::BOOL: {
        enterOuterAlt(_localctx, 6);
        setState(681);
        match(qasm3Parser::BOOL);
        break;
      }

      case qasm3Parser::DURATION: {
        enterOuterAlt(_localctx, 7);
        setState(682);
        match(qasm3Parser::DURATION);
        break;
      }

      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 8);
        setState(683);
        match(qasm3Parser::STRETCH);
        break;
      }

      case qasm3Parser::COMPLEX: {
        enterOuterAlt(_localctx, 9);
        setState(684);
        match(qasm3Parser::COMPLEX);
        setState(689);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(685);
          match(qasm3Parser::LBRACKET);
          setState(686);
          scalarType();
          setState(687);
          match(qasm3Parser::RBRACKET);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QubitTypeContext ------------------------------------------------------------------

qasm3Parser::QubitTypeContext::QubitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QubitTypeContext::QUBIT() {
  return getToken(qasm3Parser::QUBIT, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QubitTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::QubitTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleQubitType;
}


std::any qasm3Parser::QubitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQubitType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QubitTypeContext* qasm3Parser::qubitType() {
  QubitTypeContext *_localctx = _tracker.createInstance<QubitTypeContext>(_ctx, getState());
  enterRule(_localctx, 100, qasm3Parser::RuleQubitType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(693);
    match(qasm3Parser::QUBIT);
    setState(695);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(694);
      designator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

qasm3Parser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::ARRAY() {
  return getToken(qasm3Parser::ARRAY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArrayTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::ArrayTypeContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ArrayTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayType;
}


std::any qasm3Parser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 102, qasm3Parser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(697);
    match(qasm3Parser::ARRAY);
    setState(698);
    match(qasm3Parser::LBRACKET);
    setState(699);
    scalarType();
    setState(700);
    match(qasm3Parser::COMMA);
    setState(701);
    expressionList();
    setState(702);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReferenceTypeContext ------------------------------------------------------------------

qasm3Parser::ArrayReferenceTypeContext::ArrayReferenceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::ARRAY() {
  return getToken(qasm3Parser::ARRAY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArrayReferenceTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::READONLY() {
  return getToken(qasm3Parser::READONLY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::MUTABLE() {
  return getToken(qasm3Parser::MUTABLE, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::ArrayReferenceTypeContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::DIM() {
  return getToken(qasm3Parser::DIM, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayReferenceTypeContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ArrayReferenceTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayReferenceType;
}


std::any qasm3Parser::ArrayReferenceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayReferenceType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::arrayReferenceType() {
  ArrayReferenceTypeContext *_localctx = _tracker.createInstance<ArrayReferenceTypeContext>(_ctx, getState());
  enterRule(_localctx, 104, qasm3Parser::RuleArrayReferenceType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(704);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::READONLY

    || _la == qasm3Parser::MUTABLE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(705);
    match(qasm3Parser::ARRAY);
    setState(706);
    match(qasm3Parser::LBRACKET);
    setState(707);
    scalarType();
    setState(708);
    match(qasm3Parser::COMMA);
    setState(713);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(709);
        expressionList();
        break;
      }

      case qasm3Parser::DIM: {
        setState(710);
        match(qasm3Parser::DIM);
        setState(711);
        match(qasm3Parser::EQUALS);
        setState(712);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(715);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

qasm3Parser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DesignatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::DesignatorContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::DesignatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::DesignatorContext::getRuleIndex() const {
  return qasm3Parser::RuleDesignator;
}


std::any qasm3Parser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DesignatorContext* qasm3Parser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 106, qasm3Parser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    match(qasm3Parser::LBRACKET);
    setState(718);
    expression(0);
    setState(719);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalTargetContext ------------------------------------------------------------------

qasm3Parser::DefcalTargetContext::DefcalTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::MEASURE() {
  return getToken(qasm3Parser::MEASURE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::RESET() {
  return getToken(qasm3Parser::RESET, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::DELAY() {
  return getToken(qasm3Parser::DELAY, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::DefcalTargetContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalTarget;
}


std::any qasm3Parser::DefcalTargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalTarget(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalTargetContext* qasm3Parser::defcalTarget() {
  DefcalTargetContext *_localctx = _tracker.createInstance<DefcalTargetContext>(_ctx, getState());
  enterRule(_localctx, 108, qasm3Parser::RuleDefcalTarget);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(721);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & 4398046511111) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalArgumentDefinitionContext ------------------------------------------------------------------

qasm3Parser::DefcalArgumentDefinitionContext::DefcalArgumentDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionContext* qasm3Parser::DefcalArgumentDefinitionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::DefcalArgumentDefinitionContext::argumentDefinition() {
  return getRuleContext<qasm3Parser::ArgumentDefinitionContext>(0);
}


size_t qasm3Parser::DefcalArgumentDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalArgumentDefinition;
}


std::any qasm3Parser::DefcalArgumentDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalArgumentDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalArgumentDefinitionContext* qasm3Parser::defcalArgumentDefinition() {
  DefcalArgumentDefinitionContext *_localctx = _tracker.createInstance<DefcalArgumentDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 110, qasm3Parser::RuleDefcalArgumentDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(725);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(723);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(724);
      argumentDefinition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalOperandContext ------------------------------------------------------------------

qasm3Parser::DefcalOperandContext::DefcalOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalOperandContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}

tree::TerminalNode* qasm3Parser::DefcalOperandContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::DefcalOperandContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalOperand;
}


std::any qasm3Parser::DefcalOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalOperand(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalOperandContext* qasm3Parser::defcalOperand() {
  DefcalOperandContext *_localctx = _tracker.createInstance<DefcalOperandContext>(_ctx, getState());
  enterRule(_localctx, 112, qasm3Parser::RuleDefcalOperand);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(727);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateOperandContext ------------------------------------------------------------------

qasm3Parser::GateOperandContext::GateOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::GateOperandContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::GateOperandContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}


size_t qasm3Parser::GateOperandContext::getRuleIndex() const {
  return qasm3Parser::RuleGateOperand;
}


std::any qasm3Parser::GateOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateOperand(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateOperandContext* qasm3Parser::gateOperand() {
  GateOperandContext *_localctx = _tracker.createInstance<GateOperandContext>(_ctx, getState());
  enterRule(_localctx, 114, qasm3Parser::RuleGateOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(731);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(729);
        indexedIdentifier();
        break;
      }

      case qasm3Parser::HardwareQubit: {
        enterOuterAlt(_localctx, 2);
        setState(730);
        match(qasm3Parser::HardwareQubit);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternArgumentContext ------------------------------------------------------------------

qasm3Parser::ExternArgumentContext::ExternArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ExternArgumentContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::ExternArgumentContext::arrayReferenceType() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ExternArgumentContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ExternArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::ExternArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleExternArgument;
}


std::any qasm3Parser::ExternArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternArgumentContext* qasm3Parser::externArgument() {
  ExternArgumentContext *_localctx = _tracker.createInstance<ExternArgumentContext>(_ctx, getState());
  enterRule(_localctx, 116, qasm3Parser::RuleExternArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(739);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 1);
        setState(733);
        scalarType();
        break;
      }

      case qasm3Parser::READONLY:
      case qasm3Parser::MUTABLE: {
        enterOuterAlt(_localctx, 2);
        setState(734);
        arrayReferenceType();
        break;
      }

      case qasm3Parser::CREG: {
        enterOuterAlt(_localctx, 3);
        setState(735);
        match(qasm3Parser::CREG);
        setState(737);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(736);
          designator();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentDefinitionContext ------------------------------------------------------------------

qasm3Parser::ArgumentDefinitionContext::ArgumentDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArgumentDefinitionContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QubitTypeContext* qasm3Parser::ArgumentDefinitionContext::qubitType() {
  return getRuleContext<qasm3Parser::QubitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ArgumentDefinitionContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::ArgumentDefinitionContext::arrayReferenceType() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeContext>(0);
}


size_t qasm3Parser::ArgumentDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleArgumentDefinition;
}


std::any qasm3Parser::ArgumentDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArgumentDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::argumentDefinition() {
  ArgumentDefinitionContext *_localctx = _tracker.createInstance<ArgumentDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 118, qasm3Parser::RuleArgumentDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(755);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 1);
        setState(741);
        scalarType();
        setState(742);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 2);
        setState(744);
        qubitType();
        setState(745);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::QREG:
      case qasm3Parser::CREG: {
        enterOuterAlt(_localctx, 3);
        setState(747);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::QREG

        || _la == qasm3Parser::CREG)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(748);
        match(qasm3Parser::Identifier);
        setState(750);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(749);
          designator();
        }
        break;
      }

      case qasm3Parser::READONLY:
      case qasm3Parser::MUTABLE: {
        enterOuterAlt(_localctx, 4);
        setState(752);
        arrayReferenceType();
        setState(753);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentDefinitionListContext ------------------------------------------------------------------

qasm3Parser::ArgumentDefinitionListContext::ArgumentDefinitionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ArgumentDefinitionContext *> qasm3Parser::ArgumentDefinitionListContext::argumentDefinition() {
  return getRuleContexts<qasm3Parser::ArgumentDefinitionContext>();
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::ArgumentDefinitionListContext::argumentDefinition(size_t i) {
  return getRuleContext<qasm3Parser::ArgumentDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ArgumentDefinitionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ArgumentDefinitionListContext::getRuleIndex() const {
  return qasm3Parser::RuleArgumentDefinitionList;
}


std::any qasm3Parser::ArgumentDefinitionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArgumentDefinitionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArgumentDefinitionListContext* qasm3Parser::argumentDefinitionList() {
  ArgumentDefinitionListContext *_localctx = _tracker.createInstance<ArgumentDefinitionListContext>(_ctx, getState());
  enterRule(_localctx, 120, qasm3Parser::RuleArgumentDefinitionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(757);
    argumentDefinition();
    setState(762);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(758);
        match(qasm3Parser::COMMA);
        setState(759);
        argumentDefinition(); 
      }
      setState(764);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
    setState(766);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(765);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalArgumentDefinitionListContext ------------------------------------------------------------------

qasm3Parser::DefcalArgumentDefinitionListContext::DefcalArgumentDefinitionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::DefcalArgumentDefinitionContext *> qasm3Parser::DefcalArgumentDefinitionListContext::defcalArgumentDefinition() {
  return getRuleContexts<qasm3Parser::DefcalArgumentDefinitionContext>();
}

qasm3Parser::DefcalArgumentDefinitionContext* qasm3Parser::DefcalArgumentDefinitionListContext::defcalArgumentDefinition(size_t i) {
  return getRuleContext<qasm3Parser::DefcalArgumentDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::DefcalArgumentDefinitionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::DefcalArgumentDefinitionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::DefcalArgumentDefinitionListContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalArgumentDefinitionList;
}


std::any qasm3Parser::DefcalArgumentDefinitionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalArgumentDefinitionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalArgumentDefinitionListContext* qasm3Parser::defcalArgumentDefinitionList() {
  DefcalArgumentDefinitionListContext *_localctx = _tracker.createInstance<DefcalArgumentDefinitionListContext>(_ctx, getState());
  enterRule(_localctx, 122, qasm3Parser::RuleDefcalArgumentDefinitionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(768);
    defcalArgumentDefinition();
    setState(773);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(769);
        match(qasm3Parser::COMMA);
        setState(770);
        defcalArgumentDefinition(); 
      }
      setState(775);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    }
    setState(777);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(776);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalOperandListContext ------------------------------------------------------------------

qasm3Parser::DefcalOperandListContext::DefcalOperandListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::DefcalOperandContext *> qasm3Parser::DefcalOperandListContext::defcalOperand() {
  return getRuleContexts<qasm3Parser::DefcalOperandContext>();
}

qasm3Parser::DefcalOperandContext* qasm3Parser::DefcalOperandListContext::defcalOperand(size_t i) {
  return getRuleContext<qasm3Parser::DefcalOperandContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::DefcalOperandListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::DefcalOperandListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::DefcalOperandListContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalOperandList;
}


std::any qasm3Parser::DefcalOperandListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalOperandList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalOperandListContext* qasm3Parser::defcalOperandList() {
  DefcalOperandListContext *_localctx = _tracker.createInstance<DefcalOperandListContext>(_ctx, getState());
  enterRule(_localctx, 124, qasm3Parser::RuleDefcalOperandList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(779);
    defcalOperand();
    setState(784);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(780);
        match(qasm3Parser::COMMA);
        setState(781);
        defcalOperand(); 
      }
      setState(786);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    }
    setState(788);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(787);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

qasm3Parser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ExpressionListContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ExpressionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ExpressionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ExpressionListContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionList;
}


std::any qasm3Parser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionListContext* qasm3Parser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 126, qasm3Parser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(790);
    expression(0);
    setState(795);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(791);
        match(qasm3Parser::COMMA);
        setState(792);
        expression(0); 
      }
      setState(797);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
    }
    setState(799);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(798);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

qasm3Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::Identifier() {
  return getTokens(qasm3Parser::Identifier);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::Identifier(size_t i) {
  return getToken(qasm3Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IdentifierListContext::getRuleIndex() const {
  return qasm3Parser::RuleIdentifierList;
}


std::any qasm3Parser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IdentifierListContext* qasm3Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 128, qasm3Parser::RuleIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(801);
    match(qasm3Parser::Identifier);
    setState(806);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(802);
        match(qasm3Parser::COMMA);
        setState(803);
        match(qasm3Parser::Identifier); 
      }
      setState(808);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    }
    setState(810);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(809);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateOperandListContext ------------------------------------------------------------------

qasm3Parser::GateOperandListContext::GateOperandListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::GateOperandContext *> qasm3Parser::GateOperandListContext::gateOperand() {
  return getRuleContexts<qasm3Parser::GateOperandContext>();
}

qasm3Parser::GateOperandContext* qasm3Parser::GateOperandListContext::gateOperand(size_t i) {
  return getRuleContext<qasm3Parser::GateOperandContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::GateOperandListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::GateOperandListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::GateOperandListContext::getRuleIndex() const {
  return qasm3Parser::RuleGateOperandList;
}


std::any qasm3Parser::GateOperandListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateOperandList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateOperandListContext* qasm3Parser::gateOperandList() {
  GateOperandListContext *_localctx = _tracker.createInstance<GateOperandListContext>(_ctx, getState());
  enterRule(_localctx, 130, qasm3Parser::RuleGateOperandList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(812);
    gateOperand();
    setState(817);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(813);
        match(qasm3Parser::COMMA);
        setState(814);
        gateOperand(); 
      }
      setState(819);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    }
    setState(821);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(820);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternArgumentListContext ------------------------------------------------------------------

qasm3Parser::ExternArgumentListContext::ExternArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExternArgumentContext *> qasm3Parser::ExternArgumentListContext::externArgument() {
  return getRuleContexts<qasm3Parser::ExternArgumentContext>();
}

qasm3Parser::ExternArgumentContext* qasm3Parser::ExternArgumentListContext::externArgument(size_t i) {
  return getRuleContext<qasm3Parser::ExternArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ExternArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ExternArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ExternArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleExternArgumentList;
}


std::any qasm3Parser::ExternArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternArgumentListContext* qasm3Parser::externArgumentList() {
  ExternArgumentListContext *_localctx = _tracker.createInstance<ExternArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 132, qasm3Parser::RuleExternArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(823);
    externArgument();
    setState(828);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(824);
        match(qasm3Parser::COMMA);
        setState(825);
        externArgument(); 
      }
      setState(830);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
    }
    setState(832);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(831);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool qasm3Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 38: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 16);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 17);

  default:
    break;
  }
  return true;
}

void qasm3Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  qasm3parserParserInitialize();
#else
  ::antlr4::internal::call_once(qasm3parserParserOnceFlag, qasm3parserParserInitialize);
#endif
}
