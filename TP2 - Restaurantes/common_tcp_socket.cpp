//
//  common_socket.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "common_tcp_socket.h"

using namespace std;

int TCPSocket::socketGetFileDescriptor() {
    return this->socketFd;
}

TCPSocket::~TCPSocket() {
    close(this->socketFd);
    this->socketFd = 0;
}

TCPSocket::TCPSocket() {
    if ((socketFd = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR) {
        perror("Socket creation error");
        printf("Socket creation error:%sn\n", strerror(errno));
        exit(1);
    }
}

void TCPSocket::socketSend(const string &data, size_t dataLength) {
    
}

const string TCPSocket::socketReceive() {
    const string newString = "nada";
    return newString;
}

struct sockaddr_in TCPSocket::socketGetAddr(int port) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(port);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}

void TCPSocket::socketShutDown(TCPSocketShutDownHow how) {
    if (shutdown(this->socketFd, how) == SOCKET_ERROR) {
        perror("Socket shutdown error");
        printf("Socket shutdown error:%sn\n", strerror(errno));
        exit(1);
    }
}
