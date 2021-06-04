#include"../h/OnCollision.h"

void OnColl::Update(Player* player,Enemy* enemy)
{
    //���t���[��0�ŏ�����
    m_MoveVec = { 0 };
    //���ꂼ��̃��f���̒��_�Z�o
    VECTOR PlayerTop = VAdd(player->GetPos(), player->GetHeight());
    VECTOR EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());
  
    //�ړ����Player�̍��W�Z�o
    m_CharPos = VAdd(player->GetPos(), player->GetMoveVec());
    
    //  Player�̔��a�Q�@Enemy�̔��a�͂S
    if (HitCheck_Capsule_Capsule(m_CharPos, PlayerTop, 2.f, enemy->GetPos(), EnemyTop, 4.f) == TRUE)
    {
#ifdef _DEBUG
        DrawString(1700, 100, "Hit",GetColor(255, 255, 255));
#endif
        //Player����Enemy�ւ̃x�N�g���Z�o
        m_CharVec = VSub(m_CharPos, enemy->GetPos());
        //���object�̋����Z�o
        m_Length = VSize(m_CharVec);
        //�x�N�g���̐��K��
        m_PushVec = VScale(m_CharVec, 1.f / m_Length);
        // ������l�̋��������l�̑傫�����������l�ɉ����o���͂𑫂��ė���Ă��܂��ꍇ�́A�����������Ɉړ�����
        if (m_Length - 2.f + 4.f + 100 > 0.f)
        {
           m_CharPos = VAdd(enemy->GetPos(), VScale(m_PushVec, 2.f + 4.f));
        }
        else
        {
            //�d�Ȃ��Ă���ꍇ�����o��
           m_CharPos = VAdd(m_CharPos, VScale(m_PushVec, 100.f));
        }
    }
    m_MoveVec = VSub(m_CharPos, player->GetPos());
    player->SetPos(m_MoveVec);
}

void OnColl::Draw(Player* player,Enemy* enemy)
{
#ifdef _DEBUG
    VECTOR PlayerTop = VAdd(player->GetPos(), player->GetHeight());
    VECTOR EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());

    DrawCapsule3D(player->GetPos(), PlayerTop, 2.f, 4, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
    DrawCapsule3D(enemy->GetPos(), EnemyTop, 4.f, 4, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);

#endif
}