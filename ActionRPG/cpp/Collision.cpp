#include "../h/Collision.h"

Collision::Collision()
{
	Add = 8;

	y = 0;

	i = 0;

	KabeNum = 0;

	YukaNum = 0;
}

Collision::~Collision()
{
    // �����蔻����̌�n��
    //MV1CollResultPolyDimTerminate(HitPoly);
}

void Collision::Update(Player* player, Map* map)
{
	HitDim =  MV1CollCheck_Sphere(player->GetModel(), -1, player->GetPos(), 800.0f + player->MoveVector());

	// ���f���ƍU������
	MV1SetupCollInfo(player->GetModel(), -1, 8, 8, 8);

    // ���f���ƃ}�b�v�̓����蔻��
	//HitPoly = MV1CollCheck_Line(player->GetModel(), -1, SpherePos, 100.0f);

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



}

void Collision::Draw()
{
   
}