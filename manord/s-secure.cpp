#include "s-secure.h"

#include <cstring>
#include <ctime>

// manord: 0809a67c
static const uint gBase36Weights[] = {
    0x1, 0x24, 0x510, 0xb640, 0x19a100, 0x39aa400, 0x81bf100,
};

// manord: 080a9f6e
static short gSrgLastRnd = 0;

// manord: 080a9f48
static const char RGCnvrsnTbl[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// manord: 0805bcd0
// Manorsrvr.exe: inlined
void srgBase36(char *base36, void *decoded)
{
	const char *pcVar1;
	int iVar2;
	short sVar3;
	const uint *puVar4;
	uint *puVar5;
	uint local_20[7];

	puVar4 = gBase36Weights;
	puVar5 = local_20;
	for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1)
	{
		*puVar5 = *puVar4;
		puVar4 = puVar4 + 1;
		puVar5 = puVar5 + 1;
	}
	iVar2 = 0;
	sVar3 = 6;
	do
	{
		pcVar1 = std::strchr(RGCnvrsnTbl, (int)*base36);
		iVar2 = iVar2 + (ulonglong)(pcVar1 + (ulonglong)RGCnvrsnTbl) * local_20[sVar3];
		base36 = base36 + 1;
		sVar3 = sVar3 + -1;
	} while (-1 < sVar3);
	*(int *)decoded = iVar2;
	return;
}

// manord: 0805bc98
// Manorsrvr.exe: inlined
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
// Manorsrvr.exe: inlined
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

// manord: 0805bb70
// Manorsrvr.exe: inlined
static short srgenRandom(short seed, short range)
{
	if (seed != 0)
	{
		gSrgLastRnd = seed;
	}
	gSrgLastRnd = (short)((gSrgLastRnd * 7 + 3) % (int)range);
	return gSrgLastRnd;
}

// manord: 0805bd28
// Manorsrvr.exe: 004147f0
static void SrgEnDecrypt(byte *data, byte *key, const void *table)
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
		iVar3 = srgenBitTst((ulonglong)data, (ushort) * (byte *)((int)sVar1 + (ulonglong)table));
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

// manord: 0805bbb4
// Manorsrvr.exe: 004146b0
static void SrgEnPermtable(short seed, void *forward, const void *reverse)
{
	short sVar1;
	short seed_00;
	short sVar2;

	std::memset(forward, 0xff, 0xa0);
	gSrgLastRnd = seed;
	srgenRandom(0, 0xa0);
	sVar2 = 0;
	do
	{
		sVar1 = srgenRandom(0, 0xa0);
		if (*(char *)((int)sVar1 + (ulonglong)forward) != -1)
		{
			seed_00 = 1;
			while (true)
			{
				sVar1 = srgenRandom(seed_00, 0xa0);
				if (*(char *)((int)sVar1 + (ulonglong)forward) == -1)
					break;
				seed_00 = seed_00 + 1;
			}
		}
		*(char *)((int)sVar1 + (ulonglong)forward) = (char)sVar2;
		*(char *)((int)sVar2 + (ulonglong)reverse) = (char)sVar1;
		sVar2 = sVar2 + 1;
	} while (sVar2 < 0xa0);
	return;
}

// manord: 0805bdcc
// Manorsrvr.exe: 00414a00
int SrgDecode(char *str, uint *userID, uint *expires, short *productID, short *maxOccupancy,
              const void *table)
{
	char cVar1;
	size_t sVar2;
	uint uVar3;
	uint uVar4;
	int iVar5;
	uint uVar6;
	char *__dest;
	char *__s;
	ushort uVar7;
	char *pcVar8;
	byte local_259;
	uint local_258[4];
	undefined4 local_248;
	undefined1 local_244[160];
	int local_1a4[40];
	char local_104[256];

	local_259 = 10;
	*productID = 0;
	if (userID != NULL)
	{
		*userID = 0;
	}
	*expires = 0;
	*maxOccupancy = 0x19;
	__s = local_104;
	__dest = __s;
	pcVar8 = str;
	do
	{
		std::strcpy(__dest, pcVar8);
		sVar2 = std::strspn(__s, RGCnvrsnTbl);
		uVar6 = sVar2 & 0xffff;
		uVar4 = 0xffffffff;
		pcVar8 = __s;
		uVar4 = std::strlen(pcVar8);
		if (uVar6 == ~uVar4 - 1)
			break;
		__dest = __s + uVar6;
		pcVar8 = local_104 + uVar6 + 1;
	} while (true);
	iVar5 = -1;
	pcVar8 = __s;
	iVar5 = std::strlen(pcVar8);
	if (iVar5 == -0x25)
	{
		uVar7 = 0;
		do
		{
			srgBase36(__s, local_258 + uVar7);
			uVar3 = ntohl(local_258[uVar7]);
			local_258[uVar7] = uVar3;
			__s = __s + 7;
			uVar7 = uVar7 + 1;
		} while (uVar7 < 5);
		if (table == NULL)
		{
			SrgEnPermtable(10, local_244, local_1a4);
			SrgEnDecrypt((byte *)local_258, &local_259, local_1a4);
		}
		else
		{
			SrgEnDecrypt((byte *)local_258, &local_259, table);
		}
		uVar7 = 0;
		do
		{
			uVar3 = ntohl(local_258[uVar7]);
			local_258[uVar7] = uVar3;
			uVar7 = uVar7 + 1;
		} while (uVar7 < 5);
		if (local_258[2] == (local_258[0] ^ local_258[1] ^ local_258[3] ^ local_248))
		{
			uVar4 = std::time(NULL);
			if (userID != NULL)
			{
				*userID = local_258[0];
			}
			*expires = local_258[1];
			*maxOccupancy = *(short *)((void *)(local_248 + 2));
			*productID = (short)local_248;
			strcpy(str, local_104);
			if (uVar4 <= local_258[1])
			{
				return 0;
			}
			*productID = 0;
			if (userID != NULL)
			{
				*userID = 0;
			}
			*expires = 0;
			*maxOccupancy = 0x19;
			return -1;
		}
	}
	return -1;
}
