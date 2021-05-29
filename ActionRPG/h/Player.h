#ifndef Player_h_
#define Player_h_
#include"Base.h"
#include"DxLib.h"
#include"../h/Map.h"

//�A�j���[�V�������X�g


class Player :public Base
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
	Player() :
		//Base()���ŏ��������Ă���̂̓|�W�V�����ϐ�
		Base(0.f, 0.f, 0.f),
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_AnimHandle{ 0 },
		m_Direction{ 0 }
	{
		m_Speed = 100.f;
		m_Hp = 0.f;
		m_HitCounter = 0;
		m_Gravity = 9.8f;
	}
	Player(VECTOR pos) :
		Base(pos)
	{}

	~Player() { Release(); }

public:
	// �v���C���[�̃��f���擾
	int    GetModel() { return m_ModelHandle; }
	//�v���C���[�̍��W��擾
	VECTOR GetPos() { return m_Pos; }
	// �v���C���[�̈ړ��x�N�g���擾
	VECTOR MoveVecter() { return m_MoveVec; }

public:
	//Init�̈����̓��f���ǂݍ��ގ��Ɏg��
	void Init(int modelhandle, int grhandle);
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

	//�d��
	float m_Gravity;

	//���������񐔂�ۑ�����ϐ�
	int m_HitCounter;
	//�L�����̈ړ��ʕۑ��ϐ�
	VECTOR m_MoveVec;       
	//���C�̏I�_�Ɏg���ϐ�
	VECTOR m_Line;
	
	//�}�b�v�N���X�̃C���X�^���X��
	Map map;
	
};
#endif // !Player_h_



