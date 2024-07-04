#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int sockid;
    char str[100];
    struct sockaddr_in serveraddr;

    sockid = socket(AF_INET, SOCK_DGRAM, 0);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(22000);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    while (1) {
        printf("Enter string : ");
        fgets(str, sizeof(str), stdin);
        sendto(sockid, str, strlen(str), 0, (struct sockaddr*) &serveraddr, sizeof(serveraddr));

        bzero(str, sizeof(str));
        recvfrom(sockid, str, sizeof(str), 0, NULL, NULL);
        printf("Echo: %s\n", str);
    }

    close(sockid);
    return 0;
}
