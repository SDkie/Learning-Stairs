struct Symbol
{
	char name[20];
	char type[20];
	double value;
	struct Symbol *next;
};


struct Quadruple
{
	Quadruple* next;
	Quadruple* pre;
	int index;
	char op[5];
	char operand1[10];
	char operand2[10];
};


//just the structure are declared
