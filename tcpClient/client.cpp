#include "client.h"
#include "socket.h"

Client::Client()
{
	memset(recvBuf, 0, sizeof(char) * BUFSIZE);

	tcpWSA();

	clientSocket = tcpConnect();
}

Client::~Client()
{
	//�ر��׽���
	closesocket(clientSocket);

	WSACleanup();
}

void Client::sendData(std::string str) 
{
	send(clientSocket, str.c_str(), (int)str.size(), 0);
}

std::string Client::recvData() 
{
	recv(clientSocket, recvBuf, BUFSIZE, 0);
	//std::string recv = GbkToUtf8(recvBuf);
	std::cout << recvBuf << std::endl;
	return recvBuf;
}
