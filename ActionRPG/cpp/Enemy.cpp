#include"../h/Enemy.h"
#include"math.h"

void Enemy::Init(VECTOR pos)
{
	Enemy_ModelHandle = MV1LoadModel("DxChara.x");

	// �����Ă���t���O��|��
	Enemy_RunFlag = FALSE;

	// �ҋ@�A�j���[�V�������A�^�b�`
	Enemy_AnimAttachIndex = MV1AttachAnim(Enemy_ModelHandle, 4);

	// �ҋ@�A�j���[�V�����̑����Ԃ��擾���Ă���
	Enemy_AnimTotalTime = MV1GetAttachAnimTotalTime(Enemy_ModelHandle, Enemy_AnimAttachIndex);

	// �A�j���[�V�����Đ����Ԃ�������
	Enemy_AnimNowTime = 0.0f;
	MV1SetAttachAnimTime(Enemy_ModelHandle, Enemy_AnimAttachIndex, Enemy_AnimNowTime);

	// �A�j���[�V�����ňړ������Ă���t���[���̔ԍ�����������
	Enemy_MoveAnimFrameIndex = MV1SearchFrame(Enemy_ModelHandle, "BasePoint");

	// �A�j���[�V�����ňړ������Ă���t���[���𖳌��ɂ���
	MV1SetFrameUserLocalMatrix(Enemy_ModelHandle, Enemy_MoveAnimFrameIndex, MV1GetFrameLocalMatrix(Enemy_ModelHandle, Enemy_MoveAnimFrameIndex));

	// �R�c���f���̍��W��������
	Enemy_Position = VGet(pos.x, pos.y, pos.z);
	Enemy_InitialPosition = VGet(pos.x, pos.y, pos.z);

	IsActive = false;
}

void Enemy::Update(VECTOR player_pos)
{
	// �R�c���f���Q����R�c���f���P�Ɍ������x�N�g�����Z�o
	SubVector = VSub(player_pos, Enemy_Position);
	// �R�c���f���Q���珉���n�_�ւ̃x�N�g�����Z�o
	Initial_EnemyVector = VSub(Enemy_InitialPosition, Enemy_Position);

	// atan2 ���g�p���Ċp�x���擾
	Enemy_Angle = atan2(SubVector.x, SubVector.z);
	Initial_EnemyAngle = atan2(Initial_EnemyVector.x, Initial_EnemyVector.z);

	// �v���C���[�ƃG�l�~�[�̋���
	Distance_Pos.x = player_pos.x - Enemy_Position.x;
	Distance_Pos.z = player_pos.z - Enemy_Position.z;
	// �G�l�~�[�̏����ʒu�ƃG�l�~�[�̋���
	SetEnemy_Pos.x = Enemy_InitialPosition.x - Enemy_Position.x;
	SetEnemy_Pos.z = Enemy_InitialPosition.z - Enemy_Position.z;

	if (Distance_Pos.x < 0)
	{
		// �v���C���[�Ƃ̕�����+-���C��
		Enemy_direction_x = -1;
		// �v���C���[�Ƃ̋�����-��+�ɕύX
		Distance_Pos.x *= -1;
	}
	else
	{
		Enemy_direction_x = 1;
	}
	if (Distance_Pos.z < 0)
	{
		Enemy_direction_z = -1;
		Distance_Pos.z *= -1;
	}
	else
	{
		Enemy_direction_z = 1;
	}

	if (SetEnemy_Pos.x < 0)
	{
		// �����ʒu�Ƃ̕�����+-���C��
		Setenemy_direction_x = -1;
		// �����ʒu�Ƃ̋����A-��+�ɕύX
		SetEnemy_Pos.x *= -1;
	}
	else
	{
		Setenemy_direction_x = 1;
	}
	if (SetEnemy_Pos.z < 0)
	{
		Setenemy_direction_z = -1;
		SetEnemy_Pos.z *= -1;
	}
	else
	{
		Setenemy_direction_z = 1;
	}

	Enemy_MoveFlag = FALSE;

	// ��苗���ɂȂ�ƃv���C���[�̕��Ɍ���
	if (Distance_Pos.x <= 4000.0f && Distance_Pos.z <= 4000.0f)
	{
		// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F )��
		// �������l���R�c���f���� Y����]�l�Ƃ��Đݒ�
		MV1SetRotationXYZ(Enemy_ModelHandle, VGet(0.0f, Enemy_Angle + DX_PI_F, 0.0f));

		// ��苗���ɂȂ�ƃv���C���[�̕��Ɉړ�
		if (Distance_Pos.x <= 3000.0f && Distance_Pos.z <= 3000.0f)
		{
			if (Distance_Pos.x >= 300.0f) {
				Enemy_Position.x += Enemy_direction_x * m_Speed;
				Enemy_MoveFlag = TRUE;
			}
			if (Distance_Pos.z >= 300.0f) {
				Enemy_Position.z += Enemy_direction_z * m_Speed;
				Enemy_MoveFlag = TRUE;
			}
		}
	}
	else // �T�m�͈͊O�ɂȂ�Ə����ʒu�ɖ߂�
	{
		MV1SetRotationXYZ(Enemy_ModelHandle, VGet(0.0f, Initial_EnemyAngle + DX_PI_F, 0.0f));

		if (SetEnemy_Pos.x >= 0.1f) {
			Enemy_Position.x += Setenemy_direction_x * m_Speed;
			Enemy_MoveFlag = TRUE;
		}
		if (SetEnemy_Pos.z >= 0.1f) {
			Enemy_Position.z += Setenemy_direction_z * m_Speed;
			Enemy_MoveFlag = TRUE;
		}
	}

}

void Enemy::Draw()
{
	if (Enemy_RunFlag != Enemy_MoveFlag)
	{
		// �����Ă��邩�ǂ����̃t���O��ۑ�
		Enemy_RunFlag = Enemy_MoveFlag;

		// ���܂ŃA�^�b�`���Ă����A�j���[�V�������f�^�b�`
		MV1DetachAnim(Enemy_ModelHandle, Enemy_AnimAttachIndex);

		// �V�����A�j���[�V�������A�^�b�`
		if (Enemy_RunFlag)
		{
			Enemy_AnimAttachIndex = MV1AttachAnim(Enemy_ModelHandle, 1);
		}
		else
		{
			Enemy_AnimAttachIndex = MV1AttachAnim(Enemy_ModelHandle, 4);
		}

		// �A�j���[�V�����̑����Ԃ��擾���Ă���
		Enemy_AnimTotalTime = MV1GetAttachAnimTotalTime(Enemy_ModelHandle, Enemy_AnimAttachIndex);

		// �A�j���[�V�����Đ����Ԃ�������
		Enemy_AnimNowTime = 0.0f;
	}
	else
	{
		// �A�j���[�V�����Đ����Ԃ�i�߂�
		Enemy_AnimNowTime += 200.0f;

		// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
		if (Enemy_AnimNowTime >= Enemy_AnimTotalTime)
		{
			// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
			Enemy_AnimNowTime -= Enemy_AnimTotalTime;
		}
	}

	// �V�����A�j���[�V�����Đ����Ԃ��Z�b�g
	MV1SetAttachAnimTime(Enemy_ModelHandle, Enemy_AnimAttachIndex, Enemy_AnimNowTime);

	MV1SetPosition(Enemy_ModelHandle, Enemy_Position);
	MV1DrawModel(Enemy_ModelHandle);
}


void Enemy::DrawHp()
{
}


