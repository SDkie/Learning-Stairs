#include "avg.h"
#include<stdlib.h>
#include<stdio.h>

void progavg_1(char *host,int argc,char *argv[])
{
	double *ptr_input,value;
	double *result_1;
	int i;
	int no_input;
	char *endptr;
	CLIENT *clnt;
	input_data avg_1_arg;

	ptr_input=&(avg_1_arg.list[0]);
	avg_1_arg.no_of_elements=no_input= argc - 2;

	for(i=0;i<20;i++)
	{
		(*ptr_input) =0;
		ptr_input++;
	}
	ptr_input=&(avg_1_arg.list[0]);
	for(i=1;i<=no_input;i++)
	{
		value=strtod(argv[i+1],&endptr);
		*ptr_input=value;
		printf("\nNumber%d : %e",i,*ptr_input);
		ptr_input++;
	}
	
	clnt=clnt_create(host,PROGAVG,VERAVG,"udp");

	result_1=avg_1(&avg_1_arg,clnt);
	
	clnt_destroy(clnt);

	printf("\nAverage = %e \n", *result_1);	
}

int main(int argc, char *argv[])
{
	char *host;
	host=malloc(sizeof(argv[1]));
	host=argv[1];
	progavg_1(host,argc,argv);
	return 0;	
}

