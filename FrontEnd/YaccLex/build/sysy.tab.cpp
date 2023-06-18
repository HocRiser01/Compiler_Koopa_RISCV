/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"


// 声明 lexer 函数和错误处理函数
int yylex();
extern int line_number;

#include "../../../ObjTree/ObjManager.h"
void yyerror(ObjTree::ObjManager* obj_manager, const char *s);

using namespace std;


#line 84 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sysy.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEYWORD_INT_FUNC = 3,           /* KEYWORD_INT_FUNC  */
  YYSYMBOL_KEYWORD_FLOAT_FUNC = 4,         /* KEYWORD_FLOAT_FUNC  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_EQUAL = 7,                      /* EQUAL  */
  YYSYMBOL_LBRACKET = 8,                   /* LBRACKET  */
  YYSYMBOL_RBRACKET = 9,                   /* RBRACKET  */
  YYSYMBOL_LBRACE = 10,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 11,                    /* RBRACE  */
  YYSYMBOL_LPARE = 12,                     /* LPARE  */
  YYSYMBOL_RPARE = 13,                     /* RPARE  */
  YYSYMBOL_OPE_NOT = 14,                   /* OPE_NOT  */
  YYSYMBOL_OPE_ADD = 15,                   /* OPE_ADD  */
  YYSYMBOL_OPE_SUB = 16,                   /* OPE_SUB  */
  YYSYMBOL_OPE_MUL = 17,                   /* OPE_MUL  */
  YYSYMBOL_OPE_DIV = 18,                   /* OPE_DIV  */
  YYSYMBOL_OPE_MOD = 19,                   /* OPE_MOD  */
  YYSYMBOL_OPE_AND = 20,                   /* OPE_AND  */
  YYSYMBOL_OPE_OR = 21,                    /* OPE_OR  */
  YYSYMBOL_OPE_EQU = 22,                   /* OPE_EQU  */
  YYSYMBOL_OPE_NEQ = 23,                   /* OPE_NEQ  */
  YYSYMBOL_OPE_LEQ = 24,                   /* OPE_LEQ  */
  YYSYMBOL_OPE_GEQ = 25,                   /* OPE_GEQ  */
  YYSYMBOL_OPE_LSS = 26,                   /* OPE_LSS  */
  YYSYMBOL_OPE_GTR = 27,                   /* OPE_GTR  */
  YYSYMBOL_DECIMAL_CONST = 28,             /* DECIMAL_CONST  */
  YYSYMBOL_OCTAL_CONST = 29,               /* OCTAL_CONST  */
  YYSYMBOL_HEXADECIMAL_CONST = 30,         /* HEXADECIMAL_CONST  */
  YYSYMBOL_FLOAT_CONST = 31,               /* FLOAT_CONST  */
  YYSYMBOL_IDENTIFIER = 32,                /* IDENTIFIER  */
  YYSYMBOL_KEYWORD_CONST = 33,             /* KEYWORD_CONST  */
  YYSYMBOL_KEYWORD_INT = 34,               /* KEYWORD_INT  */
  YYSYMBOL_KEYWORD_FLOAT = 35,             /* KEYWORD_FLOAT  */
  YYSYMBOL_KEYWORD_VOID = 36,              /* KEYWORD_VOID  */
  YYSYMBOL_KEYWORD_IF = 37,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 38,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_WHILE = 39,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_CONTINUE = 40,          /* KEYWORD_CONTINUE  */
  YYSYMBOL_KEYWORD_BREAK = 41,             /* KEYWORD_BREAK  */
  YYSYMBOL_KEYWORD_RETURN = 42,            /* KEYWORD_RETURN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_CompUnit = 44,                  /* CompUnit  */
  YYSYMBOL_CompUnitDef = 45,               /* CompUnitDef  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_ConstDecl = 47,                 /* ConstDecl  */
  YYSYMBOL_BType = 48,                     /* BType  */
  YYSYMBOL_ConstDefList = 49,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 50,                  /* ConstDef  */
  YYSYMBOL_ArrayIndexList = 51,            /* ArrayIndexList  */
  YYSYMBOL_InitVal = 52,                   /* InitVal  */
  YYSYMBOL_InitValList = 53,               /* InitValList  */
  YYSYMBOL_VarDecl = 54,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 55,                /* VarDefList  */
  YYSYMBOL_VarDef = 56,                    /* VarDef  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_FuncType = 58,                  /* FuncType  */
  YYSYMBOL_FuncFParams = 59,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 60,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArrayIndexList = 61,  /* FuncFParamArrayIndexList  */
  YYSYMBOL_Block = 62,                     /* Block  */
  YYSYMBOL_BlockItemList = 63,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 64,                 /* BlockItem  */
  YYSYMBOL_Stmt = 65,                      /* Stmt  */
  YYSYMBOL_IntConst = 66,                  /* IntConst  */
  YYSYMBOL_FloatConst = 67,                /* FloatConst  */
  YYSYMBOL_Exp = 68,                       /* Exp  */
  YYSYMBOL_Cond = 69,                      /* Cond  */
  YYSYMBOL_LVal = 70,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 71,                /* PrimaryExp  */
  YYSYMBOL_Number = 72,                    /* Number  */
  YYSYMBOL_UnaryExp = 73,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 74,                   /* UnaryOp  */
  YYSYMBOL_FuncRPAREms = 75,               /* FuncRPAREms  */
  YYSYMBOL_MulExp = 76,                    /* MulExp  */
  YYSYMBOL_MulOp = 77,                     /* MulOp  */
  YYSYMBOL_AddExp = 78,                    /* AddExp  */
  YYSYMBOL_AddOp = 79,                     /* AddOp  */
  YYSYMBOL_RelExp = 80,                    /* RelExp  */
  YYSYMBOL_RelOp = 81,                     /* RelOp  */
  YYSYMBOL_EqExp = 82,                     /* EqExp  */
  YYSYMBOL_EqOp = 83,                      /* EqOp  */
  YYSYMBOL_LAndExp = 84,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 85                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    52,    62,    69,    79,    86,    96,   106,
     113,   123,   130,   140,   152,   157,   167,   175,   186,   193,
     203,   213,   220,   230,   238,   249,   257,   268,   275,   282,
     292,   299,   309,   320,   326,   332,   342,   353,   358,   368,
     375,   385,   392,   398,   405,   412,   420,   428,   436,   443,
     450,   457,   468,   475,   482,   492,   502,   512,   522,   533,
     540,   547,   557,   564,   574,   581,   588,   596,   606,   613,
     620,   630,   637,   647,   654,   664,   671,   678,   688,   695,
     705,   712,   722,   729,   739,   746,   753,   760,   770,   777,
     787,   794,   804,   811,   821,   828
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD_INT_FUNC",
  "KEYWORD_FLOAT_FUNC", "SEMICOLON", "COMMA", "EQUAL", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "LPARE", "RPARE", "OPE_NOT", "OPE_ADD",
  "OPE_SUB", "OPE_MUL", "OPE_DIV", "OPE_MOD", "OPE_AND", "OPE_OR",
  "OPE_EQU", "OPE_NEQ", "OPE_LEQ", "OPE_GEQ", "OPE_LSS", "OPE_GTR",
  "DECIMAL_CONST", "OCTAL_CONST", "HEXADECIMAL_CONST", "FLOAT_CONST",
  "IDENTIFIER", "KEYWORD_CONST", "KEYWORD_INT", "KEYWORD_FLOAT",
  "KEYWORD_VOID", "KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_WHILE",
  "KEYWORD_CONTINUE", "KEYWORD_BREAK", "KEYWORD_RETURN", "$accept",
  "CompUnit", "CompUnitDef", "Decl", "ConstDecl", "BType", "ConstDefList",
  "ConstDef", "ArrayIndexList", "InitVal", "InitValList", "VarDecl",
  "VarDefList", "VarDef", "FuncDef", "FuncType", "FuncFParams",
  "FuncFParam", "FuncFParamArrayIndexList", "Block", "BlockItemList",
  "BlockItem", "Stmt", "IntConst", "FloatConst", "Exp", "Cond", "LVal",
  "PrimaryExp", "Number", "UnaryExp", "UnaryOp", "FuncRPAREms", "MulExp",
  "MulOp", "AddExp", "AddOp", "RelExp", "RelOp", "EqExp", "EqOp",
  "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,  -125,  -125,   -23,  -125,  -125,  -125,    64,  -125,  -125,
    -125,   -27,  -125,  -125,   -12,    -4,  -125,  -125,  -125,   105,
    -125,    10,  -125,   129,  -125,   136,  -125,   -27,   -10,   153,
    -125,    -4,   117,   143,  -125,    20,    15,    74,  -125,   117,
    -125,   117,   143,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
      43,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   143,
      90,   121,    48,  -125,  -125,    62,   -23,    20,  -125,  -125,
      35,    53,   138,    70,  -125,  -125,  -125,  -125,   143,  -125,
    -125,   143,  -125,     3,    73,    88,  -125,  -125,   117,  -125,
    -125,  -125,  -125,    89,  -125,    90,  -125,  -125,   101,   104,
     116,   118,   110,  -125,  -125,  -125,  -125,   123,   149,  -125,
     143,  -125,   143,  -125,   143,   143,  -125,  -125,  -125,   125,
    -125,   143,   155,  -125,   152,   121,    79,   140,   156,   157,
     164,  -125,   174,  -125,    44,  -125,  -125,  -125,  -125,   143,
    -125,  -125,   143,   143,   143,    44,  -125,   142,   121,    79,
     140,   156,  -125,    44,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    28,    29,     0,     9,    10,    27,     0,     2,     4,
       6,     0,     7,     5,     0,     0,     1,     3,    14,     0,
      21,     0,    14,     0,    11,    23,    20,     0,     0,     0,
       8,     0,     0,     0,    22,     0,     0,     0,    30,     0,
      12,     0,     0,    70,    68,    69,    52,    53,    54,    55,
      14,    24,    62,    63,    16,    60,    64,    61,    73,     0,
      78,    56,     0,    37,    25,    33,     0,     0,    13,    18,
       0,     0,     0,    58,    67,    75,    76,    77,     0,    80,
      81,     0,    15,     0,     0,    32,    31,    26,     0,    17,
      59,    65,    71,     0,    74,    79,    42,    36,     0,     0,
       0,     0,     0,    39,    44,    38,    40,     0,    60,    34,
       0,    19,     0,    66,     0,     0,    49,    48,    50,     0,
      43,     0,     0,    72,     0,    82,    88,    92,    94,    57,
       0,    51,     0,    35,     0,    85,    87,    84,    86,     0,
      90,    91,     0,     0,     0,     0,    41,    45,    83,    89,
      93,    95,    47,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,   175,    98,  -125,    -1,  -125,   154,     1,   -35,
    -125,  -125,  -125,   159,  -125,  -125,  -125,   122,  -125,   -19,
    -125,  -125,  -124,  -125,  -125,   -33,    68,   -82,  -125,  -125,
     -52,  -125,  -125,   103,  -125,   -25,  -125,    45,  -125,    46,
    -125,    47,  -125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    23,    24,    25,    51,
      70,    12,    19,    20,    13,    14,    37,    38,    85,   104,
      83,   105,   106,    52,    53,    54,   124,    55,    56,    57,
      58,    59,    93,    60,    78,    61,    81,   126,   139,   127,
     142,   128,   129
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,   108,    15,    35,    68,    18,    69,    74,    96,    71,
     147,     4,     5,    63,    97,    42,    64,    43,    44,    45,
      21,   152,    28,    29,     4,     5,    94,    36,    22,   154,
      63,    46,    47,    48,    49,    50,     3,     4,     5,    92,
      98,    88,    99,   100,   101,   102,    89,    65,    87,    96,
     107,    73,   108,   111,    63,    72,    42,    82,    43,    44,
      45,     1,     2,   108,    16,    36,    90,     1,     2,   119,
      84,   108,    46,    47,    48,    49,    50,   122,    33,   123,
      66,    98,   109,    99,   100,   101,   102,    67,   132,   125,
     125,     3,     4,     5,     6,   112,   110,     3,     4,     5,
       6,   107,   113,   135,   136,   137,   138,    75,    76,    77,
      26,    27,   107,   114,   148,   118,   115,   125,   125,   125,
     107,   116,    42,   117,    43,    44,    45,    41,   120,    42,
     131,    43,    44,    45,    30,    31,    79,    80,    46,    47,
      48,    49,    50,    32,    33,    46,    47,    48,    49,    50,
      42,    91,    43,    44,    45,    42,   121,    43,    44,    45,
      39,    33,   140,   141,   133,   134,    46,    47,    48,    49,
      50,    46,    47,    48,    49,    50,   143,   145,   144,   146,
     153,   103,    17,   130,    95,    40,    34,   149,    86,   150,
       0,   151
};

