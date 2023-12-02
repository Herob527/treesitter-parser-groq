#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 29
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 23
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  sym_array_identifier = 1,
  sym_variable_identifier = 2,
  sym_normal_identifier = 3,
  sym_operator = 4,
  sym_every = 5,
  sym_string = 6,
  anon_sym_COLON = 7,
  anon_sym_LBRACE = 8,
  anon_sym_COMMA = 9,
  anon_sym_RBRACE = 10,
  anon_sym_ = 11,
  anon_sym_LBRACK = 12,
  anon_sym_RBRACK = 13,
  sym_query = 14,
  sym_pair = 15,
  sym_object = 16,
  sym_expression_identifier = 17,
  sym_expression_element = 18,
  sym_expression = 19,
  aux_sym_query_repeat1 = 20,
  aux_sym_object_repeat1 = 21,
  aux_sym_expression_repeat1 = 22,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_array_identifier] = "array_identifier",
  [sym_variable_identifier] = "variable_identifier",
  [sym_normal_identifier] = "normal_identifier",
  [sym_operator] = "operator",
  [sym_every] = "every",
  [sym_string] = "string",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACE] = "{",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACE] = "}",
  [anon_sym_] = "",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_query] = "query",
  [sym_pair] = "pair",
  [sym_object] = "object",
  [sym_expression_identifier] = "expression_identifier",
  [sym_expression_element] = "expression_element",
  [sym_expression] = "expression",
  [aux_sym_query_repeat1] = "query_repeat1",
  [aux_sym_object_repeat1] = "object_repeat1",
  [aux_sym_expression_repeat1] = "expression_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_array_identifier] = sym_array_identifier,
  [sym_variable_identifier] = sym_variable_identifier,
  [sym_normal_identifier] = sym_normal_identifier,
  [sym_operator] = sym_operator,
  [sym_every] = sym_every,
  [sym_string] = sym_string,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_] = anon_sym_,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_query] = sym_query,
  [sym_pair] = sym_pair,
  [sym_object] = sym_object,
  [sym_expression_identifier] = sym_expression_identifier,
  [sym_expression_element] = sym_expression_element,
  [sym_expression] = sym_expression,
  [aux_sym_query_repeat1] = aux_sym_query_repeat1,
  [aux_sym_object_repeat1] = aux_sym_object_repeat1,
  [aux_sym_expression_repeat1] = aux_sym_expression_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_array_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_normal_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_every] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
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
  [sym_query] = {
    .visible = true,
    .named = true,
  },
  [sym_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_object] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_element] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_query_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_object_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_key = 1,
  field_value = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 0},
    {field_value, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '!') ADVANCE(5);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '$') ADVANCE(15);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '*') ADVANCE(34);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == ':') ADVANCE(36);
      if (lookahead == '=') ADVANCE(5);
      if (lookahead == '[') ADVANCE(41);
      if (lookahead == ']') ADVANCE(42);
      if (lookahead == 'm') ADVANCE(21);
      if (lookahead == '{') ADVANCE(37);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(5);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '=') ADVANCE(5);
      if (lookahead == '[') ADVANCE(6);
      if (lookahead == 'm') ADVANCE(8);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '&') ADVANCE(33);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(34);
      if (lookahead == ']') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(33);
      END_STATE();
    case 6:
      if (lookahead == ']') ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == ']') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'c') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(9);
      END_STATE();
    case 14:
      if (lookahead == '|') ADVANCE(33);
      END_STATE();
    case 15:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 16:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_array_identifier);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_variable_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_variable_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 'a') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 'c') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 'e') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 'h') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 's') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == 't') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '[') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (lookahead == '.') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_normal_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_operator);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_every);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == ']') ADVANCE(33);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 40},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_array_identifier] = ACTIONS(1),
    [sym_variable_identifier] = ACTIONS(1),
    [sym_normal_identifier] = ACTIONS(1),
    [sym_operator] = ACTIONS(1),
    [sym_every] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_query] = STATE(27),
    [sym_object] = STATE(2),
    [sym_expression_identifier] = STATE(2),
    [aux_sym_query_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_array_identifier] = ACTIONS(5),
    [sym_variable_identifier] = ACTIONS(5),
    [sym_normal_identifier] = ACTIONS(7),
    [sym_operator] = ACTIONS(9),
    [sym_every] = ACTIONS(11),
    [sym_string] = ACTIONS(5),
    [anon_sym_LBRACE] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_normal_identifier,
    ACTIONS(11), 1,
      sym_every,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      sym_operator,
    ACTIONS(17), 3,
      sym_array_identifier,
      sym_variable_identifier,
      sym_string,
    STATE(3), 3,
      sym_object,
      sym_expression_identifier,
      aux_sym_query_repeat1,
  [26] = 7,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(26), 1,
      sym_normal_identifier,
    ACTIONS(29), 1,
      sym_operator,
    ACTIONS(32), 1,
      sym_every,
    ACTIONS(35), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 3,
      sym_array_identifier,
      sym_variable_identifier,
      sym_string,
    STATE(3), 3,
      sym_object,
      sym_expression_identifier,
      aux_sym_query_repeat1,
  [52] = 2,
    ACTIONS(40), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(38), 8,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [67] = 4,
    ACTIONS(46), 1,
      anon_sym_LBRACK,
    STATE(6), 1,
      sym_expression,
    ACTIONS(44), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(42), 6,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
  [86] = 2,
    ACTIONS(50), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(48), 8,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [101] = 2,
    ACTIONS(54), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(52), 6,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
  [114] = 2,
    ACTIONS(58), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(56), 6,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
  [127] = 2,
    ACTIONS(62), 2,
      sym_normal_identifier,
      sym_operator,
    ACTIONS(60), 6,
      ts_builtin_sym_end,
      sym_array_identifier,
      sym_variable_identifier,
      sym_every,
      sym_string,
      anon_sym_LBRACE,
  [140] = 7,
    ACTIONS(64), 1,
      sym_array_identifier,
    ACTIONS(66), 1,
      sym_normal_identifier,
    ACTIONS(68), 1,
      sym_string,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(72), 1,
      anon_sym_RBRACE,
    STATE(15), 1,
      sym_pair,
    STATE(16), 1,
      aux_sym_object_repeat1,
  [162] = 5,
    ACTIONS(68), 1,
      sym_string,
    ACTIONS(74), 1,
      sym_array_identifier,
    ACTIONS(76), 1,
      sym_normal_identifier,
    STATE(21), 1,
      sym_pair,
    ACTIONS(78), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [179] = 3,
    ACTIONS(80), 1,
      sym_normal_identifier,
    ACTIONS(83), 1,
      anon_sym_RBRACK,
    STATE(12), 2,
      sym_expression_element,
      aux_sym_expression_repeat1,
  [190] = 3,
    ACTIONS(85), 1,
      sym_normal_identifier,
    ACTIONS(87), 1,
      anon_sym_RBRACK,
    STATE(12), 2,
      sym_expression_element,
      aux_sym_expression_repeat1,
  [201] = 2,
    ACTIONS(85), 1,
      sym_normal_identifier,
    STATE(13), 2,
      sym_expression_element,
      aux_sym_expression_repeat1,
  [209] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    STATE(17), 1,
      aux_sym_object_repeat1,
  [219] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    STATE(19), 1,
      aux_sym_object_repeat1,
  [229] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(91), 1,
      anon_sym_RBRACE,
    STATE(19), 1,
      aux_sym_object_repeat1,
  [239] = 2,
    STATE(23), 1,
      sym_expression_identifier,
    ACTIONS(93), 2,
      sym_normal_identifier,
      sym_every,
  [247] = 3,
    ACTIONS(95), 1,
      anon_sym_COMMA,
    ACTIONS(98), 1,
      anon_sym_RBRACE,
    STATE(19), 1,
      aux_sym_object_repeat1,
  [257] = 1,
    ACTIONS(100), 2,
      sym_variable_identifier,
      sym_string,
  [262] = 1,
    ACTIONS(98), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [267] = 2,
    ACTIONS(102), 1,
      anon_sym_LBRACK,
    STATE(6), 1,
      sym_expression,
  [274] = 1,
    ACTIONS(104), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [279] = 2,
    ACTIONS(106), 1,
      sym_operator,
    ACTIONS(108), 1,
      anon_sym_,
  [286] = 1,
    ACTIONS(110), 2,
      sym_normal_identifier,
      anon_sym_RBRACK,
  [291] = 1,
    ACTIONS(112), 1,
      sym_operator,
  [295] = 1,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
  [299] = 1,
    ACTIONS(116), 1,
      anon_sym_COLON,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 67,
  [SMALL_STATE(6)] = 86,
  [SMALL_STATE(7)] = 101,
  [SMALL_STATE(8)] = 114,
  [SMALL_STATE(9)] = 127,
  [SMALL_STATE(10)] = 140,
  [SMALL_STATE(11)] = 162,
  [SMALL_STATE(12)] = 179,
  [SMALL_STATE(13)] = 190,
  [SMALL_STATE(14)] = 201,
  [SMALL_STATE(15)] = 209,
  [SMALL_STATE(16)] = 219,
  [SMALL_STATE(17)] = 229,
  [SMALL_STATE(18)] = 239,
  [SMALL_STATE(19)] = 247,
  [SMALL_STATE(20)] = 257,
  [SMALL_STATE(21)] = 262,
  [SMALL_STATE(22)] = 267,
  [SMALL_STATE(23)] = 274,
  [SMALL_STATE(24)] = 279,
  [SMALL_STATE(25)] = 286,
  [SMALL_STATE(26)] = 291,
  [SMALL_STATE(27)] = 295,
  [SMALL_STATE(28)] = 299,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2), SHIFT_REPEAT(3),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_repeat1, 2), SHIFT_REPEAT(5),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_query_repeat1, 2), SHIFT_REPEAT(3),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2), SHIFT_REPEAT(5),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2), SHIFT_REPEAT(10),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 3),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 3),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 1),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_query_repeat1, 1),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_identifier, 2),
  [50] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_identifier, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_object, 4),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_object, 4),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_object, 2),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_object, 2),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_object, 3),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_object, 3),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_object_repeat1, 1),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2), SHIFT_REPEAT(26),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_repeat1, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_object_repeat1, 2), SHIFT_REPEAT(11),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_object_repeat1, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 3, .production_id = 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_element, 4),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [114] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_groq(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
