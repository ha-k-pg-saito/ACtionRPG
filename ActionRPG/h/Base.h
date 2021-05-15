#ifndef Base_h_ 
#define Base_h_

#include"DxLib.h"

class Base
{
public:
	Base();		

	Base(float x, float y, float z);

	Base(VECTOR pos);

	virtual ~Base() {}		

//�p���֘A��protected���g�p
protected:				
	VECTOR m_Pos;		//�|�W�V����
	float   m_Hp;		//Hp
	float  m_Speed;		//�X�s�[�h
};


#endif