/*
ServerNet.cpp
*/
#include "Server.h"

int CServerNet::Init( const char* address,int port )
{
	ZeroMemory(&nowMessage, sizeof(char));

	int rlt = 0;

	//���ڼ�¼������Ϣ�������
	int iErrorMsg;

	//��ʼ��WinSock
	WSAData wsaData;
	iErrorMsg = WSAStartup(MAKEWORD(1,1),&wsaData);

	if (iErrorMsg != NO_ERROR)
	{
		//��ʼ��WinSockʧ��

		rlt = 1;
		return rlt;
	}

	//���������Socket
	m_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET)

	{
		//����Socket�쳣
		rlt = 2;
		return rlt;
	}

	//������Ϣ
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = port;
	serverAddr.sin_addr.s_addr = inet_addr(address);

	//��
	iErrorMsg = bind(m_sock,(sockaddr*)&serverAddr,sizeof(serverAddr));
	if (iErrorMsg < 0)
	{
		//��ʧ��
		rlt = 3;
		return rlt;
	}

	return rlt;
}

bool CServerNet::Accept()
{
	//��������
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
	//��Ӧ���Ǹ��쳣�����ͻ���û�е���closeSocket��ֱ���˳���Ϸ��ʱ�򣬽����������	
	{
	}
	if (rval == 0)
	//recv����0��ʾ�����˳�	
	{
	}
	if (rval != 0 && rval != SOCKET_ERROR)
		//��ʾ���յ�������
	{
		return buf[0];
	}
}


int CServerNet::SendMsg(const char* msg,int len)
{
	{
		int rlt = 0;

		int iErrMsg = 0;

		//������Ϣ��ָ��sock������Ϣ
		iErrMsg = send(c_socket,msg,len,0);
		if (iErrMsg < 0)
			//����ʧ��
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
