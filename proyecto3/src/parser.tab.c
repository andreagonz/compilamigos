/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "nodo.h"
#include "tabla.h"
#include "visitor.h"
    
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

extern int linea;
extern int col;
 
void yyerror(const char *s);
queue<Nodo*> * nodos = new queue<Nodo*>();
VisitorCreaTabla * vct = new VisitorCreaTabla();
string archivo;
ofstream codefile;

#line 92 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TRUE = 258,
    FALSE = 259,
    ENTERO = 260,
    FLOTANTE = 261,
    BOOLEANO = 262,
    LPAR = 263,
    RPAR = 264,
    SEMIC = 265,
    ASIG = 266,
    EQ = 267,
    NEQ = 268,
    LESS = 269,
    GREAT = 270,
    LESSEQ = 271,
    GREATEQ = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    PLUS = 276,
    MINUS = 277,
    MULT = 278,
    DIV = 279,
    INT = 280,
    FLOAT = 281,
    ID = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:355  */

  int ival;
  float fval; 
  char* sval;
  Nodo *nval;

#line 167 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 184 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   58

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  67

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    74,    81,    85,    93,    94,    97,   103,
     110,   114,   121,   124,   131,   138,   142,   149,   156,   163,
     170,   174,   181,   188,   192,   199,   207,   213,   217,   221,
     225,   232,   239,   243,   249,   257,   258,   262,   269,   279,
     286,   291,   299,   304,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "ENTERO", "FLOTANTE",
  "BOOLEANO", "LPAR", "RPAR", "SEMIC", "ASIG", "EQ", "NEQ", "LESS",
  "GREAT", "LESSEQ", "GREATEQ", "AND", "OR", "NOT", "PLUS", "MINUS",
  "MULT", "DIV", "INT", "FLOAT", "ID", "$accept", "S", "Prog", "ProgPrim",
  "Inst", "Expr", "Bexp", "Bterm", "Beq", "Bcomp", "ExprPrim", "Term",
  "Factor", "Bool", "Asig", "AsigPrim", "Easig", "Id", "Num", "Tipo", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       3,   -21,   -21,   -21,   -21,   -21,    12,    12,    12,   -21,
     -21,   -21,    17,     3,   -21,    14,   -21,    16,    15,   -10,
      26,    -9,    -5,   -21,   -21,   -21,   -21,   -21,    25,   -21,
      24,    43,   -21,   -21,   -21,   -21,   -21,   -21,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   -21,    25,   -21,    15,   -10,    26,    26,    -9,    -9,
      -9,    -9,    -5,    -5,   -21,   -21,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,    34,    42,    43,    44,     0,     0,     0,    41,
      40,    39,     0,     2,     4,     0,     6,     8,    10,    12,
      15,    20,    23,    26,    32,     7,    36,    35,    27,    28,
       0,     0,    27,    31,    30,     1,     3,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    29,     9,    11,    13,    14,    16,    17,
      18,    19,    21,    22,    24,    25,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,    40,   -21,    -6,   -21,    18,    19,   -19,
       5,   -20,    -3,   -21,   -21,   -21,    27,     1,   -21,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    32,    29,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    28,    40,    41,    33,    34,     1,     2,     3,     4,
       5,     6,    46,    47,    28,     1,     2,    35,    48,    49,
       6,    56,    57,     7,    37,     8,    62,    63,     9,    10,
      11,    52,     7,    39,     8,    38,    50,     9,    10,    11,
      42,    43,    44,    45,    66,    64,    65,    58,    59,    60,
      61,    11,    53,    36,     0,     0,    54,    51,    55
};