static const yytype_int16 yycheck[] =
{
      33,    83,     3,    13,    39,    32,    41,    59,     5,    42,
     134,    34,    35,    10,    11,    12,    35,    14,    15,    16,
      32,   145,    12,    22,    34,    35,    78,    28,    32,   153,
      10,    28,    29,    30,    31,    32,    33,    34,    35,    72,
      37,     6,    39,    40,    41,    42,    11,    32,    67,     5,
      83,    50,   134,    88,    10,    12,    12,     9,    14,    15,
      16,     3,     4,   145,     0,    66,    13,     3,     4,   102,
       8,   153,    28,    29,    30,    31,    32,   110,     8,   112,
       6,    37,     9,    39,    40,    41,    42,    13,   121,   114,
     115,    33,    34,    35,    36,     6,     8,    33,    34,    35,
      36,   134,    13,    24,    25,    26,    27,    17,    18,    19,
       5,     6,   145,    12,   139,     5,    12,   142,   143,   144,
     153,     5,    12,     5,    14,    15,    16,    10,     5,    12,
       5,    14,    15,    16,     5,     6,    15,    16,    28,    29,
      30,    31,    32,     7,     8,    28,    29,    30,    31,    32,
      12,    13,    14,    15,    16,    12,     7,    14,    15,    16,
       7,     8,    22,    23,     9,    13,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    20,    13,    21,     5,
      38,    83,     7,   115,    81,    31,    27,   142,    66,   143,
      -1,   144
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    33,    34,    35,    36,    44,    45,    46,
      47,    48,    54,    57,    58,    48,     0,    45,    32,    55,
      56,    32,    32,    49,    50,    51,     5,     6,    12,    51,
       5,     6,     7,     8,    56,    13,    48,    59,    60,     7,
      50,    10,    12,    14,    15,    16,    28,    29,    30,    31,
      32,    52,    66,    67,    68,    70,    71,    72,    73,    74,
      76,    78,    68,    10,    62,    32,     6,    13,    52,    52,
      53,    68,    12,    51,    73,    17,    18,    19,    77,    15,
      16,    79,     9,    63,     8,    61,    60,    62,     6,    11,
      13,    13,    68,    75,    73,    76,     5,    11,    37,    39,
      40,    41,    42,    46,    62,    64,    65,    68,    70,     9,
       8,    52,     6,    13,    12,    12,     5,     5,     5,    68,
       5,     7,    68,    68,    69,    78,    80,    82,    84,    85,
      69,     5,    68,     9,    13,    24,    25,    26,    27,    81,
      22,    23,    83,    20,    21,    13,     5,    65,    78,    80,
      82,    84,    65,    38,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    47,    48,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    68,    69,    70,    71,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     4,     0,     4,     1,     3,     1,     3,
       3,     1,     3,     2,     4,     5,     6,     1,     1,     1,
       1,     3,     3,     0,     2,     4,     3,     0,     2,     1,
       1,     4,     1,     2,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     4,     2,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (obj_manager, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, obj_manager); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ObjTree::ObjManager* obj_manager)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (obj_manager);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ObjTree::ObjManager* obj_manager)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, obj_manager);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ObjTree::ObjManager* obj_manager)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], obj_manager);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, obj_manager); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ObjTree::ObjManager* obj_manager)
{
  YY_USE (yyvaluep);
  YY_USE (obj_manager);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ObjTree::ObjManager* obj_manager)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: CompUnitDef  */
