#include "enemy.h"

void Enemy::init(float hp, float armor, float dexterity, float damage, float attack_speed, const std::string &name)
{
	this->hp = hp;
	this->armor = armor;
	this->dexterity = dexterity;
	this->damage = damage;
	this->attack_speed = attack_speed;
	this->name = name;
}


void Enemy::change_hp(float hp)
{
	if (game.random() > dexterity/2) {
		this->hp -= hp * (1 - armor / 100/2);
	}
}