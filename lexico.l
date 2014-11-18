%{option main

 #include "bison.h"
 int contadorDeLinhas = 1;
%}
/* TIPOS */
STRING [a-z]+[a-zA-Z0-9]*
SPACE [ \r\t]+
NUMBER [0-9]



%% /*REGRAS:*/
"\n"								{contadorDeLinhas++;}
"/*"								return BCOMENT;
"*/"								return ECOMENT;
"*"								return LCOMENT;
";\n"					    		return FIM_COMANDO;
";"									return PVIRGULA;
","									return VIRGULA;
"espera"							return ESPERA;
"fimFunc"+"\n"+						{yyterminate(); return FIMFUNC;}
(f|F)+(uncao)+							return FUNCAO;
"declare"							return DECLARACAO;
"("									return LEFT_PAR;
")"									return RIGHT_PAR;
"{"									return ABRE_CHAVE;
"}"									return FECHA_CHAVE;
"numero"							return NUMERICAL;
"texto"								return STR;
"#include"							return INCLUDE;
(\".*\")+							{yylval.strval = strdup(yytext); return TEXTO;}
(printf)+    						return PRINT;
(scanf)+ 	            			return READ;
(if)+                   		    			return IF;
(int|float|double|char)+ 		    			{yylval.strval = strdup(yytext); return TIPO;}
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
