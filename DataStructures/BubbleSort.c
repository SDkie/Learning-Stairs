#include<stdio.h>
#define MAX 30
void bubblesort(int a[MAX],int size);
int input(int a[MAX]);
void print(int a[MAX],int size);


int main()
{
	int a[MAX],result,mid,p,k,q,n,size;//size is total no of elements
	size=input(a);
	bubblesort(a,size);
	print(a,size);
}
void bubblesort(int a[MAX],int size)
{
	int i,j,flag=0,temp;
		for(i=0;i<size&&flag==0;i++)
		{
			flag=1;
			for(j=0;j<(size-i-1);j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j+1];a[j+1]=a[j];a[j]=temp;
					flag=0;
				}
			}
		}
}

void print(int a[MAX],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d\t",a[i]);
	printf("\n");
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

