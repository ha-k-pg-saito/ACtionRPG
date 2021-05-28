#include<Math.h>
#include "../h/Player.h"
#include"../h/Map.h"
#include"../h/Collision.h"

Collision collision;
Player player;

void Player::Init(int modelhandle,int grhandle)
{
	m_ModelHandle = modelhandle;
#pragma region ���f���e�N�X�`���ǂݍ��݁E�\��t��
	m_GrHandle[0] = grhandle;
	m_GrHandle[1] = LoadGraph("Tex/Player/sister_hood.png");
	m_GrHandle[2] = LoadGraph("Tex/Player/sister_juel.png");
	m_GrHandle[3] = LoadGraph("Tex/Player/sister_flame.png");
	m_GrHandle[4] = LoadGraph("Tex/Player/sister_pierce.png");
	m_GrHandle[5] = LoadGraph("Tex/Player/sister_hair.png");
	m_GrHandle[6] = LoadGraph("Tex/Player/sister_ahoge.png");
	m_GrHandle[7] = LoadGraph("Tex/Player/sister_rod.png");
	
	//���f���ɓ\��e�N�X�`��������for������
	for (int i=0;i<8;i++)
	{
		MV1SetTextureGraphHandle(m_ModelHandle, i, m_GrHandle[i], FALSE);
	
		MV1SetMaterialAmbColor(m_ModelHandle, i ,GetColorF(0.5f, 0.5f, 0.5f, 1.f));
	}
#pragma endregion 
	
	//�}�e���A���֐��ŃW���G�������𔭌�
	MV1SetMaterialEmiColor(m_ModelHandle, 2, GetColorF(0.f, 1.f, 0.f, 1.f));
	
#pragma region �A�j���[�V�����ǂݍ���	
//�ҋ@���[�V����
	m_AnimHandle[ANIM_LIST::ANIM_WAIT] = MV1LoadModel("Tex/Cat/catwait.mv1");
	m_AnimAttachIndex[ANIM_LIST::ANIM_WAIT] =
		MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_WAIT], FALSE);
	m_AnimTotalTime[ANIM_LIST::ANIM_WAIT] =
		MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_WAIT]);

//���胂�[�V����	
	//m_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("Tex/Player/sisterwalk.mv1");
	//�A�j���[�V�����̃f�o�b�O�p���f���ǂݍ��ݏ���
	m_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("Tex/Cat/catwalk.mv1");
	//�w�肵�����f���ɃA�j���[�V�������A�^�b�`����
	m_AnimAttachIndex[ANIM_LIST::ANIM_RUN] = 
		MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_RUN], FALSE);
	//�A�^�b�`�����A�j���[�V�����̑����Ԃ��擾����
	m_AnimTotalTime[ANIM_LIST::ANIM_RUN] =
		MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN]);

//�U�����[�V����
	m_AnimHandle[ANIM_LIST::ANIM_ATTACK] = MV1LoadModel("Tex/Cat/catattack.mv1");
	m_AnimAttachIndex[ANIM_LIST::ANIM_ATTACK] = 
		MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_ATTACK], TRUE);
	//�A�^�b�`�����A�j���[�V�����̑����Ԃ��擾����
	m_AnimTotalTime[ANIM_LIST::ANIM_ATTACK] = 
		MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_ATTACK]);

//�_���[�W���[�V����
	//m_AnimHandle[ANIM_LIST::ANIM_DAMAGE] = MV1LoadModel("Tex/catattack.mv1");
	m_AnimAttachIndex[ANIM_LIST::ANIM_DAMAGE] = 
		MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_DAMAGE], TRUE);
	//�A�^�b�`�����A�j���[�V�����̑����Ԃ��擾����
	m_AnimTotalTime[ANIM_LIST::ANIM_DAMAGE] = 
		MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_DAMAGE]);

#pragma endregion
}

void Player::Update()
{
	m_PlayTime++;
	Rotate();
	Move();
	Attack();
	collision.Update(&player);
//	m_Pos.y -= m_Gravity;

	//���݂̍Đ����Ԃ����Đ����Ԃ𒴂�����Đ����Ԃ�0�ɖ߂�
	if (m_PlayTime >= m_AnimTotalTime[ANIM_LIST::ANIM_RUN])
	{
		m_PlayTime = 0.f;
	}
}

//�v���C���[�`��
void Player::Draw()
{
	MV1DrawModel(m_ModelHandle);
	DrawHP();
}

