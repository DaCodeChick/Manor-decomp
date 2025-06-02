#pragma once

#include "../madwolf/typedefs.h"

struct ServerRoomRec
{
	ServerRoomRec *nextRoom;
	ServerRoomRec *prevRoom;
	ushort roomID;
	ushort flags;
	ushort maxOccupancy;
	ushort width;
	ushort height;
	char name[65];
	char description[512];
	char source[512];
};

ServerRoomRec *RmNextRoom(const ServerRoomRec *room);
ServerRoomRec *RmStartIterator();
