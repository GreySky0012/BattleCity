/**************************************************************************
*  @file	 : Scene.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 场景类
**************************************************************************/
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Ref.h"

class ActiveSprite;
class StaticSprite;
class Map;
class Award;

class Scene:public Ref
{
public:
	/********************************************************
		*  @brief    :	初始化一个场景
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	CREATE_FUNC(Scene);
	/********************************************************
		*  @brief    :	向场景里添加动态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void addActiveChild(ActiveSprite* child);
	/********************************************************
	*  @brief    :	向场景里添加静态精灵
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void addStaticChild(StaticSprite* child);
	/********************************************************
		*  @brief    :	渲染场景上的所有动态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void DrawAllActive();
	/********************************************************
	*  @brief    :	渲染场景上的所有静态精灵
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	virtual void DrawAllStatic();
	/********************************************************
		*  @brief    :	移除场景上的某个动态精灵
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeActiveChild(ActiveSprite* sp);
	/********************************************************
	*  @brief    :	移除场景上的某个静态精灵
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void removeStaticChild(StaticSprite* sp);
	~Scene();
	/********************************************************
		*  @brief    :	更新场景
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	virtual void Update(){};
	/********************************************************
	*  @brief    :	老家爆了
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void homeBoom();
	/********************************************************
		*  @brief    :	设置一个奖励
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setAward();
	/********************************************************
		*  @brief    :	消除当前奖励
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void clearAward(){ nowAward = NULL; }
	/********************************************************
		*  @brief    :	得到当前奖励
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	Award* getAward(){ return nowAward; }
protected:
	int ActiveNumber;
	int StaticNumber;
	vector<ActiveSprite*> Active_children;
	vector<StaticSprite*> Static_children;
	vector<StaticSprite*> home;
	bool win;
	Award* nowAward;
};
#endif