#pragma once

#include "../common/typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	EXPORT int SrgDecode(const char *str, uint *userID, uint *expires, short *productID,
	                     short *maxOccupancy, const void *decryptionTable);

#ifdef __cplusplus
}
#endif // __cplusplus
