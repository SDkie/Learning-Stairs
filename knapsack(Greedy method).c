#include<stdio.h>
#define MAX 20
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
	
	////sort as per profit/weight
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i);j++)
		{
			if( profit[i]*1.0/weight[i] < profit[i+1]*1.0/weight[i+1] )
			{
				temp=profit[i],profit[i]=profit[i+1],profit[i+1]=temp;
				temp=weight[i],weight[i]=weight[i+1],weight[i+1]=temp;
			}
		}
	}

	////find the profit
	for(i=0;i<n;i++)
	{
		if(currweight+weight[i]<maxweight)
		{
			currweight+=weight[i];
			q[i]=1.0;
			totalprofit+=profit[i];
		}
		else
			break;
	}
	if(i<n)
	{
		q[i]=(maxweight-currweight)/(weight[i]*1.0);
		totalprofit+=q[i]*profit[i];
	}


	//print solution	
	printf("total profit %f",totalprofit);
	return 0;
}


