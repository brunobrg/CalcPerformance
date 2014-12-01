%{

 #include "bison.h"
 int contadorDeLinhas = 1;
 int contadorEspacos = 0;
 int espacos = 0;
 int linhas_puladas = 0;
 int OK = 1;

%}
/* TIPOS */
STRING [a-z]+[a-zA-Z0-9]*
SPACE [\r]+
NUMBER [0-9]



%% /*REGRAS:*/
" "									{espacos++;}
"\t"								{inserirSaidaAnalise(contadorDeLinhas, "Error03", 0, 0); addError("Error03"); }
"\n"								{contadorDeLinhas++; linhas_puladas++; espacos = 0; contadorEspacos = 0;}
"/*"								return BCOMENT;
"*/"								return ECOMENT;
"*"									return LCOMENT;
";"									return PVIRGULA;
","									return VIRGULA;
"static"							return STATIC;
"/* Prototipos */"					return _PROTOTIPO;
"/* Structs */"						return _STRUCT;
"/* Includes */"					return _INCLUDE;
"/* Main */"						return _MAIN;
"/* Variaveis Globais */"			return _VGLOBAIS;
"/* Funcoes */"						return _FUNC;
"espera"							return ESPERA;
"fimFunc"+"\n"+						{yyterminate(); return FIMFUNC;}
"main"								return MAIN;
(f|F)+(uncao)+						return FUNCAO;
"declare"							return DECLARACAO;
"("									return LEFT_PAR;
")"									return RIGHT_PAR;
"{"									return ABRE_CHAVE;
"}"									return FECHA_CHAVE;
"numero"							return NUMERICAL;
"texto"								return STR;
"#include"							return INCLUDE;
(\".*\")+							{yylval.strval = strdup(yytext); return TEXTO;}
(printf)	  						return PRINTF;
(scanf)		            			return SCANF;
(if)+                   		    			return IF;
(int|float|double|char)+ 		    			{yylval.strval = strdup(yytext); return TIPO;}
(%+(d|f|lf|c|s|u|i))					{yylval.strval = strdup(yytext); return VARUSE;}

"+"								return SOMA;
"-"								return SUBT;
"/"								return DIVIDE;
"="								return ATRIBUI;
(\>)+ 					    			return MAIOR;
(\<)+ 					    			return MENOR;
(\=)+ 					    			return IGUAL;
"!="								return NOT;
(\|\|)+ 					    			return OU;
(&&)+ 					    			return AND;
(else)+ 				    			return ELSE;
(while)+ 				    			return WHILE;
(do)+ 				    			return DO;

{NUMBER}+                               			{yylval.strval = strdup(yytext); return T_NUMBER;}
{STRING}				    			{yylval.strval = strdup(yytext); return T_STRING;}
".h"									return PH;
{SPACE}					    			/*ignore*/



%%
