#include"../h/Camera.h"
#include<math.h>

Camera::Camera()
{
    m_Pos = VGet(0.f, 85.f, 200.f);		//VGet�ɂ����m_Pos��x,y,z�̒l���
    m_Radius = 0.f;                     //���a
    m_Angle = 0.f;                      //�p�x
    m_Length = 200.f;                   //���a�̒���
}

void Camera::Update()
{

    if (CheckHitKey(KEY_INPUT_LEFT) == 1)
    {

        m_Angle -= 8.f;
        if (m_Angle < 0.f)
        {
            m_Angle += 360.f;
        }
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
    {

        m_Angle += 8.f;
        if (m_Angle > 360.f)
        {
            m_Angle -= 360.f;
        }

    }

    m_Radius = m_Angle * 3.14 / 180.f;      //�x���@�����W�A���ɒ���

    //�J�������W�̌v�Z
    float Add_x = cos(m_Radius) * m_Length;
    float Add_z = sin(m_Radius) * m_Length;
    m_Pos.x = 0.f + Add_x;
    m_Pos.z = 0.f + Add_z;

    SetCameraNearFar(1.f, 1500.f);			//�J�����̎�O�Ɖ��N���b�v�̋���
    SetCameraPositionAndTarget_UpVecY(
        m_Pos,
        VGet(0.f, 85.f, 0.f));				//�����_�͌��_

}
