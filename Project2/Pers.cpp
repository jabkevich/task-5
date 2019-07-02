#include"Players.h"
#include <iostream>
#include <string>


float Player::melee_attack(int i)
{
	return Use_Weapon.Use_Sword(i)+(Use_Weapon.Use_Sword(i)*LVL/100);
}

float Player::long_range_attack(int i)
{
	return Use_Weapon.Use_Ranged(i)+(Use_Weapon.Use_Sword(i)*LVL / 100);
}

float Player::Use_Armor()
{
	return Armor_Selection.Use_Armor();
}

void Player::Set_LVL()
{
		LVL++;
}

void Player::Set_Exprience(float ex)
{
	Experience += ex;
}

void Player::Set_HP(float hp)
{
	HP += hp;
}

float Player::Get_HP()
{
	return HP;
}

int Player::Get_LVL()
{
	return LVL;
}
