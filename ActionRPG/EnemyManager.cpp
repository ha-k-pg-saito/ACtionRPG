#include "EnemyManager.h"

void EnemyManager::Init()
{
	for (int i = 0; i < Enemy_Num; i++)
	{
		Enemies[i].Init();
	}
}

void EnemyManager::Update(VECTOR player_pos)
{
	for (int i = 0; i < Enemy_Num; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Update(player_pos);
	}
}

void EnemyManager::Draw()
{
	for (int i = 0; i < Enemy_Num; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Draw();
	}
}

Enemy* EnemyManager::CreateEnemy()
{
	for (int i = 0; i < Enemy_Num; i++)
	{
		// ��A�N�e�B�u�̓G���A�N�e�B�u�ɕύX���� => �G�𐶐�����
		if (Enemies[i].IsActive == false)
		{
			Enemies[i].Init();
			Enemies[i].IsActive = true;

			return &Enemies[i];
		}
	}
	return nullptr;
}