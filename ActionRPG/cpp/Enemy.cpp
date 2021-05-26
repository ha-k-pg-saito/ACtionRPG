#include"../h/Enemy.h"
#include"math.h"

void Enemy::Init()
{
	m_Enemy_ModelHandle = MV1LoadModel("DxChara.x");

	m_Enemy_RunFlag = FALSE;

	// �ҋ@�A�j���[�V�������A�^�b�`
	m_Enemy_AnimAttachIndex = MV1AttachAnim(m_Enemy_ModelHandle, 4);

	// �ҋ@�A�j���[�V�����̑����Ԃ��擾���Ă���
	m_Enemy_AnimTotalTime = MV1GetAttachAnimTotalTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex);

	// �A�j���[�V�����Đ����Ԃ�������
	m_Enemy_AnimNowTime = 0.0f;
	MV1SetAttachAnimTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex, m_Enemy_AnimNowTime);

	// �A�j���[�V�����ňړ������Ă���t���[���̔ԍ�����������
	m_Enemy_MoveAnimFrameIndex = MV1SearchFrame(m_Enemy_ModelHandle, "BasePoint");

	// �A�j���[�V�����ňړ������Ă���t���[���𖳌��ɂ���
	MV1SetFrameUserLocalMatrix(m_Enemy_ModelHandle, m_Enemy_MoveAnimFrameIndex, MV1GetFrameLocalMatrix(m_Enemy_ModelHandle, m_Enemy_MoveAnimFrameIndex));

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
	m_SubVector = VSub(player_pos, m_Enemy_Position);
	// �R�c���f��Enemy���珉���n�_�ւ̃x�N�g�����Z�o
	m_Initial_EnemyVector = VSub(m_Enemy_InitialPosition, m_Enemy_Position);

	// atan2 ���g�p���Ċp�x���擾
	m_Enemy_Angle = atan2(m_SubVector.x, m_SubVector.z);
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

}

void Enemy::Draw()
{
	if (m_Enemy_RunFlag != m_Enemy_MoveFlag)
	{
		// �����Ă��邩�ǂ����̃t���O��ۑ�
		m_Enemy_RunFlag = m_Enemy_MoveFlag;

		// ���܂ŃA�^�b�`���Ă����A�j���[�V�������f�^�b�`
		MV1DetachAnim(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex);

		// �V�����A�j���[�V�������A�^�b�`
		if (m_Enemy_RunFlag)
		{
			// �ړ�
			m_Enemy_AnimAttachIndex = MV1AttachAnim(m_Enemy_ModelHandle, 1);
		}
		else
		{
			// �ҋ@
			m_Enemy_AnimAttachIndex = MV1AttachAnim(m_Enemy_ModelHandle, 4);
		}

		// �A�j���[�V�����̑����Ԃ��擾���Ă���
		m_Enemy_AnimTotalTime = MV1GetAttachAnimTotalTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex);

		// �A�j���[�V�����Đ����Ԃ�������
		m_Enemy_AnimNowTime = 0.0f;
	}
	else
	{
		// �A�j���[�V�����Đ����Ԃ�i�߂�
		m_Enemy_AnimNowTime += 200.0f;

		// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
		if (m_Enemy_AnimNowTime >= m_Enemy_AnimTotalTime)
		{
			// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
			m_Enemy_AnimNowTime -= m_Enemy_AnimTotalTime;
		}
	}

	// �V�����A�j���[�V�����Đ����Ԃ��Z�b�g
	MV1SetAttachAnimTime(m_Enemy_ModelHandle, m_Enemy_AnimAttachIndex, m_Enemy_AnimNowTime);

	MV1SetPosition(m_Enemy_ModelHandle, m_Enemy_Position);
	MV1DrawModel(m_Enemy_ModelHandle);
}


void Enemy::DrawHp()
{
}


