#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Creating the socket...\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket)
{
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); /* Local port */

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main(int argc, char *argv[])
{
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "hello from Percy's server";

    /* Create Socket */
    socket_desc = socketCreate();
    if(socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if(bindCreatedSocket(socket_desc) < 0)
    {
        // print the error message
        perror("bind failed.\n");
        return 1;
    }

    printf("Bind done\n");

    // Listen
    listen(socket_desc, 3);

    // Accept incomming connections
    while(1)
    {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        // Accept conncetion from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);

        if(sock < 0)
        {
            perror("Accept failed.\n");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        // Receive a reply from the client
        if(recv(sock, client_message, 200, 0) < 0)
        {
            printf("recv failed");
            break;
        }

        printf("Client reply : %s\n", client_message);

        if(strcmp(pMessage, client_message) == 0)
        {
            strcpy(message, "Hi there!\n");
        } else {
            strcpy(message, "Invalid Message!\n");
        }

        // send some data 
        if(send(sock, message, strlen(message), 0) < 0)
        {
            printf("Send failed.\n");
            return 1;
        }

        close(sock);
        sleep(1);
    }
    return 0;
}