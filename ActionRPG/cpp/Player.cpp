#include "../h/Player.h"
#include"DxLib.h"

//Player::Player()
//{
//	
//}
//
//Player::~Player()
//{
//	// ���f���n���h���̍폜
//	MV1DeleteModel(m_Player);
//}

void Player::Update()
{
	// ���f���̓ǂݍ���
	m_Player = MV1LoadModel("Tex/sister.mv1");

	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_Player, VGet(0.f, 0.f, 0.f));
	
}

void Player::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(m_Player);
}
