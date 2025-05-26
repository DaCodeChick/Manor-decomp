#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	EXPORT void EnCrypt(void *data, void *key, const void *table);
	EXPORT void EnDecrypt(void *data, void *key, const void *table);
	EXPORT void EnPermtable(short seed, void *forward, const void *reverse);
	EXPORT float htonf(float f);
	EXPORT float ntohf(float f);

#ifdef __cplusplus
}
#endif // __cplusplus
