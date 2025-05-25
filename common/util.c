#include "util.h"

#include <string.h>

// manord: 080a312c
static short gLastRnd = 0;

// manord: 08048248
static void enBitSet(uint *value, short bit)
{
	byte *pbVar1;
	short sVar2;

	sVar2 = bit;
	if (bit < 0)
	{
		sVar2 = bit + 7;
	}
	pbVar1 = (byte *)((int)(sVar2 >> 3) + (ulonglong)value);
	*pbVar1 = *pbVar1 | (byte)(0x80 >> ((char)bit - (char)((sVar2 >> 3) << 3) & 0x1fU));
	return;
}

// manord: 08048204
static uint enBitTst(uint value, short bit)
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
static short enRandom(short seed, short bound)
{
	if (seed != 0)
	{
		gLastRnd = seed;
	}
	gLastRnd = (short)((gLastRnd * 7 + 3) % (int)bound);
	return gLastRnd;
}

// manord: 08048280
void EnCrypt(void *data, void *key, void *table)
{
	short sVar1;
	int iVar2;
	short sVar3;
	uint local_14;
	undefined4 local_10;
	undefined4 local_c;
	undefined4 local_8;

	memset(&local_14, 0, 0x10);
	sVar3 = 0;
	do
	{
		iVar2 = enBitTst((ulonglong)data, (short)*(char *)((int)sVar3 + (ulonglong)table));
		if (iVar2 != 0)
		{
			enBitSet(&local_14, sVar3);
		}
		sVar3 = sVar3 + 1;
	} while (sVar3 < 0x80);
	gLastRnd = *(short *)key;
	sVar3 = enRandom(0, 0x100);
	*(char *)key = (char)sVar3;
	sVar3 = 0;
	do
	{
		sVar1 = enRandom(0, 0x100);
		*(char *)key = (char)sVar1;
		*(byte *)((ulonglong)&local_14 + (int)sVar3) =
		    *(byte *)((ulonglong)&local_14 + (int)sVar3) ^ *(byte *)key;
		sVar3 = sVar3 + 1;
	} while (sVar3 < 0x10);
	*(uint *)data = local_14;
	*(undefined4 *)((ulonglong)data + 4) = local_10;
	*(undefined4 *)((ulonglong)data + 8) = local_c;
	*(undefined4 *)((ulonglong)data + 0xc) = local_8;
	return;
}

// manord: 08048334
void EnDecrypt(void *data, void *key, const void *table)
{
	short sVar1;
	short sVar2;
	int iVar3;
	uint local_14;
	undefined4 local_10;
	undefined4 local_c;
	undefined4 local_8;

	memset(&local_14, 0, 0x10);
	gLastRnd = *(short *)key;
	sVar1 = enRandom(0, 0x100);
	*(char *)key = (char)sVar1;
	sVar1 = 0;
	do
	{
		sVar2 = enRandom(0, 0x100);
		*(char *)key = (char)sVar2;
		*(byte *)((int)sVar1 + (ulonglong)data) =
		    *(byte *)((int)sVar1 + (ulonglong)data) ^ *(byte *)key;
		sVar1 = sVar1 + 1;
	} while (sVar1 < 0x10);
	sVar1 = 0;
	do
	{
		iVar3 = enBitTst((ulonglong)data, (short)*(char *)((int)sVar1 + (ulonglong)table));
		if (iVar3 != 0)
		{
			enBitSet(&local_14, sVar1);
		}
		sVar1 = sVar1 + 1;
	} while (sVar1 < 0x80);
	*(uint *)data = local_14;
	*(undefined4 *)((ulonglong)data + 4) = local_10;
	*(undefined4 *)((ulonglong)data + 8) = local_c;
	*(undefined4 *)((ulonglong)data + 0xc) = local_8;
	return;
}

// manord: 08048168
void EnPermtable(short seed, void *forward, const void *reverse)
{
	short sVar1;
	short seed_00;
	short sVar2;

	memset(forward, -1, 0x80);
	gLastRnd = seed;
	enRandom(0, 0x80);
	sVar2 = 0;
	do
	{
		sVar1 = enRandom(0, 0x80);
		if (*(char *)((int)sVar1 + (ulonglong)forward) != -1)
		{
			seed_00 = 1;
			while (1)
			{
				sVar1 = enRandom(seed_00, 0x80);
				if (*(char *)((int)sVar1 + (ulonglong)forward) == -1)
					break;
				seed_00 = seed_00 + 1;
			}
		}
		*(char *)((int)sVar1 + (ulonglong)forward) = (char)sVar2;
		*(char *)((int)sVar2 + (ulonglong)reverse) = (char)sVar1;
		sVar2 = sVar2 + 1;
	} while (sVar2 < 0x80);
	return;
}
