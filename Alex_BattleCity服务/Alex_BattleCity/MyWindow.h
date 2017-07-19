/**************************************************************************
*  @file	 : MyWindow.h
*  @version  : 
*  @author   : Alex
*  @date     : 
*  @brief    : ������������
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
*  @brief    : ��Ϣ�ṹ��
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
*  @brief    : ��Ϣ���ࣨδʹ�ã�
**************************************************************************/
class MyMessage
{
public:
	/********************************************************
		*  @brief    :	�����Ϣ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void addMessage();
	/********************************************************
		*  @brief    :	���ڻ�����Ϣ
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
		*  @brief    :	ע�ᴰ��
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
		*  @brief    :	��������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool Create();
	/********************************************************
		*  @brief    :	�õ�����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	HWND getWnd();
	/********************************************************
		*  @brief    :	������Ϣѭ��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	/********************************************************
		*  @brief    :	������ѭ��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int MessageProc();
	/********************************************************
		*  @brief    :	���ô��ڵĳߴ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setWindowSize(int h, int w);
	int getWindowHeight();
	int getWindowwidth();
	/********************************************************
		*  @brief    :	ѭ������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update(DWORD dwElapsedTime);
};

#endif