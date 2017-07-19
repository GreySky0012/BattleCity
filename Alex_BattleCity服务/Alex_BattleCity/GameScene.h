/**************************************************************************
*  @file	 : GameScene.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ��Ϸ������
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
		*  @brief    :	������Ϸ��ͼ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setMap(Map* map);
	/********************************************************
		*  @brief    :	���ص�ͼ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void LoadMap();
	/********************************************************
		*  @brief    :	��ӵз�̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setEnemy(int number);
	/********************************************************
		*  @brief    :	���³���
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void Update();
	CREATE_FUNC(GameScene);
	virtual bool init();
	/********************************************************
		*  @brief    :	���ˢ�µ��Ƿ���̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool checkTank(D3DXVECTOR3 po);
	/********************************************************
		*  @brief    :	��⵱ǰ�з�̹������
		*  @input	 :
		*  @output	 :
		*  @return   :  int
		*  @author   :	Alex
		********************************************************/
	int checkEnemy();
	/********************************************************
		*  @brief    :	���Ƶз�̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void EnemyControl();
	float getWeight(D3DXVECTOR3 op,D3DXVECTOR3 dir);
	/********************************************************
		*  @brief    :	���ó���
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setScene();
	/********************************************************
		*  @brief    :	�������̹��
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setPlayerTank();
	/********************************************************
		*  @brief    :	�����ǰ������ľ�̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void clear();
	/********************************************************
		*  @brief    :	������һ�������ͼ
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void resetScene();
	~GameScene();
	/********************************************************
		*  @brief    :	����ģʽ�´�������Ϣ
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