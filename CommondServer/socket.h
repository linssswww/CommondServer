#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <winsock2.h>
#include <queue>
namespace mySocket
{
	class MessageAllocator
	{
	public:
		MessageAllocator();
		~MessageAllocator();
		void AddMessageQueue(std::string mess);
		void CalMessagePriority(std::string mess);
		std::string ConsumeMessageFromQueue();
	private:
		std::queue<std::string> que; //当在线数据到一定的层度
	};
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
		void ReSetReadFileDescribes();
		void ThreadRun();
		/*
		select 整体使用思路
		1、select 判断是否有触发 fd_num =0 没有信号。 如果》0 有信号
		2、知道有信号，但不知道是哪一个信号，所以通过轮询的办法判断是新连接还是数据过来
		3、select 当无任何的操作的时候， 集合应该是被清空的， 当有新连接或者数据过来， 集合中才有东西
		
		*/
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
