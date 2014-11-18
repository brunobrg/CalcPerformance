%{
#include <stdio.h>
#include <stdlib.h>
//#include"listaBison.h"
#include <string.h>

extern int contadorDeLinhas;
%}

%union {
   char * strval;
   int    intval;
}

%token <strval> T_NUMBER
%token <strval> T_STRING TEXTO  STR
%token AND OU IF DO THEN WHILE ELSE NOT 
%token TERMINOU DECLARACAO FIMFUNC FUNCAO ESPERA EXECUTE PASSA
%token <strval> PRINT READ LOCAL 
%token MAIOR MENOR IGUAL SOMA SUBT MULT DIVIDE ATRIBUI 
%token NUMERICAL

%token INCLUDE PH BCOMENT ECOMENT LCOMENT TIPO
%token PVIRGULA FIM_COMANDO LEFT_PAR RIGHT_PAR VIRGULA
%token ABRE_CHAVE FECHA_CHAVE


%start Etapas

%%

Etapas:
	/* Empty */
	| Comentario Includes Structs Prototipos VGlobais Funcoes
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
	| INCLUDE MENOR T_STRING PH MAIOR Includes
	;

Structs:
	/* Empty */
	;

Prototipos:
	/* Empty */ 
	| TIPO Func_Declaracao LEFT_PAR Prot_Parametros1 RIGHT_PAR FIM_COMANDO
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
	;

Funcoes:
	/* Empty */
	| Funcao Funcoes
	;

Funcao: 
	TIPO T_STRING LEFT_PAR Parametros1 RIGHT_PAR ABRE_CHAVE FECHA_CHAVE
	;

Parametros1:
	/* Empty */
	| TIPO T_STRING Parametros2
	;

Parametros2:
	/* Empty */
	| VIRGULA TIPO T_STRING Parametros2
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
