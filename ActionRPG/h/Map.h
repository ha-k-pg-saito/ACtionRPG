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
	void Init(int maphandle,int grhandle,int lastmaphandle,int lastmapgrhandle);
	void Draw();
	int GetModel(){ return m_MapHandle; }

private:
	//�}�b�v���f���ۑ��p�ϐ�
	int    m_MapHandle;
	//�}�b�v�ɓ\��e�N�X�`���ۑ��ϐ�
	int    m_GrHandle[7];
	//�{�X�X�e�[�W�̃��f���ۑ��ϐ�
	int    m_LastMHandle;
	//�{�X�X�e�[�W�̃e�N�X�`���ۑ��ϐ�
	int    m_LastMGrHandle[4];
	VECTOR m_Pos;
};

#endif