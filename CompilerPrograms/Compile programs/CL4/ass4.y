
%{
#include<stdio.h>
%}
%union{
int val;
}
%token<val> NO
%left '+' '-'
%left '*' '/'
%type<val> EXP
%%

EXP1: EXP  {printf("output%d",$1);}
;

EXP:
	EXP '+' EXP 		{$$=$1+$3;}
	|
	EXP '-' EXP		{$$=$1-$3;}
	|
	EXP '*' EXP		{$$=$1*$3;}
	|
	EXP '/' EXP		{$$=$1/$3;}
	|
	NO			{$$=$1;}
	;
%%
int main()
{
	yyparse();
	return 0;

}
int yyerror()
{
	printf("error");
	return 0;
}
