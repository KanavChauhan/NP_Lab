#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int sockid,new_com_socket;
	char str[100];
	struct sockaddr_ in serveraddr;
	sockid = socket(AF_INET,SOCK_STREAM,0);
	
	serveraddr.sin_family = AF_INRT;
	serveraddr.sin_port = htons(22000);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	bind(sockid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	listen(sockid,10);
	
	while(1)
	{
		new_com_socket = accept(sockid,(struct sockaddr*)NULL,NULL);
		recv(new_com_socket,str,100,0);
		printf("Received from client: %s\n",str);
		send(new_com_socket,str,strlen(str),0);
		close(new_com_socket);	
	}
	close(sockid);	
}