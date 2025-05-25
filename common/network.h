#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct _Connection
{
	struct _Connection *next;
	struct _Connection *prev;
	Socket sock;
	uint dataWaiting;
} Connection;

EXPORT uint NwCheckDataWaiting(const Connection *connection);

#ifdef __cplusplus
}
#endif // __cplusplus
