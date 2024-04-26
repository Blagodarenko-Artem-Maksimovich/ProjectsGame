#include "items.h"

Melee_Weapons::Melee_Weapons(float weight, float price, int quantity, const std::string & nameobject, float damage, float attack_speed, float acuity)
{
	this->weight = weight;
	this->price = price;
	this->damage = damage;
	this->attack_speed = attack_speed;
	this->acuity = this->acuity;
	this->quantity = quantity;
	std::string classname = "Melee_Weapons";
}

Notes::Notes(float weight, float price, int quantity, const std::string & nameobject, std::string pathtotext)
{
	this->weight = weight;
	this->price = price;
	this->quantity = quantity;
	this->pathtotext = pathtotext;
	std::string classname = "Notes";

}

Heal::Heal(float weight, float price, int quantity, const std::string & nameobject, float change_hp)
{
	this->weight = 0;
	this->price = price;
	this->change_hp = change_hp;
	this->quantity = quantity;
	std::string classname = "Heal";
}


Money::Money(float weight, float price, int quantity)
{
	this->weight = 0;
	this->price = price;
	this->quantity = quantity;
	std::string classname = "Money";
	nameobject = "money";
}

Armor::Armor(float weight, float price, int quantity, const std::string &nameobject, float armor, float dexterity)
{
	this->weight = weight;
	this->price = price;
	this->quantity = quantity;
	this->armor = armor; 
	this->dexterity = dexterity;
	std::string classname = "Armor";
}

Item* ItemRegistry::loadFormsStreamItem(std::istream& is)
{
	float weight,
		price;
	int quantity;
	std::string classname,
		nameobject;
	is >> classname;
	is >> weight;
	is >> price;
	is >> quantity;
	
	if (classname=="Melee_Weapons"){
		std::getline(is, nameobject,'\n');
		std::getline(is, nameobject,'\n');
		float acuity, 
			damage,
			attack_speed;
		is >> damage;
		is >> attack_speed;
		is >> acuity;
		Melee_Weapons melee_weapons (weight, price, quantity, nameobject,damage, attack_speed, acuity );
		return (&melee_weapons);
	}

	else if (classname == "Notes") {
		std::getline(is, nameobject,'\n');
		std::getline(is, nameobject,'\n');
		std::string pathtotext;
		is >> pathtotext;
		Notes notes(weight, price, quantity, nameobject, pathtotext);
		return (&notes);
	}


	else if (classname == "Heal") {
		std::getline(is, nameobject,'\n');
		std::getline(is, nameobject,'\n');
		float change_hp;
		is >> change_hp;
		Heal heal(weight, price, quantity, nameobject, change_hp);
		return (&heal);
	}

	else if (classname == "Money") { 
		Money money (weight, price, quantity);
		return (&money);
	}

	else if (classname == "Armor") { 
		std::getline(is, nameobject,'\n');
		std::getline(is, nameobject, '\n');
		float armor,
			dexterity;
		is >> armor;
		is >> dexterity;
		Armor armorclass (weight, price, quantity ,nameobject, armor, dexterity);
		return (&armorclass);
	}
}

std::vector<Item*>* ItemRegistry::loadinventory(std::istream& is)
{
	std::vector<Item*> inventory;
	int count;
	is >> count;
	ItemRegistry reg;
	for (int i = 0; i < count; i++) {

		inventory.push_back(reg.loadFormsStreamItem(is));

	}
	return ( & inventory);
}

