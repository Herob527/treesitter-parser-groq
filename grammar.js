/// <reference types="tree-sitter-cli/dsl" />

// @ts-check

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
}

/**
 * Creates a rule to optionally match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @return {ChoiceRule}
 *
 */
function commaSep(rule) {
  return optional(commaSep1(rule));
}
module.exports = grammar({
  name: "groq",
  conflicts: ($) => [
    [$.query, $.expression],
    [$.expression],
    [$.query, $.expression_condition],
  ],
  extras: ($) => [$.comment, /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/],
  rules: {
    query: ($) =>
      seq(
        repeat(
          choice(
            $.asterisk,
            $.empty_expression,
            $.underscore_identifier,
            $.variable_identifier,
            $.pair,
            $.identifier,
            $.expression,
            $.string,
            $.fields_block,
            $.comment,
            $.rest,
          ),
        ),
      ),

    reference: () => token("@"),
    rest: () => token("..."),
    asterisk: () => token("*"),

    comment: () =>
      token(
        choice(seq("//", /.*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),
      ),

    fields_block: ($) =>
      seq(
        "{",
        repeat(
          seq(
            choice(
              $.pair,
              choice($.identifier, $.underscore_identifier),
              $.rest,
            ),
            optional(token(",")),
          ),
        ),
        "}",
      ),

    underscore_identifier: (_) => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq("_", alpha, repeat(alphanumeric)));
    },

    variable_identifier: (_) => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq("$", alpha, repeat(alphanumeric)));
    },

    identifier: ($) => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq(alpha, repeat(alphanumeric), optional(token(","))));
    },

    string: (_) => seq('"', /[\w]*/, '"'),

    pair: ($) =>
      prec.left(
        2,
        seq(
          field("key", $.string),
          ":",
          field(
            "value",
            choice($.expression, $.identifier, $.underscore_identifier),
          ),
          optional(token(",")),
        ),
      ),

    // Expression
    comparision_operator: ($) =>
      token(choice("==", ">", ">=", "<", "<=", "!=", "in", "matches")),

    boolean_operator: ($) => token(choice("||", "&&")),

    empty_expression: ($) =>
      seq(choice($.underscore_identifier, $.identifier), "[]"),

    expression_element: ($) =>
      seq(
        optional(token("!")),
        optional(token("(")),
        choice($.underscore_identifier, $.identifier, $.reference),
        $.comparision_operator,
        choice($.variable_identifier, $.string),
        optional(token(")")),
      ),

    expression_condition: ($) =>
      seq(
        optional(choice($.underscore_identifier, $.identifier, $.asterisk)),
        seq(
          "[",
          repeat(seq($.expression_element, optional($.boolean_operator))),
          "]",
        ),
      ),
    expression: ($) =>
      seq(
        repeat1(
          seq(
            $.expression_condition,
            optional(choice(token("."), token("->"))),
          ),
        ),
        optional($.fields_block),
        optional(","),
      ),
  },
});
