#include<stdio.h> 
#include<fcntl.h>
main()
{
FILE *file1;
int fifo_server,fifo_client;
int choice;
char *buf;
fifo_server = open("fifo_server",O_RDWR);
if(fifo_server<1) {
 printf("Error opening file");
 }
read(fifo_server,&choice,sizeof(int));
sleep(10);
fifo_client = open("fifo_client",O_RDWR);

if(fifo_server<1) {
 printf("Error opening file");
 }

switch(choice) {

case 1: 
 buf="Linux";
 write(fifo_client,buf,10*sizeof(char)); 
 printf("\n Data sent to client \n");
 break;
case 2:

 buf="debian";
 write(fifo_client,buf,10*sizeof(char)); 
 printf("\nData sent to client\n");
 break;
case 3: 
 buf="2.6.32";
 write(fifo_client,buf,10*sizeof(char)); 
 printf("\nData sent to client\n");
}

close(fifo_server);
close(fifo_client);
}


