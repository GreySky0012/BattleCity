/**************************************************************************
*  @file	 : Ref.h
*  @version  : 
*  @author   : Alex
*  @date     : 
*  @brief    : 个体类
**************************************************************************/

#ifndef REF_H
#define REF_H

#include "ReleaseManager.h"
#include "common.h"

/**************************************************************************
*  @file	 : Ref.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 速度结构体
**************************************************************************/
struct Speed
{
	Speed(){ x = 0; y = 0; }
	Speed(double X, double Y){ x = X; y = Y; }
	double x;
	double y;
};

class Ref
{
protected:
	int tain;
public:
	/********************************************************
		*  @brief    :	初始化
		*  @input	 :
		*  @output	 :  
		*  @return   :  bool
		*  @author   :	Alex
		********************************************************/
	virtual bool init();
	/********************************************************
		*  @brief    :	加入自动管理内存
		*  @input	 :
		*  @output	 :
		*  @return   :  Ref*
		*  @author   :	Alex
		********************************************************/
	Ref* autorelease();
	/********************************************************
		*  @brief    :	释放内存
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void release();
	/********************************************************
		*  @brief    :	设置create函数
		*  @input	 :
		*  @output	 :
		*  @return   :  Ref*
		*  @author   :	Alex
		********************************************************/
	CREATE_FUNC(Ref);
	/********************************************************
		*  @brief    :	得到当前的Tain值
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getTain();
	/********************************************************
		*  @brief    :	保留该个体
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void retain(){ tain++; }
	void detain(){ tain = 0; }
	virtual ~Ref();
};

#endif