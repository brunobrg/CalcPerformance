/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "analise.h"
#include <string.h>

extern int contadorDeLinhas;
extern int OK;
extern Error error[20];
extern int totalError;

int needLines = 0;
int needSpace = 0;
int tab = 0;
int terminou = 0;

int inicioBloco = 0;
int declarando = 0;

Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;

#line 88 "bison.c" /* yacc.c:339  */

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
   by #include "bison.h".  */
#ifndef YY_YY_BISON_H_INCLUDED
# define YY_YY_BISON_H_INCLUDED
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
    T_NUMBER = 258,
    TIPO = 259,
    T_STRING = 260,
    TEXTO = 261,
    STR = 262,
    AND = 263,
    OU = 264,
    IF = 265,
    DO = 266,
    THEN = 267,
    WHILE = 268,
    ELSE = 269,
    NOT = 270,
    TERMINOU = 271,
    DECLARACAO = 272,
    FIMFUNC = 273,
    FUNCAO = 274,
    ESPERA = 275,
    EXECUTE = 276,
    PASSA = 277,
    MAIOR = 278,
    MENOR = 279,
    IGUAL = 280,
    SOMA = 281,
    SUBT = 282,
    MULT = 283,
    DIVIDE = 284,
    ATRIBUI = 285,
    NUMERICAL = 286,
    INCLUDE = 287,
    PH = 288,
    BCOMENT = 289,
    ECOMENT = 290,
    LCOMENT = 291,
    PVIRGULA = 292,
    LEFT_PAR = 293,
    RIGHT_PAR = 294,
    VIRGULA = 295,
    ABRE_CHAVE = 296,
    FECHA_CHAVE = 297,
    RETURN = 298,
    PRINTF = 299,
    SCANF = 300,
    VARUSE = 301,
    STATIC = 302,
    MAIN = 303,
    _PROTOTIPO = 304,
    _INCLUDE = 305,
    _STRUCT = 306,
    _MAIN = 307,
    _VGLOBAIS = 308,
    _FUNC = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "bison.y" /* yacc.c:355  */

   char * strval;
   int    intval;

