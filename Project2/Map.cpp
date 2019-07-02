#include"Map.h"
#include<cmath>
Map::Map(int max, int min)
{
	x_y_max = max;
	x_y_min = min;
	arr = new int[x_y_max + abs(x_y_min)];
	for (int i = 0; i < x_y_max + abs(x_y_min); i++) {
		arr[i]= i;
	}
	
	for (int i = x_y_min; i < x_y_max; i++) {
		pt[i][i] = &Actions::nothing;
	}

	
}

void Map::Generation_Of_The_World()
{
	int j;
	for (int i = 0; i < max_act; i++) {
		j = x_y_min + (int)floor((double(rand()) / RAND_MAX)*(x_y_max - x_y_min + 1));
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
