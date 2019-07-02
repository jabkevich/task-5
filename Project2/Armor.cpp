#include "Armor.h"

Armor_Selection::Armor_Selection()
{
	armor = &armor_1;
}

void Armor_Selection::Selection_Armor(Armor * armor)
{
	this->armor=armor;
}

float Armor_Selection::Use_Armor()
{
	return armor->Blocking_Damage();
}


float Armor_1_lvl::Blocking_Damage()
{
	return 0.1f;
}

float Armor_2_lvl::Blocking_Damage()
{
	return 0.25f;
}

float Armor_3_lvl::Blocking_Damage()
{
	return 0.50f;
}
