#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 13
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 11
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_COLON = 1,
  anon_sym_DASH = 2,
  sym_day = 3,
  sym_hour = 4,
  sym_date = 5,
  sym_source_file = 6,
  sym_week = 7,
  sym_day_line = 8,
  aux_sym_source_file_repeat1 = 9,
  aux_sym_week_repeat1 = 10,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ": ",
  [anon_sym_DASH] = " - ",
  [sym_day] = "day",
  [sym_hour] = "hour",
  [sym_date] = "date",
  [sym_source_file] = "source_file",
  [sym_week] = "week",
  [sym_day_line] = "day_line",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_week_repeat1] = "week_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_day] = sym_day,
  [sym_hour] = sym_hour,
  [sym_date] = sym_date,
  [sym_source_file] = sym_source_file,
  [sym_week] = sym_week,
  [sym_day_line] = sym_day_line,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_week_repeat1] = aux_sym_week_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_day] = {
    .visible = true,
    .named = true,
  },
  [sym_hour] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_week] = {
    .visible = true,
    .named = true,
  },
  [sym_day_line] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_week_repeat1] = {
    .visible = false,
    .named = false,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == ':') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == ':') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == ':') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_day);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_hour);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_hour);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
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
  [12] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_day] = ACTIONS(1),
    [sym_hour] = ACTIONS(1),
    [sym_date] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(8),
    [sym_week] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_date] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(9), 1,
      sym_day,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      sym_date,
    STATE(3), 2,
      sym_day_line,
      aux_sym_week_repeat1,
  [12] = 3,
    ACTIONS(13), 1,
      sym_day,
    ACTIONS(11), 2,
      ts_builtin_sym_end,
      sym_date,
    STATE(3), 2,
      sym_day_line,
      aux_sym_week_repeat1,
  [24] = 3,
    ACTIONS(5), 1,
      sym_date,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
    STATE(5), 2,
      sym_week,
      aux_sym_source_file_repeat1,
  [35] = 3,
    ACTIONS(18), 1,
      ts_builtin_sym_end,
    ACTIONS(20), 1,
      sym_date,
    STATE(5), 2,
      sym_week,
      aux_sym_source_file_repeat1,
  [46] = 2,
    ACTIONS(9), 1,
      sym_day,
    STATE(2), 2,
      sym_day_line,
      aux_sym_week_repeat1,
  [54] = 1,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      sym_day,
      sym_date,
  [60] = 1,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
  [64] = 1,
    ACTIONS(27), 1,
      anon_sym_COLON,
  [68] = 1,
    ACTIONS(29), 1,
      sym_hour,
  [72] = 1,
    ACTIONS(31), 1,
      anon_sym_DASH,
  [76] = 1,
    ACTIONS(33), 1,
      sym_hour,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 12,
  [SMALL_STATE(4)] = 24,
  [SMALL_STATE(5)] = 35,
  [SMALL_STATE(6)] = 46,
  [SMALL_STATE(7)] = 54,
  [SMALL_STATE(8)] = 60,
  [SMALL_STATE(9)] = 64,
  [SMALL_STATE(10)] = 68,
  [SMALL_STATE(11)] = 72,
  [SMALL_STATE(12)] = 76,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_week, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_week_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_week_repeat1, 2), SHIFT_REPEAT(9),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day_line, 5),
  [25] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_houlang(void) {
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
