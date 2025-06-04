#pragma once

#include "typedefs.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/// @brief Represents a network connection.
	typedef struct _Connection
	{
		struct _Connection *next;
		struct _Connection *prev;
		Socket sock;
		uint dataWaiting;
		bool awaitingDisconnect;
		uint bytesSent;
	} Connection;

	/**
	 * @brief Checks if there is data waiting to be sent on the specified connection.
	 * @param connection The connection to check.
	 * @return The number of bytes waiting to be sent.
	 */
	EXPORT uint NwCheckDataWaiting(const Connection *connection);

	/**
	 * @brief Checks if the specified connection is valid.
	 *
	 * @param connection The connection to check.
	 */
	EXPORT void NwFlagErrorDiscnct(Connection *connection);

	/**
	 * @brief Retrieves the IP address of the specified connection.
	 *
	 * @param connection The connection from which to retrieve the IP address.
	 * @param buffer A buffer to store the IP address as a string.
	 */
	EXPORT void NwGetIPAddress(const Connection *connection, char *buffer);

#ifdef __cplusplus
}
#endif // __cplusplus
