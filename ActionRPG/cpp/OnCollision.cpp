#include"../h/OnCollision.h"

void OnColl::Update(Player* player,Enemy* enemy)
{
//���t���[��0�ŏ�����
    m_PlayerPos = { 0.f };

    m_PlayerPos = player->GetPos();  
//���ꂼ��̃��f���̒��_�Z�o
    VECTOR PlayerMovedPos = VAdd(player->GetPos(), player->GetMoveVec());
    VECTOR PlayerTop = VAdd(PlayerMovedPos, player->GetHeight());
     m_EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());
   
//Player�̔��a�Q�@Enemy�̔��a�͂S.3
    if (HitCheck_Capsule_Capsule(PlayerMovedPos, PlayerTop, PLATER_HIT_SIZE_R,enemy->GetPos(), m_EnemyTop, ENEMY_HIT_SIZE_R) == TRUE)
    {
//�������Ă���Ȃ�ړ��O�̍��W��Ԃ�
        player->SetPos(m_OldPlayerPos);
        player->Damage();
#ifdef _DEBUG

        DrawString(1700, 100, "Hit", GetColor(255, 255, 255));
#endif     
    }
//�������Ă��Ȃ���ΑO�̍��W��ۑ�����
        m_OldPlayerPos = m_PlayerPos;
}

bool OnColl::OnCollitionSphereToCap(Player* player, Enemy* enemy)
{
    VECTOR AttackPos = VAdd(player->GetPos(), VGet(0.f, 0.f, 4.f));
    if (HitCheck_Sphere_Capsule(AttackPos, 2.f, enemy->GetPos(), m_EnemyTop, ENEMY_HIT_SIZE_R))
    {
        //enemy->Damage();
    }
    DrawSphere3D(AttackPos, 2.f, 4, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

   return true;
}

void OnColl::Draw(Player* player,Enemy* enemy)
{
#ifdef _DEBUG
    //���ꂼ��̃��f���̍��������Z���Ă���B
    //�����������݂�pos�ƃ��f���̍���
    VECTOR PlayerTop = VAdd(player->GetPos(), player->GetHeight());
    VECTOR EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());

    DrawCapsule3D(player->GetPos(), PlayerTop, PLATER_HIT_SIZE_R, POLYGON_FINENESS, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
    DrawCapsule3D(enemy->GetPos(), EnemyTop, ENEMY_HIT_SIZE_R, POLYGON_FINENESS, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);

#endif
}