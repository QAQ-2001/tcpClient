#include <winsock.h> //socketͷ�ļ�
#pragma comment (lib,"ws2_32.lib") //����socket
#include <cstring>
#include <iostream>
#include <json/json.h>
#include <iostream>

#define BUFSIZE 1024

#include <windows.h>

class Client
{
public:
    Client();
    ~Client();

    void sendData(std::string str);
    std::string recvData();
private:
    char recvBuf[BUFSIZE];
    SOCKET clientSocket;
};

