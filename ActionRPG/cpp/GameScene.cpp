#include "../h/GameScene.h"
#include"../h/Scene.h"

extern SceneKind g_SceneKind;
extern SceneStep g_SceneStep;

GameScene::GameScene()
{
}

void GameScene::InitGameScene()
{
	// ���f���̃e�N�X�`���ǂݍ���
	int PlayerGrHandle    = LoadGraph("Tex/sister_body.png");
	// ���f���̓ǂݍ���
	int PlayerModelHandle = MV1LoadModel("Tex/sister.mv1");
	//�}�b�v�̃e�N�X�`���ǂݍ���
	int MapGrHandle       = LoadGraph("Tex/rock.jpg");
	//�}�b�v���f���̓ǂݍ���
	int MapHandle         = MV1LoadModel("Tex/map.mv1");
	map.Init(MapHandle, MapGrHandle);
	player.Init(PlayerModelHandle, PlayerGrHandle);
	Push = true;
	g_SceneStep = SceneStep::Run;
}

void GameScene::RunGameScene()
{
	player.Update();
	camera.Update(&player);
	
	if (CheckHitKey(KEY_INPUT_RETURN) != 0)
	{
		if (Push == false)
		{
			Push = true;
			g_SceneStep = SceneStep::Finish;
		}
	}
	else
	{
		Push = false;
	}

	map.Draw();
	player.Draw();
}

void GameScene::FinishGameScene()
{
	g_SceneKind = SceneKind::SceneKind_Result;
	g_SceneStep = SceneStep::Init;
}

void GameScene::GameSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init:   InitGameScene();   break;
	case SceneStep::Run:    RunGameScene();    break;
	case SceneStep::Finish: FinishGameScene(); break;
	}
}
