#include "MWF.h"

struct
{
	HANDLE h;
	uint threadID;
} MWFThread;

// Manorsrvr.exe: 0041cdd0
// The Manor.exe: 0040f510
HANDLE MWF_CreateSemaphore(void)
{
	HANDLE pvVar1;
	pvVar1 = CreateMutexA(NULL, 0, NULL);
	return pvVar1;
}

// Manorsrvr.exe: 0041cdf0
// The Manor.exe: 0040f530
void MWF_DeleteSemaphore(HANDLE semaphore)
{
	CloseHandle(semaphore);
	return;
}

// Manorsrvr.exe: 0041ce60
// The Manor.exe: 0040f5c0
void MWF_ReleaseSemaphore(HANDLE semaphore)
{
	ReleaseMutex(semaphore);
	return;
}

// Manorsrvr.exe: 0041ce00
// The Manor.exe: 0040f540
BOOL MWF_TrySemaphore(HANDLE semaphore)
{
	DWORD DVar1;

	DVar1 = WaitForSingleObject(semaphore, 0);
	if (DVar1 == WAIT_ABANDONED)
	{
		DVar1 = WaitForSingleObject(semaphore, 0);
	}
	return DVar1 == 0;
}

// Manorsrvr.exe: 0041ce30
// The Manor.exe: 0040f580
void MWF_WaitSemaphore(HANDLE semaphore)
{
	DWORD DVar1;

	DVar1 = WaitForSingleObject(semaphore, 0xffffffff);
	if (DVar1 == WAIT_ABANDONED)
	{
		WaitForSingleObject(semaphore, 0);
	}
	return;
}

// Manorsrvr.exe: 0041cdc0
// The Manor.exe: 0040f500
void MWF_YieldThread(void)
{
	return;
}
