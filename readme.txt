*******************************************************
*  Name      :Ayan Tuladhar          
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This program helps to build a simple reverse echo server and a client using a TCP socket where the server and client runs at different machines. The reverse echo server receives a message from a client over a TCP socket and replies the same message back to the source in reverse order.

*******************************************************
*  Source files
*******************************************************

Name:  Server.cpp
   Main program. This is the main program for Echo Server which creates a socket connection for echo host and binds the ip address and ports into socket connection where the function also analyzes socket for receiving segments from client server. This program contains in-built linux libraries to analyze connection from client server and display the port when client server is connected where the server recieves messages from the client server and echo back. 
   
Name: Client.cpp
   Main program: This is the main program for Client server which creates a socket connection for echo server and sends and recieve messages and response from the Echo server by taking user input and displays to the screen. This program contains in-built linux libraries to analyze connection from echo server and string function to display the recieved response in a reverse order.
   
*******************************************************
*  Makefile
*******************************************************
There are two separate makefiles for both Echo Server and Client server.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Windows Visual Studios C++(Version 16.8.4) g++.  It was compiled, run, and tested on csegrid.ucdenver.pvt. (Screen shots are provided).