#line 46 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1286 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 3: /* CompUnit: CompUnit CompUnitDef  */
#line 53 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1297 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 4: /* CompUnitDef: Decl  */
#line 63 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitDefAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1308 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 5: /* CompUnitDef: FuncDef  */
#line 70 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitDefAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1319 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 80 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "DeclAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1330 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 87 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "DeclAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1341 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 8: /* ConstDecl: KEYWORD_CONST BType ConstDefList SEMICOLON  */
#line 97 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDeclAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1352 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 9: /* BType: KEYWORD_INT  */
#line 107 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BTypeAst");
            obj_manager->set_info(uuid, "KEYWORD_INT");
            (yyval.node_uuid) = uuid;
        }
#line 1363 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 10: /* BType: KEYWORD_FLOAT  */
#line 114 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BTypeAst");
            obj_manager->set_info(uuid, "KEYWORD_FLOAT");
            (yyval.node_uuid) = uuid;
        }
#line 1374 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 124 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefListAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1385 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 12: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 131 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefListAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1396 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 13: /* ConstDef: IDENTIFIER ArrayIndexList EQUAL InitVal  */
#line 141 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefAst");
            obj_manager->set_info(uuid, (yyvsp[-3].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1408 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 14: /* ArrayIndexList: %empty  */
#line 152 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ArrayIndexListAst"); // no sons
            (yyval.node_uuid) = uuid;
        }
#line 1418 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 15: /* ArrayIndexList: ArrayIndexList LBRACKET Exp RBRACKET  */
#line 158 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ArrayIndexListAst");
            obj_manager->add_son(uuid, {(yyvsp[-3].node_uuid), (yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1429 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 16: /* InitVal: Exp  */
#line 168 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValAst");
            obj_manager->set_info(uuid, "Exp"); // single exp
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1441 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 17: /* InitVal: LBRACE InitValList RBRACE  */
#line 176 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValAst");
            obj_manager->set_info(uuid, "InitValList"); // initialization list
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1453 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 18: /* InitValList: InitVal  */
#line 187 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValListAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1464 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 19: /* InitValList: InitValList COMMA InitVal  */
#line 194 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValListAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1475 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 20: /* VarDecl: BType VarDefList SEMICOLON  */
#line 204 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDeclAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1486 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 21: /* VarDefList: VarDef  */
#line 214 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefListAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1497 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 22: /* VarDefList: VarDefList COMMA VarDef  */
#line 221 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefListAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1508 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 23: /* VarDef: IDENTIFIER ArrayIndexList  */
#line 231 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefAst");
            obj_manager->set_info(uuid, (yyvsp[-1].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1520 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 24: /* VarDef: IDENTIFIER ArrayIndexList EQUAL InitVal  */
#line 239 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefAst");
            obj_manager->set_info(uuid, (yyvsp[-3].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1532 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 25: /* FuncDef: FuncType IDENTIFIER LPARE RPARE Block  */
#line 250 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncDefAst");
            obj_manager->set_info(uuid, (yyvsp[-3].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-4].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1544 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 26: /* FuncDef: FuncType IDENTIFIER LPARE FuncFParams RPARE Block  */
#line 258 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncDefAst");
            obj_manager->set_info(uuid, (yyvsp[-4].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-5].node_uuid), (yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1556 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 27: /* FuncType: KEYWORD_VOID  */
#line 269 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1567 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 28: /* FuncType: KEYWORD_INT_FUNC  */
#line 276 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1578 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 29: /* FuncType: KEYWORD_FLOAT_FUNC  */
#line 283 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1589 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 30: /* FuncFParams: FuncFParam  */
#line 293 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamsAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1600 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 31: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 300 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamsAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1611 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 32: /* FuncFParam: BType IDENTIFIER FuncFParamArrayIndexList  */
#line 310 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamAst");
            obj_manager->set_info(uuid, (yyvsp[-1].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1623 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 33: /* FuncFParamArrayIndexList: %empty  */
#line 320 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            obj_manager->set_info(uuid, "Empty");
            (yyval.node_uuid) = uuid;
        }
#line 1634 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 34: /* FuncFParamArrayIndexList: LBRACKET RBRACKET  */
#line 327 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            (yyval.node_uuid) = uuid;
        }
#line 1644 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 35: /* FuncFParamArrayIndexList: FuncFParamArrayIndexList LBRACKET Exp RBRACKET  */
#line 333 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            obj_manager->add_son(uuid, {(yyvsp[-3].node_uuid), (yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1655 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 36: /* Block: LBRACE BlockItemList RBRACE  */
#line 343 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1666 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 37: /* BlockItemList: %empty  */
#line 353 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemListAst");
            (yyval.node_uuid) = uuid;
        }
#line 1676 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 38: /* BlockItemList: BlockItemList BlockItem  */
#line 359 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemListAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1687 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 39: /* BlockItem: Decl  */
#line 369 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)}); // 通过子节点类型区分
            (yyval.node_uuid) = uuid;
        }
#line 1698 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 40: /* BlockItem: Stmt  */
#line 376 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)}); // 通过子节点类型区分
            (yyval.node_uuid) = uuid;
        }
#line 1709 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 41: /* Stmt: LVal EQUAL Exp SEMICOLON  */
#line 386 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {(yyvsp[-3].node_uuid), (yyvsp[-1].node_uuid)}); // 区分不同产生式的方法：根据子节点的个数和类型
            (yyval.node_uuid) = uuid;
        }
#line 1720 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 42: /* Stmt: SEMICOLON  */
#line 393 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            (yyval.node_uuid) = uuid;
        }
#line 1730 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 43: /* Stmt: Exp SEMICOLON  */
#line 399 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1741 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 44: /* Stmt: Block  */
#line 406 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1752 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 45: /* Stmt: KEYWORD_IF LPARE Cond RPARE Stmt  */
#line 413 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "If"); // 区分 If, IfElse, While 不得不使用 info
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1764 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 46: /* Stmt: KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt  */
#line 421 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "IfElse");
            obj_manager->add_son(uuid, {(yyvsp[-4].node_uuid), (yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1776 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 47: /* Stmt: KEYWORD_WHILE LPARE Cond RPARE Stmt  */
#line 429 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "While");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1788 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 48: /* Stmt: KEYWORD_BREAK SEMICOLON  */
#line 437 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Break"); // 区分空语句，Break, Continue, Return 也需要使用 info
            (yyval.node_uuid) = uuid;
        }
#line 1799 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 49: /* Stmt: KEYWORD_CONTINUE SEMICOLON  */
#line 444 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Continue");
            (yyval.node_uuid) = uuid;
        }
#line 1810 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 50: /* Stmt: KEYWORD_RETURN SEMICOLON  */
#line 451 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Return");
            (yyval.node_uuid) = uuid;
        }
#line 1821 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 51: /* Stmt: KEYWORD_RETURN Exp SEMICOLON  */
#line 458 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "ReturnExp");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1833 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 52: /* IntConst: DECIMAL_CONST  */
#line 469 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1844 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 53: /* IntConst: OCTAL_CONST  */
#line 476 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1855 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 54: /* IntConst: HEXADECIMAL_CONST  */
#line 483 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1866 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 55: /* FloatConst: FLOAT_CONST  */
#line 493 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FloatConstAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1877 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 56: /* Exp: AddExp  */
#line 503 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1888 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 57: /* Cond: LOrExp  */
#line 513 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CondAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1899 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 58: /* LVal: IDENTIFIER ArrayIndexList  */
#line 523 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LValAst");
            obj_manager->set_info(uuid, (yyvsp[-1].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1911 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 59: /* PrimaryExp: LPARE Exp RPARE  */
#line 534 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1922 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 60: /* PrimaryExp: LVal  */
#line 541 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1933 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 61: /* PrimaryExp: Number  */
#line 548 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1944 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 62: /* Number: IntConst  */
#line 558 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "NumberAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1955 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 63: /* Number: FloatConst  */
#line 565 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "NumberAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1966 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 64: /* UnaryExp: PrimaryExp  */
#line 575 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 1977 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 65: /* UnaryExp: IDENTIFIER LPARE RPARE  */
#line 582 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->set_info(uuid, (yyvsp[-2].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 1988 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 66: /* UnaryExp: IDENTIFIER LPARE FuncRPAREms RPARE  */
#line 589 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->set_info(uuid, (yyvsp[-3].raw_string));
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid)}); // 通过 info 和参数个数区分产生式
            (yyval.node_uuid) = uuid;
        }
#line 2000 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 67: /* UnaryExp: UnaryOp UnaryExp  */
#line 597 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2011 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 68: /* UnaryOp: OPE_ADD  */
#line 607 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 2022 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 69: /* UnaryOp: OPE_SUB  */
#line 614 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 2033 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 70: /* UnaryOp: OPE_NOT  */
#line 621 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, (yyvsp[0].raw_string));
            (yyval.node_uuid) = uuid;
        }
#line 2044 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 71: /* FuncRPAREms: Exp  */
#line 631 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncRPAREmsAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2055 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 72: /* FuncRPAREms: FuncRPAREms COMMA Exp  */
#line 638 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncRPAREmsAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2066 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 73: /* MulExp: UnaryExp  */
#line 648 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2077 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 74: /* MulExp: MulExp MulOp UnaryExp  */
#line 655 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2088 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 75: /* MulOp: OPE_MUL  */
#line 665 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "*");
            (yyval.node_uuid) = uuid;
        }
#line 2099 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 76: /* MulOp: OPE_DIV  */
#line 672 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "/");
            (yyval.node_uuid) = uuid;
        }
