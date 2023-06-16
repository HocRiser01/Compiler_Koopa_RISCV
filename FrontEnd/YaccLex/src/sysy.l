%option noyywrap
%option nounput
%option noinput

%{

#include <cstdlib>
#include <string>
#include "../StrDump.h"

// 因为 Flex 会用到 Bison 中关于 token 的定义
// 所以需要 include Bison 生成的头文件
#include "sysy.tab.hpp"
extern int line_number;

using namespace std;

%}

/* 空白符和注释 */
LineComment   "//".*

/* 整数字面量 */
Decimal       [1-9][0-9]*
Octal         0[0-7]*
Hexadecimal   0[xX][0-9a-fA-F]+

%x C_COMMENT
%x C_SINGLE_LINE_COMMENT

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); /* match c multi-line comment */ }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

{LineComment}   { }

int/[ \t]*[_a-zA-z0-9]+\(    { yylval.raw_string = merged_str_dump(yytext); return KEYWORD_INT_FUNC    ; }
float/[ \t]*[_a-zA-z0-9]+\(  { yylval.raw_string = merged_str_dump(yytext); return KEYWORD_FLOAT_FUNC  ; }
\;                           { yylval.raw_string = merged_str_dump(yytext); return SEMICOLON           ; }
\,                           { yylval.raw_string = merged_str_dump(yytext); return COMMA               ; }
\=                           { yylval.raw_string = merged_str_dump(yytext); return EQUAL               ; }
\[                           { yylval.raw_string = merged_str_dump(yytext); return LBRACKET            ; }
\]                           { yylval.raw_string = merged_str_dump(yytext); return RBRACKET            ; }
\{                           { yylval.raw_string = merged_str_dump(yytext); return LBRACE              ; }
\}                           { yylval.raw_string = merged_str_dump(yytext); return RBRACE              ; }
\(                           { yylval.raw_string = merged_str_dump(yytext); return LPARE               ; }
\)                           { yylval.raw_string = merged_str_dump(yytext); return RPARE               ; }
\!                           { yylval.raw_string = merged_str_dump(yytext); return OPE_NOT             ; }
\+                           { yylval.raw_string = merged_str_dump(yytext); return OPE_ADD             ; }
\-                           { yylval.raw_string = merged_str_dump(yytext); return OPE_SUB             ; }
\*                           { yylval.raw_string = merged_str_dump(yytext); return OPE_MUL             ; }
\/                           { yylval.raw_string = merged_str_dump(yytext); return OPE_DIV             ; }
\%                           { yylval.raw_string = merged_str_dump(yytext); return OPE_MOD             ; }
"&&"                         { yylval.raw_string = merged_str_dump(yytext); return OPE_AND             ; }
"||"                         { yylval.raw_string = merged_str_dump(yytext); return OPE_OR              ; }
"=="                         { yylval.raw_string = merged_str_dump(yytext); return OPE_EQU             ; }
"!="                         { yylval.raw_string = merged_str_dump(yytext); return OPE_NEQ             ; }
"<="                         { yylval.raw_string = merged_str_dump(yytext); return OPE_LEQ             ; }
">="                         { yylval.raw_string = merged_str_dump(yytext); return OPE_GEQ             ; }
"<"                          { yylval.raw_string = merged_str_dump(yytext); return OPE_LSS             ; }
">"                          { yylval.raw_string = merged_str_dump(yytext); return OPE_GTR             ; }
{Decimal}                    { yylval.raw_string = merged_str_dump(yytext); return DECIMAL_CONST       ; }
{Octal}                      { yylval.raw_string = merged_str_dump(yytext); return OCTAL_CONST         ; }
{Hexadecimal}                { yylval.raw_string = merged_str_dump(yytext); return HEXADECIMAL_CONST   ; }
[0-9][0-9]*\.[0-9]*          { yylval.raw_string = merged_str_dump(yytext); return FLOAT_CONST         ; }

[_a-zA-Z][_a-zA-Z0-9]*  { yylval.raw_string = merged_str_dump(yytext); 
        int typeId = IDENTIFIER; 
        if(0 == strcmp("const", yytext))    { typeId = KEYWORD_CONST;    }
        if(0 == strcmp("int", yytext))      { typeId = KEYWORD_INT;      }
        if(0 == strcmp("float", yytext))    { typeId = KEYWORD_FLOAT;    }
        if(0 == strcmp("void", yytext))     { typeId = KEYWORD_VOID;     }
        if(0 == strcmp("if", yytext))       { typeId = KEYWORD_IF;       }
        if(0 == strcmp("else", yytext))     { typeId = KEYWORD_ELSE;     }
        if(0 == strcmp("while", yytext))    { typeId = KEYWORD_WHILE;    }
        if(0 == strcmp("continue", yytext)) { typeId = KEYWORD_CONTINUE; }
        if(0 == strcmp("break", yytext))    { typeId = KEYWORD_BREAK;    }
        if(0 == strcmp("return", yytext))   { typeId = KEYWORD_RETURN;   }
        return typeId; }

[ \t]+ {  } 
\n     { line_number += 1; } /* new line */
%%
