#pragma once
#include"Weapon.h"
#include "Armor.h"
class Pers {
protected:
	Weapon_Selection Use_Weapon;
	float HP = 100;
	int LVL = 1;
public:
	virtual float melee_attack(int i) = 0;
	virtual float long_range_attack(int i) = 0;
	virtual float Get_HP()=0;
	virtual void Set_HP(float hp)=0;
};


class Player : public Pers {
private:
	float Experience = 0.0f;
	Armor_Selection Armor_Selection;
public:
	float melee_attack(int i) override;
	float long_range_attack(int i) override;
	float Use_Armor();
	void Set_LVL();
	void Set_Exprience(float ex);
	void Set_HP(float hp);
	float Get_HP();
protected:
	

};


class Bear : public Pers {
private:

public:
	Bear(int lvl);
	float melee_attack(int i) override;
	float long_range_attack(int i) override;
	void Set_HP(float hp)override;
	float Get_HP()override;
protected:
	
};

class mad_elk : public Pers {
private:

public:
	mad_elk(int lvl);
	float melee_attack(int i) override;
	float long_range_attack(int i) override;
	void Set_HP(float hp)override;
	float Get_HP()override;
protected:

};
