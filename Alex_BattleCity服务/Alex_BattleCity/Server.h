#pragma once

/*
ServerNet.h
���ڱ�ʾ����˵��������

*/

#include <stdio.h>
#include <winsock.h>

#pragma comment (lib,"ws2_32.lib")

class CServerNet
{
public:
	/********************************************************
	*  @brief    :��ʼ��������
	*  @input	 :
	*  @output	 :
	*  @return   :  0 ��ʾ�ɹ�
	*  @author   : qiyue
	********************************************************/
	int Init(const char* address,int port);
	/********************************************************
	*  @brief    :��������
	*  @input	 :�����׽���  ����  ���ݳ���
	*  @output	 :
	*  @return   :0��ʾ���ͳɹ�
	*  @author   : qiyue
	********************************************************/
	int SendMsg(const char* msg,int len);
	/********************************************************
	*  @brief    :��������
	*  @input	 :
	*  @output	 :
	*  @return   :true or false
	*  @author   : qiyue
	********************************************************/
	bool Accept();
	/********************************************************
	*  @brief    :�����������ݺ���
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	char Listening();
	/********************************************************
	*  @brief    :�ر��׽���
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	void Close();
	/********************************************************
		*  @brief    :	�õ���Ϣ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	qiyue
		********************************************************/
	char getMsg(){ return nowMessage; }
private:
	SOCKET m_sock;
	SOCKET c_socket;
	char nowMessage;
};