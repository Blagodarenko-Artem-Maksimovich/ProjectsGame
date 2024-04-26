#pragma once
#include "game.h"
#include <iostream>
#include "algoritm.h"
#include "items.h"

class Player {
	Game game;
protected: 
	float hp = 100,
		armor = 50,
		dexterity = 50,
		luky = 10,
		skilllvl_sword = 1,
		skilllvl_bow = 1,
		skilllvl_firearm = 1,
		lifting_capacity = 100,
		weight_curent=10;

	std::vector <Item *> inventory;

	void change_hp(float hp);

	void change_armor(float armor){ this->armor += armor; }

	void change_dexterity(float dexterity){ this->dexterity += dexterity; }

	void change_luky(float luky) { this->luky += luky; }

	void change_skilllvl_sword(float sword){ skilllvl_sword += sword; }

	void change_skilllvl_bow(float bow) { skilllvl_bow += bow; }

	void change_skilllvl_firearm(float firearm){ skilllvl_firearm += firearm; }

	bool takeitem(Item *take);

	bool dropitem(Item* drop, int quantity);

	int find_inventory(Item *find);
};
