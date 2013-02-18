#include<stdio.h>
void towers(int,char,char,char);

int main()
{ 
	int n;
	printf("Enter the number of disks : ");
	scanf("%d",&n);
	printf("The Tower of Hanoi involves the moves :\n\n");
	towers(n,'A','C','B');
	return 0;
}

void towers(int n,char frompeg,char topeg,char auxpeg)
{
	  if(n==1)			/* If only 1 disk, make the move and return */
	    { 
		printf("Move disk from peg %c to peg %c\n",frompeg,topeg);
	      	return;
	    }
	  towers(n-1,frompeg,auxpeg,topeg);    	          /* Move top n-1 disks from A to B, using C as auxiliary */
	  printf("Move from peg %c to peg %c\n",frompeg,topeg);  	  /* Move remaining disks from A to C */
	  towers(n-1,auxpeg,topeg,frompeg);       	  /* Move n-1 disks from B to C using A as auxiliary */ 
}


