#ifndef Player_h_
#define Player_h_

#include"DxLib.h"

class Player
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
};


#endif // !Player_h_



