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

extern int contadorEspacos;
extern int contadorDeLinhas;
extern int OK;
extern Error error[20];
extern int totalError;
extern char * yytext;
extern int yylineno;
extern FILE * yyin;
extern char exAtual[40], alunoAtual[40], arqAtual[40];

int needLines = 0;
int needSpace = 0;
extern int tab;
int terminou = 0;
char tipo[10];


int inicioBloco = 0;
int declarando = 0;

Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;

#line 95 "bison.c" /* yacc.c:339  */

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
    IGUAL = 278,
    SOMA = 279,
    SUBT = 280,
    MULT = 281,
    DIVIDE = 282,
    ATRIBUI = 283,
    MOD = 284,
    ENDERECO = 285,
    INCREMENTO = 286,
    NUMERICAL = 287,
    INCLUDE = 288,
    PH = 289,
    BCOMENT = 290,
    ECOMENT = 291,
    LCOMENT = 292,
    PVIRGULA = 293,
    LEFT_PAR = 294,
    RIGHT_PAR = 295,
    VIRGULA = 296,
    ABRE_CHAVE = 297,
    FECHA_CHAVE = 298,
    RETURN = 299,
    PRINTF = 300,
    SCANF = 301,
    VARUSE = 302,
    STATIC = 303,
    MAIN = 304,
    _PROTOTIPO = 305,
    _INCLUDE = 306,
    _STRUCT = 307,
    _MAIN = 308,
    _VGLOBAIS = 309,
    _FUNC = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "bison.y" /* yacc.c:355  */

   char * strval;
   int    intval;

