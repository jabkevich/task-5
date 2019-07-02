#include"Map.h"
#include<cmath>
#include<iostream>
#include <ctime> 
#include <stdlib.h>
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
			if (i == max_x / 2 && j == max_y / 2) World[i][j] = 9;else
			World[i][j] = 0;
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
	srand(time(NULL));

	cout << endl;
	for (int i = 0; i < max_act; i++) {
	
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
		for (int j = 0; j < max_y; j++) {
			
			cout << World[j][i]<<"  ";
			
		}
		cout << endl;
	
	}
}

int Map::Do_Act(int x_beg, int y_beg, int &x, int &y, Player &play)
{
	World[x_beg][y_beg] = 0;
	int point = World[x][y];
	  World[x][y]=9;

	  int a = (atc.*pt[x][y])(play);;
	  if (a == 0) {
		  World[x_beg][y_beg] = 9;
		  World[x][y] = point;
		  x = x_beg;
		  y = y_beg;
	  }
	
	  
	  return a;
		
		
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

void Playng(int x, int y)
{
	Map map(x, y);
	Player play;
	///////
	map.Generation_Of_The_World();
	
	int x_player=x/2;
	int y_player=y/2;
	int x1_player = x / 2;
	int y1_player = y / 2;
	char a;
	int answer;
	do {
		cout << "управление wsad. выход из игры n\n";

		map.print();
		cin >> a;
		switch (a)
		{
		case 'w':answer= map.Do_Act(x1_player, y1_player,x_player, --y_player, play);  break;
		case 's':answer = map.Do_Act(x1_player, y1_player,x_player, ++y_player, play); break;
		case 'a':answer = map.Do_Act(x1_player, y1_player,--x_player, y_player, play); break;
		case 'd': answer = map.Do_Act(x1_player, y1_player,++x_player, y_player, play); break;
	
		default: break;
		}
		x1_player = x_player;
	    y1_player = y_player;
		
		system("cls");
	} while (a != 'n'&&answer!=-1);
	cout << "игра окончена\n";

	
}
