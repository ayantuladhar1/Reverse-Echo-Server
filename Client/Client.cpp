//Name: Ayan Tuladhar

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<string>
using namespace std;



// The following program was compiled form the source refrenced below:
// https://gist.github.com/codehoose/d7dea7010d041d52fb0f59cbe3826036.
// https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods.

// The following function converts the string to reverse order after Echo server echo back client's message.
void String_reversed(string& reverse_input)
{
	int a = reverse_input.length();
	for (int b = 0; b < a / 2; b++)
		swap(reverse_input[b], reverse_input[a - b - 1]);
}


int main()
{
    // The following function creates a socket for Echo Server.
    int tcp_socket;
    int tcp_p;
    int connection_result;
    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1)
    {
        return 1;
    }

    // The following uses hint function to create a structure for the Echo server when connecting.
    
    
    string IP_Address = "127.0.0.1";
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54948);
    inet_pton(AF_INET, IP_Address.c_str(), &hint.sin_addr);

    // The following function connects the Echo server on the socket.
    connection_result = connect(tcp_socket, (sockaddr*)&hint, sizeof(hint));
    if (connection_result == -1)
    {
        return 1;
    }

    // The following while loop sets the condition to send and recieve response from the Echo server.
    // The following function takes user input and displays the message to the screen.
    
    char buffer[4096];
    string get_input;
    do 
    {
        int sending_result;
        int how_many_bytes;
        // Asks for user to input message.
        cout << "Please enter your message for the Echo Server >";
        getline(cin, get_input);
        sending_result = send(tcp_socket, get_input.c_str(), get_input.size() + 1, 0);
        if (sending_result == -1)
        {
            cout << "Error Connecting with Echo\n";
            continue;
        }
        memset(buffer, 0, 4096);
        how_many_bytes = recv(tcp_socket, buffer, 4096, 0);
        if (how_many_bytes == -1)
        {
            cout << "Echo doesn't want to respond\n";
        }
        else 
        {
            string reverse_input = get_input;
	    String_reversed(reverse_input);
	        // The follosing if/esle sets a condition to terminate the TCP connection when user input = 'fin'.
            if (get_input == "fin")
            {
                cout << "my-reverse-Echo-server: " << reverse_input << "\n";
                break;
            }
            else
            {
                cout << "The following message form the Echo Server in reverse order....." << "\n";
                cout << "" << "\n";
                
                cout << "my-reverse-Echo-server: " << reverse_input << "\n";
                cout << "" << "\n";
            }
        }
    } while (true);

    // The following function close the socket after the process is completed.
    close(tcp_socket);
    return 0;
}