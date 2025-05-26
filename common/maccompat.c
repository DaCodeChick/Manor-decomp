#include "maccompat.h"

#include <stdlib.h>
#include <string.h>

// manord: 0805c210
void *NewPtrClear(size_t inSize)
{
	void *__s;

	__s = malloc(inSize);
	if (__s != NULL)
	{
		memset(__s, 0, inSize);
	}
	return __s;
}

// manord: 0805c23c
void DisposePtr(void *inPtr)
{
	free(inPtr);
	return;
}
