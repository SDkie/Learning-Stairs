#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE* finput,*foutput;
void readquad();
void optimization();
void displayQuad();
char buff[40];
void target();
void indexforlabels();
char opcode[20];
int ilabel[20];
int in=0;
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
struct Quadruple* quad_head,*quad_curr,*t;

int main()
{
	finput=fopen("tac.dat","r");
	readquad();
	displayQuad();
	indexforlabels();
	target();
	return 0;
}

void indexforlabels()
{
	struct Quadruple* t=quad_head;
	int i,j;
	while(t!=NULL)
	{
		if(isdigit(t->result[0]))
			ilabel[in++]=atoi(t->result);
		t=t->next;
	}
	
	for(i=0;i<in;i++)
	{
		for(j=i+1;j<in;j++)
		{
			if(ilabel[i]>ilabel[j])
			{
				int temp=ilabel[i];
				ilabel[i]=ilabel[j];
				ilabel[j]=temp;
			}
		}
	}
	
	for(i=0;i<in;i++)
	{
		printf("%d\t",ilabel[i]);
	}
}

int search(int no)
{
		int i;
		for(i=0;i<in&&ilabel[i]!=no;i++);
		return(i);
}

void target()
{
		int inlable=0;
		t=quad_head;
		while(t!=NULL)
		{
//			printf("FOR index %d\n",t->index);
			if(ilabel[inlable]==t->index)
			{
				printf("label%d[%d]:\n",search(ilabel[inlable++]),t->index);
			}
			switch(t->operator1[0])
			{
				case '=':	//consider '==' case
					printf("MOV %s %s\n",t->result,t->operand1);
					break;
				case '+':
					printf("MOV AX %s\n",t->operand1);
					printf("MOV BX %s\n",t->operand2);
					printf("ADD AX BX\n");
					printf("MOV %s AX\n",t->result);
					break;
				case '-':
					printf("MOV AX %s\n",t->operand1);
					printf("MOV BX %s\n",t->operand2);
					printf("SUB AX BX\n");	
					printf("MOV %s AX\n",t->result);
					break;
				case '*':
					printf("MOV AX %s\n",t->operand1);
					printf("MOV BX %s\n",t->operand2);
					printf("MUL AX BX\n");
					printf("MOV %s AX\n",t->result);
					break;
				case '/':
					printf("MOV AX %s\n",t->operand1);
					printf("MOV BX %s\n",t->operand2);
					printf("DIV AX BX\n");
					printf("MOV %s AX\n",t->result);
					break;
				case '<':
					printf("CMP %s %s\n",t->operand1,t->operand2);
					if(t->operator1[1]=='=')
						strcpy(opcode,"JLE");
					else
						strcpy(opcode,"JL");
					break;
				case '>':
					printf("CMP %s %s\n",t->operand1,t->operand2);
					if(t->operator1[1]=='=')
						strcpy(opcode,"JGE");
					else
						strcpy(opcode,"JG");
					break;	
				case '!':
					printf("CMP %s %s\n",t->operand1,t->operand2);
					strcpy(opcode,"NE");
					break;
				case 'I':
				case 'E':
				case 'W':
					printf("%s label%d:\n",opcode,search(atoi(t->result)));
					break;
				case 'G':
					printf("JMP label%d:\n",search(atoi(t->result)));
					break;
			}
			t=t->next;
		}
}

void displayQuad()  //how to write it to a file
{
	struct Quadruple* t=quad_head;
	printf("\n\nQuad table\n");
	while(t!=NULL)
	{
		printf("%d\t\t%s\t\t%s\t\t%s\t%s\t\n",t->index,t->operator1,t->operand1,t->operand2,t->result);
		t=t->next;
	}
}

void readquad()
{			
		char *line = (char*)malloc(20);
        size_t len = 0;	
		quad_head=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		quad_curr=quad_head;
		
		
		while(getline(&line, &len, finput)!=-1)//remember -1
		{	
				quad_curr->index=atoi(strtok(line," "));
				strcpy(quad_curr->operator1,strtok(NULL," "));
				strcpy(quad_curr->operand1,strtok(NULL," "));
				strcpy(quad_curr->operand2,strtok(NULL," "));
				strcpy(quad_curr->result,strtok(NULL,"\n"));
				printf("%s",quad_curr->result);
				quad_curr->next=(struct Quadruple*)malloc(sizeof(struct Quadruple));
				quad_curr=quad_curr->next;
		}
		printf("%d",quad_curr->index);
}
