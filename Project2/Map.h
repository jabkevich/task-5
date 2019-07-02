#include"Actions.h"
#include"Players.h"
const int begin_Map = 0, end_Map = 10;
const int max_word=100;
const int max_act=30;


	/*Start_Of_Dialogue sod[25];*/
	
	

class Map {
private:
	typedef int (Actions::* pToFunc)(Player &, Pers&);
	pToFunc pt[max_word][max_word];
	int World[max_word][max_word];
	Actions atc;
	int x;
	int y;
	int max_x;
	int max_y;
	int *arr_x;
	int *arr_y;
public:
	Map(int max, int min);

	
	void Generation_Of_The_World();

	void print();

};



class Map_for_fight{
private:
	int x1, x2;
public:
	Map_for_fight();
	int return_x1();
	int return_x2();
	void plus_x1();
	void plus_x2();
	void minus_x1();
	void minus_x2();

};