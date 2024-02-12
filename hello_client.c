#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080   
#define MAX_MSG_LEN 20
#define LOCALHOST "127.0.0.1"

int main(int argc, char * argv[]) {

    char msg[MAX_MSG_LEN] = {0};

    int socket_connection = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    memset(&server, 0 , sizeof(server));
    
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(LOCALHOST);
    
    int ret = connect(socket_connection, (struct  sockaddr *)&server, sizeof(server) );

    ret = read(socket_connection, msg, 20);
    printf("Recibidos %d bits\n%s\n", ret, msg);

    ret = close(socket_connection);
    
    return 0;
}