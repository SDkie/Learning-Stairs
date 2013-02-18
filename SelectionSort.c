#include<stdio.h>
#define MAX 30
int input(int a[MAX]);
void print(int a[MAX],int size);
void selectionsort(int a[MAX],int size);
int main()
{
	int a[MAX],result,mid,p,k,q,n,size;//size is total no of elements
	size=input(a);
	selectionsort(a,size);
	print(a,size);
	return 0;
}
void selectionsort(int a[MAX],int size)
{
	int position,i,j,temp;
	for(i=0;i<size;i++)
	{
		position=i;
		for(j=i+1;j<size;j++)
		{
			if(a[j]<a[position])
			position=j;
		}
		if(i!=position)
		{
			temp=a[i];a[i]=a[position];a[position]=temp;
		}
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

