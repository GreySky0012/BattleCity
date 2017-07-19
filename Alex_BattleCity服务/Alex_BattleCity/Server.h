#pragma once

/*
ServerNet.h
用于表示服务端的网络操作

*/

#include <stdio.h>
#include <winsock.h>

#pragma comment (lib,"ws2_32.lib")

class CServerNet
{
public:
	/********************************************************
	*  @brief    :初始化服务器
	*  @input	 :
	*  @output	 :
	*  @return   :  0 表示成功
	*  @author   : qiyue
	********************************************************/
	int Init(const char* address,int port);
	/********************************************************
	*  @brief    :发送数据
	*  @input	 :监听套接字  数据  数据长度
	*  @output	 :
	*  @return   :0表示发送成功
	*  @author   : qiyue
	********************************************************/
	int SendMsg(const char* msg,int len);
	/********************************************************
	*  @brief    :接受连接
	*  @input	 :
	*  @output	 :
	*  @return   :true or false
	*  @author   : qiyue
	********************************************************/
	bool Accept();
	/********************************************************
	*  @brief    :监听接受数据函数
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	char Listening();
	/********************************************************
	*  @brief    :关闭套接字
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   : qiyue
	********************************************************/
	void Close();
	/********************************************************
		*  @brief    :	得到信息
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