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
            $.underscore_identifier,
            $.variable_identifier,
            $.pair,
            $.identifier,
            $.expression_condition,
            $.expression,
            $.string,
            $.fields_block,
            $.comment,
          ),
        ),
      ),

    dot: () => token("."),
    arrow: () => token("->"),
    reference: () => token("@"),

    comment: (_) =>
      token(
        choice(
          seq("//", /.*/),
          seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"),
          // https://tc39.es/ecma262/#sec-html-like-comments
          seq("<!--", /.*/),
          // This allows code to exist before this token on the same line.
          //
          // Technically, --> is supposed to have nothing before it on the same line
          // except for comments and whitespace, but that is difficult to express,
          // and in general tree sitter grammars tend to prefer to be overly
          // permissive anyway.
          //
          // This approach does not appear to cause problems in practice.
          seq("-->", /.*/),
        ),
      ),

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
        choice($.underscore_identifier, $.identifier, $.reference),
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
