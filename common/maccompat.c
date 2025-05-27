#include "maccompat.h"

#include <stdlib.h>
#include <string.h>

struct OpaqueHandle
{
	void *ptr;
	size_t size;
};

// Manorsrvr.exe: 004942a8
static short gLastError = 0;

// The Manor.exe: 00401cf0
void DisposeHandle(Handle handle)
{
	if (handle->ptr != NULL)
	{
		HeapFree(gHeap, 0, handle->ptr);
	}
	HeapFree(gHeap, 0, handle);
	return;
}

// manord: 0805c23c
// Manorsrvr.exe: 0041bac0
// The Manor.exe: 00401550
void DisposePtr(void *ptr)
{
#ifdef _WIN32
	HeapFree(gHeap, 0, ptr);
#else
	free(ptr);
#endif // _WIN32
	return;
}

// The Manor.exe: 00401570
size_t GetHandleSize(const Handle handle)
{
	return handle->size;
}

// The Manor.exe: 004017e0
size_t GetPtrSize(const void *ptr)
{
	SIZE_T SVar1;

	SVar1 = HeapSize(gHeap, 0, ptr);
	return SVar1;
}

// Manorsrvr.exe: 0041bab0
short MemError(void)
{
	return gLastError;
}

// Manorsrvr.exe: 0041bad0
// The Manor.exe: 00401680
Handle NewHandleClear(size_t size)
{
	Handle _Memory;
	uint uVar1;

	_Memory = (Handle)NewPtrClear(sizeof(struct OpaqueHandle));
	if (_Memory != NULL)
	{
		if (size < 1)
		{
			_Memory->ptr = NULL;
		}
		else
		{
			uVar1 = NewPtr(size);
			_Memory->ptr = uVar1;
			if (_Memory->ptr == 0)
			{
#ifdef _WIN32
				HeapFree(gHeap, 0, _Memory);
#else
				free(_Memory);
#endif // _WIN32
				gLastError = memFullErr;
				return NULL;
			}
		}
		_Memory->size = size;
		gLastError = 0;
	}
	return _Memory;
}

// Manorsrvr.exe: 0041bb30
// The Manor.exe: 00401630
void *NewPtr(size_t size)
{
	void *pvVar1;
#ifdef _WIN32
	pvVar1 = HeapAlloc(gHeap, 0, size);
#else
	pvVar1 = malloc(size);
#endif // _WIN32
	if (pvVar1 == NULL)
	{
		gLastError = memFullErr;
	}
	return;
}

// manord: 0805c210
// Manorsrvr.exe: 0041bbb0
void *NewPtrClear(size_t size)
{
#ifdef _WIN32
	{
		LPVOID pvVar1;

		pvVar1 = HeapAlloc(gHeap, HEAP_ZERO_MEMORY, size);
		if (pvVar1 == NULL)
		{
			gLastError = memFullErr;
		}
		else
		{
			gLastError = noErr;
		}
		return pvVar1;
	}
#else
	void *__s;

	__s = malloc(size);
	if (__s != NULL)
	{
		memset(__s, 0, size);
	}
	else
	{
		gLastError = memFullErr;
	}
	return __s;
#endif // _WIN32
}
