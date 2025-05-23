#include "util.h"

// manord: 080a312c
static short gLastRnd = 0;

// manord: 08048124
short enRandom(short seed, short bound)
{
	if (seed != 0)
	{
		gLastRnd = seed;
	}
	gLastRnd = (short)((gLastRnd * 7 + 3) % (int)bound);
	return gLastRnd;
}
