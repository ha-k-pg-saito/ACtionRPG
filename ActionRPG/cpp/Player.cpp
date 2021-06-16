#include<Math.h>
#include "../h/Player.h"
#include"../h/Calculation.h"
#include"../h/OnCollision.h"

void Player::Init()
{
	m_Pos={ 0.f };
	m_HitCounter = 0;
	IsAlive = true;

#pragma region ���f���E�e�N�X�`��������
	const char* tex_names[] =
	{
		"Tex/Player/sister_body.png",
		"Tex/Player/sister_hood.png",
		"Tex/Player/sister_juel.png",
		"Tex/Player/sister_flame.png",
		"Tex/Player/sister_pierce.png",
		"Tex/Player/sister_hair.png",
		"Tex/Player/sister_ahoge.png",
		"Tex/Player/sister_rod.png"
	};
	
	m_ModelHandle = MV1LoadModel("Tex/Player/sister.mv1");
	//�f�o�b�O�p���f��
	//m_ModelHandle =MV1LoadModel("Tex/Cat/catoriginal.mv1"); 
	
	//�e�N�X�`���̐������Afor�����񂵂Ă���
	for (int i = 0; i <PLAYER_TEX_NUM; i++)
	{
		m_GrHandle[i] = LoadGraph(tex_names[i]);
		MV1SetTextureGraphHandle(m_ModelHandle, i, m_GrHandle[i], FALSE);
		MV1SetMaterialAmbColor(m_ModelHandle, i ,GetColorF(0.5f, 0.5f, 0.5f, 1.f));
	}
#pragma endregion 
	
	MV1SetRotationXYZ(m_ModelHandle, VGet(0.0f, 0.f, 0.f));
//�}�e���A���֐��ŃW���G�������𔭌�
	MV1SetMaterialEmiColor(m_ModelHandle, 2, GetColorF(0.f, 1.f, 0.f, 1.f));

#pragma region �A�j���[�V�����p������
	const char* anim_names[] =
	{
		"Tex/Cat/catwait.mv1",
		"Tex/Cat/catwalk.mv1"
		"Tex/Cat/catattack.mv1",
		"Tex/Cat/catdamage.mv1",
		"Tex/Cat/catdied.mv1"
	};
	
	//������̐擪��I�ׂ�
	Anim.InitAnimation(m_ModelHandle, anim_names);
#pragma endregion

//player�̃��f���n���h��,�t���[���ԍ�,XYZ�̋�ԕ���
	MV1SetupCollInfo(m_ModelHandle, -1, 1, 1, 1);
}

void Player::Update()
{
	m_PlayTime++;
	Move();
	Rotate();
	Attack();

//���݂̍Đ����Ԃ����Đ����Ԃ𒴂�����Đ����Ԃ�0�ɖ߂�
	if (m_PlayTime >= Anim.m_AnimTotalTime[Anim.ANIM_LIST::ANIM_RUN]|| m_PlayTime >= Anim.m_AnimTotalTime[Anim.ANIM_LIST::ANIM_ATTACK])
	{
		m_PlayTime = 0.f;
	}

	//�����蔻����X�V
	MV1RefreshCollInfo(m_ModelHandle, -1);
}

//�v���C���[�`��
void Player::Draw()
{	
	if (IsAlive)
	{
		MV1DrawModel(m_ModelHandle);
#ifdef _DEBUG
		DrawLine3D(m_Pos, m_StartLine, GetColor(0, 0, 255));
		DrawLine3D(m_StartLine, m_EndLine, GetColor(0, 0, 255));
#endif
		DrawHP();
	}
}

//�v���C���[�̉�]
void Player::Rotate()
{
	float Angle{ 0.f };

	//����̃L�[���������Ƃ��Ƀv���C���[����]������
	if      (CheckHitKey(KEY_INPUT_D))  Angle += m_RotateSpeed;
	else if (CheckHitKey(KEY_INPUT_A))  Angle -= m_RotateSpeed;

	//�p�x���O�ł͂Ȃ��ꍇ
	if (Angle != PlayerState::None)
	{
		m_Digree_Y += Angle;
		//�x���@���烉�W�A���ɕϊ�
		float Rad = m_Digree_Y * DX_PI_F / 180.f;

		//�RD�̌����x�N�g���Z�o(�P�ʃx�N�g�����P)
		m_Direction.x = sinf(Rad);
		m_Direction.z = cosf(Rad);
		m_OldMoveVec.x = m_Direction.x * (m_RotateSpeed * 1.f / 60.f);
		m_OldMoveVec.z = m_Direction.z * (m_RotateSpeed * 1.f / 60.f);

		//���f���̉�]
		MV1SetRotationXYZ(m_ModelHandle, VGet(0.0f, Rad, 0.0f));
	}
}

