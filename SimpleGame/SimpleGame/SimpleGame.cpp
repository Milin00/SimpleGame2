#include<iostream>
#include"GameManager.h"

int main()
{
	srand((unsigned int)time(nullptr));
	GameManager game;
	while (true)
	{
		int x=game.SelectPlayer();
		int y=game.SelectEnemy();
		game.Battle(x,y);
		game.getMilitary();
	}
}