#line 2110 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 77: /* MulOp: OPE_MOD  */
#line 679 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "%");
            (yyval.node_uuid) = uuid;
        }
#line 2121 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 78: /* AddExp: MulExp  */
#line 689 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2132 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 79: /* AddExp: AddExp AddOp MulExp  */
#line 696 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2143 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 80: /* AddOp: OPE_ADD  */
#line 706 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddOpAst");
            obj_manager->set_info(uuid, "+");
            (yyval.node_uuid) = uuid;
        }
#line 2154 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 81: /* AddOp: OPE_SUB  */
#line 713 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddOpAst");
            obj_manager->set_info(uuid, "-");
            (yyval.node_uuid) = uuid;
        }
#line 2165 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 82: /* RelExp: AddExp  */
#line 723 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2176 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 83: /* RelExp: RelExp RelOp AddExp  */
#line 730 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2187 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 84: /* RelOp: OPE_LSS  */
#line 740 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, "<");
            (yyval.node_uuid) = uuid;
        }
#line 2198 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 85: /* RelOp: OPE_LEQ  */
#line 747 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, "<=");
            (yyval.node_uuid) = uuid;
        }
#line 2209 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 86: /* RelOp: OPE_GTR  */
#line 754 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, ">");
            (yyval.node_uuid) = uuid;
        }
