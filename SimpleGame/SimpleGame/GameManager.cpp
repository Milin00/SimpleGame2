#include "GameManager.h"
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
		std::cout << "誰を選びますか?"<<std::endl;
		std::cout<<"0:剣士 攻撃力:"<<players[0]->getAttack() << std::endl;
		std::cout << "1:魔法使い 攻撃力:" << players[1]->getAttack() << std::endl;
		std::cout << "2:召喚士 攻撃力:" << players[2]->getAttack() << std::endl;
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
	if (r == 0)
	{
		std::cout << "剣士" << std::endl;
	}
	else if (r == 1)
	{
		std::cout << "魔法使い" << std::endl;
	}
	else if (r == 2)
	{
		std::cout << "召喚士" << std::endl;
	}
	return r;
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
		if (player == 2 && enemy == 1)
		{
			std::cout << "カウンター発生" << std::endl;
			Military -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == 2 && enemy == 0)
		{
			std::cout << "クリティカル攻撃" << std::endl;
			enemyMilitary -= players[player]->getAttack() * 2;
		}
	}
}
void GameManager::getMilitary()
{
	std::cout << "プレイヤー残り戦力:" << Military << std::endl;
	std::cout << "敵の残り戦力:" << enemyMilitary << std::endl;
}