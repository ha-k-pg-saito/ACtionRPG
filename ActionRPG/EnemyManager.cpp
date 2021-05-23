#include "EnemyManager.h"

void EnemyManager::Init(VECTOR pos)
{
	for (int i = 0; i < 10; i++)
	{
		Enemies[i].Init(pos);
	}
}

void EnemyManager::Update(VECTOR player_pos)
{
	for (int i = 0; i < 10; i++)
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
	for (int i = 0; i < 10; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Draw();
	}
}

Enemy* EnemyManager::CreateEnemy(VECTOR init_pos)
{
	for (int i = 0; i < 10; i++)
	{
		// ��A�N�e�B�u�̓G���A�N�e�B�u�ɕύX���� => �G�𐶐�����
		if (Enemies[i].IsActive == false)
		{
			Enemies[i].Init(init_pos);
			Enemies[i].IsActive = true;

			return &Enemies[i];
		}
	}
	return nullptr;
}