/**************************************************************************
*  @file	 : MyWindow.h
*  @version  : 
*  @author   : Alex
*  @date     : 
*  @brief    : 程序主窗口类
**************************************************************************/

#ifndef WINDOWS_H
#define WINDOWS_H

#include <windows.h>
#include <vector>
#include <tchar.h>

class CServerNet;
using namespace std;

/**************************************************************************
*  @file	 : MyWindow.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 消息结构体
**************************************************************************/
class GameManager;
class CFont;

struct Message
{
	Message(UINT m, void(*f)(HWND, WPARAM, LPARAM));
	UINT     msg;
	void(*fp)(HWND, WPARAM, LPARAM);
};

/**************************************************************************
*  @file	 : MyWindow.h
*  @version  :
*  @author   : Alex
*  @date     :
*  @brief    : 消息基类（未使用）
**************************************************************************/
class MyMessage
{
public:
	/********************************************************
		*  @brief    :	添加消息
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void addMessage();
	/********************************************************
		*  @brief    :	窗口毁灭消息
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static void OnDestroy(HWND hwnd, WPARAM wparam, LPARAM lparam);
protected:
	static vector<Message> m_Message;
};

class MyWindow :public MyMessage
{
private:
	HWND m_hwnd;
	HINSTANCE m_hInstance;
	WNDCLASSEX m_wndClass;
	int Height;
	int width;
	CFont* frame;
	char szBuf[10];
private:
	/********************************************************
		*  @brief    :	注册窗口
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool RegisterWindow();
public:
	MyWindow();
	~MyWindow(){};
	/********************************************************
		*  @brief    :	创建窗口
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool Create();
	/********************************************************
		*  @brief    :	得到窗口
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	HWND getWnd();
	/********************************************************
		*  @brief    :	窗口消息循环
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	/********************************************************
		*  @brief    :	程序主循环
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int MessageProc();
	/********************************************************
		*  @brief    :	设置窗口的尺寸
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setWindowSize(int h, int w);
	int getWindowHeight();
	int getWindowwidth();
	/********************************************************
		*  @brief    :	循环函数
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update(DWORD dwElapsedTime);
};

#endif