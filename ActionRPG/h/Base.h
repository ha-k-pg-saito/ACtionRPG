#ifndef Base_h_ 
#define Base_h_

#include"DxLib.h"

class CharBase
{
public:
	CharBase();		

	CharBase(float x, float y, float z,float hp,float speed);

	CharBase(VECTOR pos, float hp, float speed);

	virtual ~CharBase() {}		

//�p���֘A��protected���g�p
protected:				
	VECTOR m_Pos;		//�|�W�V����
	float   m_Hp;		//Hp
	float  m_Speed;		//�X�s�[�h
};
#endif