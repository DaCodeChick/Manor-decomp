#include "maccompat.h"

#include <stdlib.h>
#include <string.h>

// Manorsrvr.exe: 004942a8
static short gError = 0;

// manord: 0805c23c
void DisposePtr(void *inPtr)
{
	free(inPtr);
	return;
}

// Manorsrvr.exe: 0041bab0
short MemError(void)
{
	return gError;
}

// manord: 0805c210
// Manorsrvr.exe: 0041bbb0
void *NewPtrClear(size_t inSize)
{
	void *__s;

	__s = malloc(inSize);
	if (__s != NULL)
	{
		memset(__s, 0, inSize);
	}
	else
	{
		gError = memFullErr;
	}
	return __s;
}
