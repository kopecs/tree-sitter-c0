const PREC = {
  PAREN_DECLARATOR: -10,
  ASSIGNMENT: -1,
  CONDITIONAL: -2,
  DEFAULT: 0,
  LOGICAL_OR: 1,
  LOGICAL_AND: 2,
  INCLUSIVE_OR: 3,
  EXCLUSIVE_OR: 4,
  BITWISE_AND: 5,
  EQUAL: 6,
  RELATIONAL: 7,
  SIZEOF: 8,
  SHIFT: 9,
  ADD: 10,
  MULTIPLY: 11,
  CAST: 12,
  UNARY: 13,
  CALL: 14,
  FIELD: 15,
  SUBSCRIPT: 16
};

module.exports = grammar({
  name: 'c0',

  extras: $ => [
    /\s|\\\r?\n/,
    $.comment,
  ],

  inline: $ => [
    $._statement,
    $._top_level_item,
    $._type_identifier,
    $._field_identifier,
    $._statement_identifier,
    $._assignment_left_expression,
  ],

  conflicts: $ => [
    [$._type_specifier, $._declarator],
    [$._type_specifier, $._expression],
  ],

  word: $ => $.identifier,

  rules: {
    translation_unit: $ => repeat($._top_level_item),

    _top_level_item: $ => choice(
      $.function_definition,
      $.use,
      $.declaration,
      $._statement,
      $.type_definition,
      $._empty_declaration
    ),


    // Main Grammar

    use: $ => seq(
      '#use',
      field('path', choice(
        $.system_lib_string,
      )),
      '\n'
    ),

    function_definition: $ => seq(
      $._declaration_specifiers,
      field('declarator', $._declarator),
      field('body', $.compound_statement)
    ),

    declaration: $ => seq(
      $._declaration_specifiers,
      field('declarator', choice(
        $._declarator,
        $.init_declarator
      )),
      ';'
    ),

    type_definition: $ => seq(
      'typedef',
      field('type', $._type_specifier),
      field('declarator', $._type_declarator),
      ';'
    ),

    _declaration_specifiers: $ => seq(
      field('type', $._type_specifier),
    ),

    declaration_list: $ => seq(
      '{',
      repeat($._top_level_item),
      '}'
    ),

    _declarator: $ => choice(
      $.pointer_declarator,
      $.function_declarator,
      $.array_declarator,
      $.parenthesized_declarator,
      $.identifier
    ),

    _field_declarator: $ => choice(
      alias($.pointer_field_declarator, $.pointer_declarator),
      alias($.function_field_declarator, $.function_declarator),
      alias($.array_field_declarator, $.array_declarator),
      alias($.parenthesized_field_declarator, $.parenthesized_declarator),
      $._field_identifier
    ),

    _type_declarator: $ => choice(
      alias($.pointer_type_declarator, $.pointer_declarator),
      alias($.function_type_declarator, $.function_declarator),
      alias($.array_type_declarator, $.array_declarator),
      alias($.parenthesized_type_declarator, $.parenthesized_declarator),
      $._type_identifier
    ),

    _abstract_declarator: $ => choice(
      $.abstract_pointer_declarator,
      $.abstract_function_declarator,
      $.abstract_array_declarator,
      $.abstract_parenthesized_declarator,
    ),

    parenthesized_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._declarator,
      ')'
    )),
    parenthesized_field_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._field_declarator,
      ')'
    )),
    parenthesized_type_declarator: $ => prec.dynamic(PREC.PAREN_DECLARATOR, seq(
      '(',
      $._type_declarator,
      ')'
    )),
    abstract_parenthesized_declarator: $ => prec(1, seq(
      '(',
      $._abstract_declarator,
      ')'
    )),

    pointer_declarator: $ => prec.dynamic(1, prec.right(seq(
      '*',
      field('declarator', $._declarator)
    ))),
    pointer_field_declarator: $ => prec.dynamic(1, prec.right(seq(
      '*',
      field('declarator', $._field_declarator)
    ))),
    pointer_type_declarator: $ => prec.dynamic(1, prec.right(seq(
      '*',
      field('declarator', $._type_declarator)
    ))),
    abstract_pointer_declarator: $ => prec.dynamic(1, prec.right(seq('*',
      field('declarator', optional($._abstract_declarator))
    ))),

    function_declarator: $ => prec(1, seq(
      field('declarator', $._declarator),
      field('parameters', $.parameter_list),
    )),
    function_field_declarator: $ => prec(1, seq(
      field('declarator', $._field_declarator),
      field('parameters', $.parameter_list)
    )),
    function_type_declarator: $ => prec(1, seq(
      field('declarator', $._type_declarator),
      field('parameters', $.parameter_list)
    )),
    abstract_function_declarator: $ => prec(1, seq(
      field('declarator', optional($._abstract_declarator)),
      field('parameters', $.parameter_list)
    )),

    array_declarator: $ => prec(1, seq(
      field('declarator', $._declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    array_field_declarator: $ => prec(1, seq(
      field('declarator', $._field_declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    array_type_declarator: $ => prec(1, seq(
      field('declarator', $._type_declarator),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),
    abstract_array_declarator: $ => prec(1, seq(
      field('declarator', optional($._abstract_declarator)),
      '[',
      field('size', optional(choice($._expression, '*'))),
      ']'
    )),

    init_declarator: $ => seq(
      field('declarator', $._declarator),
      '=',
      field('value', $._expression)
    ),

    compound_statement: $ => seq(
      '{',
      repeat($._top_level_item),
      '}'
    ),

    _type_specifier: $ => choice(
      $.struct_specifier,
      $.primitive_type,
      $.array_type,
      $._type_identifier
    ),

    primitive_type: $ => token(choice(
      'bool',
      'char',
      'int',
      'string',
      'void',
    )),

    array_type: $ => seq(
        $._type_specifier,
        "[",
        "]"
    ),

    struct_specifier: $ => seq(
      'struct',
      choice(
        seq(
          field('name', $._type_identifier),
          field('body', optional($.field_declaration_list))
        ),
        field('body', $.field_declaration_list)
      )
    ),

    field_declaration_list: $ => seq(
      '{',
      repeat($._field_declaration_list_item),
      '}'
    ),

    _field_declaration_list_item: $ => choice(
      $.field_declaration,
    ),

    field_declaration: $ => seq(
      $._declaration_specifiers,
      commaSep(field('declarator', $._field_declarator)),
      ';'
    ),

    parameter_list: $ => seq(
      '(',
      commaSep(choice($.parameter_declaration, '...')),
      ')'
    ),

    parameter_declaration: $ => seq(
      $._declaration_specifiers,
      optional(field('declarator', choice(
        $._declarator,
        $._abstract_declarator
      )))
    ),

    // Statements

    _statement: $ => choice(
      $.compound_statement,
      $.expression_statement,
      $.if_statement,
      $.do_statement,
      $.while_statement,
      $.for_statement,
      $.return_statement,
    ),

    expression_statement: $ => seq(
      optional(choice(
        $._expression,
      )),
      ';'
    ),

    if_statement: $ => prec.right(seq(
      'if',
      field('condition', $.parenthesized_expression),
      field('consequence', $._statement),
      optional(seq(
        'else',
        field('alternative', $._statement)
      ))
    )),

    while_statement: $ => seq(
      'while',
      field('condition', $.parenthesized_expression),
      field('body', $._statement)
    ),

    do_statement: $ => seq(
      'do',
      field('body', $._statement),
      'while',
      field('condition', $.parenthesized_expression),
      ';'
    ),

    for_statement: $ => seq(
      'for',
      '(',
      choice(
        field('initializer', $.declaration),
        seq(field('initializer', optional($._expression)), ';')
      ),
      field('condition', optional($._expression)), ';',
      field('update', optional($._expression)),
      ')',
      $._statement
    ),

    return_statement: $ => seq(
      'return',
      optional($._expression),
      ';'
    ),

    // Expressions

    _expression: $ => choice(
      $.conditional_expression,
      $.assignment_expression,
      $.binary_expression,
      $.unary_expression,
      $.update_expression,
      $.pointer_expression,
      $.subscript_expression,
      $.call_expression,
      $.field_expression,
      $.identifier,
      $.number_literal,
      $.string_literal,
      $.true,
      $.false,
      $.null,
      $.concatenated_string,
      $.char_literal,
      $.parenthesized_expression,
      $.alloc_expression,
      $.alloc_array_expression
    ),

    alloc_expression: $ => seq(
      "alloc",
      "(",
      $._type_specifier,
      ")"
    ),

    alloc_array_expression: $ => seq(
      "alloc_array",
      "(",
      $._type_specifier,
      ",",
      $._expression,
      ")"
    ),

    conditional_expression: $ => prec.right(PREC.CONDITIONAL, seq(
      field('condition', $._expression),
      '?',
      field('consequence', $._expression),
      ':',
      field('alternative', $._expression)
    )),

    _assignment_left_expression: $ => choice(
      $.identifier,
      $.call_expression,
      $.field_expression,
      $.pointer_expression,
      $.subscript_expression,
      $.parenthesized_expression
    ),

    assignment_expression: $ => prec.right(PREC.ASSIGNMENT, seq(
      field('left', $._assignment_left_expression),
      choice(
        '=',
        '*=',
        '/=',
        '%=',
        '+=',
        '-=',
        '<<=',
        '>>=',
        '&=',
        '^=',
        '|='
      ),
      field('right', $._expression)
    )),

    pointer_expression: $ => prec.left(PREC.CAST, seq(
      field('operator', '*'),
      field('argument', $._expression)
    )),

    unary_expression: $ => prec.left(PREC.UNARY, seq(
      field('operator', choice('!', '~', '-', '+')),
      field('argument', $._expression)
    )),

    binary_expression: $ => {
      const table = [
        ['+', PREC.ADD],
        ['-', PREC.ADD],
        ['*', PREC.MULTIPLY],
        ['/', PREC.MULTIPLY],
        ['%', PREC.MULTIPLY],
        ['||', PREC.LOGICAL_OR],
        ['&&', PREC.LOGICAL_AND],
        ['|', PREC.INCLUSIVE_OR],
        ['^', PREC.EXCLUSIVE_OR],
        ['&', PREC.BITWISE_AND],
        ['==', PREC.EQUAL],
        ['!=', PREC.EQUAL],
        ['>', PREC.RELATIONAL],
        ['>=', PREC.RELATIONAL],
        ['<=', PREC.RELATIONAL],
        ['<', PREC.RELATIONAL],
        ['<<', PREC.SHIFT],
        ['>>', PREC.SHIFT],
      ];

      return choice(...table.map(([operator, precedence]) => {
        return prec.left(precedence, seq(
          field('left', $._expression),
          field('operator', operator),
          field('right', $._expression)
        ))
      }));
    },

    update_expression: $ => {
      const argument = field('argument', $._expression);
      const operator = field('operator', choice('--', '++'));
      return prec.right(PREC.UNARY, choice(
        seq(operator, argument),
        seq(argument, operator),
      ));
    },

    cast_expression: $ => prec(PREC.CAST, seq(
      '(',
      field('type', $.type_descriptor),
      ')',
      field('value', $._expression)
    )),

    type_descriptor: $ => seq(
      field('type', $._type_specifier),
      field('declarator', optional($._abstract_declarator))
    ),

    subscript_expression: $ => prec(PREC.SUBSCRIPT, seq(
      field('argument', $._expression),
      '[',
      field('index', $._expression),
      ']'
    )),

    call_expression: $ => prec(PREC.CALL, seq(
      field('function', $._expression),
      field('arguments', $.argument_list)
    )),

    argument_list: $ => seq('(', commaSep($._expression), ')'),

    field_expression: $ => seq(
      prec(PREC.FIELD, seq(
        field('argument', $._expression),
        choice('.', '->')
      )),
      field('field', $._field_identifier)
    ),

    parenthesized_expression: $ => seq(
      '(',
      $._expression,
      ')'
    ),

    subscript_designator: $ => seq('[', $._expression, ']'),

    field_designator: $ => seq('.', $._field_identifier),

    number_literal: $ => {
      const hex = /[0-9a-fA-F]/;
      const decimal = /[0-9]/;
      const hexDigits = repeat1(hex);
      const decimalDigits = repeat1(decimal);
      return token(seq(
        optional('0x'),
        choice(
          decimalDigits,
          seq('0x', hexDigits)
        )
      ))
    },

    char_literal: $ => seq(
      '\'',
      choice(
        $.escape_sequence,
        token.immediate(/[^\n']/)
      ),
      '\''
    ),

    concatenated_string: $ => seq(
      $.string_literal,
      repeat1($.string_literal)
    ),

    string_literal: $ => seq(
      '"',
      repeat(choice(
        token.immediate(prec(1, /[^\\"\n]+/)),
        $.escape_sequence
      )),
      '"',
    ),

    escape_sequence: $ => token(prec(1, seq(
      '\\',
      choice(
        '0',
        'r',
        'n',
        'v',
        'f',
        't'
      )
    ))),

    system_lib_string: $ => token(seq(
      '<',
      repeat(choice(/[^>\n]/, '\\>')),
      '>'
    )),

    true: $ => token(choice('TRUE', 'true')),
    false: $ => token(choice('FALSE', 'false')),
    null: $ => 'NULL',

    identifier: $ => /[a-zA-Z_]\w*/,

    _type_identifier: $ => alias($.identifier, $.type_identifier),
    _field_identifier: $ => alias($.identifier, $.field_identifier),
    _statement_identifier: $ => alias($.identifier, $.statement_identifier),

    _empty_declaration: $ => seq(
      $._type_specifier,
      ';'
    ),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: $ => token(choice(
      seq('//', /(\\(.|\r?\n)|[^\\\n])*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    )),
  },

  supertypes: $ => [
    $._expression,
    $._statement,
    $._type_specifier,
    $._declarator,
    $._field_declarator,
    $._type_declarator,
    $._abstract_declarator,
  ]
});

module.exports.PREC = PREC

function commaSep (rule) {
  return optional(commaSep1(rule))
}

function commaSep1 (rule) {
  return seq(rule, repeat(seq(',', rule)))
}

function commaSepTrailing (recurSymbol, rule) {
  return choice(rule, seq(recurSymbol, ',', rule))
}
