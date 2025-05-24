#pragma once

#include "typedefs.h"

struct Connection
{
	Connection *next;
	Connection *prev;
	Socket sock;
	uint dataWaiting;
};

EXPORT uint NwCheckDataWaiting(const Connection *connection);