#line 188 "bison.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "bison.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    50,    50,    50,    50,    50,    50,    50,
      50,    53,    55,    55,    58,    60,    61,    64,    66,    66,
      69,    71,    71,    71,    71,    71,    71,    74,    78,    80,
      80,    83,    85,    89,    89,    89,    89,    89,    92,    94,
      94,    97,    99,    99,    99,   102,   104,   104,   107,   109,
     109,   113,   113,   113,   117,   117,   121,   121,   121,   121,
     121,   124,   126,   126,   129,   131,   131,   135,   135,   135,
     135,   135,   138,   140,   140,   140,   143,   145,   145,   145,
     145,   149,   149,   149,   152,   154,   155,   155,   156,   156,
     157,   157,   158,   158,   162,   162,   162,   163,   163,   163,
     167,   167,   167,   171,   171,   171,   171,   175,   175,   178,
     180,   180,   180,   184,   188,   189,   193,   193,   197,   198,
     199,   200,   204,   208,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUMBER", "TIPO", "T_STRING", "TEXTO",
  "STR", "AND", "OU", "IF", "DO", "THEN", "WHILE", "ELSE", "NOT",
  "TERMINOU", "DECLARACAO", "FIMFUNC", "FUNCAO", "ESPERA", "EXECUTE",
  "PASSA", "MAIOR", "MENOR", "IGUAL", "SOMA", "SUBT", "MULT", "DIVIDE",
  "ATRIBUI", "NUMERICAL", "INCLUDE", "PH", "BCOMENT", "ECOMENT", "LCOMENT",
  "PVIRGULA", "LEFT_PAR", "RIGHT_PAR", "VIRGULA", "ABRE_CHAVE",
  "FECHA_CHAVE", "RETURN", "PRINTF", "SCANF", "VARUSE", "STATIC", "MAIN",
  "_PROTOTIPO", "_INCLUDE", "_STRUCT", "_MAIN", "_VGLOBAIS", "_FUNC",
  "$accept", "Etapas", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "Comentario", "$@8", "Comentario_Texto", "_Includes", "$@9", "Includes",
  "$@10", "$@11", "$@12", "$@13", "$@14", "Structs", "_Prototipos", "$@15",
  "Prototipos", "Prototipo", "$@16", "$@17", "$@18", "$@19",
  "Prot_Parametros1", "$@20", "Prot_Parametros2", "$@21", "$@22",
  "_VGlobais", "$@23", "VGlobais", "$@24", "Dec_Global", "$@25", "$@26",
  "_Main", "$@27", "Main", "$@28", "$@29", "$@30", "$@31", "_Funcoes",
  "$@32", "Funcoes", "$@33", "Funcao", "$@34", "$@35", "$@36", "$@37",
  "Parametros1", "$@38", "$@39", "Parametros2", "$@40", "$@41", "$@42",
  "Estrutura", "$@43", "$@44", "Bloco", "$@45", "$@46", "$@47", "$@48",
  "Return", "$@49", "$@50", "$@51", "$@52", "Declaracao", "$@53", "$@54",
  "Printf", "$@55", "$@56", "$@57", "Printf_Param", "$@58",
  "Printf_Argumentos", "$@59", "$@60", "Scanf", "Esc_Var", "Atribuicao",
  "$@61", "Expressao", "Variavel", "Numero", "Operador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    15,   -18,  -167,  -167,  -167,    -3,   -33,    -3,    -3,
      -9,  -167,  -167,  -167,  -167,  -167,    -2,  -167,  -167,  -167,
    -167,     4,   -22,  -167,  -167,  -167,    24,    27,   -21,  -167,
    -167,  -167,    27,  -167,  -167,     1,    30,  -167,   -10,   -14,
    -167,  -167,  -167,  -167,  -167,  -167,    20,     7,    43,    44,
      -1,  -167,  -167,  -167,   -10,  -167,  -167,  -167,  -167,    -2,
      46,    47,  -167,     8,    50,  -167,  -167,    12,  -167,  -167,
    -167,    51,    17,  -167,    21,    22,  -167,    50,  -167,  -167,
      25,  -167,  -167,    54,  -167,    57,  -167,    59,  -167,  -167,
    -167,    26,    28,    17,    62,  -167,  -167,  -167,  -167,    23,
      59,    29,  -167,  -167,    31,  -167,  -167,  -167,  -167,    64,
      -4,    23,  -167,  -167,    32,    33,    34,    66,    35,    -4,
    -167,    67,    68,  -167,  -167,    -4,    37,    -4,  -167,    -4,
      52,    73,    -4,  -167,  -167,  -167,    42,  -167,    75,  -167,
    -167,  -167,    78,    81,  -167,    29,    48,  -167,   -31,     2,
    -167,  -167,  -167,  -167,    80,  -167,    82,    53,  -167,  -167,
      -5,    -5,    55,    56,  -167,    49,   -31,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,     2,
       2,  -167,  -167,    58,  -167,  -167,  -167,  -167,  -167,  -167,
      60,    84,  -167,  -167,    58,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    11,     1,    12,     4,    14,    17,    14,    14,
       0,    18,     5,    15,    16,    13,    20,    27,    21,    19,
       6,     0,    28,    22,    29,     7,     0,    31,    45,    23,
      33,    30,    31,    46,     8,     0,     0,    32,    48,     0,
      24,    34,    49,    47,    54,     9,     0,     0,     0,     0,
      61,    25,    35,    51,    48,    56,    55,    62,    10,    20,
      38,     0,    50,     0,    64,    26,    39,     0,    52,    57,
      63,     0,    41,    36,     0,     0,    67,    64,    42,    40,
       0,    53,    58,     0,    66,     0,    37,    72,    68,    43,
      73,     0,     0,    41,     0,    59,    69,    44,    74,     0,
      72,    76,    81,    60,     0,    77,    75,    82,    70,     0,
      84,     0,    78,   100,     0,     0,     0,     0,     0,    84,
      71,     0,     0,    83,   103,    84,     0,    84,   122,    84,
       0,    94,    84,    85,    79,   101,     0,    87,     0,    89,
      91,   116,     0,     0,    93,    76,     0,   104,     0,     0,
      95,    98,    80,   102,     0,   114,     0,     0,   123,   117,
     119,   118,     0,     0,   107,     0,     0,   113,   128,   127,
     129,   124,   125,   126,   130,   131,   132,   133,   134,     0,
       0,    96,    99,   109,   105,   115,   121,   120,   110,   108,
       0,     0,   106,   111,   109,   112
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,     3,  -167,  -167,    36,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,    69,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,     9,  -167,  -167,  -167,  -167,    40,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
      14,  -167,  -167,  -167,  -167,  -167,  -167,     0,  -167,  -167,
     -49,  -167,  -167,  -167,   -12,  -167,  -167,   -83,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,   -91,  -167,  -167,  -167,
     -62,  -167,  -167,  -166,   -11,  -167,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    17,    22,    28,    39,    50,     5,
       6,    10,    12,    16,    19,    21,    26,    35,    46,    59,
      20,    25,    27,    31,    32,    36,    47,    60,    80,    67,
      72,    79,    85,    93,    34,    38,    43,    48,    54,    61,
      74,    45,    49,    56,    63,    75,    87,    99,    58,    64,
      70,    71,    77,    83,    92,   100,   111,    91,    94,   101,
     106,   109,   121,   145,   103,   107,   110,   114,   115,   116,
     117,   118,   132,   142,   162,   143,   163,   119,   122,   146,
     125,   136,   154,   190,   165,   183,   189,   191,   194,   127,
     157,   129,   149,   159,   160,   161,   179
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   -90,     8,   168,   169,   158,    -2,   128,   155,   156,
     170,    13,    14,   186,   187,     3,     4,    11,   171,   172,
     173,   174,   175,   176,   177,   178,    15,    24,    23,    29,
      18,    30,    33,     9,    40,    41,   133,    42,    44,   -92,
     -86,   -88,   137,    51,   139,    52,   140,    53,    55,   144,
      66,    73,    68,    57,   -65,    76,    69,    78,    81,    88,
      82,    89,    86,    90,   102,    95,    96,    98,   112,   105,
     108,   128,   134,   135,   123,   138,   -97,   124,   131,   126,
     147,   148,   141,   150,   151,   153,   164,   166,   184,   193,
     167,    84,   181,   182,    62,    65,   152,   192,   188,   120,
     104,    37,    97,   195,   185,   180,   130
};

