#include "../h/Player.h"
#include"DxLib.h"
#include<Math.h>

Player::Player():
	Base(0.f, 0.9f,0.f),
	m_Angle{90.f},
	m_PlayTime{0}
{
	m_Speed = (20.f);	
}

void Player::Init()
{
	// ���f���̓ǂݍ���
	m_ModelHandle = MV1LoadModel("Tex/sister.mv1");

	//�A�j���[�V����
	m_AnimHandle[ANIM_LIST::ANIM_RUN]= MV1LoadModel("Tex/unitychan_RUN00_F.mv1");
	m_AnimAttachIndex[ANIM_LIST::ANIM_RUN] = MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_RUN], TRUE);
	m_AnimTotalTime[ANIM_LIST::ANIM_RUN] = MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN]);
}

void Player::Update()
{
	Move();
	m_PlayTime++;
	if (m_PlayTime>=m_AnimTotalTime[ANIM_LIST::ANIM_RUN])
	{
		m_PlayTime = 0;
	}
	MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN], m_PlayTime);
}

void Player::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(m_ModelHandle);
}

void Player::Move()
{
	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_ModelHandle, m_Pos);

	//�����x�N�g���Z�o(�P�ʃx�N�g�����P)
	m_Digree_X = cosf(m_Radian) + sinf(m_Radian);
	m_Digree_Z = -sinf(m_Radian) + cosf(m_Radian);

	//����̃L�[���������Ƃ��Ƀv���C���[���ړ�������
	if (CheckHitKey(KEY_INPUT_W)) { m_Pos.z -= m_Digree_Z * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_S)) { m_Pos.z += m_Digree_Z * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_A)) { m_Pos.x += m_Digree_X * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_D)) { m_Pos.x -= m_Digree_X * (m_Speed * 1 / 60); }
}

