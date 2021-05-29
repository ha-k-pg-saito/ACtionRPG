#include"../h/Enemy.h"
#include"math.h"

void Enemy::Init()
{
	m_Enemy_ModelHandle = MV1LoadModel("catoriginal.mv1");
	//���胂�[�V����	
		//m_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("Tex/Player/sisterwalk.mv1");
		//�A�j���[�V�����̃f�o�b�O�p���f���ǂݍ��ݏ���
	m_Enemy_AnimHandle[ANIM_LIST::ANIM_RUN] = MV1LoadModel("catwalk.mv1");
	//�w�肵�����f���ɃA�j���[�V�������A�^�b�`����
	//�A�^�b�`�[���t��������etc...
	m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_RUN] =
		MV1AttachAnim(m_Enemy_ModelHandle, ANIM_LIST::ANIM_RUN, m_Enemy_AnimHandle[ANIM_LIST::ANIM_RUN], FALSE);
	//�A�^�b�`�����A�j���[�V�����̑����Ԃ��擾����
	m_Enemy_AnimTotalTime[ANIM_LIST::ANIM_RUN] =
		MV1GetAttachAnimTotalTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_RUN]);

	//�ҋ@���[�V����
	m_Enemy_AnimHandle[ANIM_LIST::ANIM_WAIT] = MV1LoadModel("catwait0.mv1");
	m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_WAIT] =
		MV1AttachAnim(m_Enemy_ModelHandle, ANIM_LIST::ANIM_WAIT, m_Enemy_AnimHandle[ANIM_LIST::ANIM_WAIT], FALSE);
	m_Enemy_AnimTotalTime[ANIM_LIST::ANIM_WAIT] =
		MV1GetAttachAnimTotalTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_WAIT]);

	m_Enemy_MoveFlag = FALSE;

	// �R�c���f���̍��W��������
	m_Rand_Pos.x = rand() % 5000 - 2500;
	m_Rand_Pos.z = rand() % 5000 - 2500;
	m_Rand_Pos.y = 0.0f;
	m_Enemy_Position = VGet(m_Rand_Pos.x, m_Rand_Pos.y, m_Rand_Pos.z);
	m_Enemy_InitialPosition = VGet(m_Rand_Pos.x, m_Rand_Pos.y, m_Rand_Pos.z);

	m_Hp = 3;
	IsActive = true;
}

void Enemy::Update(VECTOR player_pos)
{
	// �R�c���f��Enemy����R�c���f��Player�Ɍ������x�N�g�����Z�o
	m_Vector = VSub(player_pos, m_Enemy_Position);
	// �R�c���f��Enemy���珉���n�_�ւ̃x�N�g�����Z�o
	m_Initial_EnemyVector = VSub(m_Enemy_InitialPosition, m_Enemy_Position);

	// atan2 ���g�p���Ċp�x���擾
	m_Enemy_Angle = atan2(m_Vector.x, m_Vector.z);
	m_Initial_EnemyAngle = atan2(m_Initial_EnemyVector.x, m_Initial_EnemyVector.z);

	// Player��Enemy�̋���
	m_Distance_Pos.x = player_pos.x - m_Enemy_Position.x;
	m_Distance_Pos.z = player_pos.z - m_Enemy_Position.z;
	// Enemy�̏����ʒu��Enemy�̋���
	m_SetEnemy_Pos.x = m_Enemy_InitialPosition.x - m_Enemy_Position.x;
	m_SetEnemy_Pos.z = m_Enemy_InitialPosition.z - m_Enemy_Position.z;

	if (m_Distance_Pos.x < 0)
	{
		// Player�Ƃ̕�����+-���C��
		m_Enemy_direction_x = -1;
		// Player�Ƃ̋�����-��+�ɕύX
		m_Distance_Pos.x *= -1;
	}
	else
	{
		m_Enemy_direction_x = 1;
	}
	if (m_Distance_Pos.z < 0)
	{
		m_Enemy_direction_z = -1;
		m_Distance_Pos.z *= -1;
	}
	else
	{
		m_Enemy_direction_z = 1;
	}

	if (m_SetEnemy_Pos.x < 0)
	{
		// �����ʒu�Ƃ̕�����+-���C��
		m_Setenemy_direction_x = -1;
		// �����ʒu�Ƃ̋����A-��+�ɕύX
		m_SetEnemy_Pos.x *= -1;
	}
	else
	{
		m_Setenemy_direction_x = 1;
	}
	if (m_SetEnemy_Pos.z < 0)
	{
		m_Setenemy_direction_z = -1;
		m_SetEnemy_Pos.z *= -1;
	}
	else
	{
		m_Setenemy_direction_z = 1;
	}

	m_Enemy_MoveFlag = FALSE;

	// ��苗���ɂȂ��Player�̕��Ɍ���
	if (m_Distance_Pos.x <= 4000.0f && m_Distance_Pos.z <= 4000.0f)
	{
		// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F )��
		// �������l���R�c���f���� Y����]�l�Ƃ��Đݒ�
		MV1SetRotationXYZ(m_Enemy_ModelHandle, VGet(0.0f, m_Enemy_Angle + DX_PI_F, 0.0f));

		// ��苗���ɂȂ��Player�̕��Ɉړ�
		if (m_Distance_Pos.x <= 3000.0f && m_Distance_Pos.z <= 3000.0f)
		{
			if (m_Distance_Pos.x >= 300.0f) {
				m_Enemy_Position.x += m_Enemy_direction_x * m_Speed;
				m_Enemy_MoveFlag = TRUE;
			}
			if (m_Distance_Pos.z >= 300.0f) {
				m_Enemy_Position.z += m_Enemy_direction_z * m_Speed;
				m_Enemy_MoveFlag = TRUE;
			}
		}
	}
	else // �T�m�͈͊O�ɂȂ�Ə����ʒu�ɖ߂�
	{
		MV1SetRotationXYZ(m_Enemy_ModelHandle, VGet(0.0f, m_Initial_EnemyAngle + DX_PI_F, 0.0f));

		if (m_SetEnemy_Pos.x >= 0.1f) {
			m_Enemy_Position.x += m_Setenemy_direction_x * m_Speed;
			m_Enemy_MoveFlag = TRUE;
		}
		if (m_SetEnemy_Pos.z >= 0.1f) {
			m_Enemy_Position.z += m_Setenemy_direction_z * m_Speed;
			m_Enemy_MoveFlag = TRUE;
		}
	}

	m_PlayTime++;
	if (m_PlayTime >= m_Enemy_AnimTotalTime[ANIM_LIST::ANIM_RUN] || m_PlayTime >= m_Enemy_AnimTotalTime[ANIM_LIST::ANIM_WAIT])
	{
		m_PlayTime = 0.f;
	}
}

void Enemy::Draw()
{
		// �V�����A�j���[�V�������A�^�b�`
		if (m_Enemy_MoveFlag)
		{
			// �ړ�
			MV1SetAttachAnimTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_RUN], m_PlayTime);
		}
		else
		{
			// �ҋ@
			MV1SetAttachAnimTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex[ANIM_LIST::ANIM_WAIT], m_PlayTime);
		}

	MV1SetPosition(m_Enemy_ModelHandle, m_Enemy_Position);
	MV1DrawModel(m_Enemy_ModelHandle);
}


void Enemy::DrawHp()
{
}


