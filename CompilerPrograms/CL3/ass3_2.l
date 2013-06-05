%{
#include<stdio.h>
#include<string.h>
#include"y.tab.h"
%}

%%
"for"		return(fo);
","		 return(comma);
";" 		return(semicolan);
"("		 return(ob);
")"	 	return(cb);
"++"|"--"	 return(inc_dec);
[a-z]+ 		return(var);
= 		return(equal);
[0-9]* 		return(val);
"<"|">"|"<="|">="|"=="		return(compare);
%%

int yywrap()
{

return 1;

}
//no main in lex and yacc
//because yacc will call lex
