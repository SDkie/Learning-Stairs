//perform  again
#include<stdio.h>

#define MAX 20
void partition(int a[MAX],int low,int high);
void merge(int a[MAX],int l,int m,int h);
int input(int a[MAX]);
void print(int a[MAX],int size);
int main()
{
	int a[MAX],size;
	size=input(a);
	printf("\n%d\n",size);
	print(a,size);
	partition(a,0,size-1);
	print(a,size);
	return 0;
}


void partition(int a[MAX],int i,int j)
{
	int k;
	if(i<j)
	{
		k=(i+j)/2;
		partition(a,i,k);
		partition(a,k+1,j);
		merge(a,i,k,j);	
	}
}

void merge(int a[MAX],int l,int m,int h)
{
	int c[MAX],i=l,j=m+1,count=0;
	while(i<=m&&j<=h)
	{
		if(a[i]<=a[j])
			c[count++]=a[i++];
		else
			c[count++]=a[j++];
	}
	while(i<=m)
		c[count++]=a[i++];	

	while(j<=h)
		c[count++]=a[j++];

	for(i=l,j=0;i<=h;)
		a[i++]=c[j++];
}

int input(int a[MAX])
{
	int n,i;
	printf("enter the size");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	return n;// n is equal to size
}

void print(int a[MAX],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\t",a[i]);
	
	printf("\n");
}
