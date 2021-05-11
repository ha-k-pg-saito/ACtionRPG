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

void Collision::Update(Player* player, Map* map)
{
	// �R�c���f���̈ړ��ʒu���㉺�Ɉړ�������
	y += Add;
	if (y < 0 || y > 600)
		Add = -Add;

	// ���f���ƍU������
	MV1SetupCollInfo(player->GetModel(), -1, 8, 8, 8);

    // ���f���ƃ}�b�v�̓����蔻��
    MV1SetupCollInfo(map->GetModel(), -1, 8, 8, 8);
	
	// ���f���Ƌ��Ƃ̓����蔻��i���j
	HitPolyDim = MV1CollCheck_Sphere(player->GetModel(), -1, SpherePos, 100.0f);

    // �����������ǂ����ŏ����𕪊�
    if (HitPolyDim.HitNum >= 1)
    {
        
    }

}

void Collision::Draw()
{
   
}