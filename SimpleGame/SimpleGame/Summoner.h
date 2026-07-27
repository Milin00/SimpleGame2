#pragma once
#include"Character.h"
class Summoner:public Character
{
public:
	void setAttack(int& value) override;
	std::string getName() override;
};

