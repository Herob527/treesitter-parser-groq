/// <reference types="tree-sitter-cli/dsl" />

// @ts-check

module.exports = grammar({
  name: "groq",

  rules: {
    source_file: ($) => repeat(choice($.query, $.value, $.pair)),

    query: ($) =>
      prec.left(
        2,
        choice(
          $.nullary_access_operator,
          $.arraylike,
          $.pipe,
          $.sort_order,
          $.filter,
        ),
      ),
    pair: ($) =>
      prec.left(
        1,
        choice($.identifier, $.value, $.filter, seq("=>", $.pair), "ERROR"),
      ),

    variable: ($) => /\$[_A-Za-z][_0-9A-Za-z]*/,

    keyword: ($) => choice("asc", "desc", "in", "match"),

    comparison: ($) => /(?:==|!=|>=|<=|>|<)/,

    operator: ($) => choice(/\+/, /\-/, /\*/, /\*\*/, /\//, /%/),

    pipe: ($) => /\|/,

    logical: ($) => /\!|\&\&|\|\|/,

    reference: ($) => /->/,

    range: ($) => seq(/\s*/, /\d+/, /(\.{2,3})/, /\d+/, /\s*/),

    spread: ($) => seq("...", optional(".")),

    array: ($) => prec.left(2, seq("[", repeat($.array_values), "]")),
    arraylike: ($) =>
      seq(
        "[",
        optional(seq("*", ".", optional("."))),
        optional($.arraylike_repeat1),
        "]",
        optional("."),
      ),

    array_values: ($) =>
      prec.left(2, choice($.value, $.spread, ",", /[^\s\]]/)),
    array_repeat1: ($) =>
      prec.left(2, seq($.array_values, repeat1(seq(",", $.array_values)))),
    arraylike_repeat1: ($) =>
      prec.left(1, seq($.array_values, repeat1(seq(",", $.array_values)))),

    named_projection: ($) =>
      prec.left(
        2,
        choice(
          seq($.objectkey, optional($.projection)),
          seq($.objectkey, optional($.pair)),
          seq($.objectkey), // handle the case where there's only an object key
        ),
      ),

    projection_repeat1: ($) => prec.left(1, seq($.named_projection, $.pair)),
    filter: ($) =>
      prec.left(
        2,
        choice(
          $.function_call,
          $.keyword,
          $.constant,
          $.identifier,
          $.value,
          $.comparison,
          $.operator,
          $.logical,
          "ERROR", // Add the possibility of an error in a filter
        ),
      ),
    value: ($) =>
      prec.left(
        3,
        choice(
          $.constant,
          $.number,
          $.string,
          $.array,
          $.variable,
          $.projection,
          $.function_call,
        ),
      ),

    nullary_access_operator: ($) => /[*@^]/,

    constant: ($) => choice("true", "false", "null"),

    number: ($) => /-?(?:0|[1-9]\d*)(?:\.\d+)?(?:[eE][+-]?\d+)?/,

    projection: ($) =>
      seq(
        "{",
        optional(","),
        repeat(
          seq(
            choice($.identifier, $.objectkey, $.named_projection),
            optional("..."),
            optional($.pair),
            seq(
              ":",
              choice(
                $.nullary_access_operator,
                $.arraylike,
                $.value,
                $.spread,
                $.identifier,
                $.operator,
                $.comparison,
                $.pair,
              ),
            ),
          ),
        ),
        "}",
      ),

    string: ($) => choice($.double_string, $.single_string),

    double_string: ($) => seq('"', repeat(choice(/[^"\\]+/, /\\./)), '"'), // Updated to allow escape sequences

    single_string: ($) => seq("'", repeat($.stringcontent), "'"),

    objectkey: ($) => prec.left(2, $.string),

    stringcontent: ($) => choice(/\\[\\\/bfnrt"]/, /\\u[0-9a-fA-F]{4}/, /\\./),

    sort_pair: ($) =>
      choice(
        seq(/[_A-Za-z][_0-9A-Za-z]*/, optional(/\s*(asc|desc)/)),
        seq("@", "[", $.string, "]", optional(/\s*(asc|desc)/)),
      ),

    sort_order: ($) =>
      seq("order", "(", $.sort_pair, repeat1(seq(",", $.sort_pair)), ")"),

    _sort_pair: ($) => $.sort_pair,

    function_call: ($) =>
      choice($.function_var_arg, $.function_single_arg, $.function_round),

    function_var_arg: ($) =>
      seq(
        choice("coalesce", "select"),
        "(",
        repeat1(choice($.value, $.identifier, $.filter, $.pair, ",")),
        ")",
      ),

    function_single_arg: ($) =>
      seq(
        choice("count", "defined", "length", "path", "references"),
        "(",
        choice($.query, $.identifier, $.value, $.pair),
        ")",
      ),

    function_round: ($) =>
      seq(
        choice("avg", "max", "min", "sum"),
        "(",
        choice($.query, $.identifier, $.value),
        ")",
      ),
    identifier: ($) =>
      choice(
        seq(
          choice(/[_A-Za-z][_0-9A-Za-z]*/, /[@^]/),
          optional(/\s*\[\s*\]\s*/),
          ".",
        ),
        /[_A-Za-z][_0-9A-Za-z]*/,
      ),
    error: ($) => /ERROR/,
  },
});
