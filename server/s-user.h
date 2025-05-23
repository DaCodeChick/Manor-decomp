#include "../common/typedefs.h"

struct ServerUserRec
{
	ServerUserRec *prevUser;
	ServerUserRec *nextUser;
	ServerUserRec *field2_0x8;
	ServerUserRec *field3_0xc;
	byte status;
};

ServerUserRec *usIsUser(const ServerUserRec *user);
