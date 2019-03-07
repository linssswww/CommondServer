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
		std::queue<std::string> que; //���������ݵ�һ���Ĳ��
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
		select ����ʹ��˼·
		1��select �ж��Ƿ��д��� fd_num =0 û���źš� �����0 ���ź�
		2��֪�����źţ�����֪������һ���źţ�����ͨ����ѯ�İ취�ж��������ӻ������ݹ���
		3��select �����κεĲ�����ʱ�� ����Ӧ���Ǳ���յģ� ���������ӻ������ݹ����� �����в��ж���
		
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
