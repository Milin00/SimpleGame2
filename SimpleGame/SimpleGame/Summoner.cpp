#include "Summoner.h"
Summoner::Summoner()
{
	name = "¢Š«m";
}
void Summoner::setAttack(int& value)
{
	attack = value;
}

std::string Summoner::getName() const
{
	return name;
}