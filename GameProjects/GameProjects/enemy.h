#include "game.h"
class Enemy {
	Game game;
protected:
	float hp,
		armor,
		dexterity,
		damage,
		attack_speed;
	void init (float hp=0, float armor=0, float dexterity=0, float damage=0, float attack_speed=0);

	void change_hp(float hp);
};

class Veshtitsa : public Enemy {
	Veshtitsa();
};

class Drekavac : public Enemy {
	Drekavac();
};

class Striga : public Enemy {
	Striga();
};

class Ghouls : public Enemy {
	Ghouls();
};

class Yrka : public Enemy {
	Yrka();
};

class Robber : public Enemy {
	Robber();
};

class Boss_FritzHaarmann : public Enemy {
	Boss_FritzHaarmann();
};

class Boss_Heinrich_Spatz : public Enemy {
	Boss_Heinrich_Spatz();
};

class Boss_Countess_Elizabeth : public Enemy {
	Boss_Countess_Elizabeth();
};

class Boss_Count_Vargosi : public Enemy {
	Boss_Count_Vargosi();
};