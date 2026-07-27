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
		std::cout << "íNÇëIÇ—Ç‹Ç∑Ç©?"<<std::endl;
		for (auto p : players)
		{
			std::cout << i << ":" << p->getName() << "çUåÇóÕ" << p->getAttack() << std::endl;
			i++;
		}
		std::cin >> a;
		if (a < 0 || a >= 3)
		{
			std::cout << "ñ≥å¯Ç»êîílÇ≈Ç∑ÅBÇ‡Ç§àÍìxì¸óÕÇµÇƒâ∫Ç≥Ç¢" << std::endl;
			continue;
		}
		break;
	}
	return a;
}
int GameManager::SelectEnemy()
{
	int r = rand() % 3;
	std::cout << "ìGÅF" << enemies[r]->getName() << " çUåÇóÕÅF" << enemies[r]->getAttack() << std::endl;
	return r;
}
void GameManager::EnemyState()
{
	for (auto e : enemies)
	{
		std::cout <<"ìG:"<< e->getName() << " çUåÇóÕ:" << e->getAttack() << std::endl;
	}
}

void GameManager::Battle(int player, int enemy, Action playerAction, Action enemyAction)
{
	if (playerAction == DEFEND && enemyAction == DEFEND)
	{
		std::cout<<"Ç®å›Ç¢Ç…ñhå‰ÇµÇΩ" << std::endl;
		return;
	}
	// óºï˚çUåÇ
	if (playerAction == ATTACK &&
		enemyAction == ATTACK)
	{
		int pAttack = players[player]->getAttack();
		int eAttack = enemies[enemy]->getAttack();

		std::cout << "Ç®å›Ç¢çUåÇÅI\n";

		if (pAttack > eAttack)
		{
			std::cout << "ñ°ï˚ÇÃçUåÇê¨å˜\n";
			enemyMilitary -= pAttack;
		}
		else if (eAttack > pAttack)
		{
			std::cout << "ìGÇÃçUåÇê¨å˜\n";
			Military -= eAttack;
		}
		else
		{
			std::cout << "çUåÇóÕÇ™ìØÇ∂ÅBÉhÉçÅ[\n";
		}

		return;
	}


	// ñ°ï˚çUåÇÅAìGñhå‰
	if (playerAction == ATTACK &&
		enemyAction == DEFEND)
	{
		// Ç±Ç±Ç™å≥ÇÃëäê´ï\
		if (player == 0 && enemy == 1 ||
			player == 1 && enemy == 2 ||
			player == 2 && enemy == 0)
		{
			std::cout << "ÉJÉEÉìÉ^Å[î≠ê∂\n";

			Military -= players[player]->getAttack() * 2;
		}
		else if (player == enemy)
		{
			std::cout << "ñhå‰ê¨å˜\n";
		}
		else
		{
			std::cout << "ÉNÉäÉeÉBÉJÉãçUåÇ\n";

			enemyMilitary -= players[player]->getAttack() * 2;
		}
	}


	// ñ°ï˚ñhå‰ÅAìGçUåÇ
	if (playerAction == DEFEND &&
		enemyAction == ATTACK)
	{

		if (enemy == 0 && player == 1 ||
			enemy == 1 && player == 2 ||
			enemy == 2 && player == 0)
		{
			std::cout << "ìGÇÃÉJÉEÉìÉ^Å[î≠ê∂\n";

			enemyMilitary -= enemies[enemy]->getAttack() * 2;
		}
		else if (player == enemy)
		{
			std::cout << "ñhå‰ê¨å˜\n";
		}
		else
		{
			std::cout << "ìGÇÃÉNÉäÉeÉBÉJÉãçUåÇ\n";

			Military -= enemies[enemy]->getAttack() * 2;
		}
	}


	if (Military < 0)
		Military = 0;

	if (enemyMilitary < 0)
		enemyMilitary = 0;
}
void GameManager::getMilitary()
{
	std::cout << "ÉvÉåÉCÉÑÅ[écÇËêÌóÕ:" << Military << std::endl;
	std::cout << "ìGÇÃécÇËêÌóÕ:" << enemyMilitary << std::endl;
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

Action GameManager::SelectPlayerAction()
{
	int a;

	while (true)
	{
		std::cout << "çsìÆÇëIëÇµÇƒÇ≠ÇæÇ≥Ç¢"<<std::endl;
		std::cout << "0:çUåÇ"<<std::endl;
		std::cout << "1:ñhå‰"<<std::endl;
		std::cin >> a;

		if (a == 0)
		{
			return ATTACK;
		}

		if (a == 1)
		{
			return DEFEND;
		}

		std::cout << "ñ≥å¯Ç»ì¸óÕÇ≈Ç∑"<<std::endl;
	}
}

Action GameManager::SelectEnemyAction()
{
	int r = rand() % 2;
	if (r == 0)
	{
		std::cout << "ìGÇÕçUåÇÇëIë" << std::endl;
		return ATTACK;
	}
	else
	{
		std::cout << "ìGÇÕñhå‰ÇëIë" << std::endl;
		return DEFEND;
	}
}


void GameManager::GameStart()
{
	while (Military > 0 && enemyMilitary > 0)
	{
		std::cout << "\n===== É^Å[ÉìäJén =====\n";

		int player = SelectPlayer();
		int enemy = SelectEnemy();

		Action pAction = SelectPlayerAction();
		Action eAction = SelectEnemyAction();


		Battle(
			player,
			enemy,
			pAction,
			eAction
		);


		getMilitary();


		// éüÉ^Å[ÉìÇÃçUåÇóÕïœçX
		UpdateAttack();
	}


	if (enemyMilitary <= 0)
	{
		std::cout << "ñ°ï˚êwâcÇÃèüóòÅI\n";
	}
	else
	{
		std::cout << "ìGêwâcÇÃèüóò...\n";
	}
}