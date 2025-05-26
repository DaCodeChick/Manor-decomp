#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	typedef struct OpaqueHandle *Handle;

	enum
	{
		noErr = 0,
		memFullErr = -108
	};

	EXPORT void DisposePtr(void *ptr);
	EXPORT short MemError();
	EXPORT Handle NewHandleClear(size_t size);
	EXPORT void *NewPtr(size_t size);
	EXPORT void *NewPtrClear(size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus
