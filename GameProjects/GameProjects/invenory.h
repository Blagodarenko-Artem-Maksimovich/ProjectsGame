#include "items.h"
#include <iostream>
#include <vector>
#include "player.h"

class inventory {
private:
	std::vector <Item*> inventory;

	bool takeitem(Item* take);

	bool dropitem(Item* drop, int quantity);

	int find_unventory(Item* find);
};