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
            $.asterisk,
            $.underscore_identifier,
            $.variable_identifier,
            $.pair,
            $.identifier,
            $.expression_condition,
            $.expression,
            $.string,
            $.fields_block,
          ),
        ),
      ),

    dot: () => token("."),
    arrow: () => token("->"),

    fields_block: ($) =>
      seq(
        "{",
        repeat(
          commaSep1(
            choice($.pair, choice($.identifier, $.underscore_identifier)),
          ),
        ),
        "}",
      ),

    asterisk: ($) => token("*"),

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
      return token(
        seq(
          "",
          alpha,
          repeat(alphanumeric),
          optional(seq(token(choice(".", "->")), alpha, repeat(alphanumeric))),
          optional(token(",")),
        ),
      );
    },
    null: () => token("null"),

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

    empty_expression: ($) => seq($.underscore_identifier, $.identifier, "[]"),

    expression_element: ($) =>
      seq(
        choice($.underscore_identifier, $.identifier),
        $.comparision_operator,
        choice($.variable_identifier, $.string),
      ),

    expression_condition: ($) =>
      seq(
        choice($.underscore_identifier, $.identifier, $.asterisk),
        seq(
          "[",
          repeat(seq($.expression_element, optional($.boolean_operator))),
          "]",
        ),
      ),
    expression: ($) =>
      prec.left(
        1,
        seq(
          $.expression_condition,
          choice(" ", ".", "->"),
          $.fields_block,
          optional(","),
        ),
      ),
  },
});
