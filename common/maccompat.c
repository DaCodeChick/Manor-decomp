#include "maccompat.h"

#include <stdlib.h>
#include <string.h>

// Manorsrvr.exe: 004942a8
static short gLastError = 0;

// manord: 0805c23c
// Manorsrvr.exe: 0041bac0
void DisposePtr(void *ptr)
{
	free(ptr);
	return;
}

// Manorsrvr.exe: 0041bab0
short MemError(void)
{
	return gLastError;
}

// Manorsrvr.exe: 0041bb30
void *NewPtr(size_t size)
{
	void *pvVar1;

	pvVar1 = malloc(size);
	if (pvVar1 == NULL)
	{
		gLastError = -0x6c;
	}
	return;
}

// manord: 0805c210
// Manorsrvr.exe: 0041bbb0
void *NewPtrClear(size_t size)
{
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
}
