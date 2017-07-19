/**************************************************************************
*  @file	 : Tank.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ̹�����̹��������
**************************************************************************/
#ifndef TANK_H
#define TANK_H

#include "ActiveSprite.h"
#include "common.h"

class Bullet;
/**************************************************************************
*  @file	 : Tank.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ̹����
**************************************************************************/
class Tank :public ActiveSprite
{
public:
	~Tank();
	Tank(){};
	/********************************************************
		*  @brief    :	����̹�˵�����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setTankTexture();
	/********************************************************
		*  @brief    :	�����ӵ��ĵȼ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BulletLevelAdd();
	/********************************************************
		*  @brief    :	�ı��޵�״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void ChangeInvincibleTo(bool Vincible);
	/********************************************************
		*  @brief    :	�л��޵�״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void ChangeInvincible();
	/********************************************************
		*  @brief    :	�õ���ǰ�޵�״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  bool
		*  @author   :	Alex
		********************************************************/
	bool getInvincible();
	/********************************************************
		*  @brief    :	����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void fire();
	/********************************************************
		*  @brief    :	��ʼ��һ��̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	/********************************************************
		*  @brief    :	�õ��ӵ��ȼ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getBulletLevel();
	/********************************************************
		*  @brief    :	����һ��̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static Tank* create();
	/********************************************************
		*  @brief    :	����̹��״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	�õ���̹�˷������ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Bullet*> getBullet(){ return TheBullet; }
	/********************************************************
		*  @brief    :	�Ը�̹�˵��ӵ�����һ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BulletReduce(){ BulletNumber--; }
	/********************************************************
		*  @brief    :	���ӿɷ���������ӵ���
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void MaxBulletAdd(){ MaxBullet++; }
	/********************************************************
		*  @brief    :	�Ƴ�ĳ���ӵ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeBullet(Bullet* b);
	/********************************************************
		*  @brief    :	�ı䷽��ʱ�ı�����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void dirctionRenderRet();
	/********************************************************
		*  @brief    :	�õ���̹�˵�ǰ�ļ�ʱ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getTimer(){ return Timer; }
	/********************************************************
		*  @brief    :	���̹�˵��޵�״̬��ѡ����Ӧ����������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void checkInvincible();
	/********************************************************
	*  @brief    :	��������ֵ
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void setLife(int life){ Life = life; }
	/********************************************************
	*  @brief    :	�õ�����ֵ
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	int getLife(){ return Life; }
	/********************************************************
		*  @brief    :	�õ�̹�˵Ŀɴ���״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getTouchAbleState(){ return TouchAble; }
	/********************************************************
		*  @brief    :	������õз�̹�˵�����ֵ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLife();
	/********************************************************
		*  @brief    :	����̹�˵ȼ�
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLevel(int level);
	/********************************************************
		*  @brief    :	�ı�̹�˵Ľ���״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void changeAwardAble(){ AwardAble = !AwardAble; }
	/********************************************************
		*  @brief    :	�õ�̹�˵Ľ���״̬
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getAwardAble(){ return AwardAble; }
	/********************************************************
		*  @brief    :	̹�˱�ը
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void boom();
private:
	int Life;
	int Timer;
	int BulletNumber;
	int MaxBullet;
	int BulletLevel = 1;
	bool Invincible = false;
	vector<Bullet*> TheBullet;
	int InvincibleTimer;
	int Grade;
	bool TouchAble;
	bool AwardAble;
	int counter;
};

/**************************************************************************
*  @file	 : Tank.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ̹��������
**************************************************************************/
class TankArray
{
private:
	TankArray(){};
protected:
	int TankNumber;
	vector<Tank*> Tankarray;
public:
	static TankArray* getInstance();
	/********************************************************
		*  @brief    :	�õ�̹������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getNumber(){ return TankNumber; }
	/********************************************************
		*  @brief    :	�õ�����̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Tank*> getTankArray(){ return Tankarray; }
	/********************************************************
		*  @brief    :	��������̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void VisitAll();
	/********************************************************
		*  @brief    :	���̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void pushTank(Tank* m_Tank)
	{
		Tankarray.push_back(m_Tank);
		TankNumber++;
	}
	/********************************************************
		*  @brief    :	�Ƴ�̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeTank(Tank* tank);
};
#endif