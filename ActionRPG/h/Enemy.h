#ifndef Enemy_h_
#define Enemy_h_
#include"DxLib.h"
#include"Base.h"

class Enemy :public Base
{
public:
	//�A�j���[�V�������X�g
	enum ANIM_LIST
	{

		ANIM_RUN,

		ANIM_NUM
	};

public:
	Enemy() :
		Base(0.f, 0.9f, 10.f),
		m_Radian(0.f),
		m_Digree_Y(0.f),
		m_Direction{0}
	{
		m_Speed = (10.f);
		m_Hp = (3.f);
	}

	Enemy(VECTOR pos) :
		Base(pos)
	{}

		~Enemy() {}

public:
	void Init();
	void Update();
	void Draw();
	void DrawHp();

private:
	//���f�����ۑ�����ϐ�
	int m_MHandle;

	//�v�Z�Ŏg���ϐ�
	float  m_Radian;
	float  m_Digree_Y;
	VECTOR m_Direction;

};

#endif