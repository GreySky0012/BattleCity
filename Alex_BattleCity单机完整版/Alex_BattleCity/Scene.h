/**************************************************************************
*  @file	 : Scene.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : ������
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
		*  @brief    :	��ʼ��һ������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	CREATE_FUNC(Scene);
	/********************************************************
		*  @brief    :	�򳡾�����Ӷ�̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void addActiveChild(ActiveSprite* child);
	/********************************************************
	*  @brief    :	�򳡾�����Ӿ�̬����
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void addStaticChild(StaticSprite* child);
	/********************************************************
		*  @brief    :	��Ⱦ�����ϵ����ж�̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void DrawAllActive();
	/********************************************************
	*  @brief    :	��Ⱦ�����ϵ����о�̬����
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	virtual void DrawAllStatic();
	/********************************************************
		*  @brief    :	�Ƴ������ϵ�ĳ����̬����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeActiveChild(ActiveSprite* sp);
	/********************************************************
	*  @brief    :	�Ƴ������ϵ�ĳ����̬����
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void removeStaticChild(StaticSprite* sp);
	~Scene();
	/********************************************************
		*  @brief    :	���³���
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	virtual void Update(){};
	/********************************************************
	*  @brief    :	�ϼұ���
	*  @input	 :
	*  @output	 :
	*  @return   :
	*  @author   :	Alex
	********************************************************/
	void homeBoom();
	/********************************************************
		*  @brief    :	����һ������
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setAward();
	/********************************************************
		*  @brief    :	������ǰ����
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void clearAward(){ nowAward = NULL; }
	/********************************************************
		*  @brief    :	�õ���ǰ����
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