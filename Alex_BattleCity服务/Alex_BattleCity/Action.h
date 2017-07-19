/**************************************************************************
*  @file	 : Action.h
*  @version  : ver  1.0
*  @author   : 
*  @date     : 
*  @brief    : 动作类及其派生类
**************************************************************************/
#ifndef ACTION_H
#define ACTION_H

#include "common.h"
#include "Ref.h"

class Sprite;

struct Speed;

class Action:public Ref
{
protected:
	Sprite* Target;//该动作所属的对象
	bool On;//该动作是否正在执行
public:
	/********************************************************
		*  @brief    :	更新动作所属对象的属性
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	virtual void Update() = 0;
	/********************************************************
		*  @brief    :	设置动作的对象
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setTarget(Sprite*);
	/********************************************************
		*  @brief    :	设置动作为运行状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void actionStart(){ On = true; }
	/********************************************************
		*  @brief    :	取消动作运行并删除动作
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void actionStop(){ On = false; tain = -1; }
	/********************************************************
		*  @brief    :	得到动作的当前状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getOn(){ return On; }
	/********************************************************
		*  @brief    :	得到动作的对象
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	Sprite* getTarget(){ return Target; }
	~Action();
};

/**************************************************************************
*  @file	 : Action.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 动作数组类，储存所有动作
**************************************************************************/
class ActionArray
{
	ActionArray(){};
	int actionNumber = 0;
	vector<Action*>  m_Array;
public:
	/********************************************************
		*  @brief    :	移除某个动作
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeAction(Action* ac);
	/********************************************************
		*  @brief    :	得到动作数组的单例
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static ActionArray* getInstance();
	/********************************************************
		*  @brief    :	向动作数组中加入动作对象
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void pushAction(Action* action);
	/********************************************************
		*  @brief    :	遍历动作数组中的所有动作并更新运行动作对象的属性
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void visitAll();
	/********************************************************
		*  @brief    :	得到动作数组
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Action*> getAction(){ return m_Array; }
	/********************************************************
		*  @brief    :	得到动作个数
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getNumber(){ return actionNumber; }
};
/**************************************************************************
*  @file	 : Action.h
*  @version  : ver  1.0
*  @author   : 
*  @date     : 
*  @brief    : 按速度移动类（未使用）
**************************************************************************/
class MoveBySpeed:public Action
{
	Speed speed;
public:
	MoveBySpeed(){};
	void Update();
	void setSpeed(Speed speed);
	static MoveBySpeed* create(Speed speed = Speed(0,0));
};
/**************************************************************************
*  @file	 : Action.h
*  @version  : ver  1.0
*  @author   : 
*  @date     : 
*  @brief    : 闪烁类
**************************************************************************/
class Blink:public Action
{
	int m_counter;
	int m_duration;
	int m_time;
public:
	/********************************************************
		*  @brief    :	更新闪烁对象的属性
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	设置闪烁一次的时间
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setTime(int t);
	/********************************************************
		*  @brief    :	设置闪烁经历的时间
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setDuration(int d);
	/********************************************************
		*  @brief    :	创建闪烁动作
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static Blink* create(int  duration = 1,int time = 1);
};

/**************************************************************************
*  @file	 : Action.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 移动停止类
**************************************************************************/
class Stop :public Action
{
	int m_Timer;
	int m_Time;
public:
	/********************************************************
		*  @brief    :	更新动作对象的状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	设置停止移动的时间
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setTime(int time);
	/********************************************************
		*  @brief    :	创建停止动作
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static Stop* create(int t = 1);
};

#endif