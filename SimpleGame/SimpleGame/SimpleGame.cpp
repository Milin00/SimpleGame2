#include<iostream>
#include"GameManager.h"

int main()
{
	srand((unsigned int)time(nullptr));
	GameManager game;
	bool gaming = true;
	while (gaming)
	{
		game.getMilitary();
		game.EnemyState();
		Action playeraction=game.SelectPlayerAction();
		int player=game.SelectPlayer();
		Action enemyaction=game.SelectEnemyAction();
		int enemy=game.SelectEnemy();
		game.Battle(player,enemy, playeraction, enemyaction);
		game.UpdateAttack();
		gaming=game.Gaming();
		std::cout << "\n\n\n\n\n";
	}
}