static const yytype_int8 yycheck[] =
{
       6,     0,    12,    13,     7,     8,     3,     4,     5,     6,
       7,     8,    21,    22,    13,     3,     4,     0,    23,    24,
       8,    40,    41,    20,    10,    22,    46,    47,    25,    26,
      27,    30,    20,    18,    22,    19,    11,    25,    26,    27,
      14,    15,    16,    17,    50,    48,    49,    42,    43,    44,
      45,    27,     9,    13,    -1,    -1,    38,    30,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    20,    22,    25,
      26,    27,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    33,    45,    40,    40,     0,    31,    10,    19,    18,
      12,    13,    14,    15,    16,    17,    21,    22,    23,    24,
      11,    44,    45,     9,    35,    36,    37,    37,    38,    38,
      38,    38,    39,    39,    40,    40,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    32,    32,    33,    34,
      34,    35,    35,    36,    36,    36,    37,    37,    37,    37,
      37,    38,    38,    38,    39,    39,    39,    40,    40,    40,
      40,    40,    40,    41,    41,    42,    42,    43,    44,    45,
      46,    46,    47,    47,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       2,     2,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 57 "parser.y" /* yacc.c:1646  */
    {
  (yyval.nval) = (yyvsp[0].nval);
  ofstream arbol;
  arbol.open (archivo + ".asa");
  arbol << str((yyval.nval));
  arbol.close();
  (yyval.nval)->accept(vct);
  if(!vct->tuvo_error()) {
        VisitorVerificaTipos * vvt = new VisitorVerificaTipos();
        (yyval.nval)->accept(vvt);
        if(!vvt->tuvo_error()) {
            cout << "Todo bien" << endl;
        }
  }
 }
#line 1314 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "parser.y" /* yacc.c:1646  */
    {
  Nodo *n = new NodoSeq("seq");
  n->add((yyvsp[-1].nval));
  nodos->push(n);
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1326 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "parser.y" /* yacc.c:1646  */
    {
      Nodo *n = new NodoSeq("seq");
      n->add((yyvsp[-1].nval));
      nodos->push(n);
      (yyval.nval) = n; }
#line 1342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1354 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "parser.y" /* yacc.c:1646  */
    {
  (yyval.nval) = (yyvsp[0].nval); 
}
#line 1362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoOr("or");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoAnd("and");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval);  }
#line 1398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoEq("==");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1410 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoNeq("!=");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 142 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoLess("<");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoGreat(">");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 156 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoLessEq("<=");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoGreatEq(">=");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoSum("+");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoMenos("-");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 192 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoMult("*");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoDiv("/");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 207 "parser.y" /* yacc.c:1646  */
    {
  (yyval.nval) = (yyvsp[0].nval);
}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "parser.y" /* yacc.c:1646  */
    {
  (yyval.nval) = (yyvsp[0].nval);
}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 217 "parser.y" /* yacc.c:1646  */
    {
  (yyval.nval) = (yyvsp[0].nval);
}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 221 "parser.y" /* yacc.c:1646  */
    {
    (yyval.nval) = (yyvsp[-1].nval);
}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 225 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoNeg("-");
  n->add((yyvsp[0].nval));
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 232 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoNot("not");
  n->add((yyvsp[0].nval));
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoBool("true");
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 249 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoBool("false");
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].nval)->add((yyvsp[0].nval));
  (yyval.nval) = (yyvsp[-1].nval);
}
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 269 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoAsig("=");
  nodos->push(n);
  n->add((yyvsp[-2].nval));
  n->add((yyvsp[0].nval));
  (yyval.nval) = n;
}
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 279 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoId((yyvsp[0].sval));
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 286 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoFloat((yyvsp[0].sval));
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 291 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoInt((yyvsp[0].sval));
  nodos->push(n);
  (yyval.nval) = n;
}
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 299 "parser.y" /* yacc.c:1646  */
    {
    Nodo * n = new NodoTipo("int", TINT);
    nodos->push(n);
    (yyval.nval) = n;
}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 304 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoTipo("float", TFLOAT);
  nodos->push(n);
  (yyval.nval) = n;
  }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 309 "parser.y" /* yacc.c:1646  */
    {
  Nodo * n = new NodoTipo("bool", TBOOL);
  nodos->push(n);
  (yyval.nval) = n;
  }
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1713 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 315 "parser.y" /* yacc.c:1906  */


/* Epilogo */

/* Función para liberar espacio de los nodos */
void clear() {
    while(!nodos->empty()) {
        Nodo *n = nodos->front();
        //cout << n->str() << endl;
        nodos->pop();
        delete n;
    }
    delete nodos;
}

//Metodo que marca los nodos de seq y pone cuanto nodos de secuencia tiene en su arbol contandolo a ellos
int transTreeSeqs(Nodo *nodo){	
	int seqs = 0;
        std::string seqstr = "(seq)";
	if(seqstr.compare(nodo->str()) == 0){
		seqs += 1;
	}
        
	int numhijos = nodo->num_hijos();
	for(int i = 0; i < numhijos; i++){
		seqs += transTreeSeqs(nodo->get(i));
	}

	nodo->set_num_seqs(seqs);
	return seqs;
}

//Metodo que nos dice si una cadena es un entero
inline bool isNumber(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}


