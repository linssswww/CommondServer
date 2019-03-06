#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <winsock2.h>

namespace mySocket
{
	class BaseWinSocket
	{
	public:
		BaseWinSocket();
		virtual ~BaseWinSocket();
		void BuildWinSocket(std::string ip, int port);
		void CloseWinSocket();
		void Accept(int i);
		void Recv(int i);
		void Send();

	private:
		void InitSocket();
		void Bind();
		void Listen();
		void HandleSocketSet();
		void Select();
		

	private:
		WSADATA wsadata;
		SOCKET ServSock;
		SOCKADDR_IN servAddr;
		fd_set read, cp_read;
		TIMEVAL time_out;
		int fd_num;
	};
	class TcpServer:public BaseWinSocket
	{
	public:
		TcpServer();
		virtual ~TcpServer();
		void listen();
		void recv();
		void send();
	};
}
