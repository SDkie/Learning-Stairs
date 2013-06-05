%{
#include"inter.h"
#include"y.tab.h"
#include<stdio.h>
#include<stdlib.h>
int line_no=0;
%}
num [0-9]
alpha [a-zA-Z]

%%
"main()" 				return(MAIN);
int|float|char 				{strcpy(yylval.type,yytext);return(DataType);}
if					return(IF);
else					return(ELSE);
while					return(WHILE);
{alpha}(({alpha}|{num})*)		{strcpy(yylval.syptr.name,yytext);return(ID);}
{num}+ 					{yylval.value=atof(yytext); return(NO);}
"<="					return(LE);
">="					return(GE);
"=="					return(ET);
"!="					return(NE);
"+"|"-"|"*"|"/"|";"|","|"<"|">"|"="	{return yytext[0];}
"{"|"}"|"("|")"				{return yytext[0];}
[ \t]					;
[\n]					;
%%

int yywrap()
{
	return 1;

}
