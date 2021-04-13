#ifndef Player_h_
#define Player_h_
#include"Base.h"

class Player :public Base
{
	//�A�j���[�V�������X�g
	enum ANIM_LIST
	{
		ANIM_RUN,

		ANIM_NUM,
	};

public:
	Player();		
	~Player() {}		

public:
	void Init();
	void Update();
	void Draw();
	void Move();

private:
	// ���f����ۑ�����ϐ�
	int   m_ModelHandle;

	//�A�j���[�V�����Ɏg�p����ϐ�
	int   m_AnimHandle[ANIM_NUM];
	int   m_AnimAttachIndex[ANIM_NUM];
	int   m_AnimTotalTime[ANIM_NUM];
	int   m_PlayTime;

	float m_Angle;
	float m_Radian;
	float m_Digree_X, m_Digree_Z;

};


#endif // !Player_h_



