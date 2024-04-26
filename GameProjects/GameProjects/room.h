#pragma once
 
#include <string>
#include <vector>
#include "visual.h"
#include <iostream>
#include "algoritm.h"
#include <fstream>


struct RoomDef {
	int id;
	std::string name,
		description;
	std::vector<int> conectedRooms;
	bool locked;
};


class RoomRegistry {
public:
	const RoomDef* getRoomDef(int id) const;

	int loadFormsStream(std::istream& is);

private:
	std::vector <RoomDef> rooms;
};