#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	typedef struct MWFThread;

	EXPORT HANDLE MWF_CreateSemaphore();
	EXPORT void MWF_DeleteSemaphore(HANDLE semaphore);
	EXPORT void MWF_ReleaseSemaphore(HANDLE semaphore);
	EXPORT BOOL MWF_TrySemaphore(HANDLE semaphore);
	EXPORT void MWF_UnlockOffscreen();
	EXPORT void MWF_WaitSemaphore(HANDLE semaphore);
	EXPORT void MWF_YieldThread();

#ifdef __cplusplus
}
#endif // __cplusplus
