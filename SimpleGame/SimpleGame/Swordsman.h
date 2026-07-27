#pragma once
#include"Character.h"
class Swordsman:public Character
{
public:
	void setAttack(int& value) override;
	std::string getName() override;
};