#line 196 "bison.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "bison.c" /* yacc.c:358  */

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
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      56,     2,    57,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    57,    57,    57,    57,    57,    57,    57,
      57,    60,    62,    62,    65,    67,    68,    71,    73,    73,
      76,    78,    78,    78,    78,    78,    78,    81,    85,    87,
      87,    90,    92,    96,    96,    96,    96,    96,    99,   101,
     101,   104,   106,   106,   106,   109,   111,   111,   114,   116,
     116,   120,   120,   120,   124,   124,   128,   128,   128,   128,
     128,   131,   133,   133,   136,   138,   138,   142,   142,   142,
     142,   142,   145,   147,   147,   147,   150,   152,   152,   152,
     152,   156,   156,   156,   159,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     172,   172,   172,   173,   173,   173,   177,   177,   177,   181,
     182,   182,   182,   186,   186,   186,   186,   190,   190,   193,
     195,   195,   195,   199,   199,   199,   199,   203,   204,   204,
     204,   204,   208,   208,   208,   208,   211,   213,   214,   218,
     219,   223,   224,   228,   228,   228,   232,   232,   233,   234,
     235,   239,   240,   240,   241,   241,   245,   246,   246,   247,
     247,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   265,   266,   266,   267,   267
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
  "PASSA", "IGUAL", "SOMA", "SUBT", "MULT", "DIVIDE", "ATRIBUI", "MOD",
  "ENDERECO", "INCREMENTO", "NUMERICAL", "INCLUDE", "PH", "BCOMENT",
  "ECOMENT", "LCOMENT", "PVIRGULA", "LEFT_PAR", "RIGHT_PAR", "VIRGULA",
  "ABRE_CHAVE", "FECHA_CHAVE", "RETURN", "PRINTF", "SCANF", "VARUSE",
  "STATIC", "MAIN", "_PROTOTIPO", "_INCLUDE", "_STRUCT", "_MAIN",
  "_VGLOBAIS", "_FUNC", "'<'", "'>'", "$accept", "Etapas", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "Comentario", "$@8",
  "Comentario_Texto", "_Includes", "$@9", "Includes", "$@10", "$@11",
  "$@12", "$@13", "$@14", "Structs", "_Prototipos", "$@15", "Prototipos",
  "Prototipo", "$@16", "$@17", "$@18", "$@19", "Prot_Parametros1", "$@20",
  "Prot_Parametros2", "$@21", "$@22", "_VGlobais", "$@23", "VGlobais",
  "$@24", "Dec_Global", "$@25", "$@26", "_Main", "$@27", "Main", "$@28",
  "$@29", "$@30", "$@31", "_Funcoes", "$@32", "Funcoes", "$@33", "Funcao",
  "$@34", "$@35", "$@36", "$@37", "Parametros1", "$@38", "$@39",
  "Parametros2", "$@40", "$@41", "$@42", "Estrutura", "$@43", "$@44",
  "Bloco", "$@45", "$@46", "$@47", "$@48", "$@49", "$@50", "$@51",
  "Return", "$@52", "$@53", "$@54", "$@55", "Declaracao", "$@56", "$@57",
  "Declaracao2", "$@58", "$@59", "Printf", "$@60", "$@61", "$@62",
  "Printf_Param", "$@63", "Printf_Argumentos", "$@64", "$@65", "Scanf",
  "$@66", "$@67", "$@68", "Esc_Var", "$@69", "$@70", "$@71", "If", "$@72",
  "$@73", "$@74", "Fim_If", "Else", "Else2", "Atribuicao", "$@75", "$@76",
  "Expressao", "$@77", "Variavel", "$@78", "$@79", "Numero", "$@80",
  "$@81", "Operador", "$@82", "$@83", "$@84", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,    60,    62
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -178

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    23,    -6,  -166,  -166,  -166,    -1,   -21,    -1,    -1,
      -2,  -166,  -166,  -166,  -166,  -166,     5,  -166,  -166,  -166,
    -166,    -4,     3,  -166,  -166,  -166,    51,    53,     6,  -166,
    -166,  -166,    53,  -166,  -166,    24,    54,  -166,    13,    16,
    -166,  -166,  -166,  -166,  -166,  -166,    18,    31,    72,    73,
      26,  -166,  -166,  -166,    13,  -166,  -166,  -166,  -166,     5,
      76,    77,  -166,    34,    80,  -166,  -166,    45,  -166,  -166,
    -166,    89,    58,  -166,    62,    67,  -166,    80,  -166,  -166,
      64,  -166,  -166,   103,  -166,   105,  -166,   107,  -166,  -166,
    -166,    75,    74,    58,   111,  -166,  -166,  -166,  -166,    70,
     107,    81,  -166,  -166,    83,  -166,  -166,  -166,  -166,   113,
     100,    70,  -166,  -166,  -166,    78,    82,    79,   116,   114,
       4,    85,   100,  -166,   125,   100,   127,  -166,  -166,   100,
    -166,   100,  -166,   100,  -166,    93,   102,  -166,   100,  -166,
     131,   100,  -166,  -166,  -166,  -166,   101,  -166,   109,  -166,
     110,  -166,  -166,  -166,  -166,  -166,   120,   136,  -166,   124,
     137,   150,  -166,    81,   -27,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   149,   151,     0,
       0,   121,   123,   157,  -166,   128,  -166,   133,   162,  -166,
      -7,  -166,  -166,    17,  -166,  -166,  -166,   126,  -166,   -28,
     138,   167,     0,  -166,  -166,   143,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,   144,   145,     0,  -166,   -27,  -166,
    -166,   139,  -166,  -166,   140,  -166,  -166,    39,   146,   -32,
     147,   148,    63,  -166,   174,  -166,   152,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   126,   175,  -166,
    -166,   -28,  -166
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
       0,     0,    78,    98,   106,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,    83,   113,     0,
     123,     0,   132,     0,   139,     0,   151,   152,     0,   143,
     100,     0,    85,    79,    99,   107,     0,    87,     0,    89,
       0,    91,   142,    93,   141,   140,     0,     0,    95,     0,
       0,     0,    97,    76,     0,   114,   124,   133,   155,   153,
     144,   101,   104,    80,   109,   110,   108,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   125,   156,   152,   146,
       0,   149,   148,     0,   102,   105,   111,   119,   115,     0,
       0,     0,     0,   165,   164,   166,   163,   167,   168,   169,
     170,   171,   172,   134,   162,   161,     0,   145,     0,   120,
     118,     0,   127,   128,     0,   160,   158,     0,     0,   136,
       0,     0,   150,   112,     0,   116,     0,   126,   147,   178,
     137,   138,   135,   174,   176,   121,   129,   119,     0,   122,
     130,     0,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,    19,  -166,  -166,   122,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,   153,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,    90,  -166,  -166,  -166,  -166,   130,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
     112,  -166,  -166,  -166,  -166,  -166,  -166,    86,  -166,  -166,
      27,  -166,  -166,  -166,  -111,  -166,  -166,    25,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,   -31,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,   -59,  -166,  -166,  -166,  -166,  -166,  -166,   -60,
    -166,  -166,  -166,    57,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -165,  -166,    84,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166
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
     106,   109,   124,   163,   103,   107,   110,   115,   116,   117,
     118,   119,   120,   121,   125,   141,   160,   181,   161,   182,
     122,   126,   164,   176,   183,   218,   129,   146,   177,   221,
     185,   197,   220,   234,   247,   131,   148,   178,   199,   224,
     236,   248,   251,   133,   150,   179,   229,   242,   135,   155,
     138,   159,   180,   190,   202,   191,   157,   156,   192,   201,
     200,   216,   230,   231,   228
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   203,   204,   187,     8,   136,   240,    -2,   205,   136,
     102,   174,   222,   223,   175,   193,   206,   207,   208,   209,
     210,   211,   212,     3,   152,   203,   204,    13,    14,     4,
      11,   188,   205,   213,    15,   137,     9,   227,    18,   189,
     206,   207,   208,   209,   210,   211,   212,   203,   204,   214,
     215,   232,    23,    24,   205,   217,    29,    30,    40,    41,
      33,    42,   206,   207,   208,   209,   210,   211,   212,    44,
      52,   203,   204,   214,   215,    51,    53,    55,   205,   238,
      66,    57,    68,    69,   -65,    73,   206,   207,   208,   209,
     210,   211,   212,    76,   113,   214,   215,   114,   -94,    78,
      81,   113,    86,   132,   114,   -94,    82,   -92,    88,    89,
     -90,    90,   102,    96,   -92,    95,    98,   112,   241,   214,
     215,   127,   105,   108,   -94,   130,   132,   128,   134,   140,
     143,   -94,   145,  -154,  -103,   102,   -84,   -96,   -86,   -88,
     165,   169,   171,   -84,   -96,   -86,   -88,   142,   166,   167,
     144,   168,   170,   172,   147,   184,   149,   186,   151,   194,
     153,   195,   196,   158,  -159,  -157,   162,   219,   198,   225,
     226,  -177,  -173,  -175,   239,   243,   244,   235,   237,   245,
     250,    65,   246,    97,    62,    37,   104,   233,   249,    84,
     173,   252,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139
};

