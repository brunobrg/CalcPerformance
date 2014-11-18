%{
#include <stdio.h>
#include <stdlib.h>
#include "analise.h"
#include <string.h>

extern int contadorDeLinhas;
int needLines = 0;
int needSpace = 0;
%}

%union {
   char * strval;
   int    intval;
}

%token <strval> T_NUMBER
%token <strval> T_STRING TEXTO  STR
%token AND OU IF DO THEN WHILE ELSE NOT 
%token TERMINOU DECLARACAO FIMFUNC FUNCAO ESPERA EXECUTE PASSA
%token MAIOR MENOR IGUAL SOMA SUBT MULT DIVIDE ATRIBUI 
%token NUMERICAL


//novos
%token INCLUDE PH BCOMENT ECOMENT LCOMENT
%token PVIRGULA LEFT_PAR RIGHT_PAR VIRGULA
%token ABRE_CHAVE FECHA_CHAVE
%token <strval> PRINTF SCANF VARUSE
%token TIPO STATIC

%start Etapas

%%

Etapas:
	/* Empty */
	| Comentario {inicializaAnalise(); needLines = 2;} Includes {needLines = 2;} Structs {needLines = 2;} Prototipos {needLines = 2;} VGlobais {needLines = 2;} Funcoes
	;

Comentario:
	/* Empty */
	| BCOMENT Comentario_Texto Comentario 
	| LCOMENT Comentario_Texto Comentario
	| ECOMENT
	;

Comentario_Texto:
	/* Empty */
	| T_STRING Comentario_Texto
	;

Includes:
	/* Empty */
	| INCLUDE {analise(needSpace, needLines);} MENOR T_STRING PH MAIOR Includes
	;

Structs:
	/* Empty */
	;

Prototipos:
	/* Empty */
	| Prototipo Prototipos
	;

Prototipo: 
	TIPO Func_Declaracao LEFT_PAR Prot_Parametros1 RIGHT_PAR PVIRGULA
	;

Func_Declaracao:
	T_STRING
	;

Prot_Parametros1:
	/* Empty */
	| TIPO Prot_Parametros2
	;

Prot_Parametros2:
	/* Empty */
	| VIRGULA TIPO Prot_Parametros2
	;

VGlobais:
	/* Empty */
	| STATIC Declaracao VGlobais
	;

Funcoes:
	/* Empty */
	| {needLines = 3;} Funcao Funcoes
	;

Funcao: 
	TIPO NewLine T_STRING LEFT_PAR Parametros1 RIGHT_PAR Estrutura
	;

Parametros1:
	/* Empty */
	| TIPO T_STRING Parametros2
	;

Parametros2:
	/* Empty */
	| VIRGULA TIPO T_STRING Parametros2
	;

Estrutura:
	ABRE_CHAVE Bloco FECHA_CHAVE
	;

Bloco:
	Declaracao_Bloco Comando_Bloco
	;

Declaracao_Bloco:
	/* Empty */
	| Declaracao Declaracao_Bloco
	;

Declaracao:
	TIPO T_STRING PVIRGULA
	;

Comando_Bloco:
	/* Empty */
	| Printf Comando_Bloco
	| Scanf Comando_Bloco
	;

Printf:
	PRINTF LEFT_PAR TEXTO RIGHT_PAR PVIRGULA
	;

Scanf:
	SCANF LEFT_PAR TEXTO Esc_Var PVIRGULA
	;

Esc_Var:
	RIGHT_PAR
	| VIRGULA T_STRING Esc_Var
	;



NewLine:
	/* Empty */
	| "\n" 
	;

%%

void main(void){
	yyparse();	
	printf("\n--OK!\n");
}

yyerror(char *s){
	printf("Erro na linha: %d\n", contadorDeLinhas);
	yyparse();
}

int yywrap(void) { return 1; }
