#pragma once
#include "game.h"
class Enemy {
	Game game;
protected:
	float hp,
		armor,
		dexterity,
		damage,
		attack_speed;
	std::string name;
	void init (float hp=0, float armor=0, float dexterity=0, float damage=0, float attack_speed=0, const std::string & name="Enemy");

	void change_hp(float hp);

	std::string getname() { return this->name; }
};

class Veshtitsa : public Enemy {
public:
	Veshtitsa() { init(100, 0, 50, 20, 50, "Veshtitsa"); }
};

class Drekavac : public Enemy {
public:
	Drekavac() { init(50, 0, 100, 10, 10,"Drekavac"); }
};

class Striga : public Enemy {
public:
	Striga() { init(100, 50, 10, 25, 100,"Striga"); }
};

class Ghouls : public Enemy {
public:
	Ghouls() { init(100, 0, 50, 15, 50, "Ghouls"); }
};

class Yrka : public Enemy {
public:
	Yrka() { init(50, 0, 75, 20, 25, "Yrka"); }
};

class Robber : public Enemy {
public:
	Robber() { init(100, 0, 100, 15, 50,"Robber"); }
};

class Boss_FritzHaarmann : public Enemy {
public:
	Boss_FritzHaarmann() { init(300, 50, 50, 20, 50,"Boss_FritzHaarman"); }
};

class Boss_Heinrich_Spatz : public Enemy {
public:
	Boss_Heinrich_Spatz() { init(350, 0, 70, 20, 50,"Boss_Heinrich_Spatz"); }
};

class Boss_Countess_Elizabeth : public Enemy {
public:
	Boss_Countess_Elizabeth() { init(300, 0, 100, 25, 100,"Boss_Countess_Elizabeth"); }
};

class Boss_Count_Vargosi : public Enemy {
public:
	Boss_Count_Vargosi() { init(400, 100, 10, 30, 10,"Boss_Count_Vargosi"); }
};