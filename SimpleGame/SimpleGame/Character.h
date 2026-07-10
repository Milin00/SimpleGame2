#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<random>
class Character
{
protected:
	std::string name;
	int attack;
public:
	virtual void setName(std::string& name);
	virtual void setAttack(int& attack);
};

