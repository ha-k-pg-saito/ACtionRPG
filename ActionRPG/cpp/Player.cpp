#include "../h/Player.h"
#include"DxLib.h"
#include<Math.h>

Player::Player()
{
	m_Pos = VGet(0.f, 0.9f, 0.f );
	m_Angle = (0.f);
	m_Speed = (0.5f);
}

Player::~Player()
{
}

void Player::Update()
{
	// ���f���̓ǂݍ���
	m_ModelHandle = MV1LoadModel("Tex/sister.mv1");
	
}

void Player::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(m_ModelHandle);
}

void Player::Move()
{

	m_Digree_X = cosf(m_Radian);
	m_Digree_Y = sinf(m_Radian);
	
	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_ModelHandle, m_Pos);

	//���f���̉�]
	MV1SetRotationXYZ(m_ModelHandle, VGet(m_Angle * DX_PI_F / 180.f, 0.f, 0.f));

	if (CheckHitKey(KEY_INPUT_W)) { m_Pos.z -= m_Speed; }
	if (CheckHitKey(KEY_INPUT_S)) { m_Pos.z += m_Speed; }
	if (CheckHitKey(KEY_INPUT_A)) { m_Pos.x += m_Speed; m_Angle += m_Digree_X; }
	if (CheckHitKey(KEY_INPUT_D)) { m_Pos.x -= m_Speed; m_Angle -= m_Digree_X; }

}
