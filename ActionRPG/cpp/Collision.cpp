#include "../h/Collision.h"

Collision::Collision()
{
	Add = 8;

	y = 0;

	i = 0;
}

Collision::~Collision()
{
    // �����蔻����̌�n��
    MV1CollResultPolyDimTerminate(HitPolyDim);
}

void Collision::Update(Player* player)
{
	// �R�c���f���̈ړ��ʒu���㉺�Ɉړ�������
	y += Add;
	if (y < 0 || y > 600)
		Add = -Add;

	// ���f���S�̂̃R���W�������\�z
	MV1SetupCollInfo(player->GetModel(), -1, 8, 8, 8);

	// �����蔻����s�����̈ʒu���Z�b�g�i���j
	SpherePos = VGet(250.0f, y, 600.0f);

	// ���f���Ƌ��Ƃ̓����蔻��i���j
	HitPolyDim = MV1CollCheck_Sphere(player->GetModel(), -1, SpherePos, 100.0f);

    // �����������ǂ����ŏ����𕪊�i���j
    if (HitPolyDim.HitNum >= 1)
    {
        // ���������ꍇ�͏Փ˂̏���`�悷��

        // ���������|���S���̐���`��
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Hit Poly Num   %d", HitPolyDim.HitNum);

        // ���������|���S���̐������J��Ԃ�
        for (i = 0; i < HitPolyDim.HitNum; i++)
        {
            // ���������|���S����`��
            DrawTriangle3D(
                HitPolyDim.Dim[i].Position[0],
                HitPolyDim.Dim[i].Position[1],
                HitPolyDim.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);
        }
    }

}

void Collision::Draw()
{
    // ���̕`��(���j
    DrawSphere3D(SpherePos, 100.0f, 8, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
}