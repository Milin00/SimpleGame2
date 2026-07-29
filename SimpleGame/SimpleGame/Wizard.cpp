#include "Wizard.h"
Wizard::Wizard()
{
	name = "–‚–@Žg‚¢";
}
void Wizard::setAttack(int& value)
{
	attack = value;
}
std::string Wizard::getName() const
{
	return name;
}