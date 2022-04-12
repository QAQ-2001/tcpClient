#include "socket.h"

void tcpWSA()
{
	WSADATA lpWSAD;
	WORD wVer = MAKEWORD(2, 2);
	int ret;
	ret = WSAStartup(wVer, &lpWSAD);
	if (ret != 0)
	{
		std::cout << "��ʼ������" << std::endl;
		return;					//��ʼ������
	}
	if (LOBYTE(lpWSAD.wVersion) != 2 || HIBYTE(lpWSAD.wVersion) != 2)
	{
		std::cout << WSACleanup() << std::endl;
		return;
	}
}

SOCKET tcpInit()
{
	SOCKET serverSocket;
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		std::cout << "socket create fail" << std::endl;
		return -1;
	}

	int ret;
	struct sockaddr_in FAR serverAddr;

	memset(&serverAddr, 0, sizeof(struct sockaddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERV_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP);

	ret = bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));
	if (ret == SOCKET_ERROR)
	{
		std::cout << "bind fail" << std::endl;
		return -1;
	}

	ret = listen(serverSocket, 10);
	if (ret == SOCKET_ERROR)
	{
		std::cout << "listen fail" << std::endl;
		return -1;
	}

	return serverSocket;
}

SOCKET tcpAccept(SOCKET serverSocket)
{
	SOCKET clientSocket;
	struct sockaddr_in FAR addr;
	int FAR addrlen = sizeof(struct sockaddr);

	clientSocket = accept(serverSocket, (struct sockaddr*)&addr, &addrlen);
	if (clientSocket == INVALID_SOCKET)
	{
		std::cout << "accept fail" << std::endl;
		return -1;
	}
	std::cout << inet_ntoa(addr.sin_addr) << " " << ntohs(addr.sin_port) << " success connect..." << std::endl;

	return clientSocket;
}

SOCKET tcpConnect()
{
	int ret;
	SOCKET serverSocket;
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		std::cout << "socket create fail" << std::endl;
		return -1;
	}

	struct sockaddr_in FAR serverAddr;

	memset(&serverAddr, 0, sizeof(struct sockaddr_in));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERV_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP);

	ret = connect(serverSocket, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));   //��serverSocket������ָ���ķ����������ַ serverAddr
	if (ret == SOCKET_ERROR)
	{
		std::cout << "connect fail" << std::endl;
		return -1;
	}

	return serverSocket;
}