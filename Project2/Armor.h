#pragma once
using namespace std;

class Armor {
public:
	virtual float Blocking_Damage() = 0;
};



class Armor_1_lvl : public Armor {
public:
	float Blocking_Damage() override;
};
class Armor_2_lvl : public Armor {
public:
	float Blocking_Damage() override;
};
class Armor_3_lvl : public Armor {
public:
	float Blocking_Damage() override;
};







class Armor_Selection {
protected:
	Armor *armor;
	Armor_1_lvl armor_1;
public:
	Armor_Selection();

	void Selection_Armor(Armor *weapon);
	
	float Use_Armor();
};