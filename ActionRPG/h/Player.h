#ifndef Player_h_
#define Player_h_
#include"Base.h"
#include"DxLib.h"

class Player :public Base
{
	//�A�j���[�V�������X�g
	enum ANIM_LIST
	{
		//����A�j���[�V����
		ANIM_RUN,

		ANIM_NUM,
	};

public:
	Player():
		//Base()�ŏ��������Ă���̂̓|�W�V�����ϐ�
		Base(0.f, 0.9f, 0.f),
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_AnimHandle{ 0 },
		m_Direction{0}
	{
		m_Speed = (20.f);
		m_Hp = (3.f);
	}
	Player(VECTOR pos) :
		Base(pos)
	{}

	~Player() { }

public:
	void Init(int modelhandle, int grhandle);
	void Update();
	void Draw();
	void DrawHP(); 

private:
	void Rotate();
	// �����@�ړ��������Ƃ����
	void Move();
	
public:
	//�v���C���[�̍��W��擾
	VECTOR GetPos() { return m_Pos; }
	// �v���C���[�̃��f���擾
	int GetModel() { return m_ModelHandle; }

private:
	// ���f����ۑ�����ϐ�
	int m_ModelHandle;
	int m_GrHandle[8];

	//�A�j���[�V�����Ɏg�p����ϐ�
	int   m_AnimHandle[ANIM_NUM];
	int   m_AnimAttachIndex[ANIM_NUM];
	int   m_AnimTotalTime[ANIM_NUM];
	float m_PlayTime;						//�A�j���[�V��������

	//�v�Z�Ŏg���ϐ�
	float  m_Radian;		
	float  m_Digree_Y;	
	VECTOR m_Direction;		//�����Ă������
};


#endif // !Player_h_



