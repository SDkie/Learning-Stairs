%{
#include"inter.h"
#include<stdio.h>
#include<string.h>
extern FILE *yyin;
float tcount=1;
char tvar[20]="t";
char sbuff[20];
%}

%union{
	struct Symbol syptr;  
	double value;
	char type[20];
}
%token MAIN IF ELSE WHILE
%token <syptr> ID
%token <value> NO
%token <type> DataType

%left '='
%left IF ELSE
%left LE GE ET NE
%left '<' '>'
%left '+' '-'
%left '*' '/'
%left '(' ')'
%left '{' '}'

%type <syptr> Varlist
%type <syptr> Expression

%%
Program: MAIN Block 			{printf("\nDone");}
;
Block: '{' Code '}'		
|
Code
;

Code:	Statement Code
	|
	Statement
;

Statement: Expression ';'		
	|
	Declaration
	|
	Conditional
;

Conditional:
	IFStat					{printf("\nonly if");}
	|
	IFStat Else 				{printf("\nboth if else");}	
	|
	While
;


IFStat:	IF '(' Expression ')' 			{printf("\n%s",$3.name);gcvt(quadid+2,20,sbuff);addQuad("IF",$3.name," ",sbuff); addQuad("GOTO"," "," ","Unknown");}
	'{' Code '}'				{pushid(quadid+1);backpatch();}	//remember this thing very imp
;

Else:	 ELSE 					{addQuad("ELSE"," "," ","Unknown");}   //let Elst part be as it is
	'{' Code '}'				{pushid(quadid+1);backpatch();}
;

While:
	WHILE '(' Expression ')'		{gcvt(quadid+2,20,sbuff);addQuad("WHILE ",$3.name," ",sbuff);  addQuad("GOTO"," "," ","Unknown");}			
	'{' Code '}'				{pushid(quadid);}
;

Expression:
	Expression '+' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value+$3.value;addQuad("+",$1.name,$3.name,tvar);}	
	|
	Expression '-' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value-$3.value;addQuad("-",$1.name,$3.name,tvar);}
	|
	Expression '*' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value*$3.value;addQuad("*",$1.name,$3.name,tvar);}
	|
	Expression '/' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value/$3.value;addQuad("/",$1.name,$3.name,tvar);}
	|
	Expression '<' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value<$3.value;addQuad("<",$1.name,$3.name,tvar);}
	|
	Expression '>' Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value>$3.value;addQuad(">",$1.name,$3.name,tvar);}
	|
	Expression ET Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value==$3.value;addQuad("==",$1.name,$3.name,tvar);}
	|
	Expression NE Expression	{gcvt(tcount++,20,tvar+1);strcpy($$.name,tvar);$$.value=$1.value!=$3.value;addQuad("!=",$1.name,$3.name,tvar);}
	|
	NO				{$$.value=$1;gcvt($1,20,sbuff);strcpy($$.name,sbuff);};
	|
	ID '=' Expression		{$$=$3;addQuad("=",$3.name," ",$1.name);}
	|
	ID				
;

Declaration: DataType Varlist ';'	{strcpy($2.type,$1);} 
;

Varlist:
	ID ',' Varlist			{addID(&$1);}
	|
	ID '=' NO ',' Varlist		{$1.value=$3;addID(&$1);gcvt($3,20,sbuff);addQuad("=",sbuff," ",$1.name);}
	|
	ID  				{addID(&$1);}
	|
	ID '=' NO			{$1.value=$3;addID(&$1);gcvt($3,20,sbuff);addQuad("=",sbuff," ",$1.name);}
	;
%%

int main(int argc,char** argv)
{
	FILE* fp=fopen(argv[1],"r");
	yyin=fp;
	yyparse();
	backpatch();
	displaysymbol();
	displayQuad();
	return 1;
}

int yyerror()
{

	printf("\n\nError in the input\n");
	return 1;
;
}
