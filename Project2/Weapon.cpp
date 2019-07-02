#pragma once
#include"Weapon.h"
#include <iostream>
#include <string>

using namespace std;
////// оружие
float sword_1_lvl::Hit_1()
{
	return 20.0f;
}

float sword_1_lvl::Hit_2()
{
	return 30.0f;
}

float sword_2_lvl::Hit_1()
{
	return 30.0f;
}

float sword_2_lvl::Hit_2()
{
	return 40.0f;
}

float sword_3_lvl::Hit_1()
{
	return 40.0f;
}

float sword_3_lvl::Hit_2()
{
	return 50.0f;
}
////////////лук

float ranged_1_lvl::Hit_1()
{
	return 10.0f;
}

float ranged_1_lvl::Hit_2()
{
	return 15.0f;
}

float ranged_2_lvl::Hit_1()
{
	return 15.0f;
}

float ranged_2_lvl::Hit_2()
{
	return 20.0f;
}

float ranged_3_lvl::Hit_1()
{
	return 25.0f;
}

float ranged_3_lvl::Hit_2()
{
	return 30.0f;
}


Weapon_Selection::Weapon_Selection()
{

	weapon_for_Sword = &sword;
	weapon_for_Ranged = &ranged;

}

/////использование оружия
void Weapon_Selection::Selection_Ranged(Weapon * weapon)
{
	this->weapon_for_Ranged = weapon;

}

void Weapon_Selection::Selection_Sword(Weapon * weapon)
{
	this->weapon_for_Sword = weapon;
}

float Weapon_Selection::Use_Ranged(int i)
{
	switch (i)
	{
	case 1: return weapon_for_Ranged->Hit_1(); 
	case 2: return weapon_for_Ranged->Hit_2();
	default:
		break;
	}
	return 0.0f;
}

float Weapon_Selection::Use_Sword(int i)
{
	switch (i)
	{
	case 1:return weapon_for_Sword->Hit_1();
	case 2:return weapon_for_Sword->Hit_2();
	default:
		break;
	}
	return 0.0f;
}
