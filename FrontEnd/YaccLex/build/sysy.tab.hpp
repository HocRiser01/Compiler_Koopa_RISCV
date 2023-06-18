/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_GGN_DESKTOP_GITHUB_COMPILER2022_X_FRONTEND_YACCLEX_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_HOME_GGN_DESKTOP_GITHUB_COMPILER2022_X_FRONTEND_YACCLEX_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"

    #include <string>
    #include "../../../ObjTree/ObjManager.h"

#line 54 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KEYWORD_INT_FUNC = 258,        /* KEYWORD_INT_FUNC  */
    KEYWORD_FLOAT_FUNC = 259,      /* KEYWORD_FLOAT_FUNC  */
    SEMICOLON = 260,               /* SEMICOLON  */
    COMMA = 261,                   /* COMMA  */
    EQUAL = 262,                   /* EQUAL  */
    LBRACKET = 263,                /* LBRACKET  */
    RBRACKET = 264,                /* RBRACKET  */
    LBRACE = 265,                  /* LBRACE  */
    RBRACE = 266,                  /* RBRACE  */
    LPARE = 267,                   /* LPARE  */
    RPARE = 268,                   /* RPARE  */
    OPE_NOT = 269,                 /* OPE_NOT  */
    OPE_ADD = 270,                 /* OPE_ADD  */
    OPE_SUB = 271,                 /* OPE_SUB  */
    OPE_MUL = 272,                 /* OPE_MUL  */
    OPE_DIV = 273,                 /* OPE_DIV  */
    OPE_MOD = 274,                 /* OPE_MOD  */
    OPE_AND = 275,                 /* OPE_AND  */
    OPE_OR = 276,                  /* OPE_OR  */
    OPE_EQU = 277,                 /* OPE_EQU  */
    OPE_NEQ = 278,                 /* OPE_NEQ  */
    OPE_LEQ = 279,                 /* OPE_LEQ  */
    OPE_GEQ = 280,                 /* OPE_GEQ  */
    OPE_LSS = 281,                 /* OPE_LSS  */
    OPE_GTR = 282,                 /* OPE_GTR  */
    DECIMAL_CONST = 283,           /* DECIMAL_CONST  */
    OCTAL_CONST = 284,             /* OCTAL_CONST  */
    HEXADECIMAL_CONST = 285,       /* HEXADECIMAL_CONST  */
    FLOAT_CONST = 286,             /* FLOAT_CONST  */
    IDENTIFIER = 287,              /* IDENTIFIER  */
    KEYWORD_CONST = 288,           /* KEYWORD_CONST  */
    KEYWORD_INT = 289,             /* KEYWORD_INT  */
    KEYWORD_FLOAT = 290,           /* KEYWORD_FLOAT  */
    KEYWORD_VOID = 291,            /* KEYWORD_VOID  */
    KEYWORD_IF = 292,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 293,            /* KEYWORD_ELSE  */
    KEYWORD_WHILE = 294,           /* KEYWORD_WHILE  */
    KEYWORD_CONTINUE = 295,        /* KEYWORD_CONTINUE  */
    KEYWORD_BREAK = 296,           /* KEYWORD_BREAK  */
    KEYWORD_RETURN = 297           /* KEYWORD_RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"

    ObjTree::ObjUuid node_uuid;
    const char* raw_string;

#line 118 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (ObjTree::ObjManager* obj_manager);


#endif /* !YY_YY_HOME_GGN_DESKTOP_GITHUB_COMPILER2022_X_FRONTEND_YACCLEX_BUILD_SYSY_TAB_HPP_INCLUDED  */
