#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
int main()
{
int sock=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in sockadd;
int server;
sockadd.sin_family=AF_INET;
sockadd.sin_port=htons(5667);
sockadd.sin_addr.s_addr=htonl(INADDR_ANY);
char str[100];
bzero(str,100);
printf("Enter a string");
fgets(str,100,stdin);
server=sizeof(sockadd);
sendto(sock,str,100,0,(struct sockaddr*)&sockadd,sizeof(sockadd));
bzero(str,100);
recvfrom(sock,str,100,0,(struct sockaddr*)&sockadd,&server);
printf("STRING IS:%s",str);
close(sock);
}
