#include "GameManager.h"
GameManager::GameManager()
{
	UpdateAttack();;
}
GameManager::~GameManager()
{
	for (auto p : players)
		delete p;

	for (auto e : enemies)
		delete e;
}
int GameManager::SelectPlayer()
{
	int a;
	while (true)
	{
		int i = 0;
		std::cout << "誰を選びますか?"<<std::endl;
		for (auto p : players)
		{
			std::cout << i << ":" << p->getName() << "攻撃力" << p->getAttack() << std::endl;
			i++;
		}
		std::cin >> a;
		if (a < 0 || a >= 3)
		{
			std::cout << "無効な数値です。もう一度入力して下さい" << std::endl;
			continue;
		}
		break;
	}
	return a;
}
int GameManager::SelectEnemy()
{
	int r = rand() % 3;
	std::cout << "敵：" << enemies[r]->getName() << " 攻撃力：" << enemies[r]->getAttack() << std::endl;
	return r;
}
void GameManager::EnemyState()
{
	for (auto e : enemies)
	{
		std::cout <<"敵:"<< e->getName() << " 攻撃力:" << e->getAttack() << std::endl;
	}
}

void GameManager::Battle(int player, int enemy)
{
	if (player == enemy)
	{
		std::cout << "何も起こらなかった" << std::endl;
	}
	else
	{
		if (player == 0 && enemy == 1)
		{
			std::cout << "カウンター発生" << std::endl;
			Military -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == 0 && enemy == 2)
		{
			std::cout << "クリティカル攻撃" << std::endl;
			enemyMilitary -= players[player]->getAttack() * 2;
		}
		else if (player == 1 && enemy == 2)
		{
			std::cout << "カウンター発生" << std::endl;
			Military -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == 1 && enemy == 0)
		{
			std::cout << "クリティカル攻撃" << std::endl;
			enemyMilitary -= players[player]->getAttack() * 2;
		}
		else if (player == 2 && enemy == 1)
		{
			std::cout << "カウンター発生" << std::endl;
			Military -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == 2 && enemy == 0)
		{
			std::cout << "クリティカル攻撃" << std::endl;
			enemyMilitary -= players[player]->getAttack() * 2;
		}

		if (enemyMilitary < 0)
		{
			enemyMilitary = 0;
		}
		if (Military < 0)
		{
			Military = 0;
		}
	}
}
void GameManager::getMilitary()
{
	std::cout << "プレイヤー残り戦力:" << Military << std::endl;
	std::cout << "敵の残り戦力:" << enemyMilitary << std::endl;
}

void GameManager::UpdateAttack()
{
	int sword = rand()%21 + 30;
	int wizard = rand() % 21 + 20;
	int summoner = 100 - sword - wizard;
	while (summoner < 15 || summoner>40)
	{
		sword = rand() % 21 + 30;
		wizard = rand() % 21 + 20;
		summoner = 100 - sword - wizard;
	}
	players[0]->setAttack(sword);
	players[1]->setAttack(wizard);
	players[2]->setAttack(summoner);


	sword = rand() % 21 + 30;
	wizard = rand() % 21 + 20;
	summoner = 100 - sword - wizard;
	while (summoner < 15 || summoner>40)
	{
		sword = rand() % 21 + 30;
		wizard = rand() % 21 + 20;
		summoner = 100 - sword - wizard;
	}
	enemies[0]->setAttack(sword);
	enemies[1]->setAttack(wizard);
	enemies[2]->setAttack(summoner);
}