#pragma once
#include "game.h"
#include <iostream>
#include "items.h"
class Frend {
protected:
	std::string name,
		classname;
	std::vector <Item*> inventory;
public:
	Frend(const std::string & name = "npc", const std::string &classname = "npc", std::vector <Item*> inventory = {});

	bool takeitem(Item* take);

	bool dropitem(Item* drop, int quantity);

	int find_inventory(Item* find);
};