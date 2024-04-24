#include <iostream>
class Item {
protected:
	float weight,
		price;
	int quantity;
	std::string classname,
		nameobject;
public:
	float get_weight();

	float get_price();

	int get_quantity();

	std::string get_classname();

	std::string get_nameobject();

	void set_quantity(int quantity);
};
class Weapon: public Item {
protected:
	float damage,
		attack_speed;
public:
	float get_damage();

	float get_attack_speed();
};

class Melee_Weapons :public Weapon {
private:
	float acuity;
	Melee_Weapons (float weight = 0, float price = 0, int quantity = 0, std::string nameobject="melee_weapons", float damage = 0, float attack_speed = 0, float acuity = 0);
public:
	float get_acuity();
};

class Notes : public Item {
	std::string pathtotext;
	Notes(float weight = 0, float price = 0, int quantity = 0, std::string nameobject = "notes", std::string pathtotext = "");
public:
	std::string get_pathtotext();
};

class Heal : public Item {
	float change_hp;
	Heal(float weight = 0, float price = 0, int quantity = 0, std::string nameobject="heal", float change_hp = 0);
public:
	float get_change_hp();
};

class Money : public Item {
	Money(float weight=0, float price = 0, int quantity = 0);
};

class Armor : public Item {
	float armor,
		dexterity;

	Armor(float weight = 0, float price = 0, int quantity = 0, std::string nameobject="rmor", float armor = 0, float dexterity = 0);
public:
	float get_armor();
	float get_dexterity();
};