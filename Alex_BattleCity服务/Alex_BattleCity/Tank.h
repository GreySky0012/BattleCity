/**************************************************************************
*  @file	 : Tank.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 坦克类和坦克数组类
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
*  @brief    : 坦克类
**************************************************************************/
class Tank :public ActiveSprite
{
public:
	~Tank();
	Tank(){};
	/********************************************************
		*  @brief    :	设置坦克的纹理
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setTankTexture();
	/********************************************************
		*  @brief    :	提升子弹的等级
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BulletLevelAdd();
	/********************************************************
		*  @brief    :	改变无敌状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void ChangeInvincibleTo(bool Vincible);
	/********************************************************
		*  @brief    :	切换无敌状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void ChangeInvincible();
	/********************************************************
		*  @brief    :	得到当前无敌状态
		*  @input	 :
		*  @output	 :
		*  @return   :  bool
		*  @author   :	Alex
		********************************************************/
	bool getInvincible();
	/********************************************************
		*  @brief    :	开火
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void fire();
	/********************************************************
		*  @brief    :	初始化一个坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	/********************************************************
		*  @brief    :	得到子弹等级
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getBulletLevel();
	/********************************************************
		*  @brief    :	创建一个坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	static Tank* create();
	/********************************************************
		*  @brief    :	更新坦克状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	/********************************************************
		*  @brief    :	得到该坦克发出的子弹
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Bullet*> getBullet(){ return TheBullet; }
	/********************************************************
		*  @brief    :	试该坦克的子弹数减一
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void BulletReduce(){ BulletNumber--; }
	/********************************************************
		*  @brief    :	增加可发出的最大子弹数
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void MaxBulletAdd(){ MaxBullet++; }
	/********************************************************
		*  @brief    :	移除某个子弹
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeBullet(Bullet* b);
	/********************************************************
		*  @brief    :	改变方向时改变纹理
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void dirctionRenderRet();
	/********************************************************
		*  @brief    :	得到该坦克当前的计时
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getTimer(){ return Timer; }
	/********************************************************
		*  @brief    :	检测坦克的无敌状态并选择相应的纹理区域
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void checkInvincible();
	/********************************************************
	*  @brief    :	设置生命值
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void setLife(int life){ Life = life; }
	/********************************************************
	*  @brief    :	得到生命值
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	int getLife(){ return Life; }
	/********************************************************
		*  @brief    :	得到坦克的可触摸状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getTouchAbleState(){ return TouchAble; }
	/********************************************************
		*  @brief    :	随机设置敌方坦克的生命值
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLife();
	/********************************************************
		*  @brief    :	设置坦克等级
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setLevel(int level);
	/********************************************************
		*  @brief    :	改变坦克的奖励状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void changeAwardAble(){ AwardAble = !AwardAble; }
	/********************************************************
		*  @brief    :	得到坦克的奖励状态
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool getAwardAble(){ return AwardAble; }
	/********************************************************
		*  @brief    :	坦克爆炸
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
*  @brief    : 坦克数组类
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
		*  @brief    :	得到坦克数量
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int getNumber(){ return TankNumber; }
	/********************************************************
		*  @brief    :	得到所有坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Tank*> getTankArray(){ return Tankarray; }
	/********************************************************
		*  @brief    :	遍历所有坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void VisitAll();
	/********************************************************
		*  @brief    :	添加坦克
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
		*  @brief    :	移除坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeTank(Tank* tank);
};
#endif