%{
#include <stdio.h>
#include <stdlib.h>
#include "analise.h"
#include <string.h>

extern int contadorDeLinhas;
int needLines = 0;
int needSpace = 0;
int tab = 0;
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
	| {needLines = 0;}Comentario {inicializaAnalise();} Includes {needLines = 2;} Structs {needLines = 2;} Prototipos {needLines = 2;} VGlobais {needLines = 2;} Funcoes
	;

Comentario:
	/* Empty */
	| { needLines = 2;} BCOMENT Comentario_Texto Comentario 
	| LCOMENT Comentario_Texto Comentario
	| ECOMENT
	;

Comentario_Texto:
	/* Empty */
	| T_STRING Comentario_Texto
	;

Includes:
	/* Empty */
	| INCLUDE {analise(getTab(), needLines);} MENOR T_STRING PH MAIOR Includes
	;

Structs:
	/* Empty */
	;

Prototipos:
	/* Empty */
	| Prototipo Prototipos
	;

Prototipo: 
	TIPO {analise(getTab(), needLines); needLines = 0;} T_STRING {analise(1, needLines);} LEFT_PAR {analise(0, needLines);} Prot_Parametros1 RIGHT_PAR {analise(0, needLines);} PVIRGULA {analise(needSpace, 0); needLines = 1;}
	;

Prot_Parametros1:
	/* Empty */
	| TIPO {analise(0, needLines);} Prot_Parametros2
	;

Prot_Parametros2:
	/* Empty */
	| VIRGULA {analise(0, needLines);} TIPO {analise(1, needLines);} Prot_Parametros2
	;

VGlobais:
	/* Empty */
	| STATIC {analise(getTab(), needLines); needLines = 0;} Dec_Global VGlobais
	;

Dec_Global:
	TIPO {analise(1, needLines);} T_STRING {analise(1, 0);} PVIRGULA {analise(0, 0); needLines = 1;}
	;

Funcoes:
	/* Empty */
	| {needLines = 2;} Funcao Funcoes
	;

Funcao: 
	TIPO {analise(getTab(), needLines); needLines = 1;} T_STRING {analise(getTab(), needLines); needLines = 0;} LEFT_PAR {analise(0, needLines);} Parametros1 RIGHT_PAR {analise(0, 0);} Estrutura
	;

Parametros1:
	/* Empty */
	| TIPO {analise(0, needLines);} T_STRING {analise(1, needLines);} Parametros2
	;

Parametros2:
	/* Empty */
	| VIRGULA {analise(0, needLines);} TIPO {analise(1, needLines);} T_STRING {analise(1, needLines);} Parametros2
	;

Estrutura:
	ABRE_CHAVE {analise(getTab(), needLines = 1); addTab();} Bloco FECHA_CHAVE {remTab();}
	;

Bloco:
	Declaracao_Bloco {needLines = 2;} Comando_Bloco
	;

Declaracao_Bloco:
	/* Empty */
	| Declaracao {needLines = 1;} Declaracao_Bloco
	;

Declaracao:
	TIPO {analise(getTab(), needLines);} T_STRING {analise(1, 0);} PVIRGULA {analise(0, 0); needLines = 1;}
	;

Comando_Bloco:
	/* Empty */
	| Printf Comando_Bloco
	| Scanf Comando_Bloco
	;

Printf:
	PRINTF {analise(getTab(), needLines);} LEFT_PAR {analise(0, needLines = 0);} TEXTO {analise(0, needLines);} RIGHT_PAR {analise(0, needLines);} PVIRGULA {analise(0, needLines); needLines = 1;}
	;

Scanf:
	SCANF LEFT_PAR TEXTO Esc_Var PVIRGULA
	;

Esc_Var:
	RIGHT_PAR
	| VIRGULA T_STRING Esc_Var
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
