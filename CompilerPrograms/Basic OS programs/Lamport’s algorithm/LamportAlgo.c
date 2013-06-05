#include<stdio.h>
#include<string.h>
#define max 20


struct process
{
	int clk;
	int incr;
};
struct process p[max];
int cnt;

void init()
{
	cnt=0; int i;
	printf("\ncount= "); scanf("%d", &cnt); printf("\nEnter clock increment, for all processes: \n");
	for(i=0; i<cnt; i++)
	{
		p[i].clk=0;
		scanf("%d", &p[i].incr);
	}
}
void incr()
{
	int i;
	for(i=0; i<cnt; i++)
	{
		p[i].clk+=p[i].incr;
	}
}
void print()
{
	int i;
	printf("\nClock for all processes: \n");
	for(i=0; i<cnt; i++)
	{
		printf("\nprocess %d: %d", i, p[i].clk);
	}
}
void sendmsg()
{
	int i1, i2;
	printf("\nEnter sender & receiver: "); scanf("%d %d", &i1, &i2);
	printf("\nclock of sender process %d is %d \nclock of receiver process %d is %d ", i1, p[i1].clk, i2, p[i2].clk);
	if(p[i1].clk>=p[i2].clk)
	{
		p[i2].clk=p[i1].clk+1;
		printf("\nprocess %d incremented its clock to %d", i2, p[i2].clk);
	}
	
}

int main()
{
	int i;
	init();
	while(1)
	{
		printf("\n1. print \n2. incr\n3. send msg\n4. exit\nchoice: "); scanf("%d", &i);
		switch(i)
		{
			case 1: print(); break;
			case 2: incr(); print(); break;
			case 3: sendmsg(); print(); break;
			case 4: return 0;
			default: break;
		}
	}
	return 0;
}