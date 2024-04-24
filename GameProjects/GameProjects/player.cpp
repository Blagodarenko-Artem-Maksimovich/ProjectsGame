#include "player.h"

void Player::change_hp(float hp)
{
	if (hp >= 0) {
		this->hp += hp;
	}
	else if (game.random() > dexterity){
		this->hp += hp *(1 - armor / 100/2);
	}
}

void Player::change_armor(float armor)
{
	this->armor += armor;
}

void Player::change_dexterity(float dexterity)
{
	this->dexterity+=dexterity;
}

void Player::change_luky(float luky)
{
	this->luky += luky;
}

void Player::change_skilllvl_sword(float sword)
{
	skilllvl_sword += sword;
}

void Player::change_skilllvl_bow(float bow)
{
	skilllvl_bow += bow;
}

void Player::change_skilllvl_firearm(float firearm)
{
	skilllvl_firearm += firearm;
}

bool Player::takeitem(Item *take)
{
	if ((*take).get_weight() * (*take).get_quantity() + weight_curent <= lifting_capacity) {
		if (((*take).get_classname() == "Heal")  or ((*take).get_classname() == "Many")){
			int indexx = find_inventory(take);
			if(indexx>-1) {
				(*inventory[indexx]).set_quantity((*take).get_quantity()); 
				weight_curent += (*take).get_weight() * (*take).get_quantity();
				return true;
			}
		}

		inventory.push_back(take);
		weight_curent += (*take).get_weight() * (*take).get_quantity();
		return true;

	}
	else { return false; }
}

bool Player::dropitem(Item* drop, int quantity)
{
	if (((*drop).get_classname() == "Heal") or ((*drop).get_classname() == "Many")) {
		int indexx = find_inventory(drop);
		if (indexx > -1) {
			if (quantity < (*inventory[indexx]).get_quantity()) {
				(*inventory[indexx]).set_quantity(-quantity);
				weight_curent -= (*drop).get_weight() * quantity;
				return true;
			}
			else if (quantity > (*inventory[indexx]).get_quantity()) { return false; }
		}
	}

	inventory.erase(remove(inventory.begin(), inventory.end(), (drop)), inventory.end());
	weight_curent -= (*drop).get_weight() * (*drop).get_quantity();
	return true;

}

int Player::find_inventory(Item * find)
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
