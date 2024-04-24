#include "enemy.h"

void Enemy::init(float hp, float armor, float dexterity, float damage, float attack_speed)
{
	this->hp = hp;
	this->armor = armor;
	this->dexterity = dexterity;
	this->damage = damage;
	this->attack_speed = attack_speed;
}

void Enemy::change_hp(float hp)
{
	if (game.random() > dexterity/2) {
		this->hp -= hp * (1 - armor / 100/2);
	}
}

Veshtitsa::Veshtitsa()
{
	init(100, 0, 50, 20, 50);
}

Drekavac::Drekavac()
{
	init(50, 0, 100, 10, 10);
}

Striga::Striga()
{
	init(100, 50, 10, 25, 100);
}

Ghouls::Ghouls()
{
	init(100, 0, 50, 15, 50);
}

Yrka::Yrka()
{
	init(50, 0, 75, 20, 25);
}

Robber::Robber()
{
	init(100, 0, 100, 15, 50);
}

Boss_FritzHaarmann::Boss_FritzHaarmann()
{
	init(300, 50, 50, 20, 50);
}

Boss_Heinrich_Spatz::Boss_Heinrich_Spatz()
{
	init(350, 0, 70, 20, 50);
}

Boss_Countess_Elizabeth::Boss_Countess_Elizabeth()
{
	init(300, 0, 100, 25, 100);
}

Boss_Count_Vargosi::Boss_Count_Vargosi()
{
	init(400, 100, 10, 30, 10);
}