#line 2220 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 87: /* RelOp: OPE_GEQ  */
#line 761 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, ">=");
            (yyval.node_uuid) = uuid;
        }
#line 2231 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 88: /* EqExp: RelExp  */
#line 771 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2242 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 89: /* EqExp: EqExp EqOp RelExp  */
#line 778 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[-1].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2253 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 90: /* EqOp: OPE_EQU  */
#line 788 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqOpAst");
            obj_manager->set_info(uuid, "==");
            (yyval.node_uuid) = uuid;
        }
#line 2264 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 91: /* EqOp: OPE_NEQ  */
#line 795 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqOpAst");
            obj_manager->set_info(uuid, "!=");
            (yyval.node_uuid) = uuid;
        }
#line 2275 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 92: /* LAndExp: EqExp  */
#line 805 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LAndExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2286 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 93: /* LAndExp: LAndExp OPE_AND EqExp  */
#line 812 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LAndExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2297 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 94: /* LOrExp: LAndExp  */
#line 822 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LOrExpAst");
            obj_manager->add_son(uuid, {(yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2308 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;

  case 95: /* LOrExp: LOrExp OPE_OR LAndExp  */
#line 829 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LOrExpAst");
            obj_manager->add_son(uuid, {(yyvsp[-2].node_uuid), (yyvsp[0].node_uuid)});
            (yyval.node_uuid) = uuid;
        }
#line 2319 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"
    break;


#line 2323 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/build/sysy.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (obj_manager, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, obj_manager);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, obj_manager);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (obj_manager, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, obj_manager);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, obj_manager);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 837 "/home/ggn/Desktop/Github/compiler2022-x/FrontEnd/YaccLex/src/sysy.y"


int line_number = 1;

// output error message
void yyerror(ObjTree::ObjManager* obj_manager, const char *s) {
  cerr << make_error_message((std::string(s) + " line in sy code: " + std::to_string(line_number)).c_str()) << endl;
}
