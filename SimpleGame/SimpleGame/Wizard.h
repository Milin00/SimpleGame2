#pragma once
#include"Character.h"
class Wizard:public Character
{
public:
	void setAttack(int& value) override;
	std::string getName() override;
};