#include "../madwolf/network.h"
#include "s-room.h"

struct ServerUserRec
{
	ServerUserRec *nextUser;
	ServerUserRec *prevUser;
	char address[32];
	char name[32];
	uint flags;
	ushort groupID;
	ushort userID;
	ServerRoomRec *room;
	Connection *connection;
	bool waitingForDisconnect;
	ushort width;
	ushort height;
	ushort voice;
};

struct ServerAuthUserRec
{
	ServerAuthUserRec *next;
	char name[32];
	byte encryptedName[32];
};

bool UsIsUser(const ServerUserRec *user);
ServerUserRec *usIsUser(const ServerUserRec *user);
