#include "GameManager.h"
GameManager::GameManager()
{
	UpdateAttack();
}
Action GameManager::SelectPlayerAction()
{
	int a;

	while (true)
	{
		std::cout << "行動を選択してください" << std::endl;
		std::cout << "0:攻撃" << std::endl;
		std::cout << "1:防御" << std::endl;
		std::cin >> a;

		if (a == 0)
		{
			return ATTACK;
		}

		if (a == 1)
		{
			return DEFEND;
		}

		std::cout << "無効な入力です" << std::endl;
	}
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

Action GameManager::SelectEnemyAction()
{
	int r = rand() % 2;
	if (r == 0)
	{
		std::cout << "相手は攻撃を選択" << std::endl;
		return ATTACK;
	}
	else
	{
		std::cout << "相手は防御を選択" << std::endl;
		return DEFEND;
	}
}
int GameManager::SelectEnemy() const
{
	int r = rand() % 3;
	std::cout << "相手：" << enemies[r]->getName() << " 攻撃力：" << enemies[r]->getAttack() << std::endl;
	return r;
}
void GameManager::EnemyState() const
{
	for (auto e : enemies)
	{
		std::cout <<"相手:"<< e->getName() << " 攻撃力:" << e->getAttack() << std::endl;
	}
}

void GameManager::Battle(int player, int enemy, Action playerAction, Action enemyAction)
{
	if (playerAction == DEFEND && enemyAction == DEFEND)
	{
		std::cout<<"お互いに防御した" << std::endl;
		return;
	}
	
	if (playerAction == ATTACK &&enemyAction == ATTACK)
	{
		int pAttack = players[player]->getAttack();
		int eAttack = enemies[enemy]->getAttack();

		std::cout << "お互い攻撃！" << std::endl;

		if (pAttack > eAttack)
		{
			std::cout << "プレイヤーの攻撃成功"<<std::endl;
			enemyMilitary -= pAttack;
		}
		else if (eAttack > pAttack)
		{
			std::cout << "相手の攻撃成功"<<std::endl;
			playerMilitary -= eAttack;
		}
		else
		{
			std::cout << "攻撃力が同じ。ドロー"<<std::endl;
		}

		return;
	}

	if (playerAction == ATTACK && enemyAction == DEFEND)
	{
		if ((player == 0 && enemy == 1) || (player == 1 && enemy == 2) || (player == 2 && enemy == 0))
		{
			std::cout << "カウンター発生"<<std::endl;

			playerMilitary -= players[player]->getAttack() * 2;
		}
		else if (player == enemy)
		{
			std::cout << "防御成功"<<std::endl;
		}
		else
		{
			std::cout << "クリティカル攻撃"<<std::endl;

			enemyMilitary -= players[player]->getAttack() * 2;
		}
	}

	if (playerAction == DEFEND && enemyAction == ATTACK )
	{

		if ((enemy == 0 && player == 1) || (enemy == 1 && player == 2) || (enemy == 2 && player == 0))
		{
			std::cout << "相手のカウンター発生"<<std::endl;

			enemyMilitary -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == enemy)
		{
			std::cout << "防御成功"<<std::endl;
		}
		else
		{
			std::cout << "相手のクリティカル攻撃"<<std::endl;

			playerMilitary -= enemies[enemy]->getAttack() * 2;
		}
	}


	if (playerMilitary < 0)
	{
		playerMilitary = 0;
	}

	if (enemyMilitary < 0)
	{
		enemyMilitary = 0;
	}
}
void GameManager::showMilitary() const
{
	std::cout << "プレイヤー残り戦力:" << playerMilitary << std::endl;
	std::cout << "相手の残り戦力:" << enemyMilitary << std::endl;
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


bool GameManager::Gaming()
{
	if (playerMilitary == 0)
	{
		std::cout << "相手の勝利" << std::endl;
		return false;
	}
	if (enemyMilitary==0)
	{
		std::cout << "プレイヤーの勝利" << std::endl;
		return false;
	}
	return true;
}

GameManager::~GameManager()
{
	for (auto p : players)
		delete p;

	for (auto e : enemies)
		delete e;
}