#pragma once

#include "../madwolf/typedefs.h"

struct ServerRoomRec
{
	ServerRoomRec *nextRoom;
	ServerRoomRec *prevRoom;
	short roomID;
	ushort flags;
	ushort maxOccupancy;
	ushort width;
	ushort height;
	char name[65];
	char description[512];
	char source[512];
};

short RmGetID(const ServerRoomRec *room);
bool RmMaySpoof(const ServerRoomRec *room);
bool RmMayWhisper(const ServerRoomRec *room);
ServerRoomRec *RmNextRoom(const ServerRoomRec *room);
ServerRoomRec *RmStartIterator();
