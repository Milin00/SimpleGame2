#include<iostream>
#include"GameManager.h"

int main()
{
	srand((unsigned int)time(nullptr));
	GameManager game;
	while (true)
	{
		game.getMilitary();
		game.EnemyState();
		int x=game.SelectPlayer();
		int y=game.SelectEnemy();
		game.UpdateAttack();
		std::cout << "\n";
	}
}