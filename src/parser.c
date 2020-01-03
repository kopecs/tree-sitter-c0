#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 10
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 85
#define ALIAS_COUNT 0
#define TOKEN_COUNT 82
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3

enum {
  anon_sym_int = 1,
  anon_sym_bool = 2,
  anon_sym_string = 3,
  anon_sym_char = 4,
  anon_sym_void = 5,
  anon_sym_STAR = 6,
  anon_sym_LBRACK = 7,
  anon_sym_RBRACK = 8,
  anon_sym_struct = 9,
  sym_id = 10,
  anon_sym_0 = 11,
  aux_sym_decnum_token1 = 12,
  anon_sym_DQUOTE = 13,
  anon_sym_SQUOTE = 14,
  anon_sym_LT = 15,
  anon_sym_GT = 16,
  anon_sym_BSLASH0 = 17,
  anon_sym_BSLASHn = 18,
  anon_sym_BSLASHt = 19,
  anon_sym_BSLASHv = 20,
  anon_sym_BSLASHb = 21,
  anon_sym_BSLASHr = 22,
  anon_sym_BSLASHa = 23,
  anon_sym_BSLASH_BSLASH = 24,
  anon_sym_BSLASH_SQUOTE = 25,
  anon_sym_BSLASH_DQUOTE = 26,
  anon_sym_LPAREN = 27,
  anon_sym_RPAREN = 28,
  anon_sym_LBRACE = 29,
  anon_sym_RBRACE = 30,
  anon_sym_COMMA = 31,
  anon_sym_SEMI = 32,
  anon_sym_BANG = 33,
  anon_sym_TILDE = 34,
  anon_sym_DASH = 35,
  anon_sym_DOT = 36,
  anon_sym_DASH_GT = 37,
  anon_sym_SLASH = 38,
  anon_sym_PERCENT = 39,
  anon_sym_PLUS = 40,
  anon_sym_GT_GT = 41,
  anon_sym_GT_EQ = 42,
  anon_sym_EQ_EQ = 43,
  anon_sym_BANG_EQ = 44,
  anon_sym_AMP = 45,
  anon_sym_CARET = 46,
  anon_sym_PIPE = 47,
  anon_sym_AMP_AMP = 48,
  anon_sym_PIPE_PIPE = 49,
  anon_sym_EQ = 50,
  anon_sym_PLUS_EQ = 51,
  anon_sym_DASH_EQ = 52,
  anon_sym_STAR_EQ = 53,
  anon_sym_SLASH_EQ = 54,
  anon_sym_PERCENT_EQ = 55,
  anon_sym_AMP_EQ = 56,
  anon_sym_CARET_EQ = 57,
  anon_sym_PIPE_EQ = 58,
  anon_sym_GT_GT_EQ = 59,
  anon_sym_PLUS_PLUS = 60,
  anon_sym_POUNDuse = 61,
  anon_sym_typedef = 62,
  anon_sym_if = 63,
  anon_sym_else = 64,
  anon_sym_while = 65,
  anon_sym_for = 66,
  anon_sym_return = 67,
  anon_sym_assert = 68,
  anon_sym_error = 69,
  anon_sym_true = 70,
  anon_sym_false = 71,
  anon_sym_NULL = 72,
  anon_sym_QMARK = 73,
  anon_sym_COLON = 74,
  anon_sym_alloc = 75,
  anon_sym_alloc_array = 76,
  anon_sym_BSLASHlength = 77,
  anon_sym_requires = 78,
  anon_sym_ensures = 79,
  anon_sym_loop_invariant = 80,
  anon_sym_SLASH_SLASH_AT = 81,
  sym_tp = 82,
  sym_sid = 83,
  sym_aid = 84,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_int] = "int",
  [anon_sym_bool] = "bool",
  [anon_sym_string] = "string",
  [anon_sym_char] = "char",
  [anon_sym_void] = "void",
  [anon_sym_STAR] = "*",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_struct] = "struct",
  [sym_id] = "id",
  [anon_sym_0] = "0",
  [aux_sym_decnum_token1] = "decnum_token1",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_BSLASH0] = "\\0",
  [anon_sym_BSLASHn] = "\\n",
  [anon_sym_BSLASHt] = "\\t",
  [anon_sym_BSLASHv] = "\\v",
  [anon_sym_BSLASHb] = "\\b",
  [anon_sym_BSLASHr] = "\\r",
  [anon_sym_BSLASHa] = "\\a",
  [anon_sym_BSLASH_BSLASH] = "\\\\",
  [anon_sym_BSLASH_SQUOTE] = "\\'",
  [anon_sym_BSLASH_DQUOTE] = "\\\"",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COMMA] = ",",
  [anon_sym_SEMI] = ";",
  [anon_sym_BANG] = "!",
  [anon_sym_TILDE] = "~",
  [anon_sym_DASH] = "-",
  [anon_sym_DOT] = ".",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PLUS] = "+",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_AMP] = "&",
  [anon_sym_CARET] = "^",
  [anon_sym_PIPE] = "|",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_EQ] = "=",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_AMP_EQ] = "&=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_GT_GT_EQ] = ">>=",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_POUNDuse] = "#use",
  [anon_sym_typedef] = "typedef",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_while] = "while",
  [anon_sym_for] = "for",
  [anon_sym_return] = "return",
  [anon_sym_assert] = "assert",
  [anon_sym_error] = "error",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_NULL] = "NULL",
  [anon_sym_QMARK] = "?",
  [anon_sym_COLON] = ":",
  [anon_sym_alloc] = "alloc",
  [anon_sym_alloc_array] = "alloc_array",
  [anon_sym_BSLASHlength] = "\\length",
  [anon_sym_requires] = "requires",
  [anon_sym_ensures] = "ensures",
  [anon_sym_loop_invariant] = "loop_invariant",
  [anon_sym_SLASH_SLASH_AT] = "//@",
  [sym_tp] = "tp",
  [sym_sid] = "sid",
  [sym_aid] = "aid",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_struct] = anon_sym_struct,
  [sym_id] = sym_id,
  [anon_sym_0] = anon_sym_0,
  [aux_sym_decnum_token1] = aux_sym_decnum_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_BSLASH0] = anon_sym_BSLASH0,
  [anon_sym_BSLASHn] = anon_sym_BSLASHn,
  [anon_sym_BSLASHt] = anon_sym_BSLASHt,
  [anon_sym_BSLASHv] = anon_sym_BSLASHv,
  [anon_sym_BSLASHb] = anon_sym_BSLASHb,
  [anon_sym_BSLASHr] = anon_sym_BSLASHr,
  [anon_sym_BSLASHa] = anon_sym_BSLASHa,
  [anon_sym_BSLASH_BSLASH] = anon_sym_BSLASH_BSLASH,
  [anon_sym_BSLASH_SQUOTE] = anon_sym_BSLASH_SQUOTE,
  [anon_sym_BSLASH_DQUOTE] = anon_sym_BSLASH_DQUOTE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_AMP_EQ] = anon_sym_AMP_EQ,
  [anon_sym_CARET_EQ] = anon_sym_CARET_EQ,
  [anon_sym_PIPE_EQ] = anon_sym_PIPE_EQ,
  [anon_sym_GT_GT_EQ] = anon_sym_GT_GT_EQ,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_POUNDuse] = anon_sym_POUNDuse,
  [anon_sym_typedef] = anon_sym_typedef,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_assert] = anon_sym_assert,
  [anon_sym_error] = anon_sym_error,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_NULL] = anon_sym_NULL,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_alloc] = anon_sym_alloc,
  [anon_sym_alloc_array] = anon_sym_alloc_array,
  [anon_sym_BSLASHlength] = anon_sym_BSLASHlength,
  [anon_sym_requires] = anon_sym_requires,
  [anon_sym_ensures] = anon_sym_ensures,
  [anon_sym_loop_invariant] = anon_sym_loop_invariant,
  [anon_sym_SLASH_SLASH_AT] = anon_sym_SLASH_SLASH_AT,
  [sym_tp] = sym_tp,
  [sym_sid] = sym_sid,
  [sym_aid] = sym_aid,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_0] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_decnum_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH0] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHv] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHa] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDuse] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_typedef] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_assert] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_error] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alloc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alloc_array] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHlength] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_requires] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ensures] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loop_invariant] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SLASH_AT] = {
    .visible = true,
    .named = false,
  },
  [sym_tp] = {
    .visible = true,
    .named = true,
  },
  [sym_sid] = {
    .visible = true,
    .named = true,
  },
  [sym_aid] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(98);
      if (lookahead == '!') ADVANCE(156);
      if (lookahead == '"') ADVANCE(136);
      if (lookahead == '#') ADVANCE(89);
      if (lookahead == '%') ADVANCE(162);
      if (lookahead == '&') ADVANCE(168);
      if (lookahead == '\'') ADVANCE(137);
      if (lookahead == '(') ADVANCE(150);
      if (lookahead == ')') ADVANCE(151);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead == '+') ADVANCE(163);
      if (lookahead == ',') ADVANCE(154);
      if (lookahead == '-') ADVANCE(158);
      if (lookahead == '.') ADVANCE(159);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '0') ADVANCE(134);
      if (lookahead == ':') ADVANCE(197);
      if (lookahead == ';') ADVANCE(155);
      if (lookahead == '<') ADVANCE(138);
      if (lookahead == '=') ADVANCE(173);
      if (lookahead == '>') ADVANCE(139);
      if (lookahead == '?') ADVANCE(196);
      if (lookahead == 'N') ADVANCE(5);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == ']') ADVANCE(112);
      if (lookahead == '^') ADVANCE(169);
      if (lookahead == 'a') ADVANCE(42);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'c') ADVANCE(33);
      if (lookahead == 'e') ADVANCE(46);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(58);
      if (lookahead == 'r') ADVANCE(17);
      if (lookahead == 's') ADVANCE(88);
      if (lookahead == 't') ADVANCE(67);
      if (lookahead == 'v') ADVANCE(53);
      if (lookahead == 'w') ADVANCE(35);
      if (lookahead == '{') ADVANCE(152);
      if (lookahead == '|') ADVANCE(170);
      if (lookahead == '}') ADVANCE(153);
      if (lookahead == '~') ADVANCE(157);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(149);
      if (lookahead == '\'') ADVANCE(148);
      if (lookahead == '0') ADVANCE(140);
      if (lookahead == '\\') ADVANCE(147);
      if (lookahead == 'a') ADVANCE(146);
      if (lookahead == 'b') ADVANCE(144);
      if (lookahead == 'l') ADVANCE(18);
      if (lookahead == 'n') ADVANCE(141);
      if (lookahead == 'r') ADVANCE(145);
      if (lookahead == 't') ADVANCE(142);
      if (lookahead == 'v') ADVANCE(143);
      END_STATE();
    case 2:
      if (lookahead == '@') ADVANCE(204);
      END_STATE();
    case 3:
      if (lookahead == 'L') ADVANCE(195);
      END_STATE();
    case 4:
      if (lookahead == 'L') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == 'U') ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(38);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(47);
      if (lookahead == 'o') ADVANCE(63);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(65);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(74);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(71);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(198);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 15:
      if (lookahead == 'd') ADVANCE(107);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(24);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(184);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(187);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(193);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(194);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(188);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 29:
      if (lookahead == 'f') ADVANCE(186);
      if (lookahead == 'n') ADVANCE(83);
      END_STATE();
    case 30:
      if (lookahead == 'f') ADVANCE(185);
      END_STATE();
    case 31:
      if (lookahead == 'g') ADVANCE(103);
      END_STATE();
    case 32:
      if (lookahead == 'g') ADVANCE(87);
      END_STATE();
    case 33:
      if (lookahead == 'h') ADVANCE(9);
      END_STATE();
    case 34:
      if (lookahead == 'h') ADVANCE(200);
      END_STATE();
    case 35:
      if (lookahead == 'h') ADVANCE(39);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(15);
      END_STATE();
    case 37:
      if (lookahead == 'i') ADVANCE(10);
      END_STATE();
    case 38:
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 39:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 40:
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(14);
      END_STATE();
    case 41:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 42:
      if (lookahead == 'l') ADVANCE(44);
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 43:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 44:
      if (lookahead == 'l') ADVANCE(54);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(23);
      END_STATE();
    case 46:
      if (lookahead == 'l') ADVANCE(81);
      if (lookahead == 'n') ADVANCE(78);
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 47:
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(190);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(94);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 53:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 54:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 55:
      if (lookahead == 'o') ADVANCE(60);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 57:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 58:
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 59:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 60:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 61:
      if (lookahead == 'p') ADVANCE(25);
      END_STATE();
    case 62:
      if (lookahead == 'q') ADVANCE(90);
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(189);
      END_STATE();
    case 64:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(105);
      END_STATE();
    case 66:
      if (lookahead == 'r') ADVANCE(192);
      END_STATE();
    case 67:
      if (lookahead == 'r') ADVANCE(91);
      if (lookahead == 'y') ADVANCE(61);
      END_STATE();
    case 68:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 69:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 70:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 71:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 72:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 73:
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(68);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 76:
      if (lookahead == 's') ADVANCE(202);
      END_STATE();
    case 77:
      if (lookahead == 's') ADVANCE(201);
      END_STATE();
    case 78:
      if (lookahead == 's') ADVANCE(92);
      END_STATE();
    case 79:
      if (lookahead == 's') ADVANCE(19);
      END_STATE();
    case 80:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 81:
      if (lookahead == 's') ADVANCE(20);
      END_STATE();
    case 82:
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 83:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 84:
      if (lookahead == 't') ADVANCE(191);
      END_STATE();
    case 85:
      if (lookahead == 't') ADVANCE(113);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(203);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 89:
      if (lookahead == 'u') ADVANCE(79);
      END_STATE();
    case 90:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 91:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 92:
      if (lookahead == 'u') ADVANCE(73);
      END_STATE();
    case 93:
      if (lookahead == 'u') ADVANCE(69);
      END_STATE();
    case 94:
      if (lookahead == 'v') ADVANCE(12);
      END_STATE();
    case 95:
      if (lookahead == 'y') ADVANCE(199);
      END_STATE();
    case 96:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(96)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 97:
      if (eof) ADVANCE(98);
      if (lookahead == '*') ADVANCE(109);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(127);
      if (lookahead == 'c') ADVANCE(119);
      if (lookahead == 'i') ADVANCE(124);
      if (lookahead == 's') ADVANCE(130);
      if (lookahead == 'v') ADVANCE(125);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(97)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_bool);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_string);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_char);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_void);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=') ADVANCE(176);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_struct);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'a') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'c') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'd') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'g') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'h') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'i') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'i') ADVANCE(123);
      if (lookahead == 'u') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'l') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'n') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'n') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'o') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'o') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'o') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'r') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'r') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 't') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 't') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 't') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_id);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_0);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_decnum_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(165);
      if (lookahead == '>') ADVANCE(164);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_BSLASHv);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_BSLASHb);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_BSLASHa);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(167);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(175);
      if (lookahead == '>') ADVANCE(160);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(2);
      if (lookahead == '=') ADVANCE(177);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '=') ADVANCE(178);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(183);
      if (lookahead == '=') ADVANCE(174);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      if (lookahead == '=') ADVANCE(182);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(171);
      if (lookahead == '=') ADVANCE(179);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '=') ADVANCE(180);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '=') ADVANCE(181);
      if (lookahead == '|') ADVANCE(172);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(166);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_AMP_EQ);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_GT_GT_EQ);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_POUNDuse);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_typedef);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_assert);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_error);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_alloc);
      if (lookahead == '_') ADVANCE(11);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_alloc_array);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_BSLASHlength);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_requires);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_ensures);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_loop_invariant);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH_AT);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 97},
  [2] = {.lex_state = 97},
  [3] = {.lex_state = 97},
  [4] = {.lex_state = 97},
  [5] = {.lex_state = 97},
  [6] = {.lex_state = 97},
  [7] = {.lex_state = 97},
  [8] = {.lex_state = 96},
  [9] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [aux_sym_decnum_token1] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_BSLASH0] = ACTIONS(1),
    [anon_sym_BSLASHn] = ACTIONS(1),
    [anon_sym_BSLASHt] = ACTIONS(1),
    [anon_sym_BSLASHv] = ACTIONS(1),
    [anon_sym_BSLASHb] = ACTIONS(1),
    [anon_sym_BSLASHr] = ACTIONS(1),
    [anon_sym_BSLASHa] = ACTIONS(1),
    [anon_sym_BSLASH_BSLASH] = ACTIONS(1),
    [anon_sym_BSLASH_SQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH_DQUOTE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_AMP_EQ] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [anon_sym_GT_GT_EQ] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_POUNDuse] = ACTIONS(1),
    [anon_sym_typedef] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_assert] = ACTIONS(1),
    [anon_sym_error] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_alloc] = ACTIONS(1),
    [anon_sym_alloc_array] = ACTIONS(1),
    [anon_sym_BSLASHlength] = ACTIONS(1),
    [anon_sym_requires] = ACTIONS(1),
    [anon_sym_ensures] = ACTIONS(1),
    [anon_sym_loop_invariant] = ACTIONS(1),
    [anon_sym_SLASH_SLASH_AT] = ACTIONS(1),
  },
  [1] = {
    [sym_tp] = STATE(4),
    [sym_aid] = STATE(2),
    [anon_sym_int] = ACTIONS(3),
    [anon_sym_bool] = ACTIONS(3),
    [anon_sym_string] = ACTIONS(3),
    [anon_sym_char] = ACTIONS(3),
    [anon_sym_void] = ACTIONS(3),
    [anon_sym_struct] = ACTIONS(5),
    [sym_id] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(9), 3,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_LBRACK,
  [6] = 1,
    ACTIONS(11), 3,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_LBRACK,
  [12] = 3,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      anon_sym_STAR,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
  [22] = 1,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_LBRACK,
  [28] = 1,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_LBRACK,
  [34] = 1,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_LBRACK,
  [40] = 2,
    ACTIONS(25), 1,
      sym_id,
    STATE(6), 1,
      sym_sid,
  [47] = 1,
    ACTIONS(27), 1,
      anon_sym_RBRACK,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 6,
  [SMALL_STATE(4)] = 12,
  [SMALL_STATE(5)] = 22,
  [SMALL_STATE(6)] = 28,
  [SMALL_STATE(7)] = 34,
  [SMALL_STATE(8)] = 40,
  [SMALL_STATE(9)] = 47,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = false}, SHIFT(2),
  [5] = {.count = 1, .reusable = false}, SHIFT(8),
  [7] = {.count = 1, .reusable = false}, SHIFT(3),
  [9] = {.count = 1, .reusable = true}, REDUCE(sym_tp, 1),
  [11] = {.count = 1, .reusable = true}, REDUCE(sym_aid, 1),
  [13] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [15] = {.count = 1, .reusable = true}, SHIFT(6),
  [17] = {.count = 1, .reusable = true}, SHIFT(9),
  [19] = {.count = 1, .reusable = true}, REDUCE(sym_sid, 1),
  [21] = {.count = 1, .reusable = true}, REDUCE(sym_tp, 2),
  [23] = {.count = 1, .reusable = true}, REDUCE(sym_tp, 3),
  [25] = {.count = 1, .reusable = true}, SHIFT(5),
  [27] = {.count = 1, .reusable = true}, SHIFT(7),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_C0(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
