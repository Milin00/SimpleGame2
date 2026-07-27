#pragma once
#include<array>
#include"Character.h"
#include"Swordsman.h"
#include"Wizard.h"
#include"Summoner.h"
class GameManager
{
private:
    int Military = 300;
    int enemyMilitary = 300;
    std::array<Character*,3> players = { new Swordsman(),new Wizard(),new Summoner() };
    std::array<Character*,3> enemies = { new Swordsman(),new Wizard(),new Summoner() };
public:
    int SelectPlayer();
    int SelectEnemy();
    void EnemyState();
    void Battle(int player, int enemy);
    void getMilitary();
    void UpdateAttack();
    GameManager();
    ~GameManager();
};