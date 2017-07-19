/**************************************************************************
*  @file	 : Bullet.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 子弹类和子弹数组类
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
		*  @brief    :	通过坦克初始化子弹对象
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	bool initWithParent(Tank* tank);
	/********************************************************
		*  @brief    :	通过坦克创建子弹对象
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	static Bullet* createWithParent(Tank* tank);
	/********************************************************
		*  @brief    :	设置子弹的发出坦克
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	void setParent(Tank* tank);
	/********************************************************
		*  @brief    :	得到子弹的发出坦克
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	Tank* getParent();
	/********************************************************
		*  @brief    :	更新子弹状态
		*  @input	 :
		*  @output	 :
		*  @return   :
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	切换至爆炸的纹理
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BigBoom();
	void SmallBoom();
	/********************************************************
		*  @brief    :	得到是否爆炸过的状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getBoom(){ return boom; }
	/********************************************************
		*  @brief    :	子弹速度增加
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
		*  @brief    :	得到子弹数量
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getNumber(){ return BulletNumber; }
	/********************************************************
		*  @brief    :	得到所有子弹
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Bullet*> getBulletArray(){ return Bulletarray; }
	/********************************************************
		*  @brief    :	遍历所有子弹
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void VisitAll();
	/********************************************************
		*  @brief    :	加入子弹
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
		*  @brief    :	移除子弹
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeBullet(Bullet* bullet);
};

#endif