static const yytype_int16 yycheck[] =
{
     111,     8,     9,     3,     5,     5,    38,     0,    15,     5,
      42,    38,    40,    41,    41,   180,    23,    24,    25,    26,
      27,    28,    29,     0,   135,     8,     9,     8,     9,    35,
      51,    31,    15,    40,    36,    31,    37,   202,    33,    39,
      23,    24,    25,    26,    27,    28,    29,     8,     9,    56,
      57,   216,    56,    50,    15,    38,     5,     4,    34,     5,
      54,    48,    23,    24,    25,    26,    27,    28,    29,    53,
      39,     8,     9,    56,    57,    57,     4,     4,    15,    40,
       4,    55,     5,    49,     4,    40,    23,    24,    25,    26,
      27,    28,    29,     4,     1,    56,    57,     4,     5,    41,
      38,     1,    38,    10,     4,     5,    39,    14,     5,     4,
      10,     4,    42,    39,    14,    40,     5,     4,   229,    56,
      57,    43,    41,    40,    31,    46,    10,    45,    14,    44,
       5,    31,     5,    31,     3,    42,    43,    44,    45,    46,
      39,     5,     5,    43,    44,    45,    46,   122,    39,    39,
     125,    31,    28,     3,   129,     6,   131,     6,   133,    38,
     135,    38,     5,   138,    31,     3,   141,    41,    40,    31,
       3,    28,    28,    28,    28,    28,    28,    38,    38,     5,
       5,    59,    30,    93,    54,    32,   100,   218,   247,    77,
     163,   251,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    60,     0,    35,    67,    68,    61,     5,    37,
      69,    51,    70,    69,    69,    36,    71,    62,    33,    72,
      78,    73,    63,    56,    50,    79,    74,    80,    64,     5,
       4,    81,    82,    54,    92,    75,    83,    81,    93,    65,
      34,     5,    48,    94,    53,    99,    76,    84,    95,   100,
      66,    57,    39,     4,    96,     4,   101,    55,   106,    77,
      85,    97,    94,   102,   107,    72,     4,    87,     5,    49,
     108,   109,    88,    40,    98,   103,     4,   110,    41,    89,
      86,    38,    39,   111,   108,    90,    38,   104,     5,     4,
       4,   115,   112,    91,   116,    40,    39,    89,     5,   105,
     113,   117,    42,   122,   115,    41,   118,   123,    40,   119,
     124,   114,     4,     1,     4,   125,   126,   127,   128,   129,
     130,   131,   138,   122,   120,   132,   139,    43,    45,   144,
      46,   153,    10,   161,    14,   166,     5,    31,   168,   173,
      44,   133,   125,     5,   125,     5,   145,   125,   154,   125,
     162,   125,   122,   125,   161,   167,   175,   174,   125,   169,
     134,   136,   125,   121,   140,    39,    39,    39,    31,     5,
      28,     5,     3,   118,    38,    41,   141,   146,   155,   163,
     170,   135,   137,   142,     6,   148,     6,     3,    31,    39,
     171,   173,   176,   171,    38,    38,     5,   149,    40,   156,
     178,   177,   172,     8,     9,    15,    23,    24,    25,    26,
      27,    28,    29,    40,    56,    57,   179,    38,   143,    41,
     150,   147,    40,    41,   157,    31,     3,   171,   182,   164,
     180,   181,   171,   141,   151,    38,   158,    38,    40,    28,
      38,   122,   165,    28,    28,     5,    30,   152,   159,   150,
       5,   160,   157
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      59,    67,    68,    67,    69,    69,    69,    70,    71,    70,
      72,    73,    74,    75,    76,    77,    72,    78,    79,    80,
      79,    81,    81,    83,    84,    85,    86,    82,    87,    88,
      87,    89,    90,    91,    89,    92,    93,    92,    94,    95,
      94,    97,    98,    96,   100,    99,   102,   103,   104,   105,
     101,   106,   107,   106,   108,   109,   108,   111,   112,   113,
     114,   110,   115,   116,   117,   115,   118,   119,   120,   121,
     118,   123,   124,   122,   125,   125,   126,   125,   127,   125,
     128,   125,   129,   125,   130,   125,   131,   125,   132,   125,
     134,   135,   133,   136,   137,   133,   139,   140,   138,   141,
     142,   143,   141,   145,   146,   147,   144,   149,   148,   150,
     151,   152,   150,   154,   155,   156,   153,   157,   158,   159,
     160,   157,   162,   163,   164,   161,   165,   165,   165,   166,
     166,   167,   167,   169,   170,   168,   172,   171,   171,   171,
     171,   173,   174,   173,   175,   173,   176,   177,   176,   178,
     176,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   180,   179,   181,   179,   182,   179
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
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     1,
       0,     0,     5,     0,     0,     0,     8,     0,     3,     0,
       0,     0,     5,     0,     0,     0,     8,     1,     0,     0,
       0,     7,     0,     0,     0,     8,     0,     1,     1,     1,
       2,     1,     1,     0,     0,     6,     0,     4,     1,     1,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     3
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
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 0;}
#line 1501 "bison.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "bison.y" /* yacc.c:1646  */
    {linhas_puladas = 0; comment_criador.possui = 1;}
