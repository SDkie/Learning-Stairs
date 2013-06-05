%{
#include"y.tab.h"
#include<stdio.h>
%}
	
num [0-9]
alpha [a-zA-z]

%%

{num}+ 		{yylval.val=atoi(yytext) ; return(NO); }
\n 		{return 0;} 	//ask
.		{return(yytext[0]);}

%%

int yywrap()
{

	return 0;
}

