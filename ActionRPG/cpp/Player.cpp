#include "../h/Player.h"
#include"DxLib.h"

Player::Player()
{
	m_Pos = VGet(0.f, 0.9f, 0.f);
	m_Angle = (0.f);
}

void Player::Update()
{
	// ���f���̓ǂݍ���
	m_Player = MV1LoadModel("Tex/sister.mv1");

	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_Player, m_Pos);

}

void Player::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(m_Player);
}