#line 1507 "bison.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1513 "bison.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1519 "bison.c" /* yacc.c:1646  */
    break;

  case 7:
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1525 "bison.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1531 "bison.c" /* yacc.c:1646  */
    break;

  case 9:
#line 57 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1537 "bison.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "bison.y" /* yacc.c:1646  */
    {comment_criador.possui = 1; }
#line 1543 "bison.c" /* yacc.c:1646  */
    break;

  case 13:
#line 62 "bison.y" /* yacc.c:1646  */
    {needLines = 2;}
#line 1549 "bison.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1; comment_include.possui = 1;}
#line 1555 "bison.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines);}
#line 1561 "bison.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 1567 "bison.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1573 "bison.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1579 "bison.c" /* yacc.c:1646  */
    break;

  case 25:
#line 78 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1585 "bison.c" /* yacc.c:1646  */
    break;

  case 29:
#line 87 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1; comment_prototipo.possui = 1;}
#line 1591 "bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 96 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1597 "bison.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1603 "bison.c" /* yacc.c:1646  */
    break;

  case 35:
#line 96 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1609 "bison.c" /* yacc.c:1646  */
    break;

  case 36:
#line 96 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1615 "bison.c" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, 0); needLines = 1;}
#line 1621 "bison.c" /* yacc.c:1646  */
    break;

  case 39:
