#include"../h/Camera.h"

Camera::Camera()
{
	m_Pos = VGet(340.f, 480.f, 400.f);		//VGet�ɂ����m_Pos��x,y,z�̒l���
	SetCameraNearFar(1.f, 150.f);			//�J�����̕`�拗��
	SetCameraPositionAndTargetAndUpVec(
		VGet(0.f, 0.f, -800.f),				//���_��Z��-800�̈ʒu
		VGet(0.f, 0.f, 0.f),				//�����_�͌��_
		VGet(0.f,0.f,0.f));					//�����
}

void Camera::Update()
{

}

void Camera::Move()
{


}

void Camera::Draw()
{


}
