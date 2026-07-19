#include<iostream>
#include<string>
#include<vector>
#include"Character.h"
#include"Swordsman.h"
#include"Wizard.h"
#include"Summoner.h"
#include"GameManager.h"

int main()
{
	srand((unsigned int)time(nullptr));
	std::vector<Character*> player = { new Swordsman() ,new Wizard(),new Summoner() };
	std::vector<Character*> enemy = { new Summoner(),new Swordsman(),new Wizard() };

}