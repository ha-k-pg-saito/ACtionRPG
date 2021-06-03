#ifndef Enemy_h_
#define Enemy_h_
#include"DxLib.h"
#include"Base.h"
#include"../h/Map.h"

class Enemy :public CharBase
{
public:
	//�A�j���[�V�������X�g
	enum ANIM_LIST
	{

		ANIM_RUN,

		ANIM_WAIT,

		ANIM_NUM
	};

public:
	Enemy() :
		CharBase(0.f, 0.9f, 0.f)
	{
		m_Speed = (0.5f);
		m_Hp = (3.f);
		m_EnemyHeight = { 0.f,2.f,0 };
	}

	Enemy(VECTOR pos) :
		CharBase(pos)
	{}

	~Enemy() {}

public:
	void Init();
	void Update(VECTOR player_pos);
	void Draw();
	void DrawHp();

	bool IsActive;

	int GetModel() { return m_Enemy_ModelHandle; }
	VECTOR GetPos() { return m_Enemy_Position; }
	VECTOR GetHeight() { return m_EnemyHeight; }


private:
	int    m_Enemy_ModelHandle;		//���f������ۑ�����ϐ�
	int   m_Enemy_AnimHandle[ANIM_NUM];
	int   m_Enemy_AnimAttachIndex[ANIM_NUM];
	int   m_Enemy_AnimTotalTime[ANIM_NUM];
	float m_PlayTime;				//�A�j���[�V��������

	//�v�Z�Ŏg���ϐ�
	float  m_Enemy_Angle;
	float  m_Initial_EnemyAngle;
	int    m_Enemy_MoveFlag;
	int    m_Enemy_MoveAnimFrameIndex;
	VECTOR m_Enemy_Position;
	VECTOR m_Rand_Pos;	// �����ۑ��p
	VECTOR m_Enemy_InitialPosition;
	VECTOR m_Vector;
	VECTOR m_Initial_EnemyVector;

	VECTOR m_Distance_Pos;
	VECTOR m_SetEnemy_Pos;
	// ���W��+-�̏C���p�ϐ�
	int m_Enemy_direction_x, m_Enemy_direction_z;
	int m_Setenemy_direction_x, m_Setenemy_direction_z;

	//���C�̎n�_�Ɏg���ϐ�
	VECTOR m_StartLine;
	VECTOR m_EndLine;

	Map m_MapRef;

	VECTOR m_EnemyHeight;
};

#endif