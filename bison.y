%{
#include <stdio.h>
#include <stdlib.h>
#include "analise.h"
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
%token MAIOR MENOR IGUAL SOMA SUBT MULT DIVIDE ATRIBUI 
%token NUMERICAL


//novos
%token INCLUDE PH BCOMENT ECOMENT LCOMENT TIPO
%token PVIRGULA FIM_COMANDO LEFT_PAR RIGHT_PAR VIRGULA
%token ABRE_CHAVE FECHA_CHAVE
%token <strval> PRINTF SCANF VARUSE

%start Etapas

%%

Etapas:
	/* Empty */
	| Comentario {inicializaAnalise(); analise(0,0);} _Includes Structs Prototipos VGlobais Funcoes
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

_Includes:
	/* Empty */
	| INCLUDE {analise(0, 2);} MENOR {analise(1, 0);} T_STRING {analise(0, 0);} PH {analise(0, 0);} MAIOR  {analise(0, 0);} Includes
	;

Includes:
	/* Empty */
	| INCLUDE {analise(0, 1);} MENOR {analise(1, 0);} T_STRING {analise(0, 0);} PH {analise(0, 0);} MAIOR  {analise(0, 0);} Includes
	;

Structs:
	/* Empty */
	;

Prototipos:
	/* Empty */ 
	| TIPO {analise(0, 2);} Func_Declaracao {analise(1, 0);} LEFT_PAR {analise(0, 0);} Prot_Parametros1 RIGHT_PAR {analise(0, 0);} FIM_COMANDO {analise(0, 0);}
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
	| Declaracao
	;

Funcoes:
	/* Empty */
	| Funcao Funcoes
	;

Funcao: 
	TIPO NewLine {analise(0, 1);} T_STRING {analise(0, 0);} LEFT_PAR {analise(0, 0);} Parametros1 RIGHT_PAR Estrutura
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
	TIPO {analise(0, 2);} T_STRING {analise(1, 0);} FIM_COMANDO {analise(0, 0);}
	;

Comando_Bloco:
	/* Empty */
	| Printf Comando_Bloco
	| Scanf Comando_Bloco
	;

Printf:
	PRINTF {analise(0, 0);} LEFT_PAR {analise(0, 0);} TEXTO {analise(0, 0);} RIGHT_PAR {analise(0, 0);} FIM_COMANDO {analise(0, 0);}
	;

Scanf:
	SCANF LEFT_PAR TEXTO Esc_Var FIM_COMANDO
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