static const yytype_uint8 yycheck[] =
{
       4,     5,     5,     8,     9,     3,     0,     5,    39,    40,
      15,     8,     9,   179,   180,     0,    34,    50,    23,    24,
      25,    26,    27,    28,    29,    30,    35,    49,    24,     5,
      32,     4,    53,    36,    33,     5,   119,    47,    52,    43,
      44,    45,   125,    23,   127,    38,   129,     4,     4,   132,
       4,    39,     5,    54,     4,     4,    48,    40,    37,     5,
      38,     4,    37,     4,    41,    39,    38,     5,     4,    40,
      39,     5,     5,     5,    42,    38,     3,    44,    43,    45,
      38,     6,    30,     5,     3,    37,     6,     5,    39,     5,
      37,    77,    37,    37,    54,    59,   145,    37,    40,   111,
     100,    32,    93,   194,   166,   161,   117
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,    34,    64,    65,    58,     5,    36,
      66,    50,    67,    66,    66,    35,    68,    59,    32,    69,
      75,    70,    60,    24,    49,    76,    71,    77,    61,     5,
       4,    78,    79,    53,    89,    72,    80,    78,    90,    62,
      33,     5,    47,    91,    52,    96,    73,    81,    92,    97,
      63,    23,    38,     4,    93,     4,    98,    54,   103,    74,
      82,    94,    91,    99,   104,    69,     4,    84,     5,    48,
     105,   106,    85,    39,    95,   100,     4,   107,    40,    86,
      83,    37,    38,   108,   105,    87,    37,   101,     5,     4,
       4,   112,   109,    88,   113,    39,    38,    86,     5,   102,
     110,   114,    41,   119,   112,    40,   115,   120,    39,   116,
     121,   111,     4,     4,   122,   123,   124,   125,   126,   132,
     119,   117,   133,    42,    44,   135,    45,   144,     5,   146,
     149,    43,   127,   122,     5,     5,   136,   122,    38,   122,
     122,    30,   128,   130,   122,   118,   134,    38,     6,   147,
       5,     3,   115,    37,   137,    39,    40,   145,     3,   148,
     149,   150,   129,   131,     6,   139,     5,    37,     8,     9,
      15,    23,    24,    25,    26,    27,    28,    29,    30,   151,
     151,    37,    37,   140,    39,   145,   148,   148,    40,   141,
     138,   142,    37,     5,   143,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      56,    64,    65,    64,    66,    66,    66,    67,    68,    67,
      69,    70,    71,    72,    73,    74,    69,    75,    76,    77,
      76,    78,    78,    80,    81,    82,    83,    79,    84,    85,
      84,    86,    87,    88,    86,    89,    90,    89,    91,    92,
      91,    94,    95,    93,    97,    96,    99,   100,   101,   102,
      98,   103,   104,   103,   105,   106,   105,   108,   109,   110,
     111,   107,   112,   113,   114,   112,   115,   116,   117,   118,
     115,   120,   121,   119,   122,   122,   123,   122,   124,   122,
     125,   122,   126,   122,   128,   129,   127,   130,   131,   127,
     133,   134,   132,   136,   137,   138,   135,   140,   139,   141,
     142,   143,   141,   144,   145,   145,   147,   146,   148,   148,
     148,   148,   149,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     4,     0,     2,     2,     0,     0,     3,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       3,     0,     2,     0,     0,     0,     0,    10,     0,     0,
       3,     0,     0,     0,     5,     0,     0,     3,     0,     0,
       4,     0,     0,     5,     0,     3,     0,     0,     0,     0,
      10,     0,     0,     3,     0,     0,     3,     0,     0,     0,
       0,    10,     0,     0,     0,     5,     0,     0,     0,     0,
       7,     0,     0,     5,     0,     2,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     0,     8,     0,     3,     0,
       0,     0,     5,     5,     1,     3,     0,     4,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
        case 3:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 0;}
