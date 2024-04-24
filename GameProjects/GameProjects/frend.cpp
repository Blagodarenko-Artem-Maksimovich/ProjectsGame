#include "frend.h"

Frend::Frend(std::string name, std::string classname, std::vector<Item*> inventory)
{
	this->name = name;
	this->classname = classname;
	this->inventory = inventory;
}

bool Frend::takeitem(Item* take)
{
	if (((*take).get_classname() == "Heal") or ((*take).get_classname() == "Many")) {
		int indexx = find_inventory(take);
		if (indexx > -1) {
			(*inventory[indexx]).set_quantity((*take).get_quantity());
			return true;
		}
	}

	inventory.push_back(take);
	return true;
}

bool Frend::dropitem(Item* drop, int quantity)
{
	if (((*drop).get_classname() == "Heal") or ((*drop).get_classname() == "Many")) {
		int indexx = find_inventory(drop);
		if (indexx > -1) {
			if (quantity < (*inventory[indexx]).get_quantity()) {
				(*inventory[indexx]).set_quantity(-quantity);
				return true;
			}
			else if (quantity > (*inventory[indexx]).get_quantity()) { return false; }
		}
	}

	inventory.erase(remove(inventory.begin(), inventory.end(), (drop)), inventory.end());
	return true;
}

int Frend::find_inventory(Item* find)
{
	std::string nametmp = (*find).get_nameobject();
	std::string nameclasstmp = (*find).get_classname();
	for (int i = 0; i < inventory.size(); i++) {
		if (((*inventory[i]).get_nameobject() == nametmp) and ((*inventory[i]).get_classname() == nameclasstmp)) {
			return i;
		}
	}
	return -1;
}