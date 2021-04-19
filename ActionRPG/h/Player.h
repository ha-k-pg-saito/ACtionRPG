#ifndef Player_h_
#define Player_h_
#include"Base.h"

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
	Player();		
	~Player() {}		

public:
	void Init();
	void Update();
	void Draw();
	void Move();
	void HP();

private:
	// ���f����ۑ�����ϐ�
	int   m_ModelHandle;

	//�A�j���[�V�����Ɏg�p����ϐ�
	int   m_AnimHandle[ANIM_NUM];
	int   m_AnimAttachIndex[ANIM_NUM];
	int   m_AnimTotalTime[ANIM_NUM];
	int   m_PlayTime;						//�A�j���[�V��������

	//�v�Z�Ŏg���ϐ�
	float m_Radian;						//�p�x	
	float m_Digree_X, m_Digree_Z;		//�����x�N�g���̕ۑ�

};


#endif // !Player_h_



