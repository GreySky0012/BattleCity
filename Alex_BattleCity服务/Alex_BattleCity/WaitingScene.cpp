#include "WaitingScene.h"
#include "ActiveSprite.h"
#include "CFont.h"
#include <tchar.h>
#include "GameManager.h"
#include "Server.h"
#include "GameScene.h"
#include "StartScene.h"
#include "common.h"

static bool waiting = true;

DWORD WINAPI Fun(LPVOID lpParamter)
{
	if (GameManager::getInstance()->getServer()->Accept())
	{
		waiting = false;
	}
	return 0;
}

bool WaitingScene::init()
{
	Scene::init();
	waiting = true;
	background = ActiveSprite::create();
	background->LoadTexture(_T("../Sprite/background.jpg"), 640, 480, 1);
	background->setPosition(D3DXVECTOR3(0, 0, 0));
	//addActiveChild(background);
	font = new CFont;
	font->Create();
	rect = { 200, 100, 440, 200 };
	hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	return true;
}

void WaitingScene::Update()
{
	font->GetFont()->DrawText(NULL, _T("请等待玩家进入"), -1, &rect, DT_TOP | DT_RIGHT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 255.0f));
	if (!waiting)
	{
		SuspendThread(hThread);
		CloseHandle(hThread);
		GameManager::getInstance()->setPlayer(3);
		GameScene* scene = GameScene::create();
		GameManager::getInstance()->setScene(scene);
		release();
		return;
	}
	if (GameManager::getInstance()->getClick3() == ESCBUTTON_UP)
	{
		StartScene* scene = StartScene::create();
		GameManager::getInstance()->setScene(scene);
		release();
		return;
	}
}