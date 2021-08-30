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

// try to connect with server
int socketConnect(int hSocket)
{
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming interface */
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htons(ServerPort); 

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

// Send data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char *Rqst, short lenRqst)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

// Receive the data from the server
int socketReceive(int hSocket, char *Rsp, short RcvSize)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time out\n");
        return -1;
    }

    shortRetval = recv(hSocket, Rsp, RcvSize, 0);
    printf("Response %s\n", Rsp);

    return shortRetval;
}

int main(int argc, char *argv[])
{
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    /* Create Socket */
    hSocket = socketCreate();
    
    if(hSocket == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if(bindCreatedSocket(hSocket) < 0)
    {
        // print the error message
        perror("Connect failed.\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    // Send data to the server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    // Received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server Response : %s\n\n", server_reply);

    close(hSocket);
    
    return 0;
}