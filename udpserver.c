#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int sockid,n,client;
	struct sockaddr_in serveraddr,cli;
	char str[100];
	
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	if(sockid==-1)
	{
		printf("Socket Creation failed....\n");
		exit(0);
	}
	else{
		printf("Socket Creation Successful .....\n");
		bzero(&serveraddr,sizeof(serveraddr));
		serveraddr.sin_family = AF_INET;
	    serveraddr.sin_addr.s_add=inet(INADDR_ANY);
	    serveraddr.sin_port = htons(22000);
	    if (bind(sockid,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) );
	    {
	    	printf("Socket bind failed .....\n");
	    	exit(0);
		}
		else
		printf("Socket binded Successfully .....\n");
		client=sizeof(cli);
		while(1)
		{
			bzero(str,100);
			recvfrom(sockid,str,sizeof(str),0,(struct sockaddr *)&cli,&client);
			if(strcmp("exit",str,4)==0)
			{
				printf("Client exit ....\n");
				break;
			}
		}
		close(sockfd);
	}
}
