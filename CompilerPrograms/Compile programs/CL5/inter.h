#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Symbol
{
	char name[20];
	char type[20];
	double value;
	struct Symbol *next;
};

struct Quadruple
{
	struct Quadruple* next;
	struct Quadruple* pre;
	int index;
	char operator1[20];
	char operand1[10];
	char operand2[10];
	char result[20];
};

struct Symbol* symbol_head;
struct Symbol* symbol_current;
struct Quadruple* quad_head;
struct Quadruple* quad_current;
int quadid;
void displaysymbol();
void backpatch();

extern void init();
void addID(struct Symbol* symbol);
