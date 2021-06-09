#ifndef Map_h_
#define Map_h_

#include"DxLib.h"

class Map
{
public:
	Map() :
		m_MapHandle(0),
		m_StagePos{ 71,-10,462 },
		HitPoly{ 0 }
	{}
	~Map() {}

public:	
	//���f������n���Q�b�^�[
	int GetModel(){ return m_MapHandle; }

public:
	void Init();
	void Draw();
	bool CollisionToModel(VECTOR startpos, VECTOR endpos,VECTOR* intersectpos);

private:
	//�}�b�v���f���ۑ��p�ϐ�
	int    m_MapHandle;
	//�}�b�v�ɓ\��e�N�X�`���ۑ��ϐ�
	int    m_GrHandle[10];
	VECTOR m_StagePos;
	//DxLib�ɂ��邠���蔻��p�̖߂�l+�ϐ�
	MV1_COLL_RESULT_POLY HitPoly;

#define MAP_TEX_NUM      10
};
#endif