#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
int sockid=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in sockadd,sock1;
sockadd.sin_family=AF_INET;
sockadd.sin_port=htons(5100);
sockadd.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sockid,(struct sockaddr *)&sockadd,sizeof(sockadd));
listen(sockid,10);
int acc=accept(sockid,NULL,NULL);
char str[100];
recv(acc,str,100,0);
printf("send string:%s",str);
send(acc,str,strlen(str),0);
close(acc);
close(sockid);
}
