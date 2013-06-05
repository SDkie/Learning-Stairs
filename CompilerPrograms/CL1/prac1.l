%{
	int count=0;
	int o=0;

%}
LETTER [a-zA-Z]  
DIGIT [0-9]  

%%
abc {printf("%s\n",yytext);}
[abc] {printf("[%s]\n",yytext);}
"{" {o++;}
. {count++; printf(yytext);} 
\n {printf("newline\n");}
{LETTER}*".h" 
%%

int main(int argc, char** argv)
{
	FILE* file;
	file=fopen(argv[1],"r");
	yyin=file;
	yylex();

	printf("total count: %d  %d\n",count,o);
	return 0;
}
