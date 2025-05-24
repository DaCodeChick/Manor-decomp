#include "s-secure.h"

#include <cstring>

// manord: 080a9f6e
static short gSrgLastRnd = 0;

// manord: 0805bc98
static void srgenBitSet(int value, short bit)
{
	byte *pbVar1;
	short sVar2;

	sVar2 = bit;
	if (bit < 0)
	{
		sVar2 = bit + 7;
	}
	pbVar1 = (byte *)((sVar2 >> 3) + value);
	*pbVar1 = *pbVar1 | (byte)(0x80 >> ((char)bit - (char)((sVar2 >> 3) << 3) & 0x1fU));
	return;
}

// manord: 0805bc54
static int srgenBitTst(int value, short bit)
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

// manord: 0805bd28
static void SrgEnDecrypt(byte *data, byte *key, const void *bitPermutations)
{
	short sVar1;
	short sVar2;
	int iVar3;
	undefined4 *puVar4;
	undefined4 local_18[5];

	std::memset(local_18, 0, sizeof local_18);
	gSrgLastRnd = (short)*key;
	sVar1 = srgenRandom(0, 0x100);
	*key = (byte)sVar1;
	sVar1 = 0;
	do
	{
		sVar2 = srgenRandom(0, 0x100);
		*key = (byte)sVar2;
		data[sVar1] = data[sVar1] ^ *key;
		sVar1 = sVar1 + 1;
	} while (sVar1 < 0x14);
	sVar1 = 0;
	do
	{
		iVar3 = srgenBitTst((ulonglong)data,
		                    (ushort) * (byte *)((int)sVar1 + (ulonglong)bitPermutations));
		if (iVar3 != 0)
		{
			srgenBitSet((ulonglong)local_18, sVar1);
		}
		sVar1 = sVar1 + 1;
	} while (sVar1 < 0xa0);
	puVar4 = local_18;
	for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1)
	{
		*(undefined4 *)data = *puVar4;
		puVar4 = puVar4 + 1;
		data = data + 4;
	}
	return;
}

// manord: 0805bb70
static short srgenRandom(short seed, short range)
{
	if (seed != 0)
	{
		gSrgLastRnd = seed;
	}
	gSrgLastRnd = (short)((gSrgLastRnd * 7 + 3) % (int)range);
	return gSrgLastRnd;
}

// manord: 0805bbb4
static void SrgEnPermtable(short seed, void *forwardTable, const void *reverseTable)
{
	short sVar1;
	short seed_00;
	short sVar2;

	std::memset(forwardTable, 0xff, 0xa0);
	gSrgLastRnd = seed;
	srgenRandom(0, 0xa0);
	sVar2 = 0;
	do
	{
		sVar1 = srgenRandom(0, 0xa0);
		if (*(char *)((int)sVar1 + (ulonglong)forwardTable) != -1)
		{
			seed_00 = 1;
			while (true)
			{
				sVar1 = srgenRandom(seed_00, 0xa0);
				if (*(char *)((int)sVar1 + (ulonglong)forwardTable) == -1)
					break;
				seed_00 = seed_00 + 1;
			}
		}
		*(char *)((int)sVar1 + (ulonglong)forwardTable) = (char)sVar2;
		*(char *)((int)sVar2 + (ulonglong)reverseTable) = (char)sVar1;
		sVar2 = sVar2 + 1;
	} while (sVar2 < 0xa0);
	return;
}
