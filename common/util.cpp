#include "util.h"

// manord: 080a312c
static short gLastRnd = 0;

// manord: 08048204
int enBitTst(int value, short bit)
{
	short sVar1;

	sVar1 = bit;
	if (bit < 0)
	{
		sVar1 = bit + 7;
	}
	return (uint)(((int)*(char *)((sVar1 >> 3) + value) &
	               0x80 >> ((char)bit - (char)((sVar1 >> 3) << 3) & 0x1fU)) != 0);
}

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
