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
  extras: ($) => [$.comment, /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/],
  rules: {
    query: ($) =>
      seq(
        repeat(
          choice(
            $.asterisk,
            $.variable_identifier,
            $.identifier_item,
            $.string,
            $.comment,
            $.rest,
            $.object,
          ),
        ),
      ),

    reference: () => token("@"),
    rest: () => token("..."),
    asterisk: () => token("*"),
    dot: () => token("."),
    arrow: () => token("->"),

    object: ($) =>
      seq(
        "{",
        repeat(seq(choice($.underscore_identifier, $.identifier, $.pair), ",")),
        "}",
      ),
    pair: ($) =>
      seq(
        field("key", $.string),
        optional(":"),
        field("value", seq($.identifier_item, $.object)),
      ),

    comment: () =>
      token(
        choice(seq("//", /.*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),
      ),

    identifier_item: ($) =>
      seq(
        choice($.identifier, $.underscore_identifier, $.expression),
        optional(choice($.dot, $.arrow)),
      ),

    underscore_identifier: () => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq("_", alpha, repeat(alphanumeric)));
    },

    variable_identifier: () => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq("$", alpha, repeat(alphanumeric)));
    },

    identifier: ($) => {
      const alpha = /[a-zA-Z]+?/;
      const alphanumeric = /[_a-zA-Z\d]+?/;
      return token(seq(alpha, repeat(alphanumeric), optional(token(","))));
    },

    string: () => seq('"', /[\w]*/, '"'),

    comparision_operator: () =>
      token(choice("==", ">", ">=", "<", "<=", "!=", "in", "matches")),

    boolean_operator: () => token(choice("||", "&&")),

    expression_element: ($) =>
      seq(
        optional(seq("!", "(")),
        choice($.identifier, $.underscore_identifier),
        $.comparision_operator,
        choice($.string, $.variable_identifier),
        optional(seq(")")),
      ),

    expression: ($) =>
      seq(
        "[",
        repeat(seq($.expression_element, optional($.boolean_operator))),
        "]",
      ),
  },
});
