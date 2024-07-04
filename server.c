#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
int sockid,client;
sockid=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in serveradd,clientadd;
serveradd.sin_family=AF_INET;
serveradd.sin_port=htons(5667);
serveradd.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sockid,(struct sockaddr*)&serveradd,sizeof(serveradd));
char str[100];
bzero(str,100);
char rev[100];
bzero(rev,100);
client=sizeof(clientadd);
recvfrom(sockid,str,100,0,(struct sockaddr*)&clientadd,&client);
printf("STRING IS:%s",str);
for(int i=0;i<strlen(str);i++)
{
rev[i]=str[strlen(str)-1-i];
}
printf("STRING IS:%s\n",rev);
sendto(sockid,rev,100,0,(struct sockaddr*)&clientadd,sizeof(clientadd));
close(sockid);
}