//Metodo que nos dice si una cadena es un float
bool isFloat(const std::string & s)
{
   char * p ;
   strtod(s.c_str(), &p) ;

   return (*p == 0) ;
}


//Metodo que genera el codigo en x86-64 (AUXILIAR)
void genCodeOpera(Nodo *nodo, int reg, std::string tipo){

	int vars = nodo->num_vars();
	int numhijos = nodo->num_hijos();
	std::string nodo_value = nodo->get_valor();

	if( nodo_value.compare("+") == 0 || nodo_value.compare("-") == 0 || nodo_value.compare("*") == 0 || nodo_value.compare("/") == 0 ){
		Nodo *h0 = nodo->get(0);
		Nodo *h1 = nodo->get(1);			
		if (h0->num_vars() == 0 || h1->num_vars() == 0){
				if(h0->num_vars() == 0){
					genCodeOpera(h1, reg, tipo);
					if(tipo.compare("int") == 0){
						if( nodo_value.compare("+") == 0){
							codefile << "addq $"+h0->get_valor()+" %r"+std::to_string(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("-") == 0){
							codefile << "subq $"+h0->get_valor()+" %r"+std::to_string(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							codefile << "imulq $"+h0->get_valor()+" %r"+std::to_string(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("/") == 0){
							codefile << "divq $"+h0->get_valor()+" %r"+std::to_string(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						//cout << "INT"+nodo_value+"CONS R"+std::to_string(reg)+" "+h0->get_valor() << endl;
					}else{
						if( nodo_value.compare("+") == 0){
							codefile << "addss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("-") == 0){
							codefile << "subss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							codefile << "mulss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("/") == 0){
							codefile << "divss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						//cout << "FLOAT"+nodo_value+"CONS R"+std::to_string(reg)+" "+h0->get_valor() << endl;
					}
				}else{
					genCodeOpera(h0, reg, tipo);
					if(tipo.compare("int") == 0){
						if( nodo_value.compare("+") == 0){
							codefile << "addq $"+h1->get_valor()+" %r"+std::to_string(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("-") == 0){
							codefile << "subq $"+h1->get_valor()+" %r"+std::to_string(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							codefile << "imulq $"+h1->get_valor()+" %r"+std::to_string(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("/") == 0){
							codefile << "divq $"+h1->get_valor()+" %r"+std::to_string(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						//cout << "INT"+nodo_value+"CONS R"+std::to_string(reg)+" "+h1->get_valor() << endl;
					}else{
						if( nodo_value.compare("+") == 0){
							codefile << "addss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("-") == 0){
							codefile << "subss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							codefile << "mulss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						if( nodo_value.compare("/") == 0){
							codefile << "divss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
						}
						//cout << "FLOAT"+nodo_value+"CONS R"+std::to_string(reg)+" "+h1->get_valor() << endl;
					}

				}
		}else{
			genCodeOpera(nodo->get(0), reg, tipo);
			genCodeOpera(nodo->get(1), reg-1, tipo);

			if(tipo.compare("int") == 0){
				if( nodo_value.compare("+") == 0){
					codefile << "addq %r"+std::to_string(reg-1)+" %r"+std::to_string(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("-") == 0){
					codefile << "subq %r"+std::to_string(reg-1)+" %r"+std::to_string(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("*") == 0){
					codefile << "imulq %r"+std::to_string(reg-1)+" %r"+std::to_string(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("/") == 0){
					codefile << "divq %r"+std::to_string(reg-1)+" %r"+std::to_string(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	
				}
				//cout << "INT"+nodo_value+" R"+std::to_string(reg)+" R"+std::to_string(reg-1) << endl;	
			}else{
				if( nodo_value.compare("+") == 0){
					codefile << "addss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("-") == 0){
					codefile << "subss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("*") == 0){
					codefile << "mulss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;	
				}
				if( nodo_value.compare("/") == 0){
					codefile << "divss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
				}
				//cout << "FLOAT"+nodo_value+" R"+std::to_string(reg)+" R"+std::to_string(reg-1) << endl;	
			}		
		}
		return;
	}

	if( nodo_value.compare("and") == 0 || nodo_value.compare("or") == 0){
		Nodo *h0 = nodo->get(0);
		Nodo *h1 = nodo->get(1);
		if (h0->num_vars() == 0 || h1->num_vars() == 0){
				if(h0->num_vars() == 0){
					std::string consvalue = "0";
					if (h0->get_valor().compare("true") == 0){
						consvalue = "1";
					}else{
						consvalue = "0";
					}
					genCodeOpera(h1, reg, tipo);
					codefile <<nodo_value+"q $"+consvalue+" %r"+std::to_string(reg)  +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;
					//cout <<"BOOL"+nodo_value+"CONS R"+std::to_string(reg)+" "+h0->get_valor() << endl;
				}else{ 
					std::string consvalue = "0";
					if (h1->get_valor().compare("true") == 0){
						consvalue = "1";
					}else{
						consvalue = "0";
					}
					genCodeOpera(h0, reg, tipo);
					codefile <<nodo_value+"q $"+consvalue+" %r"+std::to_string(reg)  +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;
					//cout <<"BOOL"+nodo_value+"CONS R"+std::to_string(reg)+" "+h1->get_valor() << endl;
				}			

		}else{
			genCodeOpera(nodo->get(0), reg, tipo);
			genCodeOpera(nodo->get(1), reg-1, tipo);
			//cout << "BOOL"+nodo_value+" R"+std::to_string(reg)+" R"+std::to_string(reg-1) << endl;
			codefile << nodo_value+"q %r"+std::to_string(reg-1)+" %r"+std::to_string(reg) +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;					
		}
		return;
	}

	if(nodo_value.compare("not") == 0){
		//notq D D ← ˜D
		genCodeOpera(nodo->get(0), reg, tipo);
			codefile << "notq %r"+std::to_string(reg) +"\t#notq D D ← ^D"<< endl;
		//cout << "BOOL"+nodo_value+" R"+std::to_string(reg) << endl;
		return;

	}

	//movq S, D ####D ← S
	if(tipo.compare("int") == 0){
		codefile << "movq "+nodo_value+" %r"+std::to_string(reg)+"\t#movq S, D D ← S   LOAD"<< endl;
		//cout << "INT LOAD R"+std::to_string(reg)+" "+nodo_value << endl;
	}
	if(tipo.compare("bool") == 0){
		std::string consvalue = "0";
		if (nodo_value.compare("true") == 0){
			consvalue = "1";
		}else{
			consvalue = "0";
		}
		codefile << "movq "+consvalue+" %r"+std::to_string(reg)+"\t#movq S, D D ← S   LOAD"<< endl;
		//cout << "BOOL LOAD R"+std::to_string(reg)+" "+nodo_value << endl;
	}
	if(tipo.compare("float") == 0){
		codefile << "movss "+nodo_value+" %xmm"+std::to_string(reg)+"\t#movss S, D D ← S   LOAD"<< endl;
		//cout << "FLOAT LOAD R"+std::to_string(reg)+" "+nodo_value << endl;
	}	
}


//Metodo que genera el codigo en x86-64 (PRINCIPAL)
void genCode(Nodo *nodo, TablaSimbolos *ts){	

  	int num_seqs = nodo->num_seqs();
	if (num_seqs == 1){

                Nodo *linea = nodo->get(0);
		std::string nodo_value = linea->get_valor();

		if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0 || nodo_value.compare("float") == 0 || nodo_value.compare("=") == 0){

			if(nodo_value.compare("=") == 0){
				Nodo *var = linea->get(0);
				Nodo *exp = linea->get(1);


                                Simbolo *sim1 = ts->look_up(var->get_valor());
				int tiposim = sim1->get_tipo();
				std::string tipo;
				//cout << "Varible:"+var->get_valor() << endl;
				//cout << "Tipo:"+tipo << endl;
				//cout << str(exp) << endl;
			
				//movq S, D ####D ← S
				if(tiposim == 0){
					tipo = "int";
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movq %r"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "INT SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", "R"+std::to_string(exp->num_vars()), var->get_valor());
				}
				if(tiposim == 2){
					tipo = "bool";
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movq %r"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "BOOL SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", "R"+std::to_string(exp->num_vars()), var->get_valor());
				}
				if(tiposim == 1){
					tipo = "float";
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movss %xmm"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movss S, D D ← S   SAVE"<< endl;
					//cout << "FLOAT SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", "R"+std::to_string(exp->num_vars()), var->get_valor());
				}

			}else{
				std::string tipo = linea->get_valor();
				Nodo *linea2 = linea->get(0);
				Nodo *var = linea2->get(0);
				Nodo *exp = linea2->get(1);
				//cout << "Tipo:"+tipo << endl;
				//cout << "Varible:"+var->get_valor() << endl;
				//cout << str(exp) << endl;


				//movq S, D D ← S
				//genCodeX8664(tipo, "SAVE", "R"+std::to_string(exp->num_vars()), var->get_valor());
				if(tipo.compare("int") == 0){
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movq %r"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "INT SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
				}
				if(tipo.compare("bool") == 0){
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movq %r"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "BOOL SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
				}
				if(tipo.compare("float") == 0){
					genCodeOpera(exp, exp->num_vars(), tipo);
  					codefile << "movss %xmm"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movss S, D D ← S   SAVE"<< endl;
					//cout << "FLOAT SAVE R"+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
				}


			}

		}else{
			//cout << str(linea) << endl;
			//IGNORAMOS CALCULOS QUE NO TENGA ASIGNACION POR QUE SE SON CALCULOS QUE NO SE
			//USAN NUNCA
			//genCodeOpera(linea, linea->num_vars());
		}

	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			genCode(nodo->get(i), ts);
		}
	}

}


//Metodo que evalua las contasntes dentro del arbol para simplificarlos (AUXILIAR)
std::string evalConstantsNodo(Nodo *nodo){

	int numhijos = nodo->num_hijos();
	std::string nodo_value = nodo->get_valor();

	if(numhijos == 0){
		return nodo->get_valor();
	}
	if(numhijos == 1){
		std::string new_val;
		std::string valh0 =  evalConstantsNodo(nodo->get(0));
		if ( nodo_value.compare("not") == 0){
			if (valh0.compare("true") == 0){
				new_val = "false";
			}else{
				new_val = "true";
			}
			return new_val;
		}else{
			cout << "evalNodo: NOOO DEBE PASAR" << endl;
			cout << nodo_value << endl;
		}
	}
	if(numhijos == 2){
		std::string new_val;
		std::string valh0 =  evalConstantsNodo(nodo->get(0));
		std::string valh1 =  evalConstantsNodo(nodo->get(1));

		if( nodo_value.compare("and") == 0 || nodo_value.compare("or") == 0 ){
			if( nodo_value.compare("and") == 0){
				if (valh0.compare("true") == 0 && valh1.compare("true") == 0){
					new_val = "true";
				}else{
					new_val = "false";
				}
			}
			if( nodo_value.compare("or") == 0){
				if (valh0.compare("true") == 0 || valh1.compare("true") == 0){
					new_val = "true";
				}else{
					new_val = "false";
				}
			}
			return new_val;
		}

		if( nodo_value.compare("+") == 0 || nodo_value.compare("-") == 0 || nodo_value.compare("*") == 0 || nodo_value.compare("/") == 0 ){
			if(isNumber(valh0)){
				int new_num = 0;
				int numh0 = std::stoi(valh0);
				int numh1 = std::stoi(valh1);
				if(nodo_value.compare("+") == 0){
					new_num = numh0 + numh1;
				}
				if(nodo_value.compare("-") == 0){
					new_num = numh0 - numh1;
				}
				if(nodo_value.compare("*") == 0){
					new_num = numh0 * numh1;
				}
				if(nodo_value.compare("/") == 0){
					new_num = numh0 / numh1;
				}
				return std::to_string(new_num);
			}else{
				float new_num = 0.0;
				float numh0 = std::atof(valh0.c_str());
				float numh1 = std::atof(valh1.c_str());
				if(nodo_value.compare("+") == 0){
					new_num = numh0 + numh1;
				}
				if(nodo_value.compare("-") == 0){
					new_num = numh0 - numh1;
				}
				if(nodo_value.compare("*") == 0){
					new_num = numh0 * numh1;
				}
				if(nodo_value.compare("/") == 0){
					new_num = numh0 / numh1;
				}
				return std::to_string(new_num);
			}
	
		}	
	}

}


//Metodo que evalua las contasntes dentro del arbol para simplificarlos  (PRINCIPAL)
void evalConstants(Nodo *nodo){
	std::string nodo_value = nodo->get_valor();
  	int num_vars = nodo->num_vars();
	

	if (num_vars == 0 && nodo_value.compare("seq") != 0){
		std::string val = evalConstantsNodo(nodo);
		while( nodo->num_hijos() > 0){
			Nodo *newnodo = nodo->pop_back();
		}
		nodo->set_valor(val);
	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			evalConstants(nodo->get(i));
		}
	}

}


//Metodo que implementa el agoritmo Sehti-Ullman simple
int simpleSethUll(Nodo *nodo){

	//cout << "entro a: "+nodo->str() +"tiene "+ std::to_string(nodo->num_hijos()) +" hijos "<< endl;
	int vars = 0;
        std::string seqstr = "(seq)";
	int numhijos = nodo->num_hijos();
	if(seqstr.compare(nodo->str()) == 0){
		for(int i = 0; i < numhijos; i++){
			int vars_temp;
			vars_temp = simpleSethUll(nodo->get(i));

                        if (vars_temp > vars){
				vars = vars_temp;
			}

		}
	}else{
		if (numhijos == 2){

			//cout << nodo->get_valor()+": DOS hijos" << endl;
			int vars_temp1 = simpleSethUll(nodo->get(0));
			int vars_temp2 = simpleSethUll(nodo->get(1));
			if (vars_temp1 > vars_temp2){
				vars = vars_temp1;
			}else{
				if (vars_temp1 < vars_temp2){
					vars = vars_temp2;
				}else{
					if (vars_temp1 != 0	){
						vars = vars_temp1 + 1;
					}
				}
			}

		}else{
			if (numhijos == 1){
				//cout << nodo->get_valor()+": UN hijos" << endl;
				vars = simpleSethUll(nodo->get(0));
			}else{
				if (numhijos == 0){
					//cout << nodo->get_valor()+": NINGUN hijo" << endl;
					std::string nodo_value = nodo->get_valor();
					if ( isNumber(nodo_value) || isFloat(nodo_value) || nodo_value.compare("true") == 0  || nodo_value.compare("false") == 0  ){
						//cout << nodo_value+": Es INT FLOAT True o False" << endl;
						vars = 0;
					}else{
						//cout << nodo_value+": NO ES INT Numero FLOAT True o False" << endl;
						vars = 1;
					}
				}else{
					cout << "simpleSethUll: NOOoO DEBE PASRA" << endl;					
				}
			}
		}
	}
	//cout << nodo->str() +" "+ std::to_string(vars) << endl;
	nodo->set_num_vars(vars);
	return vars;	
}


//Metodo para generar el .data apartir del arbol
void genData(Nodo *nodo){	
	
  	int num_seqs = nodo->num_seqs();
	if (num_seqs == 1){
                Nodo *linea = nodo->get(0);
		std::string nodo_value = linea->get_valor();

		if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0 || nodo_value.compare("float") == 0){
			Nodo *var = linea->get(0);
			Nodo *exp = linea->get(1);
			if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0){
				codefile << var->get(0)->get_valor()+": \t .quad\t 0"  << endl;		
			}else{
				codefile << var->get(0)->get_valor()+": \t .float\t 0.0"  << endl;		
			}
		}
	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			genData(nodo->get(i));
		}
	}
}

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "Uso: ./kyc-ip <archivo>" << endl;
                clear();
		return -1;
 	}
        
	FILE *myfile = fopen(argv[1], "r");
	if (!myfile) {
		cout << "Error al abrir archivo!" << endl;
                clear();
		return -1;
	}
        string s = argv[1];
        archivo = s.substr(s.find_last_of("\\/") + 1, s.size());
        archivo = archivo.substr(0, archivo.find_last_of("."));
	yyin = myfile;

	do {
		yyparse();
	} while (!feof(yyin));
        

	//Obtenemos la tabla de simbolos y los nodos 
	TablaSimbolos *ts = vct->get_tabla();
        Nodo *root = nodos->back();

	//Abrimos el archivo para escribir el codigo generado
        codefile.open (archivo+".codigo");

	//Generamos la marca de seqs los nodos que solo tiene una sequencia son los que "tiene" lineas de codigo
	transTreeSeqs(root);
	//Implementacion simple del algoritmo Sehti-Ullman
	simpleSethUll(root);
	//Este metodo simplifica el arbol es decir las operaciones que operan entre puras contasntes se simplifican en un solo nodo
	evalConstants(root);
	//Genera el codigo .data
	codefile << "\t.data" << endl;
	genData(root);
	//Genera el codigo .text
	codefile << "\t.text" << endl;
	codefile << "\t.globl _start" << endl;
	codefile << "_start:" << endl;
	genCode(root, ts);

	//Cerramos el archivo
	codefile.close();

        clear();
}




void yyerror(const char *s) {
	cout << "Error! en línea " << linea << ", columna " << col << "  Mensaje: " << s << endl;
        clear();
	exit(-1);
}