#line 1432 "bison.c" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "bison.y" /* yacc.c:1646  */
    {inicializaAnalise();}
#line 1438 "bison.c" /* yacc.c:1646  */
    break;

  case 5:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1444 "bison.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1450 "bison.c" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1456 "bison.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1462 "bison.c" /* yacc.c:1646  */
    break;

  case 9:
#line 50 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1468 "bison.c" /* yacc.c:1646  */
    break;

  case 12:
#line 55 "bison.y" /* yacc.c:1646  */
    {comment_criador.possui = 1; }
#line 1474 "bison.c" /* yacc.c:1646  */
    break;

  case 13:
#line 55 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1480 "bison.c" /* yacc.c:1646  */
    break;

  case 18:
#line 66 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1486 "bison.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines);}
#line 1492 "bison.c" /* yacc.c:1646  */
    break;

  case 22:
#line 71 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 1498 "bison.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1504 "bison.c" /* yacc.c:1646  */
    break;

  case 24:
#line 71 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1510 "bison.c" /* yacc.c:1646  */
    break;

  case 25:
#line 71 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1516 "bison.c" /* yacc.c:1646  */
    break;

  case 29:
#line 80 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1522 "bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1528 "bison.c" /* yacc.c:1646  */
    break;

  case 34:
#line 89 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1534 "bison.c" /* yacc.c:1646  */
    break;

  case 35:
#line 89 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1540 "bison.c" /* yacc.c:1646  */
    break;

  case 36:
#line 89 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1546 "bison.c" /* yacc.c:1646  */
    break;

  case 37:
#line 89 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, 0); needLines = 1;}
#line 1552 "bison.c" /* yacc.c:1646  */
    break;

  case 39:
#line 94 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1558 "bison.c" /* yacc.c:1646  */
    break;

  case 42:
#line 99 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1564 "bison.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1570 "bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 104 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1576 "bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 109 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1582 "bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 113 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1588 "bison.c" /* yacc.c:1646  */
    break;

  case 52:
