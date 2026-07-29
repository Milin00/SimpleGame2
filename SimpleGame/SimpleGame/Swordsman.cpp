#include "Swordsman.h"
Swordsman::Swordsman()
{
	name = "Œ•Žm";
}
void Swordsman::setAttack(int& value)
{
	attack = value;
}

std::string Swordsman::getName() const
{
	return name;
}