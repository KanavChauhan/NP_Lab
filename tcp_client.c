#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
int main()
{
int sockid;
char str[100];
bzero(str,100);
sockid=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in sockclient;
sockclient.sin_family=AF_INET;
sockclient.sin_port=htons(8080);
sockclient.sin_addr.s_addr=htonl(INADDR_ANY);
connect(sockid,(struct sockaddr*)&sockclient,sizeof(sockclient));
while(1)
{
printf("Enter a string:-");
fgets(str,100,stdin);
send(sockid,str,strlen(str),0);
bzero(str,100);
recv(sockid,str,100,0);
printf("Replied:-%s",str);
if(strcmp(str,"exit")==0)
{
printf("exit\n");
break;
}
}
close(sockid);
}
