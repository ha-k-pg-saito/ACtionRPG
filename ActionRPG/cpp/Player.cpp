#include<Math.h>
#include "../h/Player.h"
#include"DxLib.h"

void Player::Init()
{
	// ���f���̓ǂݍ���
	m_ModelHandle = MV1LoadModel("Tex/sister.mv1");
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
	DrawHP();
}

void Player::Move()
{
	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_ModelHandle, m_Pos);

	VECTOR Move_Vec{ 0.f,0.f,0.f };

	//���f���̉�]
	MV1SetRotationXYZ(m_ModelHandle, VGet(0.0f,m_Radian * DX_PI_F / 180.0f, 0.0f));

	//�RD�̌����x�N�g���Z�o(�P�ʃx�N�g�����P)
	m_Digree_X = sinf(m_Radian);
	m_Digree_Z = cosf(m_Radian);

	//����̃L�[���������Ƃ��Ƀv���C���[�����Ă�������ɂ��ړ�������
	if (CheckHitKey(KEY_INPUT_W)) { Move_Vec.z -= m_Digree_Z * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_S)) { Move_Vec.z += m_Digree_Z * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_A)) { Move_Vec.x += m_Digree_X * (m_Speed * 1 / 60); }
	if (CheckHitKey(KEY_INPUT_D)) { Move_Vec.x -= m_Digree_X * (m_Speed * 1 / 60); }

	if (Move_Vec.x != 0.f || Move_Vec.z != 0.f)
	{
		//�A�j���[�V����
		m_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("Tex/unitychan_RUN00_F.mv1");
		m_AnimAttachIndex[ANIM_LIST::ANIM_RUN] = MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_RUN], TRUE);
		m_AnimTotalTime[ANIM_LIST::ANIM_RUN] = MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN]);
		m_Pos.x += Move_Vec.x;
		m_Pos.z += Move_Vec.z;
	}

}

void Player::DrawHP()
{
	//HP�o�[�`��i�l�p�`�j
	DrawBox(100, 65, 900, 140, GetColor(0,255,0), TRUE);
	//HP�Q�[�W�ǂݍ��ݕ`��
	LoadGraphScreen(0, 0, "Tex/HPGauge.png", TRUE);
}

