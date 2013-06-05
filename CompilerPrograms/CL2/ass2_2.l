%{
	#include<stdio.h>
	#include<string.h>
	int lineno=1;
	char id[10][10];
	int icount=0;
%}
word [^ \n\t]+

%%
"("|")"|"<"|">"|"{"|"}"|","|";" printf("\n%s- special character",yytext);
\n printf("\nline no %d\n ",lineno++);
# printf("\n# - preprocessor character");
("+"|"=") printf("\n%s - operator",yytext);
int|float printf("\n %s - data type", yytext);
include printf("\n include - preprocessor keyword");
[a-z]+.h printf("\n %s - header file",yytext);		  // ask for {word}.h - try this latter
"//".*\n printf("\n %s-SComment", yytext);
"main"|"printf" printf("\n %s -functions",yytext);
"return".*\n printf("\nreturn statement");
"/*"(.|\n)*"*/" printf("\n %s -mcomment",yytext);		//done
"\""(.*)"\"" printf("\n %s - string", yytext);
[a-z](([a-z]|[0-9]|"_")*) {printf("\n %s identifier",yytext);find();}
%%

int find()
{
	printf("\n stored");
}
int main(int argc,char ** argv)
{
	FILE* file;
	file=fopen(argv[1],"r");
	yyin=file;
	printf("line no 1\n");	
	yylex();
	return 0;
}
