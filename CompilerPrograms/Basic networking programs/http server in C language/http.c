#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include <stdlib.h>
 #include <pthread.h>
#include<fcntl.h>
int handle(int clientfd)
{
    char mesg[99999], *reqline[3], data_to_send[1024], path[1000];
    int n, filefd;
    char *ROOT;
    ROOT=malloc(100);
    ROOT=getenv("PWD");
    memset( (void*)mesg, (int)'\0', 99999 );

    n=read(clientfd, mesg, sizeof(mesg));

    if (n<0)   						 // receive error
        fprintf(stderr,("recv() error\n"));
    else if (n==0)    					// receive socket closed
        fprintf(stderr,"Client disconnected upexpectedly.\n");
    else   							 // message received
    {
        printf("%s[[[[[END]]]]]", mesg);
        reqline[0] = strtok (mesg, " \t\n");
        if ( strncmp(reqline[0], "GET\0", 4)==0 )
        {
            reqline[1] = strtok (NULL, " \t");
            reqline[2] = strtok (NULL, " \t\n");
            if ( strncmp( reqline[2], "HTTP/1.0", 8)!=0 && strncmp( reqline[2], "HTTP/1.1", 8)!=0 )
                write(clientfd, "HTTP/1.0 400 Bad Request\n", 25);
            else
            {
                if ( strncmp(reqline[1], "/\0", 2)==0 )
                    reqline[1] = "/index.html";        
                strcpy(path, ROOT);
                strcpy(&path[strlen(ROOT)], reqline[1]);

                if ( (filefd=open(path, O_RDONLY))!=-1 )    //FILE FOUND
                {
                    send(clientfd, "HTTP/1.0 200 OK\n\n", 17, 0);
                    while ( (n=read(filefd, data_to_send, 1024))>0 )
                        write(clientfd, data_to_send, n);
                }
                else    
			write(clientfd, "HTTP/1.0 404 Not Found\n", 23); //FILE NOT FOUND
            }
        }
    }
    //Closing SOCKET
    close(clientfd);
}

int main(int argc,char* argv[])
{
	pthread_t t;
	int portno;
	char buff[2000];
	socklen_t clilen;
	int sockfd,sockfd_cli;
	struct sockaddr_in server_addr,client_addr;
	bzero(&server_addr,sizeof(server_addr));
	bzero(&client_addr,sizeof(client_addr));
	bzero(&buff,sizeof(buff));
	//check the argument validity
	//create socket
	sockfd=socket(AF_INET, SOCK_STREAM ,0);
	if(sockfd<0)
	{
		printf("error in socket\n");
		return 0;
	}
	//bind
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[1]));
	server_addr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		printf("error in bind\n");
		return 0;
	}
	
	//listen
	listen(sockfd,5);
	//accept
	clilen=sizeof(client_addr);
	
	while(1)
 	{
		sockfd_cli=accept(sockfd,(struct sockaddr*) &client_addr,&clilen);
		pthread_create(&t,0,&handle,sockfd_cli);
		printf("thread created\n");
	}	
	
	close(sockfd);
	close(sockfd_cli);
	return 0;
}
