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
	int m_MouseX;				// �}�E�X��X���W
	int m_MouseY;				// �}�E�X��Y���W
	int m_BeforeMouseX;			// 1�t���[���O�̃}�E�X��X���W
	int m_BeforeMouseY;			// 1�t���[���O�̃}�E�X��Y���W
	int m_FrameCounter;			// �t���[���J�E���^�[
	float	m_AngleH;			// �����p�x
	float	m_AngleV;			// �����p�x
	float   m_Speed;			// �ړ����x
	VECTOR	m_Pos;				// �J�������W
	VECTOR	m_Target;			// �����_���W
};


#endif