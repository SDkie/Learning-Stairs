#include<stdio.h>
#define MAX 30
int input(int a[MAX]);
void print(int a[MAX],int size);
void insertionsort(int a[MAX],int size);

int main()
{
	int a[MAX],result,mid,p,k,q,n,size;//size is total no of elements
	size=input(a);
	insertionsort(a,size);
	print(a,size);
	return 0;
}

void insertionsort(int a[MAX],int size)
{
	int i,j,hold;
	for(i=1;i<size;i++)//insert ith position
	{
		hold=a[i];
		j=i;
		while(hold<a[j-1]&&j!=0)//check the loop
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=hold;
	}
}

int input(int a[MAX])
{
	int n,i;
	printf("enter the size");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	return n;							// n is equal to size remember this
}

void print(int a[MAX],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d\t",a[i]);
	printf("\n");
}

