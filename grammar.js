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

  rules: {
    query: ($) =>
      seq(
        repeat(
          choice(
            $.variable_identifier,
            $.normal_identifier,
            $.operator,
            $.every,
            $.string,
            $.expression_identifier,
            $.array_identifier,
            $.object,
          ),
        ),
      ),

    array_identifier: (_) => {
      const alpha = /[_a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq(alpha, repeat(alphanumeric), "[]"));
    },

    variable_identifier: (_) => {
      const alpha = /[_a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq("$", alpha, repeat(alphanumeric)));
    },

    normal_identifier: ($) => {
      const alpha = /[_a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(
        seq(
          "",
          alpha,
          repeat(alphanumeric),
          optional(seq(".", alpha, repeat(alphanumeric))),
        ),
      );
    },

    operator: (_) => token(choice("==", "||", "&&", "matches", "!=", "[]")),

    every: () => token("*"),

    string: () => token(seq('"', /[\w]*?/, '"')),

    pair: ($) =>
      seq(
        field("key", $.string),
        ":",
        field("value", choice($.expression_identifier, $.normal_identifier)),
      ),

    object: ($) =>
      seq(
        "{",
        commaSep(
          optional(choice($.pair, $.normal_identifier, $.array_identifier)),
        ),
        "}",
      ),

    expression_identifier: ($) =>
      seq(choice($.normal_identifier, $.every), $.expression),

    expression_element: ($) =>
      seq(
        $.normal_identifier,
        $.operator,
        choice($.variable_identifier, $.string),
        choice($.operator, ""),
      ),

    expression: ($) => seq("[", repeat1($.expression_element), "]"),
  },
});
