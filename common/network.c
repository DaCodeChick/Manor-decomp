#include "network.h"

#include <stdio.h>

#ifdef _WIN32
#include <winsock.h>
#else
#endif // _WIN32

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

// manord: 0804bbd4
// Manorsrvr.exe: 00403b90
void NwGetIPAddress(const Connection *connection, char *buffer)
{
	struct sockaddr local_74;
	int local_c;

	local_c = 0x68; // note: seems inconsistent with the size of sockaddr
	*buffer = '\0';
	getpeername(connection->sock, &local_74, &local_c);
	if (local_74.sa_family == AF_INET)
	{
		sprintf(buffer, "%d.%d.%d.%d", (uint)(byte)local_74.sa_data[2],
		        (uint)(byte)local_74.sa_data[3], (uint)(byte)local_74.sa_data[4],
		        (uint)(byte)local_74.sa_data[5]);
	}
	return;
}
