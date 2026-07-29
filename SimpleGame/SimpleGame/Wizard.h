#pragma once
#include"Character.h"
class Wizard:public Character
{
public:
	Wizard();
	void setAttack(int& value) override;
	std::string getName() const override;
};