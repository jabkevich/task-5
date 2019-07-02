#include "Actions.h"
#include "Map.h"
#include<iostream>
#include<string>

using namespace std;
int Actions::The_Battle_with_Bear(Player & player, Pers & bear)
{
	//-1-смерть
	//0-отспуление
	//1-поебда
	Map_for_fight field;
	calculation calc;
	Chek ch;
	int i=0;
	int a=0;
	int number_of_moves_for_player=10;
	int number_of_moves_for_bear=10;


	do{
		number_of_moves_for_player = 10;
		number_of_moves_for_bear = 10;

		cout << "Выше HP: " << player.Get_HP() <<" "<< endl;
		cout << "HP мишки: " << bear.Get_HP() << endl;
		cout << "Ваше место-положение\n";
		cout << "ваша ближняя быстрая атака: " << player.melee_attack(1) << ". сильная атака: " << player.melee_attack(1) << endl << "Ваша дальняя быстрая атака" << player.long_range_attack(1) << ". Ваша сильная дальняя атака" << player.long_range_attack(2) << endl << "Ваша броня " << player.Use_Armor() << endl; 
		cout << "быстрая атака вашего врага: " << bear.melee_attack(1) << " сильная атака: " << bear.melee_attack(2) << endl << "lальняя быстрая атака врага" << player.long_range_attack(1) << ". сильная дальняя атака" << player.long_range_attack(2) << endl; 
		cout << endl;
		for (int i = 0; i < 10; i++) {
			if (i == field.return_x1())
				cout << "+";
			else cout << "_";
			if (i == field.return_x2())
				cout << "-";
			else cout << "_";
			
		}
		do {
			cout << endl;
			cout << "У вас " << number_of_moves_for_player << "ходов. Выбери действие:\n ";
			cout << "Выше HP: " << player.Get_HP() << " " << endl;
			cout << "HP мишки: " << bear.Get_HP() << endl;
			cout << "отступить: 0";
			cout << "приблизиться на одну клетку 1. Это займет 1-балл\n";
			cout << "отдалиться на одну клетку 2. Это займет 1-балл\n";
			cout << "ударть мечем: 3. Это займет 4-балла\n";
			cout << "выстрел из лука: 4. Это займет 2 балла\n";
			cout << "завершить ход: 5" << endl;
			cin >> a;
			switch (a)
			{
			case 0: return 0;
			case 1: if (ch.Chek_moves(number_of_moves_for_player, 1)) {
				if (ch.Advance_Distance_Check(field.return_x1(), field.return_x2()))
				{
					field.plus_x1();
					number_of_moves_for_player--;
				}
			}break;

			case 2:  if (ch.Chek_moves(number_of_moves_for_player, 1)) {
				if (ch.End_Check(field.return_x1(), 1)) {
					field.minus_x1();
					number_of_moves_for_player--;
				}
				break;
			}
			case 3:  if (ch.Chek_moves(number_of_moves_for_player, 4)) {
				if (ch.Check_Distance_For_Attack(field.return_x1(), field.return_x2()))
				{
					bear.Set_HP(calc.Damage_Calculation(0, player.melee_attack(i)));
					number_of_moves_for_player -= 4;

				}
			}break;

			case 4: if (ch.Chek_moves(number_of_moves_for_player, 2)) {
				bear.Set_HP(calc.Damage_Calculation(0, player.long_range_attack(i)));
				number_of_moves_for_player -= 2;

			} break;
			}
		} while (a != 5);



	//	player.Set_HP(calc.Damage_Calculation(player.Use_Armor(), bear.long_range_attack(i)));
	//player.Set_HP(calc.Damage_Calculation(player.Use_Armor, bear.melee_attack(i)));
	

	
	} while (player.Get_HP() <= 0 && bear.Get_HP() <= 0);

	if (player.Get_HP() <= 0)return -1;
	if (bear.Get_HP() <= 0)return 1;
}

int Actions::The_Battle_with_Elk(Player & player, Pers & elk)
{
	//-1-смерть
//0-отспуление
//1-поебда

	calculation calc;
	int i=0;

	player.Set_HP(calc.Damage_Calculation(player.Use_Armor(), elk.long_range_attack(i)));
	player.Set_HP(calc.Damage_Calculation(player.Use_Armor(), elk.melee_attack(i)));
	elk.Set_HP(calc.Damage_Calculation(0, player.long_range_attack(i)));
	elk.Set_HP(calc.Damage_Calculation(0, player.melee_attack(i)));
	return 0;
}

int Actions::nothing(Player & player, Pers & elk)
{
	return 0;
}

void Massage::massage_about_Advance_Distance()
{
	cout << "вы находитесь слишком близко к врагу. выберите другое действие\n";
}

void Massage::massage_about_Check_Distance_For_Attack()
{
	cout << "Вы находитесь слишком далеко от врага, выберите другое действие\n";
}

void Massage::massage_about_End_Check()
{
	cout << "Вы находитесь слишком далеко от врага, выберите другое действие\n";
}

void Massage::massage_about_Moves()
{
	cout << "у вас не хватает очков\n" << endl;
}

bool Chek::Chek_moves(int num1, int num2)
{
	Massage m;
	if (num1 - num2 < 0) { m.massage_about_Moves();  return false; }
	return true;

}

bool Chek::Advance_Distance_Check(int x1, int x2)
{
	Massage m;
	if (x1 + 2 == x2) { m.massage_about_Advance_Distance(); return false; }
	if (x1 - 2 == x2) return false;
	return true;
}

bool Chek::End_Check(int x1, int i)
{
	Massage m;
	if (x1 - 1 == begin_Map) { m.massage_about_Advance_Distance(); return false; }///////10-начало поля 
	if (x1 + 1 == end_Map) return false;/////конец поля
	return true;
}

bool Chek::Check_Distance_For_Attack(int x1, int x2)
{
	Massage m;
	if (x1 + 2 != x2) { m.massage_about_Check_Distance_For_Attack(); return false; }
	if (x1 - 2 != x2) { return false; }
	return true;
}

void calculation::Boost_skells(Player & player)
{
}

float calculation::Damage_Calculation(float Armor, float Damage)
{
	return 0.0f;
}
