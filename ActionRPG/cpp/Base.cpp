#include"../h/Base.h"

//�����o�C�j�V�����C�U�ɂă����o�ϐ�������
Base::Base() :
	m_Pos{0.f},
	m_Hp{0.f},
	m_Speed{0.f}
{
}

Base::Base(float x, float y, float z) :
	m_Pos(VGet(x, y, z)),
	m_Hp{ 0.f },
	m_Speed{ 0.f }
{
}

Base::Base(VECTOR pos) :
	m_Pos(pos),
	m_Hp{ 0.f },
	m_Speed{ 0.f }
{
}

