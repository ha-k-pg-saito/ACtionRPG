#ifndef Base_h_ 
#define Base_h_

#include"DxLib.h"

class Base
{
public:
	Base();				//�R���X�g���N�^

	Base(float x, float y, float z);

	Base(VECTOR pos);

	~Base() {}			//�f�X�g���N�^

protected:				//�p���֘A��protected���g�p
	VECTOR m_Pos;		//�|�W�V����
	float  m_Hp;		//Hp
	float  m_Speed;		//�X�s�[�h
};


#endif