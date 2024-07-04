#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char sendline[100],recvline[100];
	int sockid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serveraddr;
	
	serveraddr.sin_family = AF_INRT;
	serveraddr.sin_port = htons(22000);	
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	connect(sockid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	fgets(sendline,100,stdin);
	send(sockid,sendline,strlen(sendline),0);
	recv(sockid,recvline,100,0);
	printf("Server said: %s",recvline);
	close(sockid);
}