#line 113 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); inserirVar(&varDeclaradas, (yyvsp[-2].strval), (yyvsp[0].strval), "global");}
#line 1594 "bison.c" /* yacc.c:1646  */
    break;

  case 53:
#line 113 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 1600 "bison.c" /* yacc.c:1646  */
    break;

  case 54:
#line 117 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1606 "bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 121 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 1;}
#line 1612 "bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 121 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1618 "bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 121 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1624 "bison.c" /* yacc.c:1646  */
    break;

  case 59:
#line 121 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1630 "bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 126 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1636 "bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 131 "bison.y" /* yacc.c:1646  */
    {needLines = 1;}
#line 1642 "bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 135 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 1;}
#line 1648 "bison.c" /* yacc.c:1646  */
    break;

  case 68:
#line 135 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1654 "bison.c" /* yacc.c:1646  */
    break;

  case 69:
#line 135 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1660 "bison.c" /* yacc.c:1646  */
    break;

  case 70:
#line 135 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1666 "bison.c" /* yacc.c:1646  */
    break;

  case 73:
#line 140 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1672 "bison.c" /* yacc.c:1646  */
    break;

  case 74:
#line 140 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1678 "bison.c" /* yacc.c:1646  */
    break;

  case 77:
#line 145 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1684 "bison.c" /* yacc.c:1646  */
    break;

  case 78:
#line 145 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1690 "bison.c" /* yacc.c:1646  */
    break;

  case 79:
#line 145 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1696 "bison.c" /* yacc.c:1646  */
    break;

  case 81:
#line 149 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 1); addTab();}
#line 1702 "bison.c" /* yacc.c:1646  */
    break;

  case 82:
#line 149 "bison.y" /* yacc.c:1646  */
    {inicioBloco = 1;}
#line 1708 "bison.c" /* yacc.c:1646  */
    break;

  case 83:
#line 149 "bison.y" /* yacc.c:1646  */
    {remTab(); analise(getTab(), needLines = 1);}
#line 1714 "bison.c" /* yacc.c:1646  */
    break;

  case 86:
#line 155 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1720 "bison.c" /* yacc.c:1646  */
    break;

  case 88:
#line 156 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1726 "bison.c" /* yacc.c:1646  */
    break;

  case 90:
#line 157 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1732 "bison.c" /* yacc.c:1646  */
    break;

  case 92:
#line 158 "bison.y" /* yacc.c:1646  */
    {needLines = 2; if(inicioBloco) needLines = 1; inicioBloco = 0;}
#line 1738 "bison.c" /* yacc.c:1646  */
    break;

  case 94:
#line 162 "bison.y" /* yacc.c:1646  */
    {analise(getTab()+1, needLines);}
#line 1744 "bison.c" /* yacc.c:1646  */
    break;

  case 95:
#line 162 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1750 "bison.c" /* yacc.c:1646  */
    break;

  case 96:
#line 162 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1756 "bison.c" /* yacc.c:1646  */
    break;

  case 97:
#line 163 "bison.y" /* yacc.c:1646  */
    {analise(getTab()+1, needLines);}
#line 1762 "bison.c" /* yacc.c:1646  */
    break;

  case 98:
#line 163 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1768 "bison.c" /* yacc.c:1646  */
    break;

  case 99:
#line 163 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1774 "bison.c" /* yacc.c:1646  */
    break;

  case 100:
#line 167 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); declarando = 1;}
#line 1780 "bison.c" /* yacc.c:1646  */
    break;

  case 101:
#line 167 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); analiseBloco(inicioBloco, (yyvsp[0].strval));}
#line 1786 "bison.c" /* yacc.c:1646  */
    break;

  case 102:
#line 167 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 1792 "bison.c" /* yacc.c:1646  */
    break;

  case 103:
#line 171 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines);}
#line 1798 "bison.c" /* yacc.c:1646  */
    break;

  case 104:
#line 171 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines = 0);}
#line 1804 "bison.c" /* yacc.c:1646  */
    break;

  case 105:
#line 171 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1810 "bison.c" /* yacc.c:1646  */
    break;

  case 106:
#line 171 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines); needLines = 1;}
#line 1816 "bison.c" /* yacc.c:1646  */
    break;

  case 107:
