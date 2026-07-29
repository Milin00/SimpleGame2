#pragma once
#include"Character.h"
class Summoner:public Character
{
public:
	Summoner();
	void setAttack(int& value) override;
	std::string getName() const override;
};

