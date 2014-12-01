%{
#include <stdio.h>
#include <stdlib.h>
#include "analise.h"
#include <string.h>

extern int contadorDeLinhas;
extern int OK;
int needLines = 0;
int needSpace = 0;
int tab = 0;
int terminou = 0;
extern Error error[20];
extern int totalError;

Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;

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
%token TIPO STATIC MAIN
%token _PROTOTIPO _INCLUDE _STRUCT _MAIN _VGLOBAIS _FUNC

%start Etapas

%%

Etapas:
	/* Empty */
	| {needLines = 0;} Comentario {inicializaAnalise();} _Includes {needLines = 2;} Structs {needLines = 2;} _Prototipos {needLines = 2;} _VGlobais {needLines = 2;} _Main {needLines = 2;} _Funcoes
	;

Comentario:
	/* Empty */
	| BCOMENT {comment_criador.possui = 1; }Comentario_Texto ECOMENT {needLines = 2;}
	; 

Comentario_Texto:
	/* Empty */
	| T_STRING Comentario_Texto
	| LCOMENT Comentario_Texto
	;

_Includes:
	/* Empty */
	| _INCLUDE {analise(getTab(), needLines = 2); needLines = 1;} Includes
	;

Includes:
	/* Empty */
	| INCLUDE {analise(getTab(), needLines);} MENOR T_STRING PH MAIOR Includes
	;

Structs:
	/* Empty */
	;

_Prototipos:
	/* Empty */
	| _PROTOTIPO {analise(getTab(), needLines = 2); needLines = 1;} Prototipos
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

_VGlobais:
	/* Empty */
	| _VGLOBAIS {analise(getTab(), needLines = 2); needLines = 1;} VGlobais
	;

VGlobais:
	/* Empty */
	| STATIC {analise(getTab(), needLines); needLines = 0;} Dec_Global VGlobais
	;

Dec_Global:
	TIPO {analise(1, needLines);} T_STRING {analise(1, 0);} PVIRGULA {analise(0, 0); needLines = 1;}
	;

_Main:
	_MAIN {analise(getTab(), needLines = 2); needLines = 1;} Main
	;

Main:
	TIPO {analise(getTab(), needLines); needLines = 1;} MAIN {analise(getTab(), needLines); needLines = 0;} LEFT_PAR {analise(0, needLines);} Parametros1 RIGHT_PAR {analise(0, 0);} Estrutura
	;

_Funcoes:
	/* Empty */
	| _FUNC {analise(getTab(), needLines = 2); needLines = 1;} Funcoes
	;

Funcoes:
	/* Empty */
	| {needLines = 1;} Funcao Funcoes
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
	ABRE_CHAVE {analise(getTab(), needLines = 1); addTab();} Bloco FECHA_CHAVE {remTab(); analise(getTab(), needLines = 1);}
	;

Bloco:
	/* Empty */
	| Declaracao Bloco
	| Printf Bloco
	| Scanf Bloco
	;

Declaracao:
	TIPO {analise(getTab(), needLines);} T_STRING {analise(1, 0);} PVIRGULA {analise(0, 0); needLines = 1;}
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
	comment_criador.possui = 0;
	comment_prototipo.possui = 0;
	comment_include.possui = 0;
	comment_main.possui = 0;
	comment_vglobais.possui = 0;

	yyparse();
	if(terminou)
	{
		int i = 0;

		printf("\nAnalise terminada");
		if(OK)
			printf("--OK!");
		else
		{
			printf("\n\n");
			imprimeAnalise();
			printf("\n");
			for(i = 0; i < 20 ; i++)
			{
				if(error[i].qnt > 0)
				{
					printf("%s: %d\n", error[i].nome, error[i].qnt);
				}
			}
			printf("\nTotal de erros: %d\n", totalError);
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
