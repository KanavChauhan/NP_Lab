#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<netdb.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{
int sock=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in sockadder;
sockadder.sin_family=AF_INET;
sockadder.sin_port=htons(5100);
sockadder.sin_addr.s_addr=htonl(INADDR_ANY);
//bind(sock,(struct sockaddr*)&sockadder,sizeof(sockadder));
connect(sock,(struct sockaddr*)&sockadder,sizeof(sockadder));
char str[100];
bzero(str,100);
printf("Enter a string");
fgets(str,100,stdin);
send(sock,str,strlen(str),0);
bzero(str,100);
recv(sock,str,100,0);
printf("the recived:--%s",str);
close(sock);
}

