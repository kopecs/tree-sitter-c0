module.exports = grammar ({
    name: 'C0',

    rules: {
        prog: $ => repeat(choice(
            $.gdecl,
            $.gdefn
        )),

        gdecl: $ => choice(
            seq("struct", $.sid, ";"),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(",", $.tp, $.vid))), ")", ";"),
            seq("#use", $.liblit, "\n"),
            seq("#use", $.strlit, "\n")
        )

        gdefn: $ => choice(
            seq("struct", $.sid, "{", repeat($.tp, $.fid, ";"), "}", ";"),
            seq($.tp, $.vid, "(", optional(seq($.tp, $.vid, repeat(",", $.tp, $.vid))), ")", "{", repeat(stmt), "}"),
            seq("typedef", $.tp, $.aid)
        ),
        
        stmt: $ => choice(
            seq($.simple, ";"),
            seq("if", "(", $.exp, ")", $.stmt, optional(seq("else", $.stmt))),
            seq("while", "(", $.exp, ")", $.stmt),
            seq("for", "(", optional($.simple), ";", $.exp, ";", optional($.simple), ")", $.stmt),
            seq("return", optional($.exp), ";"),
            seq("{", repeat($.stmt), "}"),
            seq("assert", "(", $.exp, ")", ";"),
            seq("error", "(", $.exp, ")", ";")
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
            seq("alloc_array", "(", $.tp, $.exp, ")")
        ),
    }
});
