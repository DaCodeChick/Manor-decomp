#include "s-room.h"

struct ServerUserRec
{
	ServerUserRec *nextUser;
	ServerUserRec *prevUser;
	ServerUserRec *field2_0x8;
	ServerUserRec *field3_0xc;
	byte status;
	ushort groupID;
	ushort userID;
	ServerRoomRec *room;
	char name[32];
};

struct ServerAuthUserRec
{
	ServerAuthUserRec *next;
	char name[32];
	byte encryptedName[32];
};

bool UsIsUser(const ServerUserRec *user);
ServerUserRec *usIsUser(const ServerUserRec *user);
