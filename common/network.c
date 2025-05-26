#include "network.h"

// manord: 0804b414
// Manorsrvr.exe: 004038a0
uint NwCheckDataWaiting(const Connection *connection)
{
	return connection->dataWaiting;
}

// manord: 0804bc5c
// Manorsrvr.exe: 00403bf0
void NwFlagErrorDiscnct(Connection *connection)
{
	connection->awaitingDisconnect = true;
	return;
}
