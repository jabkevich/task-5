#include"Map.h"
#include<cmath>
#include<iostream>

using namespace std;
Map::Map(int max, int min)
{
	max_x = max;
	max_y = min;
	arr_x = new int[max_x];
	arr_y = new int[max_y];

	for (int i = 0; i < max_x; i++) {
		arr_x[i]= i;
	}
	for (int i = 0; i < max_y; i++) {
		arr_y[i] = i;
	}
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			pt[i][j] = &Actions::nothing;
		}
	}

	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			 World[i][j]=0;
		}
	}

	
}

void Map::Generation_Of_The_World()
{
	int x=0;
	int y=0;
	int RandAct;
	int Min_RandAct=0;
	int Max_RandAct=3;


	cout << endl;
	for (int i = 0; i < max_act; i++) {
		/*x = 0 + (int)floor((double(rand()) / RAND_MAX)*(max_x-0- i +1));
		y =0  + (int)floor((double(rand()) / RAND_MAX)*(max_y - 0- i  + 1));
		RandAct = Min_RandAct + (int)floor((double(rand()) / RAND_MAX)*(Max_RandAct - Min_RandAct + 1));*/
		x=0 + (int)floor((double(rand()) / RAND_MAX)*(max_x-1 - 0 -i+ 1));
		y = 0 + (int)floor((double(rand()) / RAND_MAX)*(max_y-1 - 0-i + 1));
		if (x != max_x / 2 && y != max_y / 2) {
			switch (0)//вставить переменную RandAct после того как будут добавлены новые акты или диалоги.
			{
			case 0: pt[arr_x[x]][arr_y[y]] = &Actions::The_Battle_with_Bear;
				World[arr_x[x]][arr_y[y]] = 1; break;//опасность
			case 1: pt[arr_x[x]][arr_y[y]] = &Actions::The_Battle_with_Elk;
				World[arr_x[x]][arr_y[y]] = 1;  break;//опасность
			/*case 2: pt[arr[x]][arr1[y]] = &Actions::The_Battle_with_Elk; World[arr[x]][arr1[y]] = 2;  break;*///продавец
			}
		}
			swap(arr_x[x], arr_x[max_x-1-i]);
			swap(arr_y[y], arr_y[max_y-1 - i]);
		
	
	}
}

void Map::print()
{
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < abs(max_y); j++) {
			if (i == max_x / 2 && j == abs(max_y) / 2)cout << "p" << "  ";else
			cout << World[i][j]<<"  ";
			
		}
		cout << endl;
	
	}
}

Map_for_fight::Map_for_fight()
{
	
		this->x1 = begin_Map;
		this->x2 = end_Map;
	
}

int Map_for_fight::return_x1()
{
	return x1;
}

int Map_for_fight::return_x2()
{
	return x2;
}

void Map_for_fight::plus_x1()
{
	x1++;
}
void Map_for_fight::plus_x2()
{
	x2++;
}
void Map_for_fight::minus_x1()
{
	x1--;
}
void Map_for_fight::minus_x2()
{
	x2--;
};
