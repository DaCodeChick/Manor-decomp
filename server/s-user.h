#include "../common/typedefs.h"

struct ServerUserRec
{
	ServerUserRec *prevUser;
	ServerUserRec *nextUser;
	byte status;
};
