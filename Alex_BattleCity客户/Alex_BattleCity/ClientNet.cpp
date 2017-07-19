/*
CLientNet.cpp
*/
#include "ClientNet.h"


int CClientNet::Init()
{
	int rlt = 0;

	//���ڼ�¼������Ϣ�������
	int iErrorMsg;

	//��ʼ��WinSock
	WSAData wsaData;
	iErrorMsg = WSAStartup(MAKEWORD(1, 1), &wsaData);

	if (iErrorMsg != NO_ERROR)
	{
		//��ʼ��WinSockʧ��
		rlt = 1;
		return rlt;
	}

	//���������Socket
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET)

	{
		//����Socket�쳣
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

		//������Ϣ��ָ��sock������Ϣ
		iErrMsg = send(m_sock, msg, len, 0);
		if (iErrMsg < 0)
			//����ʧ��
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
