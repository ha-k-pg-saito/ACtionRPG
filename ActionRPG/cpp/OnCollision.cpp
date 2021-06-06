#include"../h/OnCollision.h"

void OnColl::Update(Player* player,Enemy* enemy)
{
//���t���[��0�ŏ�����
    m_CharPos = { 0.f };

//���ꂼ��̃��f���̒��_�Z�o
    VECTOR PlayerTop = VAdd(player->GetPos(), player->GetHeight());
    VECTOR EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());
//�ړ��O��Player�̍��W�ۑ�
    m_CharPos = player->GetPos();
//�ߋ��̃|�W�V����������
    m_OldCharPos = m_CharPos;
   
//  Player�̔��a�Q�@Enemy�̔��a�͂S
    if (HitCheck_Capsule_Capsule(player->GetPos(), PlayerTop, 2.f, enemy->GetPos(), EnemyTop, 4.f) == TRUE)
    {
#ifdef _DEBUG
        DrawString(1700, 100, "Hit", GetColor(255, 255, 255));
#endif     
       
        //�������Ă���Ȃ�ړ��O�̍��W��Ԃ�
        player->SetPos(m_OldCharPos);
    }
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