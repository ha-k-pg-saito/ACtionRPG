#include"../h/Camera.h"

#include<math.h>

Camera::Camera()
{
    m_MouseX = 960;                 // �}�E�X��X���W
    m_MouseY = 540;                 // �}�E�X��Y���W
    m_BeforeMouseX = 960;           // 1�t���[���O�̃}�E�X��X���W
    m_BeforeMouseY = 540;           // 1�t���[���O�̃}�E�X��Y���W
    m_FrameCounter = 0;             // �t���[���J�E���^�[
    m_AngleH = 180.f;			    // �����p�x
    m_AngleV = 0.0f;			    // �����p�x
    m_Speed  = 0.1f;                // �ړ����x
    m_Pos    = VGet(0.f, 0.f, 0.f); // �J�������W
    m_Target = VGet(0.f, 0.f, 0.f); // �����_���W
}

Camera::~Camera()
{
}

void Camera::Update(Player* player)
{   
    //�}�E�X�J�[�\���������Ȃ�����
    SetMouseDispFlag(FALSE);

    //GetMousePoint((int*)&m_Mouse.m_BeforeMouseX, (int*)&m_Mouse.m_BeforeMouseY);
    GetMousePoint(&m_MouseX, &m_MouseY);

    if (m_FrameCounter % 30 == 0)
    {
        //�}�E�X�J�[�\���𒆐S�Ɉړ�
        SetMousePoint(960, 540);
        m_MouseX = 960;
        m_MouseY = 540;
        m_BeforeMouseX = 960;
        m_BeforeMouseY = 540;
    }

    m_FrameCounter++;
 
    //�J�������W�̍X�V
    m_AngleV -= (m_MouseY - m_BeforeMouseY) / 100.f;
    m_AngleH += (m_MouseX - m_BeforeMouseX) / 100.f;

    //�}�E�X���W�̕ۑ�
    m_BeforeMouseX = m_MouseX;
    m_BeforeMouseY = m_MouseY;

    // ������p�x�ȏ�ɂ͂Ȃ�Ȃ��悤�ɂ���
    if (m_AngleV > DX_PI_F / 2.0f - 1.0f)
    {
        m_AngleV = DX_PI_F / 2.0f - 1.0f;
    }
    // ������p�x�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
    if (m_AngleV < -DX_PI_F / 2.0f + 1.0f)
    {
        m_AngleV = -DX_PI_F / 2.0f + 1.0f;
    }

    //�����_�̐ݒ�
    m_Target = VAdd(player->GetPos(), VGet(0.f, 10.f, 0.f));

    MATRIX RotZ, RotY;
    float Camera_Plam_BeforeMouseYer_Length;
    MV1_COLL_RESULT_POLY_DIM HRes;
    int HitNum;

    // ���������̉�]�͂x����]
    RotY = MGetRotY(m_AngleH);

    // ���������̉�]�͂y����] )
    RotZ = MGetRotZ(m_AngleV);

    // �J��������v���C���[�܂ł̏����������Z�b�g
    Camera_Plam_BeforeMouseYer_Length = 30.f;

    // �J�����̍��W���Z�o
    m_Pos = VAdd(VTransform(VTransform(VGet(-Camera_Plam_BeforeMouseYer_Length, 0.0f, 0.0f), RotZ), RotY), m_Target);

    //�J�����̎�O�Ɖ��N���b�v�̋���
    SetCameraNearFar(1.f, 1500.f);	

    //�J�����̍��W�X�V
    SetCameraPositionAndTarget_UpVecY(
        m_Pos,
        m_Target);				//�����_��Plam_BeforeMouseYer
}
