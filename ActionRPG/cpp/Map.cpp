#include"../h/Map.h"

void Map::Init(int maphandle,int grhandle)
{
	
#pragma region �}�b�v���f���ǂݍ���
	//�����}�b�v���f��
	m_MapHandle = maphandle;
	//�����}�b�v�e�N�X�`��
	m_GrHandle[0] = grhandle;
	m_GrHandle[1] =  LoadGraph("Tex/Stage/ground.jpg");
	m_GrHandle[2] =  LoadGraph("Tex/Stage/bark.jpg");
	m_GrHandle[3] =  LoadGraph("Tex/Stage/wood.jpg");
	m_GrHandle[4] =  LoadGraph("Tex/Stage/wood kawa.jpg");
	m_GrHandle[5] =  LoadGraph("Tex/Stage/wood yuka.jpg");
	m_GrHandle[6] =  LoadGraph("Tex/Stage/wood kabe.jpg");
	m_GrHandle[7] =  LoadGraph("Tex/Stage/grass.jpg");
	m_GrHandle[8] =  LoadGraph("Tex/Stage/bridge.jpg");
	m_GrHandle[9] =  LoadGraph("Tex/Stage/water.jpg");

#pragma endregion
	//���f���ɓ\��e�N�X�`���̐�������for������
	for (int i = 0; i <10 ; i++)
	{
		MV1SetTextureGraphHandle(m_MapHandle, i, m_GrHandle[i], FALSE);
	}
}

void Map::Draw()
{
	MV1SetPosition(m_MapHandle, m_Pos);
	MV1DrawModel(m_MapHandle);
	//MV1SetPosition(m_LastMHandle, m_Pos);
	//MV1DrawModel(m_LastMHandle);
}

bool Map::CollisionToModel(VECTOR startpos,VECTOR endpos)
{
	//���f���S�̂̃R���W�������\�z
	MV1SetupCollInfo(m_MapHandle, -1, 8, 8, 8);
	//0�Ԗڂ̃t���[���̃R���W���������X�V����
	MV1RefreshCollInfo(m_MapHandle, 0);
	//-1�ԃt���[���ƃ��C�Ƃ̂����蔻��
	//m_Pos�͎n�_�Em_Line�͏I�_
	HitPoly = MV1CollCheck_Line(m_MapHandle, -1, startpos, endpos);

	//���������Ȃ炻�̈ʒu�����C�̏I�_�Ƃ���
	if (HitPoly.HitFlag == 1)
	{
		endpos = HitPoly.HitPosition;
	}
	if (HitPoly.HitFlag == 1)
	{
		// �����������ǂ�����\������
		DrawFormatString(1000, 200, GetColor(255, 255, 255), "HIT:%d", HitPoly.HitFlag);
	}
	else
	{
		DrawString(1000, 200, "�������ĂȂ�", GetColor(255, 255, 255));
	}
		return false;
}
