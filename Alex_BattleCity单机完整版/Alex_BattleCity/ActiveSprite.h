/**************************************************************************
*  @file	 : ActiveSprite.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ��̬������
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
	*  @brief    :	���þ���Ŀ��Ʒ�
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void setPlayer(int p){ Player = p; }
	/********************************************************
	*  @brief    :	�õ�����Ŀ��Ʒ�
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	int getPlayer(){ return Player; }
	/********************************************************
	*  @brief    :	�Ѷ�̬����Ӹ��ڵ��Ƴ�
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void removeFromParent();
	/********************************************************
		*  @brief    :	�ƶ���ʹ��MoveBySpeed����δʹ�ã�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void move();
	/********************************************************
		*  @brief    :	��ʼ��һ����̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	/********************************************************
		*  @brief    :	���õȼ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLevel(int level){ Level = level; }
	/********************************************************
		*  @brief    :	�õ��ȼ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getLevel(){ return Level; }
	/********************************************************
		*  @brief    :	������Ӫ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setCamp(bool m_camp);
	/********************************************************
		*  @brief    :	�õ���Ӫ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getCamp();
	/********************************************************
		*  @brief    :	�����ٶ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setSpeed(Speed sp);
	/********************************************************
		*  @brief    :	�õ��ٶ�
		*  @input	 :
		*  @output	 :
		*  @return   :  Speed
		*  @author   :	Alex
		********************************************************/
	Speed getSpeed();
	/********************************************************
		*  @brief    :	���÷���
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setDirection(D3DXVECTOR3 Direction);
	/********************************************************
		*  @brief    :	�õ�����
		*  @input	 :
		*  @output	 :
		*  @return   :  D3DXVECTOR3
		*  @author   :	Alex
		********************************************************/
	D3DXVECTOR3 getDirection();
	/********************************************************
		*  @brief    :	������̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static ActiveSprite* create();
	/********************************************************
		*  @brief    :	���¶�̬��������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	virtual void Update(){};
	/********************************************************
	*  @brief    :	��̬����ת��ʱ��λ
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void returnPosition();
};

#endif