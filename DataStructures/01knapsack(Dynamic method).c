#include<stdio.h>
#define MAX 20
int max(int a,int b);

int main()
{
	int n;		  //number of items
	int weight[MAX];  //weights
	int profit[MAX];  //profit
	float q[MAX]={0};	  //selected quantity (initally all zero)
	int maxweight;
	float totalprofit=0;		
	int currweight=0;  //current weight
	int i,j;
	int temp;
	int calculate[MAX][MAX];
	//input
	printf("Enter number of items");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter weight and profit for item %d",i);
		scanf("%d %d",&weight[i],&profit[i]);
	}
	
	printf("Enter max weight");
	scanf("%d",&maxweight);	
	//calculate
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=maxweight;j++)
		{
			if(j>=weight[i])
			{
				calculate[i][j]=max(calculate[i-1][j], calculate[i-1][j-weight[i]] + profit[i]);
			}
			else
			{
				calculate[i][j]=calculate[i-1][j];
			}
//		printf("%d ",calculate[i][j]);
		}
//		getchar();
//		printf("\n");
	}
			
	//print solution	
	printf("total profit %d",calculate[n-1][maxweight]);
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}
