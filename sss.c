#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

struct sockaddr_in addr;
struct sockaddr_in6 addr6;

int main(int argc, char *argv[]){
    int sock = 0, cnx = 0;
    int porta = atoi(argv[2]);
    int ipv = atoi(argv[3]);
    if(ipv == 4){
        addr.sin_port = htons(porta);
        addr.sin_family = AF_INET;
        inet_pton(AF_INET, argv[1], &addr.sin_addr);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if(sock < 0){
            perror("Socket error");
            return 1;
        }

        cnx = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if(cnx == 0){
            printf("*Porta acessivel...\n");
        } else{
            printf("*Porta fechada...\n");

        }

    }

    if(ipv == 6){
        addr6.sin6_port = htons(porta);
        addr6.sin6_family = AF_INET6;
        inet_pton(AF_INET6, argv[1], &addr6.sin6_addr);
        sock = socket(AF_INET6, SOCK_STREAM, 0);
        if(sock < 0){
            perror("Socket error");
            return 1;
        }

        cnx = connect(sock, (struct sockaddr *)&addr6, sizeof(addr6));
        if(cnx == 0){
            printf("*Porta acessivel...\n");
        } else{
            printf("*Porta fechada...\n");

        }

    }

    return 0;
}
