#include "s-room.h"

struct ServerUserRec
{
	ServerUserRec *nextUser;
	ServerUserRec *prevUser;
	ServerUserRec *field2_0x8;
	ServerUserRec *field3_0xc;
	byte status;
	ushort userID;
	ServerRoomRec *room;
	char name[32];
};

bool UsIsUser(const ServerUserRec *user);
ServerUserRec *usIsUser(const ServerUserRec *user);
