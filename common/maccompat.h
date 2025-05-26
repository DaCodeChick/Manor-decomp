#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	EXPORT void DisposePtr(void *inPtr);
	EXPORT void *NewPtrClear(size_t inSize);

#ifdef __cplusplus
}
#endif // __cplusplus
