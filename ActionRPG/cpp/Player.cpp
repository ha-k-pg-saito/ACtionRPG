#include<Math.h>
#include "../h/Player.h"
#include"../h/Calculation.h"
#include"../h/OnCollision.h"

void Player::Init()
{
	m_Pos={ 0.f,-3.f,0.f };
	m_HitCounter = 0;
	IsAlive = true;

#pragma region ���f���E�e�N�X�`���ǂݍ���
//�v���C���E�����f���̃e�N�X�`���ǂݍ���
	m_GrHandle = LoadGraph("Tex/Player/RuneKnight_M_Ekard.tga");
	m_SwordGrHandle = LoadGraph("Tex/Player/Sword_12.tga");
//�v���C���E�����f���ǂݍ���
	m_ModelHandle = MV1LoadModel("Tex/Player/Ekard.mv1");
	m_SwordHandle = MV1LoadModel("Tex/Player/Sword_12.mv1");
	//���f���̃X�P�[���ύX
	Scale = { 0.15f,0.15f,0.15f };
	MV1SetScale(m_ModelHandle, Scale);
	MV1SetScale(m_SwordHandle, Scale);
	
//�w��}�e���A���̃e�N�X�`���ԍ����擾
	int texindex = MV1GetMaterialDifMapTexture(m_ModelHandle, 0);
	int tex2 = MV1GetMaterialDifMapTexture(m_SwordHandle, 0);
//���f���Ƀe�N�X�`����\��
	int hand = MV1SetTextureGraphHandle(m_ModelHandle, texindex, m_GrHandle, FALSE);
	MV1SetTextureGraphHandle(m_SwordHandle, tex2, m_SwordGrHandle, FALSE);
//�v���C���̃}�e���A���̃A���r�G���g�J���[�ύX
	MV1SetMaterialAmbColor(m_ModelHandle, 0, GetColorF(1.f, 1.f, 1.f, 0.f));

#pragma endregion 

#pragma region �A�j���[�V�����p������
	const char* anim_names[] =
	{
		"Tex/Payer/Ekard_BattleIdle.mv1",
		"Tex/Payer/Ekard_Run.mv1",
		"Tex/Ct/catattack.mv1",
		"Tex/Ct/catdamage.mv1",
		"Tex/Ct/catdied.mv1"
	};
	
	//������̐擪��I�ׂ�
	Anim.InitAnimation(m_ModelHandle, anim_names);
#pragma endregion
	
//player�̃��f���n���h��,�t���[���ԍ�,XYZ�̋�ԕ���
	MV1SetupCollInfo(m_ModelHandle, -1, 1, 1, 1);
}

void Player::Update()
{
	if (m_AnimKind != ANIM_ATTACK)
	{
		Move();
		Rotate();
	}
	Attack();
	UpdateAnimation();

	//������������t���[������������
	int FrameNum = MV1SearchFrame(m_ModelHandle, "Bip001 R Hand");
	//�t���[�����W�̕ϊ��s���ݒ肷��
	MATRIX Matrix = MV1GetFrameLocalWorldMatrix(m_ModelHandle, FrameNum);
	//�����蔻����X�V
	MV1RefreshCollInfo(m_ModelHandle, -1);
	//���f���̍��W�ϊ��p�s����Z�b�g����
	MV1SetMatrix(m_SwordHandle, Matrix);
}

//�A�j���[�V�����̐؂�ւ��𐧌䂷��֐�
void Player::UpdateAnimation()
{
//���݂̏�Ԃ����ăA�j���[�V������؂�ւ���
	m_AnimKind = ANIM_IDLE;		//������ԁi�ҋ@�j
	switch (m_AnimKind)
	{
	case ANIM_IDLE:						//�ҋ@���[�V����->���胂�[�V���� or�U�����[�V����
		//�ړ��ʂ�0�ł͖����Ƃ�
		if (m_OldMoveVec.x != PlayerState::None && m_OldMoveVec.z != PlayerState::None)
		{
			m_AnimKind = ANIM_RUN;	
		}
		//���N���b�N���ꂽ�Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != PlayerState::None)
		{
			m_AnimKind = ANIM_ATTACK;
		}
		break;
	case ANIM_RUN:						//���胂�[�V����->�ҋ@���[�V���� or �U�����[�V����
		//�ړ��ʂ�0�̎�
		if (m_OldMoveVec.x == PlayerState::None && m_OldMoveVec.z == PlayerState::None)
		{
			m_AnimKind = ANIM_IDLE;		
		}
		//���N���b�N���ꂽ�Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != PlayerState::None)
		{
			m_AnimKind = ANIM_ATTACK;
		}
		break;
	case ANIM_ATTACK:					//�U�����[�V�����[���ҋ@���[�V���� or ���胂�[�V����
		if (m_OldMoveVec.x == PlayerState::None && m_OldMoveVec.z == PlayerState::None)
		{
			m_AnimKind = ANIM_IDLE;
		}
		if (m_OldMoveVec.x != PlayerState::None && m_OldMoveVec.z != PlayerState::None)
		{
			m_AnimKind = ANIM_RUN;
		}
		break;
	default:
		break;
	}
	//��Ԃɍ��킹���A�j���[�V������������
	Anim.SetAnimation(m_ModelHandle, m_AnimKind);
}