#line 175 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1822 "bison.c" /* yacc.c:1646  */
    break;

  case 110:
#line 180 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1828 "bison.c" /* yacc.c:1646  */
    break;

  case 111:
#line 180 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1834 "bison.c" /* yacc.c:1646  */
    break;

  case 116:
#line 193 "bison.y" /* yacc.c:1646  */
    {Inserir(&saida, " = ", contadorDeLinhas);}
#line 1840 "bison.c" /* yacc.c:1646  */
    break;

  case 122:
#line 204 "bison.y" /* yacc.c:1646  */
    {inserirVar(&varUsadas, "null", (yyvsp[0].strval), "escopo");}
#line 1846 "bison.c" /* yacc.c:1646  */
    break;

  case 124:
#line 212 "bison.y" /* yacc.c:1646  */
    {}
#line 1852 "bison.c" /* yacc.c:1646  */
    break;

  case 125:
#line 213 "bison.y" /* yacc.c:1646  */
    {}
#line 1858 "bison.c" /* yacc.c:1646  */
    break;

  case 126:
#line 214 "bison.y" /* yacc.c:1646  */
    {}
#line 1864 "bison.c" /* yacc.c:1646  */
    break;

  case 127:
#line 215 "bison.y" /* yacc.c:1646  */
    {}
#line 1870 "bison.c" /* yacc.c:1646  */
    break;

  case 128:
#line 216 "bison.y" /* yacc.c:1646  */
    {}
#line 1876 "bison.c" /* yacc.c:1646  */
    break;

  case 129:
#line 217 "bison.y" /* yacc.c:1646  */
    {}
#line 1882 "bison.c" /* yacc.c:1646  */
    break;

  case 130:
#line 218 "bison.y" /* yacc.c:1646  */
    {}
#line 1888 "bison.c" /* yacc.c:1646  */
    break;

  case 131:
#line 219 "bison.y" /* yacc.c:1646  */
    {}
#line 1894 "bison.c" /* yacc.c:1646  */
    break;

  case 132:
#line 220 "bison.y" /* yacc.c:1646  */
    {}
#line 1900 "bison.c" /* yacc.c:1646  */
    break;

  case 133:
#line 221 "bison.y" /* yacc.c:1646  */
    {}
#line 1906 "bison.c" /* yacc.c:1646  */
    break;

  case 134:
#line 222 "bison.y" /* yacc.c:1646  */
    {}
#line 1912 "bison.c" /* yacc.c:1646  */
    break;


#line 1916 "bison.c" /* yacc.c:1646  */
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
#line 226 "bison.y" /* yacc.c:1906  */


void main(void){
	comment_criador.possui = 0;
	comment_prototipo.possui = 0;
	comment_include.possui = 0;
	comment_main.possui = 0;
	comment_vglobais.possui = 0;

	yyparse();
	if(terminou)
	{
		analisaVariaveis();
		int i = 0;

		printf("\nAnalise terminada");
		if(OK)
			printf("--OK!");
		else
		{
			printf("\n\n");
			imprimeAnalise();
			printf("\n");
			printf("\nTotal de erros: %d\n", totalError);
			for(i = 0; i < 20 ; i++)
			{
				if(error[i].qnt > 0)
				{
					printf("%s: %d\n", error[i].nome, error[i].qnt);
				}
			}
		}
		printf("\n");
	}
}

yyerror(char *s){
	printf("Erro na linha: %d:%d\n", contadorDeLinhas, contadorEspacos);
	
	OK = 0;

	if(comment_criador.possui == 0)
	{
		printf("\n---Codigo nao se encontra no formato requisitado, por favor, insira comentarios do criador---\n");
	}
	if(comment_include.possui == 0)
	{
		printf("\n---Codigo nao se encontra no formato requisitado, por favor, insira comentarios antes dos INCLUDES---\n");
	}
	if(comment_prototipo.possui == 0)
	{
		printf("\n---Codigo nao se encontra no formato requisitado, por favor, insira comentarios dos PROTOTIPOS---\n");
	}
}

int yywrap(void)
{
	terminou = 1;
	return 1; 
}