#line 101 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1627 "bison.c" /* yacc.c:1646  */
    break;

  case 42:
#line 106 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1633 "bison.c" /* yacc.c:1646  */
    break;

  case 43:
#line 106 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1639 "bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 111 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1645 "bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 116 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1651 "bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 120 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1657 "bison.c" /* yacc.c:1646  */
    break;

  case 52:
#line 120 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); inserirVar(&varDeclaradas, (yyvsp[-2].strval), (yyvsp[0].strval), "global");}
#line 1663 "bison.c" /* yacc.c:1646  */
    break;

  case 53:
#line 120 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 1669 "bison.c" /* yacc.c:1646  */
    break;

  case 54:
#line 124 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1675 "bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 128 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 1;}
#line 1681 "bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 128 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1687 "bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 128 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1693 "bison.c" /* yacc.c:1646  */
    break;

  case 59:
#line 128 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1699 "bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 133 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 2); needLines = 1;}
#line 1705 "bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 138 "bison.y" /* yacc.c:1646  */
    {needLines = 1;}
#line 1711 "bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 142 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 1;}
#line 1717 "bison.c" /* yacc.c:1646  */
    break;

  case 68:
#line 142 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); needLines = 0;}
#line 1723 "bison.c" /* yacc.c:1646  */
    break;

  case 69:
#line 142 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1729 "bison.c" /* yacc.c:1646  */
    break;

  case 70:
#line 142 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1735 "bison.c" /* yacc.c:1646  */
    break;

  case 73:
#line 147 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1741 "bison.c" /* yacc.c:1646  */
    break;

  case 74:
#line 147 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1747 "bison.c" /* yacc.c:1646  */
    break;

  case 77:
#line 152 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1753 "bison.c" /* yacc.c:1646  */
    break;

  case 78:
#line 152 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1759 "bison.c" /* yacc.c:1646  */
    break;

  case 79:
#line 152 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1765 "bison.c" /* yacc.c:1646  */
    break;

  case 81:
#line 156 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 1); addTab();}
#line 1771 "bison.c" /* yacc.c:1646  */
    break;

  case 82:
#line 156 "bison.y" /* yacc.c:1646  */
    {inicioBloco = 1;}
#line 1777 "bison.c" /* yacc.c:1646  */
    break;

  case 83:
#line 156 "bison.y" /* yacc.c:1646  */
    {remTab(); analise(getTab(), needLines = 1);}
#line 1783 "bison.c" /* yacc.c:1646  */
    break;

  case 86:
#line 162 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1789 "bison.c" /* yacc.c:1646  */
    break;

  case 88:
#line 163 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1795 "bison.c" /* yacc.c:1646  */
    break;

  case 90:
#line 164 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1801 "bison.c" /* yacc.c:1646  */
    break;

  case 92:
#line 165 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1807 "bison.c" /* yacc.c:1646  */
    break;

  case 94:
#line 166 "bison.y" /* yacc.c:1646  */
    {if(declarando)needLines = 2; declarando = inicioBloco = 0;}
#line 1813 "bison.c" /* yacc.c:1646  */
    break;

  case 96:
#line 167 "bison.y" /* yacc.c:1646  */
    {needLines = 2; if(inicioBloco) needLines = 1; inicioBloco = 0;}
#line 1819 "bison.c" /* yacc.c:1646  */
    break;

  case 98:
#line 168 "bison.y" /* yacc.c:1646  */
    {yyclearin; inserirSaidaError(yytext, "teste", contadorDeLinhas, contadorEspacos);}
#line 1825 "bison.c" /* yacc.c:1646  */
    break;

  case 100:
#line 172 "bison.y" /* yacc.c:1646  */
    {analise(getTab()+1, needLines);}
#line 1831 "bison.c" /* yacc.c:1646  */
    break;

  case 101:
#line 172 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1837 "bison.c" /* yacc.c:1646  */
    break;

  case 102:
#line 172 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1843 "bison.c" /* yacc.c:1646  */
    break;

  case 103:
#line 173 "bison.y" /* yacc.c:1646  */
    {analise(getTab()+1, needLines);}
#line 1849 "bison.c" /* yacc.c:1646  */
    break;

  case 104:
#line 173 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1855 "bison.c" /* yacc.c:1646  */
    break;

  case 105:
