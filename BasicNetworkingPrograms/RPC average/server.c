#include "avg.h"
#include<stdlib.h>
#include<stdio.h>
#include<rpc/rpc.h>

static double sum_avg;

double *avg_1(input_data *ptr_input,CLIENT *client)
{
	int i;
	sum_avg=0;
	double *dp;
	dp=ptr_input->list;

	printf("\nNumber of Input %d ",ptr_input->no_of_elements);
	for(i=0;i<=ptr_input->no_of_elements;i++)
	{
		printf("\nNumber%d : %e",i,*dp);
		sum_avg+= (*dp);
		dp++;
	}
	sum_avg/=20;
	return (&sum_avg);
}
double *avg_1_svc(input_data *ptr_input,struct svc_req *svc)
{	
	CLIENT *client;
	return avg_1(ptr_input,client);
}
