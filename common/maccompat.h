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

	EXPORT void DisposePtr(void *ptr);
	EXPORT short MemError();
	EXPORT void *NewPtrClear(size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus
