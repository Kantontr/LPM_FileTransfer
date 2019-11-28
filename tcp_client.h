#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H
#include "utility.h"
#include "Socket.h"

std::string ip = Socket::ipFromHostName("google.com"); //Get ip addres from hostname
stdstring port = "80"; //let's talk on http port
Socket *sock = new Socket(AF_INET,SOCK_STREAM,0);  //AF_INET (Internet mode) SOCK_STREAM (TCP mode) 0 (Protocol any)
sock->connect(ip, port); //Connect to google.com:80
sock->socket_write("GET / HTTP/1.1\r\n\r\n");//Send GET request to google.com:80
int seconds = 10;//Wait 10 second for response
vector<Socket> reads(1);
reads[0] = *sock;
if(sock->select(&reads, NULL, NULL, seconds) < 1){//Socket::select waits until sock reveives some input (for example the answer from google.com)
    //Something went wrong
}else{
    string buffer;
    sock->socket_read(buffer, 1024);//Read 1024 bytes of the answer
    cout << buffer << endl;
}

#endif // TCP_CLIENT_H
