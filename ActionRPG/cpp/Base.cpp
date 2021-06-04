#include"../h/Base.h"

//�����o�C�j�V�����C�U�ɂă����o�ϐ�������
CharBase::CharBase() :
	m_Pos{0.f},
	m_Hp{0.f},
	m_Speed{0.f}
{
}

CharBase::CharBase(float x, float y, float z,float hp,float speed) :
	m_Pos(VGet(x, y, z)),
	m_Hp{ hp },
	m_Speed{ speed }
{
}

CharBase::CharBase(VECTOR pos, float hp, float speed) :
	m_Pos(pos),
	m_Hp{ hp },
	m_Speed{ speed }
{
}

