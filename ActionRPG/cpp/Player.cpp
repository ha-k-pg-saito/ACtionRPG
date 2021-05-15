#include<Math.h>
#include "../h/Player.h"
#include"DxLib.h"

void Player::Init(int modelhandle,int grhandle)
{
	m_ModelHandle = modelhandle;
#pragma region ���f���e�N�X�`���ǂݍ���
	m_GrHandle[0] = grhandle;
	m_GrHandle[1] = LoadGraph("Tex/Player/sister_hood.png");
	m_GrHandle[2] = LoadGraph("Tex/Player/sister_juel.png");
	m_GrHandle[3] = LoadGraph("Tex/Player/sister_flame.png");
	m_GrHandle[4] = LoadGraph("Tex/Player/sister_pierce.png");
	m_GrHandle[5] = LoadGraph("Tex/Player/sister_hair.png");
	m_GrHandle[6] = LoadGraph("Tex/Player/sister_ahoge.png");
	m_GrHandle[7] = LoadGraph("Tex/Player/sister_rod.png");
#pragma endregion 

	for (int i=0;i<8;i++)
	{
		MV1SetTextureGraphHandle(m_ModelHandle, i, m_GrHandle[i], FALSE);
	
		MV1SetMaterialAmbColor(m_ModelHandle, i ,GetColorF(0.5f, 0.5f, 0.5f, 1.f));
	}
	//�}�e���A���֐��ŃW���G�������𔭌�
	MV1SetMaterialEmiColor(m_ModelHandle, 2, GetColorF(0.f, 1.f, 0.f, 1.f));
}

void Player::Update()
{
	Rotate();
	Move();
	
	m_PlayTime++;
	if (m_PlayTime>=m_AnimTotalTime[ANIM_LIST::ANIM_RUN])
	{
		m_PlayTime = 0.f;
	}
	MV1SetAttachAnimTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN], m_PlayTime);
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
	if (CheckHitKey(KEY_INPUT_A)) { Digree -= RotateSpeed; }
	if (CheckHitKey(KEY_INPUT_D)) { Digree += RotateSpeed; }

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
	//����Collision�̓��C�ƃ}�b�v�̂����蔻����s���Ă���
	Collision();
	
	// ��ʂɈڂ郂�f���̈ړ�
	MV1SetPosition(m_ModelHandle, m_Pos);
	//�ꎞ�I�Ɉړ��ʂ�ۑ�����
	VECTOR Move_Vec{ 0.f,0.f,0.f };
	
#pragma region �ړ����� 
	//�����Ă�������Ɉړ�
	if (CheckHitKey(KEY_INPUT_W))
	{ 
		//60�Ŋ��邱�Ƃ�60�t���[���Ői�ރx�N�g�����o���Ă���
		Move_Vec.x -= m_Direction.x * (m_Speed * 1 / 60);
		Move_Vec.z -= m_Direction.z * (m_Speed * 1 / 60);
	}
	if (CheckHitKey(KEY_INPUT_S)) 
	{
		Move_Vec.x += m_Direction.x * (m_Speed * 1 / 60);
		Move_Vec.z += m_Direction.z * (m_Speed * 1 / 60);
	}
	//���C�̕`��
	//�I�_�͈ړ��O�̏ꏊ����ړ��������̃x�N�g���𑫂��ďo���Ă���
	m_Line = VAdd(GetPos(), Move_Vec);
	DrawLine3D(m_Pos, m_Line, GetColor(0, 0, 255));
#pragma endregion

	//�ړ������̂��𒲂ׂĈړ����Ă����Ȃ�A�j���[�V��������
	if (Move_Vec.x != 0.f || Move_Vec.z != 0.f)
	{
		//�ҋ@��Ԃ��瑖�郂�[�V�����ɐ؂�ւ���
		m_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("Tex/catwalk.mv1");
		//�w�肵�����f���ɃA�j���[�V�������A�^�b�`����
		//�A�^�b�`�[���t��������etc...
		m_AnimAttachIndex[ANIM_LIST::ANIM_RUN] = MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_RUN], TRUE);
		//�A�^�b�`�����A�j���[�V�����̑����Ԃ��擾����
		m_AnimTotalTime[ANIM_LIST::ANIM_RUN] = MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_RUN]);
		//�{���̃|�W�V�����ϐ��Ɉꎞ�I�ɕۑ����Ă����l�����Z����
		m_Pos.x += Move_Vec.x;
		m_Pos.z += Move_Vec.z;
	}
	else 
	{
		//�����ĂȂ���Αҋ@���[�V����
		m_PlayTime = 0.f;
		m_AnimHandle[ANIM_LIST::ANIM_NUM] = MV1LoadModel("Tex/catwait.mv1");
		m_AnimAttachIndex[ANIM_LIST::ANIM_NUM] = MV1AttachAnim(m_ModelHandle, 0, m_AnimHandle[ANIM_LIST::ANIM_NUM], TRUE);
		m_AnimTotalTime[ANIM_LIST::ANIM_NUM] = MV1GetAttachAnimTotalTime(m_ModelHandle, m_AnimAttachIndex[ANIM_LIST::ANIM_NUM]);
	}
}

void Player::DrawHP()
{
	//HP�o�[�`��i�l�p�`�j
	DrawBox(75, 65, 920, 140, GetColor(0,255,0), TRUE);
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

void Player::Collision()
{
	//���f���S�̂̃R���W�������\�z
	MV1SetupCollInfo(m_ModelHandle, 0, 8, 8, 8);
	//0�Ԗڂ̃t���[���̃R���W���������X�V����
	MV1RefreshCollInfo(m_ModelHandle, 0);
	//0�ԃt���[���ƃ��C�s�̂����蔻��
	HitPoly= MV1CollCheck_Line(m_ModelHandle, 0, m_Pos, m_Line);

	//���������Ȃ炻�̈ʒu�����C�̏I�_�Ƃ���
	if (HitPoly.HitFlag == 1)
	{
		m_Line = HitPoly.HitPosition;
	}
	// �����������ǂ�����\������
	DrawFormatString(1500, 100, GetColor(255, 255, 255), "HIT:%d", HitPoly.HitFlag);
}
