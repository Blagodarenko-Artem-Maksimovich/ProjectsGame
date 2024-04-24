#include "items.h"

Melee_Weapons::Melee_Weapons(float weight, float price, int quantity, std::string nameobject, float damage, float attack_speed, float acuity)
{
	this->weight = weight;
	this->price = price;
	this->damage = damage;
	this->attack_speed = attack_speed;
	this->acuity = this->acuity;
	this->quantity = quantity;
	std::string classname = "Melee_Weapons";
}

float Melee_Weapons::get_acuity()
{
	return acuity;
}

Notes::Notes(float weight, float price, int quantity, std::string nameobject, std::string pathtotext)
{
	this->weight = weight;
	this->price = price;
	this->quantity = quantity;
	this->pathtotext = pathtotext;
	std::string classname = "Notes";

}

std::string Notes::get_pathtotext()
{
	return pathtotext;
}


Heal::Heal(float weight, float price, int quantity, std::string nameobject, float change_hp)
{
	this->weight = 0;
	this->price = price;
	this->change_hp = change_hp;
	this->quantity = quantity;
	std::string classname = "Heal";
}

float Heal::get_change_hp()
{
	return change_hp;
}

Money::Money(float weight, float price, int quantity)
{
	this->weight = 0;
	this->price = price;
	this->quantity = quantity;
	std::string classname = "Money";
	nameobject = "money";
}

Armor::Armor(float weight, float price, int quantity, std::string nameobject, float armor, float dexterity)
{
	this->weight = weight;
	this->price = price;
	this->quantity = quantity;
	this->armor = armor; 
	this->dexterity = dexterity;
	std::string classname = "Armor";
}

float Armor::get_armor()
{
	return armor;
}

float Armor::get_dexterity()
{
	return dexterity;
}

float Item::get_weight()
{
	return weight;
}

float Item::get_price()
{
	return price;
}

int Item::get_quantity()
{
	return quantity;
}

std::string Item::get_classname()
{
	return classname;
}

std::string Item::get_nameobject()
{
	return nameobject;
}

void Item::set_quantity(int quantity)
{
	this->quantity += quantity;
}

float Weapon::get_damage()
{
	return damage;
}

float Weapon::get_attack_speed()
{
	return attack_speed;
}
