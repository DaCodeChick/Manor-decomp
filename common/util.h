#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	EXPORT void enBitSet(uint *value, short bit);
	EXPORT int enBitTst(uint value, short bit);
	EXPORT short enRandom(short seed, short bound);

#ifdef __cplusplus
}
#endif // __cplusplus
