#include"../h/OnCollision.h"

void OnColl::Update(Player* player,Enemy* enemy)
{
//毎フレーム0で初期化
    m_PlayerPos = { 0.f };
    m_EnemyPos = { 0.f };

    m_PlayerPos = player->GetPos();  
    m_EnemyPos = enemy->GetPos();
//それぞれのモデルの頂点算出
    VECTOR PlayerMovedPos = VAdd(player->GetPos(), player->GetMoveVec());
    VECTOR PlayerTop = VAdd(PlayerMovedPos, player->GetHeight());
    VECTOR EnemyTop = VAdd(enemy->GetPos(), enemy->GetHeight());
   
//Playerの半径２　Enemyの半径は４.3
    if (HitCheck_Capsule_Capsule(PlayerMovedPos, PlayerTop, PLATER_HIT_SIZE_R,
                                 enemy->GetPos(), EnemyTop, ENEMY_HIT_SIZE_R) == TRUE)
    {
#ifdef _DEBUG
        DrawString(1700, 100, "Hit", GetColor(255, 255, 255));
#endif     
//当たっているなら移動前の座標を返す
        player->SetPos(m_OldPlayerPos);
        //enemy->SetPos(m_OldEnemyPos);
    }
//あたっていなければ前の座標を保存する
        m_OldPlayerPos = m_PlayerPos;
        m_OldEnemyPos = m_EnemyPos;
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