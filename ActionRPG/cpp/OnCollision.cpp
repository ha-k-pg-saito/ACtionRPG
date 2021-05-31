#include "..\h\OnCollision.h"
#include"../h/Player.h"

void OnColl::Init(Player* player)
{
	//�@player�̃��f���n���h��,�t���[���ԍ�,XYZ�̋�ԕ���
	MV1SetupCollInfo(player->GetModel(), -1, 1, 1, 1);
	//MV1SetupCollInfo(enemy->GetModel(), -1, 1, 1, 1);

}

void OnColl::Update(Player* player)
{
    MV1RefreshCollInfo(player->GetModel(), -1);
	SpherePos = VGet( 100.f, 0.f, 100.f );

	HitPolyDim = MV1CollCheck_Sphere(player->GetModel(), -1, SpherePos, 100.f);

	DrawSphere3D(SpherePos, 10.f, 8, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

    // �����������ǂ����ŏ����𕪊�
    if (HitPolyDim.HitNum >= 1)
    {
        // ���������ꍇ�͏Փ˂̏���`�悷��

        // ���������|���S���̐���`��
        DrawFormatString(100, 200, GetColor(255, 255, 255), "Hit Poly Num   %d", HitPolyDim.HitNum);

        // ���������|���S���̐������J��Ԃ�
        for (int i = 0; i < HitPolyDim.HitNum; i++)
        {
            // ���������|���S����`��
            DrawTriangle3D(
                HitPolyDim.Dim[i].Position[0],
                HitPolyDim.Dim[i].Position[1],
                HitPolyDim.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);
        }
    }

}
