/**************************************************************************
*  @file	 : ActiveSprite.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 动态精灵类
**************************************************************************/
#ifndef ACTIVESPRITE_H
#define ACTIVESPRITE_H

#include "common.h"
#include "Action.h"
#include "Sprite.h"

class ActiveSprite :public Sprite
{
protected:
	ActiveSprite(){};
	Speed m_speed;
	D3DXVECTOR3 Direction;
	bool camp;
	int Level;
	int Player;
public:
	~ActiveSprite();
	/********************************************************
	*  @brief    :	设置精灵的控制方
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void setPlayer(int p){ Player = p; }
	/********************************************************
	*  @brief    :	得到精灵的控制方
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	int getPlayer(){ return Player; }
	/********************************************************
	*  @brief    :	把动态精灵从父节点移除
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void removeFromParent();
	/********************************************************
		*  @brief    :	移动（使用MoveBySpeed）（未使用）
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void move();
	/********************************************************
		*  @brief    :	初始化一个动态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	/********************************************************
		*  @brief    :	设置等级
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLevel(int level){ Level = level; }
	/********************************************************
		*  @brief    :	得到等级
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getLevel(){ return Level; }
	/********************************************************
		*  @brief    :	设置阵营
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setCamp(bool m_camp);
	/********************************************************
		*  @brief    :	得到阵营
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getCamp();
	/********************************************************
		*  @brief    :	设置速度
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setSpeed(Speed sp);
	/********************************************************
		*  @brief    :	得到速度
		*  @input	 :
		*  @output	 :
		*  @return   :  Speed
		*  @author   :	Alex
		********************************************************/
	Speed getSpeed();
	/********************************************************
		*  @brief    :	设置方向
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setDirection(D3DXVECTOR3 Direction);
	/********************************************************
		*  @brief    :	得到方向
		*  @input	 :
		*  @output	 :
		*  @return   :  D3DXVECTOR3
		*  @author   :	Alex
		********************************************************/
	D3DXVECTOR3 getDirection();
	/********************************************************
		*  @brief    :	创建动态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static ActiveSprite* create();
	/********************************************************
		*  @brief    :	更新动态精灵属性
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	virtual void Update(){};
	/********************************************************
	*  @brief    :	动态精灵转向时复位
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void returnPosition();
};

#endif