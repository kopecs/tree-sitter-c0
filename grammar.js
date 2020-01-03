module.exports = grammar ({
    name: 'C0',

    rules: {
        id: $ => /[A-Za-z_][A-Za-z0-9_]*/,

        sid: $ => $.id,
        fid: $ => $.id,
        vid: $ => $.id,
        aid: $ => $.id,
        

        num: $ => choice(
            $.decnum,
            $.hexnum
        ),

        decnum: $ => choice(
            "0",
            /[1-9][0-9]*/
        ),

        hexnum: $ => /0[xX][0-9a-fA-F]+/,

        strlit: $ => seq("\"", repeat($.schar), "\""),

        chrlit: $ => seq("'", $.cchar, "'"),

        liblit: $ => seq("<", repeat($.lchar), ">"),

        schar: $ => choice(
            $.nchar,
            $.esc
        ),

        cchar: $ => choice(
            $.nchar,
            $.esc,
            "\"",
            "\\0"
        ),

        nchar: $ => /[a-z0-9!#$%&'()*+,.\/:;<=>?@\[\] ^_`{|}~-]/,

        lchar: $ => /[a-z0-9!"#$%&'()*+,.\/:;<=?@\[\] ^_`{|}~-]/,

        esc: $ => choice(
            "\\n",
            "\\t",
            "\\v",
            "\\b",
            "\\r",
            "\\a",
            "\\\\",
            "\\'",
            "\\\""
        ),

        sep: $ => choice(
            "(",
            ")",
            "[",
            "]",
            "{",
            "}",
            ",",
            ";"
        ),

        unop: $ => choice(
            "!",
            "~",
            "-",
            "*"
        ),

        binop: $ => choice(
            ".",
            "->",
            "*",
            "/",
            "%",
            "+",
            "-",
            "<<",
            ">>",
            "<",
            "<=",
            ">=",
            ">",
            "==",
            "!=",
            "&",
            "^",
            "|",
            "&&",
            "||",
        ),

        asnop: $ => choice(
            "=",
            "+=",
            "-=",
            "*=",
            "/=",
            "%=",
            "&=",
            "^=",
            "|=",
            "<<=",
            ">>="
        ),

        postop: $ => choice(
            "--",
            "++"
        ),

        prog: $ => repeat(choice(
            $.gdecl,
            $.gdefn
        )),

        gdecl: $ => choice(
            seq("struct", $.sid, ";"),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(seq(",", $.tp, $.vid)))), ")", ";"),
            seq("#use", $.liblit, "\n"),
            seq("#use", $.strlit, "\n"),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(seq(",", $.tp, $.vid)))), ")", repeat($.anno), ";")
        ),

        gdefn: $ => choice(
            seq("struct", $.sid, "{", repeat(seq($.tp, $.fid, ";")), "}", ";"),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(seq(",", $.tp, $.vid)))), ")", "{", repeat($.stmt), "}"),
            seq("typedef", $.tp, $.aid),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(seq(",", $.tp, $.vid)))), ")", repeat($.anno), "{", repeat($.stmt), "}")
        ),
        
        stmt: $ => choice(
            seq($.simple, ";"),
            seq("if", "(", $.exp, ")", $.stmt, optional(seq("else", $.stmt))),
            seq("while", "(", $.exp, ")", $.stmt),
            seq("for", "(", optional($.simple), ";", $.exp, ";", optional($.simple), ")", $.stmt),
            seq("return", optional($.exp), ";"),
            seq("{", repeat($.stmt), "}"),
            seq("assert", "(", $.exp, ")", ";"),
            seq("error", "(", $.exp, ")", ";"),
            seq(repeat1($.anno), $.stmt),
            seq("{", repeat($.stmt), repeat1($.anno), "}")
        ),

        simple: $ => choice(
            seq($.lv, $.asnop, $.exp),
            seq($.lv, "++"),
            seq($.lv, "--"),
            $.exp,
            seq($.tp, $.vid, optional(seq("=", $.exp))),
        ),

        lv: $ => choice(
            $.vid,
            seq($.lv, ".", $.fid),
            seq($.lv, "->", $.fid),
            seq("*", $.lv),
            seq($.lv, optional($.exp)),
            seq("(", $.lv, ")")
        ),

        tp: $ => choice(
            "int",
            "bool",
            "string",
            "char",
            "void",
            seq($.tp, "*"),
            seq($.tp, "[", "]"),
            seq("struct", $.sid),
            $.aid
        ),

        exp: $ => choice(
            seq("(", $.exp, ")"),
            $.num,
            $.strlit,
            $.chrlit,
            "true",
            "false",
            "NULL",
            $.vid,
            seq($.exp, $.binop, $.exp),
            seq($.unop, $.exp),
            seq($.exp, "?", $.exp, ":", $.exp),
            seq($.vid, "(", optional(seq($.exp, repeat(seq(",", $.exp)))), ")"),
            seq($.exp, ".", $.fid),
            seq($.exp, "->", $.fid),
            seq($.exp, "[", $.exp, "]"),
            seq("alloc", "(", $.tp, ")"),
            seq("alloc_array", "(", $.tp, $.exp, ")"),
            "\\result",
            seq("\\length", "(", $.exp, ")")
        ),

        spec: $ => choice(
            seq("requires", $.exp, ";"),
            seq("ensures", $.exp, ";"),
            seq("loop_invariant", $.exp, ";"),
            seq("assert", $.exp, ";")
        ),

        anno: $ => choice(
            seq("//@", repeat($.spec), "\n"),
            seq("/*", repeat($.spec), "\n")
        ),
    }
});
