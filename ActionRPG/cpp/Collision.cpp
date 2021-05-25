#include "../h/Collision.h"

Collision::Collision()
{
	Add = 8;

	y = 0;

	i = 0;

	KabeNum = 0;

	YukaNum = 0;

	MoveFlag = 0;
}

Collision::~Collision()
{
    // �����蔻����̌�n��
    //MV1CollResultPolyDimTerminate(HitPoly);
	//MV1CollResultPolyDimTerminate(HitDim);
}

void Collision::Update(Player* player)
{
	HitDim =  MV1CollCheck_Sphere(player->GetModel(), -1, player->GetPos(), PLAYER_ENUM_DEFAULT_SIZE + VSize(player->MoveVecter()));

	NowPos = VAdd(player->GetPos(), player->MoveVecter());

	//HitPoly = MV1CollCheck_Line(player->GetModel(), -1, SpherePos, 100.0f);

	if (fabs(player->MoveVecter().x) > 0.01f || fabs(player->MoveVecter().z) > 0.01f)
	{
		MoveFlag = 1;
	}
	else
	{
		MoveFlag = 0;
	}

	for (i = 0; i < HitDim.HitNum; i++)
	{
		// �w�y���ʂɐ������ǂ����̓|���S���̖@���̂x�������O�Ɍ���Ȃ��߂����ǂ����Ŕ��f����
		if (HitDim.Dim[i].Normal.y < 0.000001f && HitDim.Dim[i].Normal.y > -0.000001f)
		{
			// �ǃ|���S���Ɣ��f���ꂽ�ꍇ�ł��A�L�����N�^�[�̂x���W�{�P�D�O����荂���|���S���̂ݓ����蔻����s��
			if (HitDim.Dim[i].Position[0].y > player->GetPos().y + 1.0f ||
				HitDim.Dim[i].Position[1].y > player->GetPos().y + 1.0f ||
				HitDim.Dim[i].Position[2].y > player->GetPos().y + 1.0f)
			{
				// �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
				if (KabeNum < 2048)
				{
					// �|���S���̍\���̂̃A�h���X��ǃ|���S���|�C���^�z��ɕۑ�����
					Kabe[KabeNum] = &HitDim.Dim[i];

					// �ǃ|���S���̐������Z����
					KabeNum++;
				}
			}
		}
		else
		{
			// �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
			if (YukaNum < CHARA_MAX_HITCOLL)
			{
				// �|���S���̍\���̂̃A�h���X�����|���S���|�C���^�z��ɕۑ�����
				Yuka[YukaNum] = &HitDim.Dim[i];

				// ���|���S���̐������Z����
				YukaNum++;
			}
		}
	}

	// ���|���S���Ƃ̓����蔻��
	if (YukaNum != 0)
	{
			float MaxY;

			// ���~�����W�����v���ł͂Ȃ��ꍇ�̏���

			// ���|���S���ɓ����������ǂ����̃t���O��|���Ă���
			HitFlag = 0;

			// ��ԍ������|���S���ɂԂ���ׂ̔���p�ϐ���������
			MaxY = 0.0f;

			// ���|���S���̐������J��Ԃ�
			for (i = 0; i < YukaNum; i++)
			{
				// i�Ԗڂ̏��|���S���̃A�h���X�����|���S���|�C���^�z�񂩂�擾
				Poly = Yuka[i];

				
					// �����Ă���ꍇ�͓��̐悩�炻�������Ⴂ�ʒu�̊Ԃœ������Ă��邩�𔻒�( �X�΂ŗ�����ԂɈڍs���Ă��܂�Ȃ��� )
					//LineRes = HitCheck_Line_Triangle(VAdd(NowPos, VGet(0.0f, PLAYER_HIT_HEIGHT, 0.0f)), VAdd(NowPos, VGet(0.0f, -40.0f, 0.0f)), Poly->Position[0], Poly->Position[1], Poly->Position[2]);
				

				// �������Ă��Ȃ������牽�����Ȃ�
				if (LineRes.HitFlag == FALSE) continue;

				// ���ɓ��������|���S��������A�����܂Ō��o�������|���S�����Ⴂ�ꍇ�͉������Ȃ�
				if (HitFlag == 1 && MaxY > LineRes.Position.y) continue;

				// �|���S���ɓ��������t���O�𗧂Ă�
				HitFlag = 1;

				// �ڐG�����x���W��ۑ�����
				MaxY = LineRes.Position.y;
			}

			// ���|���S���ɓ����������ǂ����ŏ����𕪊�
			if (HitFlag == 1)
			{
				// ���������ꍇ

				// �ڐG�����|���S���ň�ԍ����x���W���v���C���[�̂x���W�ɂ���
				NowPos.y = MaxY;

			}
	} 

	// �V�������W��ۑ�����
	player->GetPos() = NowPos;

	// �v���C���[�̃��f���̍��W���X�V����
	MV1SetPosition(player->GetModel(), player->GetPos());
}

void Collision::Draw()
{
   
}