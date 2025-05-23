#pragma once

#include "typedefs.h"

struct Connection
{
	Connection *next;
	Connection *prev;
	Socket sock;
};
