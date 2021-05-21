#ifndef Player_h_
#define Player_h_
#include"Base.h"
#include"DxLib.h"
#include"../h/Map.h"

class Player :public Base
{
	//�A�j���[�V�������X�g
	enum ANIM_LIST
	{
		//����A�j���[�V����
		ANIM_RUN,
		ANIM_ATTACK,
		ANIM_NUM,
	};

public:
	Player():
		//Base()���ŏ��������Ă���̂̓|�W�V�����ϐ�
		Base(0.f, 0.9f, 0.f),
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_AnimHandle{ 0 },
		m_Direction{0}
	{
		m_Speed = (100.f);
		m_Hp = (0.f);
		m_HitCounter = (0);
	}
	Player(VECTOR pos) :
		Base(pos)
	{}

	~Player() { Release(); }

public:
	//Init�̈����̓��f���ǂݍ��ގ��Ɏg��
	void Init(int modelhandle, int grhandle);
	void Update();
	void Draw();
	void DrawHP(); 
	void Release();
	void Attack();


private:
	void Rotate();
	// �����@�ړ��������Ƃ����
	void Move();
	
public:
	//�v���C���[�̍��W��擾
	VECTOR GetPos() { return m_Pos; }
	// �v���C���[�̃��f���擾
	int GetModel() { return m_ModelHandle; }
	// �v���C���[�̈ړ��x�N�g���擾
	VECTOR MoveVecter() { return Move_Vec; }

private:
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
<<<<<<< HEAD
	VECTOR m_Direction;		

	//���C�̕`��Ɏg���ϐ�
	VECTOR m_Line;

	//���������񐔂�ۑ�����ϐ�
	int m_HitCounter;

	//�}�b�v�N���X�̃C���X�^���X��
	Map map;
=======
	VECTOR m_Direction;		//�����Ă������
	VECTOR Move_Vec;        //�L�����̈ړ��x�N�g��
>>>>>>> Collision
};


#endif // !Player_h_



