#ifndef Player_h_
#define Player_h_
#include"Base.h"
#include"DxLib.h"
#include"../h/Map.h"
#include"../h/Enemy.h"

class Player :public CharBase
{
	//�A�j���[�V�������Ǘ�����enum
	enum ANIM_LIST
	{
		ANIM_WAIT,
		ANIM_RUN,
		ANIM_ATTACK,
		ANIM_DAMAGE,
		ANIM_DIED,
		ANIM_NUM,
	};

public:
	Player(Map* map) :
		//CharBase({pos},hp,speed)�����������Ă���
		CharBase({ 0.f, 0.f, 0.f }, 0, 40.f), 
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_AnimHandle{ 0 },
		m_Direction{ 0 },
		m_HitCounter{0},
		m_HeightCapsule { 0.f,6.f,0 }
	{
		m_MapRef = map;
	}
	Player(VECTOR pos, float hp, float speed) :
		CharBase(pos, hp, speed)
	{}

	~Player() { Release(); }

public:
// �v���C���[�̃��f���擾
	int    GetModel() { return m_ModelHandle; }
	VECTOR SetPos(VECTOR movevec) { return m_MoveVec; }
//�v���C���[�̍��W��擾
	VECTOR GetPos() { return m_Pos; }
// �v���C���[�̈ړ��x�N�g���擾
	VECTOR GetMoveVec() { return m_MoveVec; }
//�v���C���̍������擾
	VECTOR GetHeight() { return m_HeightCapsule; }

public:
	void Init();
	void Update();
	void Draw();
	void DrawHP(); 
	void Release();
	void Attack();

private:
//player�̊֐����ŌĂяo���֐�
	void Rotate();
	void Move();
	void Damage();

private:
// 3D���f����ۑ�����ϐ�
	int m_ModelHandle;
//3D���f���ɓ\��e�N�X�`���ۑ��ϐ�
	int m_GrHandle[8];

//�A�j���[�V�����Ɏg�p����ϐ�
	int   m_AnimHandle[ANIM_NUM];
	int   m_AnimAttachIndex[ANIM_NUM];
	int   m_AnimTotalTime[ANIM_NUM];
	float m_PlayTime;						//�A�j���[�V��������

//�v�Z�Ŏg���ϐ�
	float  m_Radian;		
	float  m_Digree_Y;	
	VECTOR m_Direction;	

//���������񐔂�ۑ�����ϐ�
	int m_HitCounter;
//�L�����̈ړ��ʕۑ��ϐ�
	VECTOR m_MoveVec;       
//���C�̎n�_�Ɏg���ϐ�
	VECTOR m_StartLine;
	VECTOR m_EndLine;
//�J�v�Z���̓����蔻��Ŏg�p����ϐ�
	VECTOR m_HeightCapsule;

	Map* m_MapRef;
	
//Player�̃e�N�X�`����
#define PLAYER_TEX_NUM  8
};
#endif // !Player_h_



