
%{
#include<stdio.h>
#include<string.h>
int word=0,lines=0,chars=0;
%}
word [^ \t\n]+
eol \n

%%
{word} {word++;chars+=yyleng;;}
{eol} {lines++;}
%%


int main(int argc,char** argv)
{
	FILE* file=fopen(argv[1],"r");
	yyin=file;
	yylex();
	printf("no of word %d lines %d chars %d",word,lines,chars);
	return 0;
}


