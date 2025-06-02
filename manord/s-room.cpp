#include "s-room.h"

// manord: 080a9768
// Manorsrvr.exe: 0048b5d0
static ServerRoomRec *RMFirstRoom = NULL;

// manord: 080558cc
// Manorsrvr.exe: 00404480
ServerRoomRec *RmNextRoom(const ServerRoomRec *room)
{
	return room->nextRoom;
}

// manord: 080558c0
// Manorsrvr.exe: 00404470
ServerRoomRec *RmStartIterator()
{
	return RMFirstRoom;
}
