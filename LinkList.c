
//SEE FOR REVERSE OTHER SOLUTION
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct linklist
{
	struct node *start;
	int size;
};
void intz(struct linklist *p);
void reverse(struct linklist *p);
void print(struct linklist *p);
void insertfront(struct linklist * p,int newdata);
void insertpositon(struct linklist *p,int newdata,int position);
void deletenode(struct linklist *p,int position);
void insertlast(struct linklist *p,int new);
void deletelast(struct linklist *p);
void deletefront(struct linklist *p);
int main()
{
	struct linklist *p=(struct linklist*)malloc(sizeof(struct linklist));
	int n,newdata,position;
	do
	{
		printf("\nenter your choice 1.initz2.insert3.print4.delete");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			intz(p);
			break;
			case 2:
			printf("\nenter your subchoice");
			scanf("%d",&n);
			printf("enter the data");
			scanf("%d",&newdata);
			switch(n)
			{
				case 1:
				insertlast(p,newdata);
				print(p);
				break;
				case 2:
				insertfront(p,newdata);
				print(p);
				break;
				case 3:
				printf("\nenter your subchoice:1.front 2.last 3. middle");
				scanf("%d",&position);
				insertpositon(p,newdata,position);
				print(p);
				break;
			}
			break;
			case 3:
			print(p);
			break;
			case 4:
			printf("\nenter your subchoice:1.front 2.last 3. middle");
			scanf("%d",&n);
			switch(n)
			{
				case 1:
				deletefront(p);
				print(p);
				break;
				case 2:
				deletelast(p);
				print(p);
				break;
				case 3:
				printf("enter the position data");
				scanf("%d",&position);
				deletenode(p,position);
				
				break;
				
			}
			break;
			case 5:
				reverse(p);
				print(p);
				break;
		}
	}while(n!=0);
	return 0;
}
void reverse(struct linklist *p)
{
	struct node *pre,*ptr,*nextp,*newstart;
	if(p->size==1)
	return;
	if(p->size==2)
	{
		newstart=p->start->next;
		newstart->next=p->start;
		p->start=newstart;
		return;
	}
	else
	{
		pre=NULL;
		ptr=p->start;
		nextp=ptr->next;
		
		while(nextp!=NULL)
		{
			ptr->next=pre;
			pre=ptr;
			ptr=nextp;
			nextp=nextp->next;
		}
			ptr->next=pre;
			p->start=ptr;
	}
}
/*
void reverse(struct linklist *p)
{
	struct node *pre,*ptr,*nextp,*newstart;
	if(p->size==1)
	return;
	if(p->size==2)
	{
		newstart=p->start->next;
		newstart->next=p->start;
		p->start=newstart;
		return;
	}
	else
	{
		pre=NULL;
		ptr=p->start;
		nextp=ptr->next;
		
		while(ptr!=NULL)
		{
			ptr->next=pre;
			pre=ptr;
			ptr=nextp;
			if(ptr!=NULL)
			nextp=nextp->next;
		}
	}
}*/
void deletenode(struct linklist *p,int position)
{
	struct node* ptr=p->start,*previous;
	if(p->start->data==position)//imp condition dont forget this to include
	{
		deletefront(p);
		return;
	}
	while(ptr->data!=position)
	{
		previous=ptr;
		ptr=ptr->next;
	}
	previous->next=ptr->next;
	p->size--;
	print(p);
}
void deletefront(struct linklist *p)
{
	if(	p->size==0)
	{
		printf("empty link list");
		return;
	}
	if(p->size==1)
	{
		intz(p);
		return;
	}
	p->start=p->start->next;
	p->size--;
}
void deletelast(struct linklist *p)
{
	if(	p->size<=1)//remember this its important to consider (else segmantaion fault)
	{
		intz(p);
		return;
	}
	
	struct node *ptr=p->start;	
	while(ptr->next->next!=NULL)
	ptr=ptr->next;
	ptr->next=NULL;
	p->size--;
}
void insertpositon(struct linklist *p,int newdata,int position)
{

	struct node* new=(struct node*)malloc(sizeof(struct node)),*ptr=p->start;
	new->data=newdata;
	p->size++;
	
	while(ptr->data!=position)
	ptr=ptr->next;
	
	new->next=ptr->next;
	ptr->next=new;
}

void insertfront(struct linklist *p,int newdata)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=newdata;
	new->next=p->start;
	p->start=new;
	p->size++;
}
void print(struct linklist *p)
{
	struct node* ptr=p->start;
	int n=p->size,i;
	if(p->size==0)
	{
		printf("empty");
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}
void insertlast(struct linklist *p,int newdata)
{
	struct node* ptr;	
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=newdata;
	p->size++;
	new->next=NULL;
	if(p->start==NULL)
	{
		p->start=new;
	}
	else
	{
		ptr=p->start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new;
	}
}
void intz(struct linklist *p)
{
	p->start=NULL;
	p->size=0;
}
