#include <iostream>
#include <string>
#include"Players.h"
#include"Map.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "rus");
	Map map(30, 30);

	map.Generation_Of_The_World();
	map.print();

	system("pause");
	return 0;
}