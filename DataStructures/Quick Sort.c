#include<stdio.h>
#define MAX 20
void quicksort(int a[MAX],int number);
int input(int a[MAX]);
void print(int a[MAX],int size);
int main()
{
	int a[MAX],size;
	size=input(a);
	printf("\n%d\n",size);
	print(a,size);
	quicksort(a,size);
	print(a,size);
	return 0;
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

void quicksort(int a[MAX],int number)
{
	int low=0,high=number-1,pivot,hold;

	if(number<2)
		return;
	else
	{
		pivot=a[high/2];
		while(low!=high)
		{
			while(low<high && pivot>a[low])
				low++;	

			while(low<high && pivot<a[high])
				high--;
			
			if(low<high)  //swap
			{
				hold=a[high];a[high]=a[low];a[low]=hold;
			}
		}
			quicksort(a,low);
			quicksort(&a[low+1],number-low-1);
	}
}
