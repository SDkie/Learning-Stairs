%{
#include<string.h>
unsigned charcount = 0, wordcount = 0, linecount = 0;
char str[50];
int o = 0;
int c = 0;

%}
word [^ \t\n]+
eol \n



%%
"{" {o++;}
"}" {c++;}
{eol} { linecount++; charcount++;  printf("%d\t%d\t%d\t\n",yylineno++,wordcount,charcount); charcount=0; wordcount=0; }
{word}  { wordcount++; charcount += yyleng; strcpy(str,yytext); printf(" %s ",str);}
. charcount++;

%%
main(argc,argv)
int argc ;
char **argv;
{
if(argc > 1) 
{ 
FILE *file;
file = fopen(argv[1], "r") ;
if(!file) 
{
fprintf(stderr,"could not open %s\n",argv[1]);
exit(1);
}
printf("\nContents\tLine no\tWord count\tChar count\n");

yyin = file;
}
printf("\n");

if(o==c)
	printf("\nBrackets Correctly Enclosed !!\n");
else if(o<c)
	printf("\n{ is missing !! \n");
else
	printf("\n} is missing !! \n");


yylex();

return 0;
}
