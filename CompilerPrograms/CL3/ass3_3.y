%{

#include<stdio.h>

%}

%token fo,var,comma,semicolan,ob,cb,inc_dec,val,equal,compare

%%
for_stat:
fo ob init semicolan semicolan var cb {printf("done");}
|
fo ob init semicolan condition semicolan var inc_dec cb {printf("done");}
|
fo ob semicolan semicolan cb 		{printf("done");}
;

init:
var equal val 		{printf("initialization");}
|
var 			{printf("initialization");}		
;


condition:
var compare val
|
var compare var

%%

int yyerror()
{

	printf("Error");
	return 0;
}
int main()
{
	yyparse();
	return 0;
}
