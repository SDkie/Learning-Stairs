lex ass5.l
yacc -vd ass5.y
gcc y.tab.c lex.yy.c inter.c
./a.out input.c 
