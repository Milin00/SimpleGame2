#include<iostream>
#include"GameManager.h"

int main()
{
	srand((unsigned int)time(nullptr));
	GameManager game;
	bool gaming = true;
	while (gaming)
	{
		game.showMilitary();
		game.EnemyState();
		Action playerAction=game.SelectPlayerAction();
		int player=game.SelectPlayer();
		Action enemyAction=game.SelectEnemyAction();
		int enemy=game.SelectEnemy();
		game.Battle(player,enemy, playerAction, enemyAction);
		game.UpdateAttack();
		gaming=game.Gaming();
		std::cout << "\n\n\n\n\n";
	}
}