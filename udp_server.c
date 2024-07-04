#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
int sockid=socket(AF_INET,SOCK_DGRAM,0);
char str[100];
bzero(str,100);
struct sockaddr_in server,client;
server.sin_family=AF_INET;
server.sin_port=htons(8080);
server.sin_addr.s_addr=htonl(INADDR_ANY);
int lenci;
lenci=sizeof(client);
bind(sockid,(struct sockaddr *)&server,sizeof(server));
while(1)
{
recvfrom(sockid,str,100,0,(struct sockaddr*)&client,&lenci);
printf("MESSAGE RECIVIED:-%s",str);
bzero(str,100);
printf("Enter a string:-");
fgets(str,100,stdin);
sendto(sockid,str,100,0,(struct sockaddr*)&client,sizeof(client));
if(strncmp(str,"exit",4)==0)
{
printf("Exit");
break;
}
}
close(sockid);
}
