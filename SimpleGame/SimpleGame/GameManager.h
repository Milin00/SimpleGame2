#pragma once
#include<array>
#include"Character.h"
#include"Swordsman.h"
#include"Wizard.h"
#include"Summoner.h"

enum Action
{
    ATTACK,
    DEFEND
};

class GameManager
{
private:
    int playerMilitary = 300;
    int enemyMilitary = 300;
    std::array<Character*,3> players = { new Swordsman(),new Wizard(),new Summoner() };
    std::array<Character*,3> enemies = { new Swordsman(),new Wizard(),new Summoner() };
public:
    int SelectPlayer();
    int SelectEnemy() const;
    void EnemyState() const;
    void Battle(int player, int enemy,Action playerAction,Action enemyAction);
    void showMilitary() const;
    void UpdateAttack();
    bool Gaming();
    Action SelectPlayerAction();
    Action SelectEnemyAction();
    GameManager();
    ~GameManager();
};