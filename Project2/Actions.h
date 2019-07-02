#pragma once
#include "Players.h"


class Massage {
public:
	void massage_about_Advance_Distance();
	void massage_about_Check_Distance_For_Attack();
	void massage_about_End_Check();
	void  massage_about_Moves();
	void  massage_about_wins();
	void  massage_about_loss();
};

class Chek :public Player {
public:
	void CHEK_LVL(Player &player) {

	}
	bool Chek_moves(int num1, int num2);
	bool Advance_Distance_Check(int x1, int x2);
	bool  End_Check(int x1, int i);
	bool Check_Distance_For_Attack(int x1, int x2);

};

class calculation :public Player {
public:
	void Boost_skells(Player &player);
	float Damage_Calculation(float Armor, float Damage);
};


class Actions {
public:
	int The_Battle_with_Bear(Player &player);
	int The_Battle_with_Elk(Player &player);
	int nothing(Player &player);
};


//class Start_Of_Dialogue
//{
//public:
//
//
//
//
//
//};