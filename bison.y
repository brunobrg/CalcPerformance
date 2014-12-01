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
int Possui_Comment_Criador = 0;
int Possui_Comment_Include = 0;
int Possui_Comment_Prot = 0;
int terminou = 0;
extern Error error[20];
extern int totalError;

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
%token _PROTOTIPO _INCLUDE _STRUCT

%start Etapas

%%

Etapas:
	/* Empty */
	| {needLines = 0;} Comentario {inicializaAnalise();} _Includes {needLines = 2;} Structs {needLines = 2;} _Prototipos {needLines = 2;} VGlobais {needLines = 2;} Funcoes
	;

Comentario:
	/* Empty */
	| BCOMENT {Possui_Comment_Criador = 1; }Comentario_Texto ECOMENT {needLines = 2;}
	; 

Comentario_Texto:
	/* Empty */
	| T_STRING Comentario_Texto
	| LCOMENT Comentario_Texto
	;

_Includes:
	/* Empty */
	| BCOMENT {analise(getTab(), needLines); needLines = 0; Possui_Comment_Include = 1;} _INCLUDE {analise(1, needLines);} ECOMENT {analise(1, needLines); needLines = 1;} Includes
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
	| BCOMENT {analise(getTab(), needLines); needLines = 0; Possui_Comment_Prot = 1;} _PROTOTIPO {analise(1, needLines);} ECOMENT {analise(1, needLines); needLines = 1;} Prototipos
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
	if(terminou)
	{
		int i = 0;

		printf("\nAnalise terminada");
		if(OK)
			printf("--OK!");
		else
		{
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
	OK = 0;
	printf("Erro na linha: %d\n", contadorDeLinhas);
	
	if(!Possui_Comment_Criador)
	{
		printf("\n---Codigo nao no formato requisitado, por favor, insira comentarios do criador---\n");
	}
	if(!Possui_Comment_Include)
	{
		printf("\n---Codigo nao no formato requisitado, por favor, insira comentarios antes dos INCLUDES---\n");
	}
	if(!Possui_Comment_Prot)
	{
		printf("\n---Codigo nao no formato requisitado, por favor, insira comentarios dos PROTOTIPOS---\n");
	}
}

int yywrap(void)
{
	terminou = 1;
	return 1; 
}