void Player::Move()
{
//���t���[��0�ŏ���������
	VECTOR MoveVec{ 0.f };

#pragma region �ړ����� 
//����̃L�[���������Ƃ��Ɉړ�
	if (CheckHitKey(KEY_INPUT_W))
	{ 
		//60�Ŋ��邱�Ƃ�60�t���[���Ői�ރx�N�g�����o���Ă���
		MoveVec.x -= m_Direction.x * (m_Speed * 1.f / 60.f);
	    MoveVec.z -= m_Direction.z * (m_Speed * 1.f / 60.f);
	}
	else if (CheckHitKey(KEY_INPUT_S)) 
	{
		MoveVec.x += m_Direction.x * (m_Speed * 1.f / 60.f);
		MoveVec.z += m_Direction.z * (m_Speed * 1.f / 60.f);
	}

#pragma endregion
	if (MoveVec.x != PlayerState::None && MoveVec.z != PlayerState::None)
	{
		MoveVec = Slerp(m_OldMoveVec, MoveVec, 0.2f);
	}
	
	//�ߋ��̈ړ��x�N�g���ۑ�
	m_OldMoveVec = MoveVec;

	//�ړ������̂��𒲂ׂĈړ����Ă����Ȃ�A�j���[�V��������
	if (VSize(MoveVec) >= 0.1f)
	{
		//atan2���g�����ƂŌ��݂̌����Ă����������180�U�����
		float Rad = (float)atan2(-MoveVec.x, -MoveVec.z);

		//m_Digree_Y = Rad * 180.f / DX_PI_F;
		MV1SetRotationXYZ(m_ModelHandle, VGet(0.f, Rad, 0.f));
		//����A�j���[�V����
		Anim.SetAnimation(m_ModelHandle, Anim.ANIM_LIST::ANIM_RUN, m_PlayTime);

		VECTOR CenterPos = m_Pos;
		CenterPos.y += 6.f;
		//���������Ƃ�����I�_�ɂ���
		VECTOR HitPos{ 0.f };
		if (m_MapRef->CollisionToModel(CenterPos, VAdd(CenterPos, MoveVec), &HitPos))	return;

		//�����n�_�l����ǂꂭ�炢���炷�̂�
		VECTOR vertical{ 0.f,4.f,0.f };
		//�n�_�͌��݂̃|�W�V�����ƈړ��ʂ�ۑ����Ă���ϐ��𑫂��Ă���
		m_StartLine = VAdd(m_Pos, MoveVec);
		m_StartLine.y +=vertical.y ;
		//�����n�_�l����ǂꂭ�炢���Ƀ��C���o���̂�
		VECTOR DownLine{ 0.f,-16.f,0.f };
		m_EndLine = VAdd(m_StartLine, DownLine);
		//�o�������C�̃}�b�v�Ƃ̂����蔻��
		if (m_MapRef->CollisionToModel(m_StartLine, m_EndLine, &HitPos))
		{
			m_Pos = HitPos;
		}
	
		// ��ʂɈڂ郂�f���̈ړ�
		MV1SetPosition(m_ModelHandle, m_Pos);
	}
	else 
	{
		//�ҋ@���[�V����
		Anim.SetAnimation(m_ModelHandle, Anim.ANIM_LIST::ANIM_WAIT, m_PlayTime);
	}
}

void Player::DrawHP()
{
	const int HPX = 75;
	const int HPY = 65;
	int color = GetColor(0, 255, 0);
	//HP�Q�[�W�`��
	if      (m_HitCounter == 0)  m_Hp = DrawBox(HPX, HPY, 920, 140, color, TRUE);
	else if (m_HitCounter == 1)  m_Hp = DrawBox(HPX, HPY, 709, 140,color, TRUE); 
	else if (m_HitCounter == 2)  m_Hp = DrawBox(HPX, HPY, 498, 140,color, TRUE); 
	else if (m_HitCounter == 3)  m_Hp = DrawBox(HPX, HPY, 287, 140,color, TRUE);
	else
	{
		m_Hp = DrawBox(HPX, HPY, 75, 140, color, TRUE);
		Anim.SetAnimation(m_ModelHandle, Anim.ANIM_LIST::ANIM_DIED, m_PlayTime);
		if (m_PlayTime >= Anim.m_AnimAttachIndex[Anim.ANIM_LIST::ANIM_DIED])  Release();
		IsAlive = false;
	}
	//HP�Q�[�W�ǂݍ��ݕ`��
	LoadGraphScreen(0, 0, "Tex/HPGauge.png", TRUE);
}

void Player::Release()
{
	//3D���f���̍폜
	MV1DeleteModel(m_ModelHandle);
	for (int i = 0; i < PLAYER_TEX_NUM; i++)
	{
		//�e�N�X�`���̍폜
		DeleteGraph(m_GrHandle[i]);
	}
}

void Player::Attack()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != PlayerState::None)
	{
		//�U���A�j���[�V����
		Anim.SetAnimation(m_ModelHandle, Anim.ANIM_LIST::ANIM_ATTACK, m_PlayTime);
		OnColl::Inatance()->OnCollitionSphereToCap(this, &Enemy);
	}
}

//���̊֐��̓_���[�W��^���Ă����G�ɂ��̊֐����Ăяo��
void Player::Damage()
{
	m_HitCounter ++;
	Anim.SetAnimation(m_ModelHandle, Anim.ANIM_LIST::ANIM_DAMAGE, m_PlayTime);
}