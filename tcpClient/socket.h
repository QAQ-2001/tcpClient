#ifndef SOCKET_H
#define SOCKET_H

#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
#include <Windows.h>

#define SERV_PORT 9000
#define IP "192.168.1.168"

void tcpWSA();
SOCKET tcpInit();
SOCKET tcpAccept(SOCKET serverSocket);
SOCKET tcpConnect();

#endif