#pragma once

/*
ClinetNet.h��
���ڱ�ʾһ���ͻ����������
*/

#include <stdio.h>
#include<windows.h>

#pragma comment(lib, "Ws2_32.lib")

class CClientNet
{
public:

	/********************************************************
	*  @brief    :��ʼ�������socket
	*  @input	 :
	*  @output	 :
	*  @return   :  0 ��ʾ�ɹ�
	*  @author   : qiyue
	********************************************************/
	int Init();

	/********************************************************
	*  @brief    :
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	bool Connect(const char* address, int port);

	/********************************************************
	*  @brief    :
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	char Listening();

	/********************************************************
	*  @brief    :
	*  @input	 :
	*  @output	 :
	*  @return   :  0 ��ʾ�ɹ�
	*  @author   : qiyue
	********************************************************/
	int SendMsg(const char* msg,int len);
	
	/********************************************************
	*  @brief    :
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	void Close();

public:
	SOCKET m_sock;
	char buf[1024];
};