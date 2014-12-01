/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "bison.y" /* yacc.c:1909  */

   char * strval;
   int    intval;

#line 114 "bison.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */
