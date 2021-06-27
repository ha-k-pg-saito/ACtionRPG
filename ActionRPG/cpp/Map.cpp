#include"../h/Map.h"

void Map::Init()
{
#pragma region �}�b�v�֘A�ǂݍ���
	const char* file_name[]
	{
		"Tex/Stage/rock.jpg",
		"Tex/Stage/ground.jpg",
		"Tex/Stage/bark.jpg",
		"Tex/Stage/wood.jpg",
		"Tex/Stage/wood kawa.jpg",
		"Tex/Stage/wood yuka.jpg",
		"Tex/Stage/wood kabe.jpg",
		"Tex/Stage/grass.jpg",
		"Tex/Stage/bridge.jpg",
		"Tex/Stage/water.jpg"
	};

	for (int i = 0; i < MAP_TEX_NUM; i++)
	{
		m_GrHandle[i] = LoadGraph(file_name[i]);
	}

	//�����}�b�v���f��
	m_MapHandle = MV1LoadModel("Tex/Stage/map2.mv1");

#pragma endregion
	//���f���ɓ\��e�N�X�`���̐�������for������
	for (int i = 0; i <MAP_TEX_NUM ; i++)
	{
		MV1SetTextureGraphHandle(m_MapHandle, i, m_GrHandle[i], FALSE);
	}
	//���Ƃ��Ƃ̃}�b�v�f�[�^��100�{���Ă���
	VECTOR Scale{ 100.f,100.f,100.f };
	MV1SetScale(m_MapHandle, Scale);
	MV1SetPosition(m_MapHandle, m_StagePos);
	//���f���S�̂̃R���W�������\�z
	MV1SetupCollInfo(m_MapHandle, -1, 8, 8, 8);
}

void Map::Draw()
{
	MV1DrawModel(m_MapHandle);
}

//�}�b�v�ƃ��C�̂����蔻��
//Player�����łȂ�Enemy�ł��g�p����
bool Map::CollisionToModel(VECTOR startpos, VECTOR endpos, VECTOR* intersectpos)
{
	//-1�ԃt���[���ƃ��C�Ƃ̂����蔻��
	//m_Pos�͎n�_�Em_Line�͏I�_
	HitPoly = MV1CollCheck_Line(m_MapHandle, -1, startpos, endpos);

	if (HitPoly.HitFlag == 0)
	{	
		return false;
	}

	if (intersectpos != nullptr)
	{
		*intersectpos= HitPoly.HitPosition;
	}

	return true;

}