//�v���C���[�̉�]
void Player::Rotate()
{
	float Digree = 0.f;
	float RotateSpeed = 5.f;

	//����̃L�[���������Ƃ��Ƀv���C���[����]������
	if (CheckHitKey(KEY_INPUT_D)) { Digree += RotateSpeed; }
	else if (CheckHitKey(KEY_INPUT_A)) { Digree -= RotateSpeed; }
	
	if (Digree != 0.f)
	{
		m_Digree_Y += Digree;
		//�x���@���烉�W�A���ɕϊ�
		float Rad = m_Digree_Y * DX_PI_F / 180.0f;

		//�RD�̌����x�N�g���Z�o(�P�ʃx�N�g�����P)
		m_Direction.x = sinf(Rad);
		m_Direction.z = cosf(Rad);
	
		//���f���̉�]
		MV1SetRotationXYZ(m_ModelHandle, VGet(0.0f, Rad, 0.0f));
	}
}

void Player::Move()
{
	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_ModelHandle, m_Pos);
	//�ꎞ�I�Ɉړ��ʂ�ۑ�����
	m_MoveVec = { 0.f };
#pragma region �ړ����� 
	//�����Ă�������Ɉړ�
	if (CheckHitKey(KEY_INPUT_W))
	{ 
		//60�Ŋ��邱�Ƃ�60�t���[���Ői�ރx�N�g�����o���Ă���
		m_MoveVec.x += m_Direction.x * (m_Speed * 1 / 60);
		m_MoveVec.z += m_Direction.z * (m_Speed * 1 / 60);
	}
	else if (CheckHitKey(KEY_INPUT_S)) 
	{
		m_MoveVec.x -= m_Direction.x * (m_Speed * 1 / 60);
		m_MoveVec.z -= m_Direction.z * (m_Speed * 1 / 60);
	}	
#pragma endregion
	//���C�̕`��
	//�I�_�͈ړ��O�̏ꏊ����ړ��������̃x�N�g���𑫂��ďo���Ă���
	m_Line = VAdd(GetPos(), m_MoveVec);
	DrawLine3D(m_Pos, m_Line, GetColor(0, 0, 255));
	map.CollisionToModel(m_Pos, m_Line);
	
	//�ړ������̂��𒲂ׂĈړ����Ă����Ȃ�A�j���[�V��������
	if (m_MoveVec.x != 0.f || m_MoveVec.z != 0.f)
	{
		//atan2���g�����ƂŌ��݂̌����Ă����������180�U�����
		float Rad = atan2(m_MoveVec.x, m_MoveVec.z);
		MV1SetRotationXYZ(m_ModelHandle, VGet(0.0f, Rad, 0.0f));
		m_Digree_Y = Rad * 180.f / DX_PI_F;
		//����A�j���[�V����
		MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN], m_PlayTime);
		//�{���̃|�W�V�����ϐ��Ɉꎞ�I�ɕۑ����Ă����l�����Z����
		m_Pos.x -= m_MoveVec.x;
		m_Pos.z -= m_MoveVec.z;
	}
	else 
	{
		//�ҋ@���[�V����
		MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_WAIT], m_PlayTime);
	}
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "���݂̃|�W�V������%f�ł�", m_MoveVec.x, m_MoveVec.z);
}

void Player::DrawHP()
{
	const int HPX = 75;
	const int HPY = 65;
	//HP�Q�[�W�`��
	if (m_HitCounter == 0)       m_Hp = DrawBox(HPX, HPY, 920, 140, GetColor(0, 255, 0), TRUE);
	else if (m_HitCounter == 1)  m_Hp = DrawBox(HPX, HPY, 709, 140, GetColor(0, 255, 0), TRUE); 
	else if (m_HitCounter == 2)  m_Hp = DrawBox(HPX, HPY, 498, 140, GetColor(0, 255, 0), TRUE); 
	else if (m_HitCounter == 3)  m_Hp = DrawBox(HPX, HPY, 287, 140, GetColor(0, 255, 0), TRUE);
	else if (m_HitCounter == 4) 
	{
		m_Hp = DrawBox(HPX, HPY, 75, 140, GetColor(0, 255, 0), TRUE);
		MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_DIED], m_PlayTime);
		if (m_PlayTime >= m_AnimAttachIndex[ANIM_LIST::ANIM_DIED])  Release();
	}
	//HP�Q�[�W�ǂݍ��ݕ`��
	LoadGraphScreen(0, 0, "Tex/HPGauge.png", TRUE);
}

void Player::Release()
{
	//3D���f���̍폜
	MV1DeleteModel(m_ModelHandle);
	//�e�N�X�`���̍폜
	DeleteGraph(m_GrHandle[8]);
}

void Player::Attack()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//�U���A�j���[�V����
		MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_ATTACK], m_PlayTime);
	}
}

//���̊֐��̓_���[�W��^���Ă����G�ɂ��̊֐����Ăяo��
void Player::Damage()
{
	m_HitCounter ++;
	MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_DAMAGE], m_PlayTime);
}
