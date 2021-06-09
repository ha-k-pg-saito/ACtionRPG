#ifndef Enemy_h_
#define Enemy_h_
#include"DxLib.h"
#include"Base.h"
#include"../h/Map.h"
#include"../h/Animation.h"

class Enemy :public CharBase
{
public:
	Enemy() :
		CharBase({ 0.f, 0.9f, 0.f }, 3, 0.5f)
	{
		m_EnemyHeight = { 0.f,2.f,0 };
	}

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
	void SetPos(VECTOR setpos) { m_Enemy_Position = setpos; }

private:
	int    m_Enemy_ModelHandle;		//���f������ۑ�����ϐ�

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
	Animation Anim;

	VECTOR m_EnemyHeight;
};
#endif