//�v���C���[�`��
void Player::Draw()
{	
	if (IsAlive)
	{
#ifdef _DEBUG
		DrawLine3D(m_Pos, m_StartLine, GetColor(0, 0, 255));
		DrawLine3D(m_StartLine, m_EndLine, GetColor(0, 0, 255));
#endif
		MV1DrawModel(m_ModelHandle);
		MV1DrawModel(m_SwordHandle);
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
		m_OldMoveVec.x = m_Direction.x * (m_RotateSpeed * 1.f / FPS);
		m_OldMoveVec.z = m_Direction.z * (m_RotateSpeed * 1.f / FPS);

		//���f���̉�]
		MV1SetRotationXYZ(m_ModelHandle, VGet(0.f, Rad, 0.f));
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
		//�P�t���[���œ�������������o���Ă���
		MoveVec.x -= m_Direction.x * (m_Speed * 1.f / FPS);
	    MoveVec.z -= m_Direction.z * (m_Speed * 1.f / FPS);
	}
	else if (CheckHitKey(KEY_INPUT_S)) 
	{
		MoveVec.x += m_Direction.x * (m_Speed * 1.f /FPS);
		MoveVec.z += m_Direction.z * (m_Speed * 1.f /FPS);
	}

#pragma endregion
	if (MoveVec.x != PlayerState::None && MoveVec.z != PlayerState::None)
	{
		MoveVec = Slerp(m_OldMoveVec, MoveVec, 0.2f);
	}
	
	//�ߋ��̈ړ��x�N�g���ۑ�
	m_OldMoveVec = MoveVec;
	//�ړ��x�N�g����0.1�ȏ�
	if (VSize(MoveVec) >= 0.1f)
	{
		//atan2���g�����ƂŌ��݂̌����Ă����������180�U�����
		float Rad = (float)atan2f(-MoveVec.x, -MoveVec.z);

		MV1SetRotationXYZ(m_ModelHandle, VGet(0.f, Rad, 0.f));
		m_Digree_Y = Rad * 180.f / DX_PI_F;

		VECTOR CenterPos = m_Pos;
		CenterPos.y += 6.f;
		//���������Ƃ�����I�_�ɂ���
		VECTOR HitPos{ 0.f };
		if (m_MapRef->CollisionToModel(CenterPos, VAdd(CenterPos, MoveVec), &HitPos))	return;

		// �ړ���̍��W��ۑ�
		m_StartLine = VAdd(m_Pos, MoveVec);

		// ���C�̌��_�����Ƃ߂� (�ړ���̍��W+����)
		VECTOR Vertical{ 0.f,RAY_ORIGIN,0.f };
		m_StartLine.y += Vertical.y;
		
		// ���C�̏I�_�����Ƃ߂� (���C�̌��_ + �������x�N�g��)
		VECTOR DownLine{ 0.f,RAY_DOWN,0.f };
		m_EndLine = VAdd(m_StartLine, DownLine);

		// �}�b�v�Ƃ̌�������
		if (m_MapRef->CollisionToModel(m_StartLine, m_EndLine, &HitPos))
		{
			m_Pos = HitPos;
		}
	}
		// ��ʂɈڂ郂�f���̈ړ�
		MV1SetPosition(m_ModelHandle, m_Pos);
}

void Player::DrawHP()
{
	const int HPX = 75;
	const int HPY = 960;
	int color = GetColor(0, 255, 0);
	DrawBox(HPX, HPY, 920, 1040, GetColor(255,0,0), TRUE);
	//HP�Q�[�W�`��
	if      (m_HitCounter == 0)  m_Hp = DrawBox(HPX, HPY, 920, 1040, color, TRUE);
	else if (m_HitCounter == 1)  m_Hp = DrawBox(HPX, HPY, 690, 1040,color, TRUE); 
	else if (m_HitCounter == 2)  m_Hp = DrawBox(HPX, HPY, 460, 1040,color, TRUE); 
	else if (m_HitCounter == 3)  m_Hp = DrawBox(HPX, HPY, 230, 1040,color, TRUE);
	else
	{
		m_Hp = DrawBox(HPX, HPY, 75, 1040, color, TRUE);
		Release();
		IsAlive = false;
	}
	//HP�Q�[�W�ǂݍ��ݕ`��
	LoadGraphScreen(0, 900, "Tex/HPGauge.png", TRUE);
}

void Player::Release()
{
	//3D���f���̍폜
	MV1DeleteModel(m_ModelHandle);
		//�e�N�X�`���̍폜
		DeleteGraph(m_GrHandle);
}

void Player::Attack()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != PlayerState::None)
	{
		OnColl::Inatance()->OnCollitionSphereToCap(this, &Enemy);
	}
}

//���̊֐��̓_���[�W��^���Ă����G�ɂ��̊֐����Ăяo��
void Player::Damage()
{
	m_HitCounter ++;
}