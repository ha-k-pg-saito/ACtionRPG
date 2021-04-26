#ifndef Camera_h_
#define Camera_h_
#include"DxLib.h"
#include"../h/Player.h"
class Camera 
{
public:
	Camera();
	~Camera();

	void Update(Player* player);

private:
	//VECTOR  m_Pos;
	//float	m_Radius;
	//float	m_Angle;
	//float	m_Length;

	float	m_AngleH;			// �����p�x
	float	m_AngleV;			// �����p�x
	float   m_Speed;			// �ړ����x
	VECTOR	m_Pos;				// �J�������W
	VECTOR	m_Target;			// �����_���W
};


#endif