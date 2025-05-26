#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	enum
	{
		memFullErr = -108
	};

	EXPORT void DisposePtr(void *inPtr);
	EXPORT void *NewPtrClear(size_t inSize);

#ifdef __cplusplus
}
#endif // __cplusplus
