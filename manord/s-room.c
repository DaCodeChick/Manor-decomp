#include "s-room.h"
#include "../madwolf/manor.h"

// manord: 080a9768
// Manorsrvr.exe: 0048b5d0
static ServerRoomRec *RMFirstRoom = NULL;

// manord: 08057c2c
// Manorsrvr.exe: 004066b0
short RmGetID(const ServerRoomRec *room)
{
	if (room != NULL)
	{
		return room->roomID;
	}
	return 0;
}

// manord: 08057c64
// Manorsrvr.exe: 004066f0
bool RmMaySpoof(const ServerRoomRec *room)
{
	if (room != NULL)
	{
		return (room->flags & RF_NoSpoofing) == 0;
	}
	return false;
}

// manord: 08057c44
// Manorsrvr.exe: 004066d0
bool RmMayWhisper(const ServerRoomRec *room)
{
	if (room != NULL)
	{
		return (room->flags & RF_NoWhispering) == 0;
	}
	return false;
}

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
