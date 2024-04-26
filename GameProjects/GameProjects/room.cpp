#include "room.h"

constexpr int MAX_STRING_LEN = 256;

const RoomDef* RoomRegistry::getRoomDef(int id) const
{
	if (id > 0 and id <= rooms.size()) {
		return (&rooms[id-1]);
	}
}

int RoomRegistry::loadFormsStream(std::istream& is)
{
	rooms.clear();
	int count ;
	is >> count;

	for (int j = 0; j < count; j++) {
		RoomDef rd;
		is >> rd.id;
		is >> rd.name;
		//is >> rd.description;
		std::getline(is, rd.description, '\n');
		std::getline(is, rd.description,'\n');
		
		int countConnectedRooms;
		is >> countConnectedRooms;
		
		for (int i = 0; i < countConnectedRooms; ++i) {
			int roomId;
			is >> roomId;
			rd.conectedRooms.push_back(roomId);
			
		}

		is >> rd.locked;
		rooms.push_back(std::move(rd));
	}
	
	int currentRoomId;
	is >> currentRoomId;
	return currentRoomId;
}

