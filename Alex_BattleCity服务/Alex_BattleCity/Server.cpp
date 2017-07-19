/*
ServerNet.cpp
*/
#include "Server.h"

int CServerNet::Init( const char* address,int port )
{
	ZeroMemory(&nowMessage, sizeof(char));

	int rlt = 0;

	//用于记录错误信息，并输出
	int iErrorMsg;

	//初始化WinSock
	WSAData wsaData;
	iErrorMsg = WSAStartup(MAKEWORD(1,1),&wsaData);

	if (iErrorMsg != NO_ERROR)
	{
		//初始化WinSock失败

		rlt = 1;
		return rlt;
	}

	//创建服务端Socket
	m_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET)

	{
		//创建Socket异常
		rlt = 2;
		return rlt;
	}

	//声明信息
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = port;
	serverAddr.sin_addr.s_addr = inet_addr(address);

	//绑定
	iErrorMsg = bind(m_sock,(sockaddr*)&serverAddr,sizeof(serverAddr));
	if (iErrorMsg < 0)
	{
		//绑定失败
		rlt = 3;
		return rlt;
	}

	return rlt;
}

bool CServerNet::Accept()
{
	//公开连接
	listen(m_sock, 5);

	sockaddr_in tcpAddr;
	int len = sizeof(sockaddr);
	int rval;

	c_socket = accept(m_sock, (sockaddr*)&tcpAddr, &len);
	if (c_socket == INVALID_SOCKET)
	{
		return false;
	}
	else
	{
		return true;
	}
}

char CServerNet::Listening()
{
	char buf[1024];
	int rval;
			
	memset(buf,0,sizeof(buf));
	rval = recv(c_socket,buf,1024,0);			
	if (rval == SOCKET_ERROR)				
	//这应该是个异常，当客户端没有调用closeSocket就直接退出游戏的时候，将会进入这里	
	{
	}
	if (rval == 0)
	//recv返回0表示正常退出	
	{
	}
	if (rval != 0 && rval != SOCKET_ERROR)
		//显示接收到的数据
	{
		return buf[0];
	}
}


int CServerNet::SendMsg(const char* msg,int len)
{
	{
		int rlt = 0;

		int iErrMsg = 0;

		//发送消息，指定sock发送消息
		iErrMsg = send(c_socket,msg,len,0);
		if (iErrMsg < 0)
			//发送失败
		{
			rlt = 1;
			return rlt;
		}

		return rlt;
	}
}

void CServerNet::Close()
{
	closesocket(c_socket);
	closesocket(m_sock);
}
