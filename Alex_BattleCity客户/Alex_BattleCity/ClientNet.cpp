/*
CLientNet.cpp
*/
#include "ClientNet.h"


int CClientNet::Init()
{
	int rlt = 0;

	//用于记录错误信息，并输出
	int iErrorMsg;

	//初始化WinSock
	WSAData wsaData;
	iErrorMsg = WSAStartup(MAKEWORD(1, 1), &wsaData);

	if (iErrorMsg != NO_ERROR)
	{
		//初始化WinSock失败
		rlt = 1;
		return rlt;
	}

	//创建服务端Socket
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET)

	{
		//创建Socket异常
		rlt = 2;
		return rlt;
	}
}

bool CClientNet::Connect(const char* address, int port)
{
	sockaddr_in addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = port;
	addrSrv.sin_addr.s_addr = inet_addr(address);

	m_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(m_sock, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET)
	{
		return false;
	}
	else
	{
		return true;
	}
}

char CClientNet::Listening()
{

	int rlt;

	memset(buf, 0, sizeof(buf));
	rlt = recv(m_sock, buf, 1024, 0);
	if (rlt == SOCKET_ERROR)
	{
	}
	else
	{
		return buf[0];
	}
}

int CClientNet::SendMsg(const char* msg, int len)
{

	{
		int rlt = 0;

		int iErrMsg = 0;

		//发送消息，指定sock发送消息
		iErrMsg = send(m_sock, msg, len, 0);
		if (iErrMsg < 0)
			//发送失败
		{
			rlt = 1;
			return rlt;
		}

		return rlt;
	}

}

void CClientNet::Close()
{
	closesocket(m_sock);
}
