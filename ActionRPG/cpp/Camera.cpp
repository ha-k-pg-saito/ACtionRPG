#include"../h/Camera.h"

#include<math.h>

Camera::Camera()
{
    //m_Pos = VGet(0.f, 9.f, 0.f);		//VGet�ɂ����m_Pos��x,y,z�̒l���
    //m_Radius = 0.f;                     //���a
    //m_Angle = 0.f;                      //�p�x
    //m_Length = 20.f;                   //���a�̒���

    m_AngleH = 180.f;			// �����p�x
    m_AngleV = 0.0f;			// �����p�x
    m_Speed  = 0.1f;            // �ړ����x
    m_Pos    = VGet(0.f, 0.f, 0.f);// �J�������W
    m_Target = VGet(0.f, 0.f, 0.f);// �����_���W
}

Camera::~Camera()
{
}

void Camera::Update(Player* player)
{
    //�T���v��
    //�}�E�X�|�C���^���̎g�p
    int X, Y;
    GetMousePoint(&X, &Y);
    DrawCircle(X, Y, 5.f, GetColor(0, 255, 0), TRUE);
    //���o���̕�U�̃I�u�W�F�N�g
    DrawSphere3D(VGet(20.0f, 0.0f, 0.0f), 8.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
    
    //�J�����̏㉺���E�ړ�
    //if (CheckHitKey(KEY_INPUT_UP) == 1)
    if (CheckHitKey(KEY_INPUT_T) == 1)
    {
        m_AngleV += m_Speed;
        // ������p�x�ȏ�ɂ͂Ȃ�Ȃ��悤�ɂ���
        if (m_AngleV > DX_PI_F / 2.0f - 1.0f)
        {
            m_AngleV = DX_PI_F / 2.0f - 1.0f;
        }
    }
    //if (CheckHitKey(KEY_INPUT_DOWN) == 1)
    if (CheckHitKey(KEY_INPUT_G) == 1)
    {
        m_AngleV -= m_Speed;
        // ������p�x�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
        if (m_AngleV < -DX_PI_F / 2.0f + 1.0f)
        {
            m_AngleV = -DX_PI_F / 2.0f + 1.0f;
        }
    }
    //if (CheckHitKey(KEY_INPUT_LEFT) == 1)
    if (CheckHitKey(KEY_INPUT_F) == 1)
    {
        m_AngleH += m_Speed;
    }
    //if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
    if (CheckHitKey(KEY_INPUT_H) == 1)
    {
        m_AngleH -= m_Speed;
    }

    //�����_�̐ݒ�
    m_Target = VAdd(player->GetPos(), VGet(0.f, 10.f, 0.f));

    MATRIX RotZ, RotY;
    float Camera_Player_Length;
    MV1_COLL_RESULT_POLY_DIM HRes;
    int HitNum;

    // ���������̉�]�͂x����]
    RotY = MGetRotY(m_AngleH);

    // ���������̉�]�͂y����] )
    RotZ = MGetRotZ(m_AngleV);

    // �J��������v���C���[�܂ł̏����������Z�b�g
    Camera_Player_Length = 30.f;

    // �J�����̍��W���Z�o
    // �w���ɃJ�����ƃv���C���[�Ƃ̋����������L�т��x�N�g����
    // ����������]( �y����] )���������Ɛ���������]( �x����] )���čX��
    // �����_�̍��W�𑫂������̂��J�����̍��W
    m_Pos = VAdd(VTransform(VTransform(VGet(-Camera_Player_Length, 0.0f, 0.0f), RotZ), RotY), m_Target);



    SetCameraNearFar(1.f, 1500.f);			//�J�����̎�O�Ɖ��N���b�v�̋���
    SetCameraPositionAndTarget_UpVecY(
        m_Pos,
        m_Target);				//�����_��Player
}
