#pragma once
#include"Character.h"
class Swordsman:public Character
{
public:
	Swordsman();
	void setAttack(int& value) override;
	std::string getName() const override;
};

