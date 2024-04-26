#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class Item {
protected:
	float weight,
		price;
	int quantity;
	std::string classname,
		nameobject;
public:
	float get_weight() { return weight; }

	float get_price() { return price; }

	int get_quantity() { return quantity; }

	std::string get_classname() { return classname; }

	std::string get_nameobject() { return nameobject; }

	void set_quantity(int quantity) { this->quantity = quantity; }
};
class Weapon: public Item {
protected:
	float damage,
		attack_speed;
public:
	float get_damage() { return damage; }

	float get_attack_speed() { return attack_speed; }
};

class Melee_Weapons :public Weapon {
private:
	float acuity;
	
public:
	Melee_Weapons (float weight = 0, float price = 0, int quantity = 0, const std::string & nameobject="melee_weapons", float damage = 0, float attack_speed = 0, float acuity = 0);
	float get_acuity() { return acuity; }
};

class Notes : public Item {
	std::string pathtotext;
	
public:
	Notes(float weight = 0, float price = 0, int quantity = 0, const std::string & nameobject = "notes", std::string pathtotext = "");
	std::string get_pathtotext() { return pathtotext; }
};

class Heal : public Item {
	float change_hp;
	
public:
	Heal(float weight = 0, float price = 0, int quantity = 0, const  std::string &nameobject="heal", float change_hp = 0);
	float get_change_hp() { return change_hp; }
};

class Money : public Item {
public:
	Money(float weight=0, float price = 0, int quantity = 0);
};

class Armor : public Item {
	float armor,
		dexterity;
public:
	Armor(float weight = 0, float price = 0, int quantity = 0, const std::string & nameobject="armor", float armor = 0, float dexterity = 0);
	float get_armor() { return armor; }
	float get_dexterity() { return dexterity; }
};

class ItemRegistry {
public:
	Item* loadFormsStreamItem(std::istream& is);
	std::vector <Item*>* loadinventory(std::istream& is);
};