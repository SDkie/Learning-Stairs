#include"inter.h"
int id[20];
struct Quadruple* ptr[20];
int headid=0;
int headptr=0;
char buff[20];
void pushptr(struct Quadruple* newptr)
{
	ptr[headptr++]=newptr;	
	//printf("pushed ptr%d\n",newptr->index);
}

struct Quadruple* popptr()
{
	struct Quadruple* temp;
	if(headptr==0)
		return 0;
	else 
	{
		temp=ptr[--headptr];
	//	printf("poped ptr%d\n",temp->index);
		return temp;
	}
}


void pushid(int newid)
{
	id[headid++]=newid;	
	//printf("pushed id%d, %d\n",newid,id[headid-1]);
}

int popid()
{
	int temp;
	if(headid==0)
		return 0;
	else 
	{
		temp=id[--headid];
		//printf("poped id%d, [%d]\n",temp,headid);
		return temp;
	}
}

void backpatch()
{
	int cid;
	struct Quadruple* cptr;
	//printf("Head values%d %d\n",headptr,headid);
	while(cid=popid())
	{
		gcvt(cid,20,buff);
		cptr=popptr();
		strcpy(cptr->result,buff);		
		//getchar();
	}

}

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

	if(!strcmp(quad_current->result,"Unknown"))
	{
		pushptr(quad_current);
	}
	quad_current->next=NULL;
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

