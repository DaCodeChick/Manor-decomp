#include "s-room.h"
#include "../madwolf/manor.h"

#include <string.h>

// manord: 080a9768
// Manorsrvr.exe: 0048b5d0
static ServerRoomRec *RMFirstRoom = NULL;

// manord: 08055888
// Manorsrvr.exe: 00404430
ServerRoomRec *RmFindFile(const char *path)
{
	int iVar1;
	ServerRoomRec *pSVar2;

	pSVar2 = RMFirstRoom;
	if (RMFirstRoom != NULL)
	{
		do
		{
			iVar1 = strcmp(path, pSVar2->filePath);
			if (iVar1 == 0)
			{
				return pSVar2;
			}
			pSVar2 = pSVar2->nextRoom;
		} while (pSVar2 != NULL);
	}
	return pSVar2;
}

// manord: 08055eb0
// Manorsrvr.exe: 00404a10
void RmGetAvailID(short *id)
{
  ushort uVar1;
  ServerRoomRec *pSVar2;
  
  uVar1 = 99;
  do {
    uVar1 = uVar1 + 1;
    pSVar2 = RMFirstRoom;
    if (RMFirstRoom != NULL) {
      do {
        if (pSVar2->roomID == uVar1) break;
        pSVar2 = pSVar2->nextRoom;
      } while (pSVar2 != NULL);
    }
    if (pSVar2 == NULL) {
      *id = uVar1;
      return;
    }
  } while( true );
}

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

// manord: 080580d8
// Manorsrvr.exe: 00406b60
void RmGetRoomDim(const ServerRoomRec *room, ushort *width, ushort *height)
{
	*width = room->width;
	*height = room->height;
	return;
}

// manord: 08056548
// Manorsrvr.exe: 00405050
bool RmMayLooseProps(const ServerRoomRec *room)
{
	return (room->flags & RF_NoLooseProps) == 0;
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

// manord: 08056488
// Manorsrvr.exe: 00404f70
ushort RmNameToID(char *name)
{
	int iVar1;
	ServerRoomRec *pSVar2;

	pSVar2 = RMFirstRoom;
	if (RMFirstRoom != NULL)
	{
		do
		{
			iVar1 = strcmp(&pSVar2->name, name);
			if (iVar1 == 0)
			{
				return pSVar2->roomID;
			}
			pSVar2 = pSVar2->nextRoom;
		} while (pSVar2 != NULL);
	}
	return 0;
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
