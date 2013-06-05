#include"inter.h"



void addQuad(char* operator1,char* operand1,char* operand2,char* result)
{
	if(quad_head==NULL) 
	{
		quad_head=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		quad_current=quad_head;
	}
	else
	{
		quad_current->next=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		quad_current=quad_current->next;
	}
	strcpy(quad_current->operator1,operator1);
	strcpy(quad_current->operand1,operand1);
	strcpy(quad_current->operand2,operand2);
	strcpy(quad_current->result,result);
	quad_current->index=quadid++;
}


void addID(struct Symbol* symbol)
{
	if(symbol_head==NULL)	//head empty
	{
		symbol_head=(struct Symbol*)malloc(sizeof(struct Symbol));
		symbol_current=symbol_head;
	}
	else	// add to next of current
	{
		symbol_current->next=(struct Symbol*)malloc(sizeof(struct Symbol));
		symbol_current=symbol_current->next;
	}
		//copy to current

	strcpy(symbol_current->type,symbol->type);
	strcpy(symbol_current->name,symbol->name);
	symbol_current->value=symbol->value;	//check
	symbol_current->next=NULL;		//make it null
}

void displayQuad()
{
	struct Quadruple* t=quad_head;
	printf("\n\nQuad table\n");
	while(t!=NULL)
	{
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",t->index,t->operator1,t->operand1,t->operand2,t->result);
		t=t->next;
	}
}

void displaysymbol()
{
	struct Symbol* t=symbol_head;
	printf("\n\nSymbole table:\n");
	while(t!=NULL)
	{
		printf("%s %s %f\n",t->type,t->name,t->value);
		t=t->next;
	}
}
void init()
{
	symbol_head=NULL;
	quad_head=NULL;
	quadid=0;
}

