%{
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
%}

%union {
   char * strval;
   int    intval;
}

%token <strval> T_NUMBER TIPO
%token <strval> T_STRING TEXTO  STR
%token AND OU IF DO THEN WHILE ELSE NOT 
%token TERMINOU DECLARACAO FIMFUNC FUNCAO ESPERA EXECUTE PASSA
%token IGUAL SOMA SUBT MULT DIVIDE ATRIBUI MOD ENDERECO
%token NUMERICAL


//novos
%token INCLUDE PH BCOMENT ECOMENT LCOMENT
%token PVIRGULA LEFT_PAR RIGHT_PAR VIRGULA
%token ABRE_CHAVE FECHA_CHAVE RETURN
%token <strval> PRINTF SCANF VARUSE
%token STATIC MAIN error
%token _PROTOTIPO _INCLUDE _STRUCT _MAIN _VGLOBAIS _FUNC

%start Etapas

%%

Etapas:
	/* Empty */
	| {needLines = 0;} Comentario {linhas_puladas = 0; comment_criador.possui = 1;} _Includes {needLines = 2;} Structs {needLines = 2;} _Prototipos {needLines = 2;} _VGlobais {needLines = 2;} _Main {needLines = 2;} _Funcoes
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
	| _INCLUDE {analise(getTab(), needLines = 2); needLines = 1; comment_include.possui = 1;} Includes
	;

Includes:
	/* Empty */
	| INCLUDE {analise(getTab(), needLines);} '<' {analise(1, 0);} T_STRING {analise(0, 0);} PH {analise(0, 0);} '>' {analise(0, 0);} Includes
	;

Structs:
	/* Empty */
	;

_Prototipos:
	/* Empty */
	| _PROTOTIPO {analise(getTab(), needLines = 2); needLines = 1; comment_prototipo.possui = 1;} Prototipos
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
	TIPO {analise(1, needLines);} T_STRING {analise(1, 0); inserirVar(&varDeclaradas, $1, $3, "global");} PVIRGULA {analise(0, 0); needLines = 1;}
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
	ABRE_CHAVE {analise(getTab(), needLines = 1); addTab();} {inicioBloco = 1;} Bloco FECHA_CHAVE {remTab(); analise(getTab(), needLines = 1);}
	;

Bloco:
	/* Empty */
	| Declaracao Bloco
	| {if(declarando)needLines = 2; declarando = inicioBloco = 0;}  Printf Bloco
	| {if(declarando)needLines = 2; declarando = inicioBloco = 0;}  Scanf Bloco
	| {if(declarando)needLines = 2; declarando = inicioBloco = 0;}  If Bloco
	| {if(declarando)needLines = 2; declarando = inicioBloco = 0;}  Else Bloco
	| {if(declarando)needLines = 2; declarando = inicioBloco = 0;}  Atribuicao Bloco
	| {needLines = 2; if(inicioBloco) needLines = 1; inicioBloco = 0;} Return Bloco
	| error {yyclearin; inserirSaidaError(yytext, "teste", contadorDeLinhas, contadorEspacos);} Bloco
	;

Return:
	RETURN {analise(getTab()+1, needLines);} T_STRING {analise(0, 0);} PVIRGULA {analise(0, 0);} 
	| RETURN {analise(getTab()+1, needLines);} T_NUMBER {analise(0, 0);} PVIRGULA {analise(0, 0);} 
	;

Declaracao:
	TIPO {analise(getTab(), needLines); declarando = 1; strcpy(tipo, $1);} T_STRING {analise(1, 0); analiseBloco(inicioBloco, $3); inserirVar(&varDeclaradas, $1, $3, "escopo");} Declaracao2
	;

Declaracao2
	: PVIRGULA {analise(0, 0); needLines = 1;}
	| VIRGULA {analise(0, 0);} T_STRING {analise(1, 0); analiseBloco(inicioBloco, $3); inserirVar(&varDeclaradas, tipo, $3, "escopo");} Declaracao2
	;

Printf:
	PRINTF {analise(getTab(), needLines);} LEFT_PAR {analise(0, needLines = 0);} Printf_Param RIGHT_PAR {analise(0, needLines);} PVIRGULA {analise(0, needLines); needLines = 1;}
	;

Printf_Param:
	TEXTO {analise(0, needLines);} Printf_Argumentos
	;

Printf_Argumentos:
	/* Empty */
	| VIRGULA {analise(0, needLines);} T_STRING {analise(1, needLines);} Printf_Argumentos
	;

Scanf:
	SCANF {analise(getTab(), needLines);} LEFT_PAR {analise(0, 0);} TEXTO {analise(0, 0);} Esc_Var PVIRGULA {analise(0, 0); needLines = 1;}
	;

Esc_Var:
	RIGHT_PAR {analise(0, 0);}
	| VIRGULA {analise(0, 0);} ENDERECO {analise(1, 0);} T_STRING {analise(0, 0);} Esc_Var
	;

If
	: IF {analise(getTab(), needLines = 1);} LEFT_PAR {analise(1, 0); needLines = 0, needSpace = 0;} Expressao RIGHT_PAR {analise(0, 0);}Fim_If
	;

Fim_If
	:
	| PVIRGULA
	| Estrutura
	;

Else
	: ELSE {analise(getTab(), 1);}
	| Else Else2
	;

Else2
	: If
	| Estrutura
	;

Atribuicao:
	Variavel {analise(getTab(), 1);} ATRIBUI {analise(1, 0); needLines = 0; needSpace = 1;} Expressao PVIRGULA {analise(0, 0); needLines = 1;}
	;

Expressao
	: LEFT_PAR {analise(needSpace, 0); needSpace = 0;} Expressao RIGHT_PAR {analise(0, 0);}
	| T_NUMBER {analise(needSpace, needLines); needSpace = 0; needLines = 0;}
	| T_STRING {analise(needSpace, needLines); needSpace = 0; needLines = 0; inserirVar(&varUsadas, "null", $1, "escopo");}
	| Expressao Operador  Expressao
	;

Variavel:
	T_STRING  {inserirVar(&varUsadas, "null", $1, "escopo");}
	;
	
   	
Operador:
  	'>' {analise(2, 0); needSpace = 0;}
  	| '<' {analise(2, 0); needSpace = 0;}
  	| IGUAL {analise(1, 0); needSpace = 1;}
  	| OU {analise(1, 0); needSpace = 1;}
  	| AND {analise(1, 0); needSpace = 1;}
	| NOT {analise(1, 0); needSpace = 0;}
  	| SOMA {analise(1, 0); needSpace = 1;}
  	| SUBT {analise(1, 0); needSpace = 1;}
  	| MULT {analise(1, 0); needSpace = 1;}
  	| DIVIDE {analise(1, 0); needSpace = 1;}
  	| ATRIBUI {analise(1, 0); needSpace = 1;}
  	| MOD {analise(1, 0); needSpace = 1;}
  	| '<' {analise(1, 0);} ATRIBUI {analise(0, 0); needSpace = 1;}
  	| '>' {analise(1, 0);} ATRIBUI {analise(0, 0); needSpace = 1;}
  	| NOT {analise(1, 0);} ATRIBUI {analise(0, 0); needSpace = 1;}
  	;


%%

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
