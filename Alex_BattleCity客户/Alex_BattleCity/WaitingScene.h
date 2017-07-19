#ifndef WAITINGSCENE_H
#define WAITINGSCENE_H

#include "Scene.h"
#include <Windows.h>

class CFont;
class ActiveSprite;

class WaitingScene :public Scene
{
	ActiveSprite* background;
	CFont* font;
	RECT rect;
public:
	void Update();
	CREATE_FUNC(WaitingScene);
	virtual bool init();
};

#endif