#line 173 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1861 "bison.c" /* yacc.c:1646  */
    break;

  case 106:
#line 177 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines); declarando = 1; strcpy(tipo, (yyvsp[0].strval));}
#line 1867 "bison.c" /* yacc.c:1646  */
    break;

  case 107:
#line 177 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); analiseBloco(inicioBloco, (yyvsp[0].strval)); inserirVar(&varDeclaradas, (yyvsp[-2].strval), (yyvsp[0].strval), "escopo");}
#line 1873 "bison.c" /* yacc.c:1646  */
    break;

  case 109:
#line 181 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 1879 "bison.c" /* yacc.c:1646  */
    break;

  case 110:
#line 182 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1885 "bison.c" /* yacc.c:1646  */
    break;

  case 111:
#line 182 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); analiseBloco(inicioBloco, (yyvsp[0].strval)); inserirVar(&varDeclaradas, tipo, (yyvsp[0].strval), "escopo");}
#line 1891 "bison.c" /* yacc.c:1646  */
    break;

  case 113:
#line 186 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines);}
#line 1897 "bison.c" /* yacc.c:1646  */
    break;

  case 114:
#line 186 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines = 0);}
#line 1903 "bison.c" /* yacc.c:1646  */
    break;

  case 115:
#line 186 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1909 "bison.c" /* yacc.c:1646  */
    break;

  case 116:
#line 186 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines); needLines = 1;}
#line 1915 "bison.c" /* yacc.c:1646  */
    break;

  case 117:
#line 190 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1921 "bison.c" /* yacc.c:1646  */
    break;

  case 120:
#line 195 "bison.y" /* yacc.c:1646  */
    {analise(0, needLines);}
#line 1927 "bison.c" /* yacc.c:1646  */
    break;

  case 121:
#line 195 "bison.y" /* yacc.c:1646  */
    {analise(1, needLines);}
#line 1933 "bison.c" /* yacc.c:1646  */
    break;

  case 123:
#line 199 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines);}
#line 1939 "bison.c" /* yacc.c:1646  */
    break;

  case 124:
#line 199 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1945 "bison.c" /* yacc.c:1646  */
    break;

  case 125:
#line 199 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1951 "bison.c" /* yacc.c:1646  */
    break;

  case 126:
#line 199 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 1957 "bison.c" /* yacc.c:1646  */
    break;

  case 127:
#line 203 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1963 "bison.c" /* yacc.c:1646  */
    break;

  case 128:
#line 204 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1969 "bison.c" /* yacc.c:1646  */
    break;

  case 129:
#line 204 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 1975 "bison.c" /* yacc.c:1646  */
    break;

  case 130:
#line 204 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1981 "bison.c" /* yacc.c:1646  */
    break;

  case 132:
#line 208 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), needLines = 1);}
#line 1987 "bison.c" /* yacc.c:1646  */
    break;

  case 133:
#line 208 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needLines = 0, needSpace = 0;}
#line 1993 "bison.c" /* yacc.c:1646  */
    break;

  case 134:
#line 208 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 1999 "bison.c" /* yacc.c:1646  */
    break;

  case 139:
#line 218 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), 1);}
#line 2005 "bison.c" /* yacc.c:1646  */
    break;

  case 143:
#line 228 "bison.y" /* yacc.c:1646  */
    {analise(getTab(), 1);}
#line 2011 "bison.c" /* yacc.c:1646  */
    break;

  case 144:
#line 228 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needLines = 0; needSpace = 1;}
#line 2017 "bison.c" /* yacc.c:1646  */
    break;

  case 145:
#line 228 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needLines = 1;}
#line 2023 "bison.c" /* yacc.c:1646  */
    break;

  case 146:
#line 232 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, 0); needSpace = 0;}
#line 2029 "bison.c" /* yacc.c:1646  */
    break;

  case 147:
#line 232 "bison.y" /* yacc.c:1646  */
    {analise(0, 0);}
#line 2035 "bison.c" /* yacc.c:1646  */
    break;

  case 151:
#line 239 "bison.y" /* yacc.c:1646  */
    {inserirVar(&varUsadas, "null", (yyvsp[0].strval), "escopo"); analise(needSpace, needLines); needSpace = 0; needLines = 0;}
#line 2041 "bison.c" /* yacc.c:1646  */
    break;

  case 152:
