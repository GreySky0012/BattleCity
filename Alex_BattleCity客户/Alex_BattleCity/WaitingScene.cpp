#include "WaitingScene.h"
#include "ActiveSprite.h"
#include "CFont.h"
#include <tchar.h>
#include "GameManager.h"
#include "GameScene.h"
#include "ClientNet.h"
#include "StartScene.h"

bool WaitingScene::init()
{
	Scene::init();
	background = ActiveSprite::create();
	background->LoadTexture(_T("../Sprite/background.jpg"), 640, 480, 1);
	background->setPosition(D3DXVECTOR3(0, 0, 0));
	//addActiveChild(background);
	font = new CFont;
	font->Create();
	rect = { 200, 100, 440, 200 };
	return true;
}

void WaitingScene::Update()
{
	font->GetFont()->DrawText(NULL, _T("正在寻找主机"), -1, &rect, DT_TOP | DT_RIGHT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 255.0f));
	if (GameManager::getInstance()->getClient()->Connect("223.3.103.231",8888))
	{
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