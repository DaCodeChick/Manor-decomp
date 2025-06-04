#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/// @brief Opaque structure representing a thread.
	typedef struct OpaqueMWThread MWThread;

	/**
	 * @brief Create a semaphore.
	 * @param name The name of the semaphore.
	 * @return A handle to the created semaphore.
	 */
	EXPORT HANDLE MWF_CreateSemaphore(const char *name);

	/**
	 * @brief Delete a semaphore.
	 *
	 * @param semaphore The semaphore to delete.
	 */
	EXPORT void MWF_DeleteSemaphore(HANDLE semaphore);

	/**
	 * @brief Release a semaphore.
	 *
	 * @param semaphore The semaphore to release.
	 */
	EXPORT void MWF_ReleaseSemaphore(HANDLE semaphore);

	/**
	 * @brief Try to acquire a semaphore.
	 * @param semaphore The semaphore to acquire.
	 * @return TRUE if the semaphore was acquired, FALSE otherwise.
	 */
	EXPORT BOOL MWF_TrySemaphore(HANDLE semaphore);

	/// @brief Unlock the offscreen buffer.
	EXPORT void MWF_UnlockOffscreen();

	/**
	 * @brief Wait for a semaphore to be released.
	 *
	 * @param semaphore The semaphore to wait for.
	 */
	EXPORT void MWF_WaitSemaphore(HANDLE semaphore);

	/// @brief Yield the current thread.
	EXPORT void MWF_YieldThread();

#ifdef __cplusplus
}
#endif // __cplusplus
