/**************************************************************************
*  @file	 : Bullet.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : �ӵ�����ӵ�������
**************************************************************************/
#ifndef BULLET_H
#define BULLET_H

#define BulletSpeed (Speed(0,0))

#include "Tank.h"

class Bullet :public ActiveSprite
{
public:
	~Bullet();
	Bullet(){};
	/********************************************************
		*  @brief    :	ͨ��̹�˳�ʼ���ӵ�����
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	bool initWithParent(Tank* tank);
	/********************************************************
		*  @brief    :	ͨ��̹�˴����ӵ�����
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	static Bullet* createWithParent(Tank* tank);
	/********************************************************
		*  @brief    :	�����ӵ��ķ���̹��
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	void setParent(Tank* tank);
	/********************************************************
		*  @brief    :	�õ��ӵ��ķ���̹��
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	Tank* getParent();
	/********************************************************
		*  @brief    :	�����ӵ�״̬
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	�л�����ը������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BigBoom();
	void SmallBoom();
	/********************************************************
		*  @brief    :	�õ��Ƿ�ը����״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getBoom(){ return boom; }
	/********************************************************
		*  @brief    :	�ӵ��ٶ�����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void SpeedUp();
private:
	Tank* Parent;
	int counter;
	bool boom;
};

class BulletArray
{
private:
	BulletArray(){};
protected:
	int BulletNumber;
	vector<Bullet*> Bulletarray;
public:
	static BulletArray* getInstance();
	/********************************************************
		*  @brief    :	�õ��ӵ�����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getNumber(){ return BulletNumber; }
	/********************************************************
		*  @brief    :	�õ������ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Bullet*> getBulletArray(){ return Bulletarray; }
	/********************************************************
		*  @brief    :	���������ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void VisitAll();
	/********************************************************
		*  @brief    :	�����ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void pushBullet(Bullet* m_Bullet)
	{
		Bulletarray.push_back(m_Bullet);
		BulletNumber++;
	}
	/********************************************************
		*  @brief    :	�Ƴ��ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeBullet(Bullet* bullet);
};

#endif