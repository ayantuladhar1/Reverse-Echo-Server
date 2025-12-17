//Name : Ayan Tuladhar

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<string>
#include<unistd.h>
using namespace std;



//The following function was compiled from the source refrenced below.
//https://gist.github.com/codehoose/020c6213f481aee76ea9b096acaddfaf.

int main()
{
    // The following function creats a socket connection for echo host.
    int receiving_segmnets;
    receiving_segmnets = socket(AF_INET, SOCK_STREAM, 0);
    if (receiving_segmnets == -1)
    {
        cerr << "Socket Connection Error\n";
        return -1;
    }

    // The following funtion binds the ip address and ports into socket connection.
    // The following function analyzes socket for recieivng segments from client server.
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54948);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    bind(receiving_segmnets, (sockaddr*)&hint, sizeof(hint));
    listen(receiving_segmnets, SOMAXCONN);

    // The following function anazlyzes connection from client server and waits till it's connected.
    // The following function creates a remote name for client server and displays the port where client server is connected.
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    int Socket_of_Client;
    Socket_of_Client = accept(receiving_segmnets, (sockaddr*)&client, &clientSize);
    char echo_host[NI_MAXHOST];
    char connection[NI_MAXSERV];
    memset(echo_host, 0, NI_MAXHOST); 
    memset(connection, 0, NI_MAXSERV);

    // The following if/else function sets the condition to display the port number after the connection is made. 
    if (getnameinfo((sockaddr*)&client, sizeof(client), echo_host, NI_MAXHOST, connection, NI_MAXSERV, 0) == 0)
    {
        cout << echo_host << " > my-reverse-echo-server:" << connection << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, echo_host, NI_MAXHOST);
        cout << echo_host << " > my-reverse-echo-server:" << ntohs(client.sin_port) << endl;
    }

    // The following function close the receiving segments after the receiving is completed.
    close(receiving_segmnets);


    // The folowing function receives the message from the client server and echo back.
    char buffer[4096];
    int how_many_bytes;
    while (true)
    {
        memset(buffer, 0, 4096);
	cout << "Incoming from Client:\n";
        how_many_bytes = recv(Socket_of_Client, buffer, 4096, 0);
        if (how_many_bytes == -1)
        {
            cerr << "Sorry! There was an error in connection\n";
            break;
        }

        if (how_many_bytes == 0)
        {
            cout << "The TCP network has been disconnected\n";
            break;
        }
        cout << string(buffer, 0, how_many_bytes) << endl;
        send(Socket_of_Client, buffer, how_many_bytes + 1, 0);
    }

    // The following function close the sockets after the process is completed.
    close(Socket_of_Client);
    return 0;
}