#include "network.h"

// manord: 0804b414
// Manorsrvr.exe: 004038a0
uint NwCheckDataWaiting(const Connection *connection)
{
	return connection->dataWaiting;
}
