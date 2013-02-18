#include<stdio.h>
#define MAX 20 

int place(int* queen,int row);
void nqueen(int n);
int main()
{
	int n;
	scanf("%d",&n);
	nqueen(n);
}

void nqueen(int n)
{
	int queen[MAX]={0};
	int row,col;
	for(row=0;row<n;)//placing n queen 
	{
		for(;queen[row]<n;queen[row]++)
		{
			if(place(queen,row))
				break;
		}	
		if(queen[row]<n)  //last placement is successfull
		{
			row++;	  //move ahead
			queen[row]=0;
			if(row==n)
				break;
		}
		else
		{	
			row--;
			queen[row]++;
		}
	}
	
	for(row=0;row<n;row++)
		printf("%d",queen[row]);
}


int place(int* queen,int row)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		if(queen[i]==queen[row]) //same column
			return 0;
		else	if(abs(row-i)==abs(queen[row]-queen[i]))
			return 0;
	}
	return 1;
}
