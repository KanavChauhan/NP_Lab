#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
printf("---------------------------------------");
long valread;
char *server_response="http/1.1 200 ok\nContent-Type:text/html\nContent-Length: 1000\n\n <!DOCTYPE HTML> <HTML><body><h1>HELLOWORLD</h1></body></html>";
int sockid=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in sockadd;
sockadd.sin_family=AF_INET;
sockadd.sin_port=htons(8080);
sockadd.sin_addr.s_addr=INADDR_ANY;
bind(sockid,(struct sockaddr *)&sockadd,sizeof(sockadd));
listen(sockid,10);
printf("*********************************");
while(1)
{
printf("*******************waiting for server**************");
int acc=accept(sockid,(struct sockaddr *)&sockadd,(socklen_t*)&sockadd);
char str[30000]={0};
valread=read(sockid,str,30000);
printf("%s\n",str);
write(sockid,server_response,strlen(server_response));
printf("*******************response send**************");
close(sockid);
}
return 0;
}
