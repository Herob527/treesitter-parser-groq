/** @type {import('eslint').ESLint.ConfigData}*/
module.exports = {
  env: {
    commonjs: true,
    es2021: true,
  },
  extends: ["plugin:prettier/recommended"],
  overrides: [],
  parserOptions: {
    ecmaVersion: "latest",
    sourceType: "module",
  },
  plugins: ["prettier", "@stylistic"],
  rules: {
    "spaced-comment": "off",
    indent: ["error", 2, { SwitchCase: 1 }],
    "prettier/prettier": "error",
    "max-len": [
      "error",
      {
        code: 80,
        ignoreComments: true,
        ignoreUrls: true,
        ignoreStrings: true,
      },
    ],
    "@stylistic/no-multi-spaces": "warn",
  },
};
