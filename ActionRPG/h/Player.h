#ifndef Player_h_
#define Player_h_
#include"Base.h"

class Player :public Base
{
	//�V���O���g��
public:
	static Player* Instance()
	{
		static Player instance;
		return&instance;
	}

public:
	void Update();
	void Draw();
	void Move();

private:
	Player();
	// ���f����ۑ�����ϐ�
	int   m_Player;
	float m_Angle;
	float m_Radian;
	float m_Digree_X, m_Digree_Y;

};


#endif // !Player_h_



