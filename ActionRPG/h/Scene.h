#ifndef Scene_h_
#define Scene_h_

#include"DxLib.h"
//�V�[���̎��
enum SceneKind
{
	SceneKind_Title,
	SceneKind_Game,
	SceneKind_Result
};

enum SceneStep
{
	Init,
	Run,
	Finish
};

void SceneUpdate();

//�l���ς��Ȃ��̂�const�g�p
static const int color = GetColor(255, 255, 255);

#endif