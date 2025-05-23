#pragma once

#include "../common/typedefs.h"

struct ServerRoomRec
{
	ServerRoomRec *prevRoom;
	ServerRoomRec *nextRoom;
	ushort roomID;
	ushort flags;
	ushort maxOccupancy;
	ushort width;
	ushort height;
	char name[65];
	char description[512];
	char source[512];
};
