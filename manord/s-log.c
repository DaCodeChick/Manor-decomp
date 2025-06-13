#include "s-log.h"

#include <stdio.h>

// manord: 080a3130
static FILE *gLogFile = NULL;

// manord: 08048494
void CloseLog(void)
{
	if (gLogFile != NULL)
	{
		fclose(gLogFile);
	}
	gLogFile = NULL;
	return;
}
