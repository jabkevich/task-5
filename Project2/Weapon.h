#pragma once

using namespace std;

class Weapon {
public:
	virtual float Hit_1() = 0;
	virtual float Hit_2() = 0;

};



class sword_1_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};
class sword_2_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};
class sword_3_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};



class ranged_1_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};
class ranged_2_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};
class ranged_3_lvl : public Weapon {
public:
	float Hit_1() override;
	float Hit_2() override;
};



class Weapon_Selection {
protected:
	Weapon *weapon_for_Ranged;
	Weapon *weapon_for_Sword;
	sword_1_lvl sword;
	ranged_1_lvl ranged;
public:
	Weapon_Selection();
	void Selection_Ranged(Weapon *weapon);
	void Selection_Sword(Weapon *weapon);
	
	float Use_Ranged(int i);
	float Use_Sword(int i);
};

//////////////////////////////////////////////////////



