/**************************************************************************
*  @file	 : GameScene.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 游戏场景类
**************************************************************************/
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "common.h"

class Tank;
class Sound;

class GameScene :public Scene
{
public:
	/********************************************************
		*  @brief    :	设置游戏地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setMap(Map* map);
	/********************************************************
		*  @brief    :	加载地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void LoadMap();
	/********************************************************
		*  @brief    :	添加敌方坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setEnemy(int number);
	/********************************************************
		*  @brief    :	更新场景
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	CREATE_FUNC(GameScene);
	virtual bool init();
	/********************************************************
		*  @brief    :	检测刷新点是否有坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool checkTank(D3DXVECTOR3 po);
	/********************************************************
		*  @brief    :	检测当前敌方坦克数量
		*  @input	 :
		*  @output	 :
		*  @return   :  int
		*  @author   :	Alex
		********************************************************/
	int checkEnemy();
	/********************************************************
		*  @brief    :	控制敌方坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void EnemyControl();
	float getWeight(D3DXVECTOR3 op,D3DXVECTOR3 dir);
	/********************************************************
		*  @brief    :	布置场景
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setScene();
	/********************************************************
		*  @brief    :	配置玩家坦克
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setPlayerTank();
	/********************************************************
		*  @brief    :	清除当前场景里的静态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void clear();
	/********************************************************
		*  @brief    :	进入下一关重设地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void resetScene();
	~GameScene();
	/********************************************************
		*  @brief    :	联机模式下处理按键信息
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void checkMsg();
private:
	ActiveSprite* flag;
	ActiveSprite* playerSign_T_1;
	ActiveSprite* playerSign_T_2;
	ActiveSprite* playerSign_R_1;
	ActiveSprite* playerSign_R_2;
	ActiveSprite* playerIco_1;
	ActiveSprite* playerIco_2;
	ActiveSprite* background2;
	Tank* MyTank1;
	Tank* MyTank2;
	Map* nowmap;
	int EnemyTimer;
	int nowEnemyNumber;
	int EnemyNumber;
	Map* nowMap;
	int Grade_1;
	int Grade_2;
	int n;
	int j_1;
	int j_2;
	vector<ActiveSprite*> levelArray;
	vector<ActiveSprite* >player_1_grade;
	vector<ActiveSprite* >player_2_grade;
	ActiveSprite* player_1_blood;
	ActiveSprite* player_2_blood;
	vector<ActiveSprite*>NumberOfEnemy;
	int counter;
	Sound* StartSound;
	char recv1, recv2;
	char* send1;
	char* send2;
};

#endif