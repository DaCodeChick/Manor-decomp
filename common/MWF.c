#include "MWF.h"

// Manorsrvr.exe: 0041cdd0
HANDLE MWF_CreateSemaphore(void)
{
	HANDLE pvVar1;
	pvVar1 = CreateMutexA(NULL, 0, NULL);
	return pvVar1;
}

// Manorsrvr.exe: 0041cdf0
void MWF_DeleteSemaphore(HANDLE semaphore)
{
	CloseHandle(semaphore);
	return;
}

// Manorsrvr.exe: 0041ce60
void MWF_ReleaseSemaphore(HANDLE semaphore)
{
	ReleaseMutex(semaphore);
	return;
}

// Manorsrvr.exe: 0041ce00
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
void MWF_YieldThread(void)
{
	return;
}
