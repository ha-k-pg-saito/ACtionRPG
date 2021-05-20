#ifndef Map_h_
#define Map_h_

#include"DxLib.h"

class Map
{
public:
	Map() :
		m_MapHandle(0),
		m_Pos{71,0,462}
	{}
	~Map() {}

public:
	void Init(int maphandle,int grhandle);
	void Draw();
	int GetModel(){ return m_MapHandle; }
	bool CollisionToModel(VECTOR startpos, VECTOR endpos);

private:
	//�}�b�v���f���ۑ��p�ϐ�
	int    m_MapHandle;
	//�}�b�v�ɓ\��e�N�X�`���ۑ��ϐ�
	int    m_GrHandle[10];
	VECTOR m_Pos;
	//DxLib�ɂ��邠���蔻��p�̖߂�l+�ϐ�
	MV1_COLL_RESULT_POLY HitPoly;
};

#endif