#line 240 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, needLines); needSpace = 0; needLines = 0;}
#line 2047 "bison.c" /* yacc.c:1646  */
    break;

  case 153:
#line 240 "bison.y" /* yacc.c:1646  */
    { analise(0,0); inserirVar(&varUsadas, "null", (yyvsp[0].strval), "escopo");}
#line 2053 "bison.c" /* yacc.c:1646  */
    break;

  case 154:
#line 241 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, needLines); needSpace = 0; needLines = 0; inserirVar(&varUsadas, "null", (yyvsp[0].strval), "escopo");}
#line 2059 "bison.c" /* yacc.c:1646  */
    break;

  case 155:
#line 241 "bison.y" /* yacc.c:1646  */
    {analise(0,0);}
#line 2065 "bison.c" /* yacc.c:1646  */
    break;

  case 156:
#line 245 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, needLines); needSpace = 0; needLines = 0;}
#line 2071 "bison.c" /* yacc.c:1646  */
    break;

  case 157:
#line 246 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, needLines); needSpace = 0; needLines = 0;}
#line 2077 "bison.c" /* yacc.c:1646  */
    break;

  case 158:
#line 246 "bison.y" /* yacc.c:1646  */
    { analise(0,0);}
#line 2083 "bison.c" /* yacc.c:1646  */
    break;

  case 159:
#line 247 "bison.y" /* yacc.c:1646  */
    {analise(needSpace, needLines); needSpace = 0; needLines = 0; }
#line 2089 "bison.c" /* yacc.c:1646  */
    break;

  case 160:
#line 247 "bison.y" /* yacc.c:1646  */
    {analise(0,0);}
#line 2095 "bison.c" /* yacc.c:1646  */
    break;

  case 161:
#line 253 "bison.y" /* yacc.c:1646  */
    {analise(2, 0); needSpace = 0;}
#line 2101 "bison.c" /* yacc.c:1646  */
    break;

  case 162:
#line 254 "bison.y" /* yacc.c:1646  */
    {analise(2, 0); needSpace = 0;}
#line 2107 "bison.c" /* yacc.c:1646  */
    break;

  case 163:
#line 255 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2113 "bison.c" /* yacc.c:1646  */
    break;

  case 164:
#line 256 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2119 "bison.c" /* yacc.c:1646  */
    break;

  case 165:
#line 257 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2125 "bison.c" /* yacc.c:1646  */
    break;

  case 166:
#line 258 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 0;}
#line 2131 "bison.c" /* yacc.c:1646  */
    break;

  case 167:
#line 259 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2137 "bison.c" /* yacc.c:1646  */
    break;

  case 168:
#line 260 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2143 "bison.c" /* yacc.c:1646  */
    break;

  case 169:
#line 261 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2149 "bison.c" /* yacc.c:1646  */
    break;

  case 170:
#line 262 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2155 "bison.c" /* yacc.c:1646  */
    break;

  case 171:
#line 263 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2161 "bison.c" /* yacc.c:1646  */
    break;

  case 172:
#line 264 "bison.y" /* yacc.c:1646  */
    {analise(1, 0); needSpace = 1;}
#line 2167 "bison.c" /* yacc.c:1646  */
    break;

  case 173:
#line 265 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 2173 "bison.c" /* yacc.c:1646  */
    break;

  case 174:
#line 265 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needSpace = 1;}
#line 2179 "bison.c" /* yacc.c:1646  */
    break;

  case 175:
#line 266 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 2185 "bison.c" /* yacc.c:1646  */
    break;

  case 176:
#line 266 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needSpace = 1;}
#line 2191 "bison.c" /* yacc.c:1646  */
    break;

  case 177:
#line 267 "bison.y" /* yacc.c:1646  */
    {analise(1, 0);}
#line 2197 "bison.c" /* yacc.c:1646  */
    break;

  case 178:
#line 267 "bison.y" /* yacc.c:1646  */
    {analise(0, 0); needSpace = 1;}
#line 2203 "bison.c" /* yacc.c:1646  */
    break;


#line 2207 "bison.c" /* yacc.c:1646  */
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
#line 271 "bison.y" /* yacc.c:1906  */


void main(void){
	//Funcao referente ao inicio
	inicio();
	printf("--Analise terminada\n");
}

yyerror(char *s){

	OK = 0;
	printf("Erro na linha %d:%d\n", contadorDeLinhas, contadorEspacos);
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
