/**************************************************************************
*  @file	 : Map.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 地图类和地图管理器类
**************************************************************************/
#ifndef MAP_H
#define MAP_H

#include "Ref.h"
#include <vector>
using namespace std;

class Map;
class GameScene;
class StaticSprite;

/**************************************************************************
*  @file	 : Map.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 地图管理器类
**************************************************************************/
class MapManager
{
private:
	vector<Map*> MapArray;
	int m_MapNumber;
	MapManager();
public:
	static MapManager* getInstance();
	/********************************************************
		*  @brief    :	向管理器中添加地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void addMap(Map*);
	/********************************************************
		*  @brief    :	向场景中加载地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void LoadMap(GameScene* scene,int Number);
	~MapManager();
	/********************************************************
		*  @brief    :	得到所有地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	vector<Map*> getMapArray(){ return MapArray; }
	/********************************************************
		*  @brief    :	删掉玩家新建地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void removeLast();
};

/**************************************************************************
*  @file	 : Map.h
*  @version  : ver  1.0
*  @author   : Alex
*  @date     : 
*  @brief    : 地图类
**************************************************************************/
class Map:public Ref
{
	int m_wall[676];
public:
	CREATE_FUNC(Map);
	/********************************************************
		*  @brief    :	得到当前地图的数据
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	int* getMap(){ return m_wall; }
	/********************************************************
		*  @brief    :	初始化该地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	bool init();
	/********************************************************
		*  @brief    :	设置地图数据
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void setMap(int wall[]);
	/********************************************************
		*  @brief    :	把地图加载到场景上
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void LoadToScene(GameScene* scene);
	/********************************************************
		*  @brief    :	修改地图
		*  @input	 :
		*  @output	 :
		*  @return   :  
		*  @author   :	Alex
		********************************************************/
	void fixMap(int position, int type);
	void copyTo(int wall[][26]);//未使用
};

#endif