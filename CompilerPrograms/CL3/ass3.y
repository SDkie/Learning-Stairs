%{
#include<stdio.h>
%}

%token A,B,C

%%
S1:
A B C {printf("match");}
%%


int main()
{
	yyparse();
	return 0;
}

int yyerror()
{

	return 0;
}
