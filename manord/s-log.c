#include "s-log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// manord: 080a3130
static FILE *gLogFile = NULL;

// manord: 080a36f0
static bool gNoFork = false;

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

// manord: 0804c044
// Manorsrvr.exe: 00406b80
void DbHexDump(const void *data, size_t size)
{
	char cVar1;
	uint uVar2;
	uint uVar3;
	uint uVar4;
	const void *pvVar5;
	char local_130[32];
	char local_110[256];

	uVar4 = 0;
	pvVar5 = data;
	if (size != 0)
	{
		do
		{
			local_110[0] = '\0';
			sprintf(local_130, "%08lX_(%08lX): ", pvVar5, uVar4);
			strcat(local_110, local_130);
			uVar3 = uVar4;
			if (uVar4 < uVar4 + 0x10)
			{
				do
				{
					if (uVar3 < size)
					{
						sprintf(local_130, "%02X", (uint) * (byte *)(uVar3 + (size_t)data));
					}
					else
					{
						sprintf(local_130, "   ", pvVar5);
					}
					strcat(local_110, local_130);
					uVar3 = uVar3 + 1;
				} while (uVar3 < uVar4 + 0x10);
			}
			sprintf(local_130, "   ", pvVar5);
			strcat(local_110, local_130);
			uVar2 = strlen(local_110);
			for (uVar3 = uVar4; (uVar3 < uVar4 + 0x10 && (uVar3 < size)); uVar3 = uVar3 + 1)
			{
				cVar1 = *(char *)(uVar3 + (int)data);
				if ((cVar1 < ' ') || (0xd9 < cVar1))
				{
					local_110[uVar2 & 0xffff] = '.';
				}
				else
				{
					local_110[uVar2 & 0xffff] = cVar1;
				}
				uVar2 = uVar2 + 1;
			}
			local_110[uVar2 & 0xffff] = '\0';
			// LogString(NULL,"dbhexdmp","%s",local_110);
			uVar4 = uVar4 + 0x10;
			pvVar5 = (void *)((size_t)pvVar5 + 0x10);
		} while (uVar4 < size);
	}
	return;
}

// manord: 080484e8
// Manorsrvr.exe: 00411820
int LogString(const ServerUserRec *user, const char *level, const char *format, ...)
{
	struct tm *__tp;
	int iVar1;
	time_t local_51c;
	char local_518[256];
	char local_418[20];
	char local_404[512];
	char local_204[512];
	va_list args;

	va_start(args, format);
	vsnprintf(local_204, 0x200, format, args);
	va_end(args);
	time(&local_51c);
	__tp = localtime(&local_51c);
	strftime(local_418, 0x14, "%m/%d/%Y %H:%M:%S", __tp);
	/*UsGetUserLogInfo(user,local_518);
	snprintf(local_404,0x200,"%s %s %8.8s %s\n",local_418,local_518,level,
	         local_204);*/
	snprintf(local_404, 0x200, "%s %8.8s %s\n", local_418, level, local_204);
	if (gLogFile == NULL)
	{
		iVar1 = fprintf(stderr, "%s", local_404);
	}
	else
	{
		fputs(local_404, gLogFile);
		iVar1 = fflush_locked(gLogFile);
	}
	if (gNoFork)
	{
		iVar1 = printf("%s", local_404);
	}
	return iVar1;
}
