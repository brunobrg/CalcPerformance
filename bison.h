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
    T_STRING = 259,
    TEXTO = 260,
    STR = 261,
    AND = 262,
    OU = 263,
    IF = 264,
    DO = 265,
    THEN = 266,
    WHILE = 267,
    ELSE = 268,
    NOT = 269,
    TERMINOU = 270,
    DECLARACAO = 271,
    FIMFUNC = 272,
    FUNCAO = 273,
    ESPERA = 274,
    EXECUTE = 275,
    PASSA = 276,
    MAIOR = 277,
    MENOR = 278,
    IGUAL = 279,
    SOMA = 280,
    SUBT = 281,
    MULT = 282,
    DIVIDE = 283,
    ATRIBUI = 284,
    NUMERICAL = 285,
    INCLUDE = 286,
    PH = 287,
    BCOMENT = 288,
    ECOMENT = 289,
    LCOMENT = 290,
    PVIRGULA = 291,
    LEFT_PAR = 292,
    RIGHT_PAR = 293,
    VIRGULA = 294,
    ABRE_CHAVE = 295,
    FECHA_CHAVE = 296,
    PRINTF = 297,
    SCANF = 298,
    VARUSE = 299,
    TIPO = 300,
    STATIC = 301,
    MAIN = 302,
    _PROTOTIPO = 303,
    _INCLUDE = 304,
    _STRUCT = 305,
    _MAIN = 306,
    _VGLOBAIS = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "bison.y" /* yacc.c:1909  */

   char * strval;
   int    intval;

#line 112 "bison.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */
