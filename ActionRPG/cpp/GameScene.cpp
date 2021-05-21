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
	int PlayerGrHandle    = LoadGraph("Tex/Player/sister_body.png");
	// ���f���̓ǂݍ���
	int PlayerModelHandle = MV1LoadModel("Tex/Player/sister.mv1");
	//�f�o�b�O�p�G���f���ǂݍ���
	//int PlayerModelHandle = MV1LoadModel("Tex/Cat/catoriginal (2).mv1");
	//�}�b�v�̃e�N�X�`���ǂݍ���
	int MapGrHandle = LoadGraph("Tex/Stage/rock.jpg");
	//�}�b�v���f���̓ǂݍ���
	int MapHandle = MV1LoadModel("Tex/Stage/map.mv1");
	int SoundHandle = LoadSoundMem("Sound/�|���\�̂���p��.mp3");
	map.Init(MapHandle, MapGrHandle);
	player.Init(PlayerModelHandle, PlayerGrHandle);
	Sound::Instance()->Init(SoundHandle);
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
	//Sound::Instance()->play();
}

void GameScene::FinishGameScene()
{
	Sound::Instance()->stop();
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
