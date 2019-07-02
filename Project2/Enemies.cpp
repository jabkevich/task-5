#include"Players.h"
#include <iostream>
#include <string>

using namespace std;

float Bear::melee_attack(int i)

{
	return (Use_Weapon.Use_Sword(i) + (Use_Weapon.Use_Sword(i)*float(LVL) / 100))/1.5;
}

float Bear::long_range_attack(int i)
{
	return Use_Weapon.Use_Ranged(i)+(Use_Weapon.Use_Ranged(i)*float(LVL) / 100)/1.5;
}

void Bear::Set_HP(float hp)
{
	HP += hp;
}

float Bear::Get_HP()
{
	return HP;
}

int Bear::Get_LVL()
{
	return LVL;
}

Bear::Bear()
{
	LVL=1 + (int)floor((double(rand()) / RAND_MAX)*(10 - 1  + 1));
}

Bear::Bear(int lvl)
{
	LVL = lvl;
}
/////////////////////////////////////////////////
mad_elk::mad_elk(int lvl)
{
	LVL = lvl;
}
mad_elk::mad_elk()
{
	LVL = 1 + (int)floor((double(rand()) / RAND_MAX)*(10 - 1 + 1));
}
void mad_elk::Set_HP(float hp)
{
	HP += hp;
}

float mad_elk::Get_HP()
{
	return HP;
}

int mad_elk::Get_LVL()
{
	return LVL;
}

float mad_elk::melee_attack(int i)
{
	cout << "Ћос€ра атакует рогами\n";
	return (Use_Weapon.Use_Sword(i) + (Use_Weapon.Use_Sword(i)*float(LVL) / 100))/2;
}

float mad_elk::long_range_attack(int i)
{
	cout << "Ћос€ра швыр€етс€ говном\n";
	return (Use_Weapon.Use_Ranged(i) + (Use_Weapon.Use_Ranged(i)*float(LVL) / 100))/2;
}


