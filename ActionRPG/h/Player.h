#ifndef Player_h_
#define Player_h_
#include"Base.h"

class Player:public Base
{
	//�V���O���g��
public :
	static Player* Instance()
	{
		static Player instance;
		return& instance;
	}

public:
	void Update();
	void Draw();

private:
	// ���f����ۑ�����ϐ�
	int m_Player;
	Player() {}
};


#endif // !Player_h_



