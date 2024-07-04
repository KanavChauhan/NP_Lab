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
struct sockaddr_in sockserver;
sockserver.sin_family=AF_INET;
sockserver.sin_port=htons(8080);
sockserver.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sockid,(struct sockaddr*)&sockserver,sizeof(sockserver));
listen(sockid,10);
int acc=accept(sockid,(struct sockaddr*)NULL,NULL);
while(1)
{
recv(acc,str,100,0);
printf("Recivied text:%s",str);
bzero(str,100);
printf("Enter a string:-");
fgets(str,100,stdin);
send(acc,str,strlen(str),0);
if(strcmp(str,"exit")==0)
{
printf("exit\n");
break;
}
}
close(acc);
close(sockid);
}
