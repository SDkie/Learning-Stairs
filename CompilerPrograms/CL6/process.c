#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE* finput,*foutput;
void readquad();
void init();
void optimization();
void displayQuad();
char buff[40];

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
struct Quadruple* quad_head,*quad_curr;

int main()
{
	init();
	readquad();
	displayQuad();
	optimization();
	displayQuad();
	return 0;
}

//remember the getline formate
void readquad()
{	
		
		char *line = (char*)malloc(20);
	        size_t len = 0;	
		quad_head=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		quad_curr=quad_head;
		
		while(getline(&line, &len, finput)!=-1)//remember -1
		{
				
				quad_curr->index=atoi(strtok(line," "));
				printf("%d",quad_curr->index);
				strcpy(quad_curr->operator1,strtok(NULL," "));
				strcpy(quad_curr->operand1,strtok(NULL," "));
				strcpy(quad_curr->operand2,strtok(NULL," "));
				strcpy(quad_curr->result,strtok(NULL," "));
				printf("%s",quad_curr->result);
				quad_curr->next=(struct Quadruple*)malloc(sizeof(struct Quadruple));
				quad_curr=quad_curr->next;
		}
		printf("%d",quad_curr->index);
}

void optimization()
{
		struct Quadruple *currptr,*preptr,*nextptr,*t;
		currptr=quad_head;
		preptr=NULL;
		nextptr=quad_head->next;
		double res;
		char buff[20];
		int optimized=0;
		while(currptr!=NULL)
		{
			//printf("index- %d",currptr->index);
			if(isdigit(currptr->operand1[0])&&isdigit(currptr->operand2[0]))
			{
				//printf("processing%c %d %d",currptr->operator1[0],atoi(currptr->operand1),atoi(currptr->operand2));
				//printf("\n%d",currptr->index);
				switch(currptr->operator1[0])
				{
					printf("%d",currptr->operator1[0]);
					case '+':
						res=atoi(currptr->operand1)+atoi(currptr->operand2);
					break;
					case '-':
						res=atoi(currptr->operand1)-atoi(currptr->operand2);
					break;
					case '*':
						res=atoi(currptr->operand1)*atoi(currptr->operand2);
					break;
					case '/':
						res=atoi(currptr->operand1)/atoi(currptr->operand2);
					break;
				}
				gcvt(res,20,buff);
				//printf("IN");
				//printf("(%s)%d (%s)%d",currptr->result,strlen(currptr->result),nextptr->operand1,strlen(nextptr->operand1));
				if(!strcmp(currptr->result,nextptr->operand1))
				{
						strcpy(nextptr->operand1,buff);
						optimized++;
				}
				else if(!strcmp(currptr->result,nextptr->operand2))
				{
						strcpy(nextptr->operand2,buff);		
						optimized++;
				}
				nextptr->index--;
				printf("\nbefore%d %s %s %s %s",nextptr->index,nextptr->operator1,nextptr->operand1,nextptr->operand2,nextptr->result);
				
				currptr=nextptr;
				free(preptr->next);
				preptr->next=currptr;
				nextptr=currptr->next;
				
				t=quad_head;
				while(t!=NULL)
				{
					if(t->index>currptr->index)
						t->index--;
					if(isdigit(t->result[0])&&atoi(t->result)>currptr->index)	//its like a jump
					{
							gcvt(atoi(t->result)-1,20,buff);
							strcpy(t->result,buff);
					}
					t=t->next;
				}
				
				continue;
			}			
			preptr=currptr;
			currptr=nextptr;
			if(nextptr!=NULL)
			nextptr=nextptr->next;
			//getchar();
		}
}

void init()
{
	finput=fopen("input.dat","r");
	foutput=fopen("output.dat","w");

}

void displayQuad()  //how to write it to a file
{
	struct Quadruple* t=quad_head;
	printf("\n\nQuad table\n");
	while(t!=NULL)
	{
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",t->index,t->operator1,t->operand1,t->operand2,t->result);
		t=t->next;
	}
}
