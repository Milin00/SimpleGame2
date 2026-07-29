#pragma once
#include<array>
#include<memory>
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
    std::array< std::unique_ptr<Character>,3> players ={std::make_unique<Swordsman>(),std::make_unique<Wizard>(),std::make_unique<Summoner>()};
    std::array< std::unique_ptr<Character>, 3> enemies = { std::make_unique<Swordsman>(),std::make_unique<Wizard>(),std::make_unique<Summoner>() };
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
};