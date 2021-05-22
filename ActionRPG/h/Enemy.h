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
		Base(0.f, 0.9f, 10.f)
	{
		m_Speed = (10.f);
		m_Hp = (3.f);
	}

	Enemy(VECTOR pos) :
		Base(pos)
	{}

	~Enemy() {}

public:
	void Init(VECTOR value);
	void Update(VECTOR player_pos);
	void Draw();
	void DrawHp();

	bool IsActive;

private:
	//���f������ۑ�����ϐ�
	int    m_Enemy_ModelHandle;

	//�v�Z�Ŏg���ϐ�
	float  m_Enemy_Angle;
	float  m_Initial_EnemyAngle;
	float  m_Enemy_AnimTotalTime;
	float  m_Enemy_AnimNowTime;
	int    m_Enemy_AnimAttachIndex;
	int    m_Enemy_RunFlag;
	int    m_Enemy_MoveFlag;
	int    m_Enemy_MoveAnimFrameIndex;
	VECTOR m_Enemy_Position;
	VECTOR m_Enemy_InitialPosition;
	VECTOR m_SubVector;
	VECTOR m_Initial_EnemyVector;

	VECTOR m_Distance_Pos;
	VECTOR m_SetEnemy_Pos;
	// ���W��+-�̏C���p�ϐ�
	int m_Enemy_direction_x, m_Enemy_direction_z;
	int m_Setenemy_direction_x, m_Setenemy_direction_z;

};

#endif