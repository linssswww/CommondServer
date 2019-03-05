#include "socket.h"

mySocket::BaseWinSocket::BaseWinSocket()
{
}

mySocket::BaseWinSocket::~BaseWinSocket()
{
}

void mySocket::BaseWinSocket::BuildWinSocket(std::string ip, int port)
{
}

void mySocket::BaseWinSocket::CloseWinSocket()
{
}

void mySocket::BaseWinSocket::Listen()
{
	if (listen(ServSock, 5) == SOCKET_ERROR)
		throw std::logic_error("Listen error");
}

void mySocket::BaseWinSocket::HandleSocketSet()
{
	FD_SET(ServSock, &read);
}

void mySocket::BaseWinSocket::Select()
{
	if ((fd_num = select(0, &cp_read, 0, 0, &time_out)) == SOCKET_ERROR)
		throw std::logic_error("SOCKET_ERROR");
}

void mySocket::BaseWinSocket::Accept()
{
}

void mySocket::BaseWinSocket::Recv()
{
}

void mySocket::BaseWinSocket::Send()
{
}

void mySocket::BaseWinSocket::InitSocket()
{
	if(WSAStartup(MAKEWORD(2, 2), &wsadata)!=0)
		throw std::logic_error("Startup fail");

	ServSock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(8899);

	FD_ZERO(&read);
}

void mySocket::BaseWinSocket::Bind()
{
	if (bind(ServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		throw std::logic_error("bind error");
}
