#pragma once
#include <string>
namespace myHttp
{
	class Http
	{
	public:
		Http();
		virtual ~Http();
		void BuildHttpServer();
		void GetRequest();
		void PostRequest();
	};
	class ParseHttpProTocol
	{
	public:
		ParseHttpProTocol();
		virtual ~ParseHttpProTocol();
		
	private:
		int content_length;
		std::string content;
	};
	class WinSocket
	{
	public:
		WinSocket();
		virtual ~WinSocket();
		void BuildWinSocket();
		void CloseWinSocket();
		void Recv();

		void Send();
	};
	class LinuxSocket
	{
		LinuxSocket();
		virtual ~LinuxSocket();
	};
	class TcpServer:public WinSocket
	{
	public:
		TcpServer();
		virtual ~TcpServer();
		void listen();
		void recv();
		void send();
	};
}
