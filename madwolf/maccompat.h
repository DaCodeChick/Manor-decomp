#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	typedef struct OpaqueHandle *Handle;

	enum
	{
		noErr = 0,        /// No error occurred.
		memFullErr = -108 /// Memory full error.
	};

	/**
	 * @brief Disposes a handle.
	 *
	 * @param handle Handle to be disposed.
	 */
	EXPORT void DisposeHandle(Handle handle);

	/**
	 * @brief Disposes a pointer.
	 *
	 * @param ptr Pointer to be disposed.
	 */
	EXPORT void DisposePtr(void *ptr);

	/**
	 * @brief Gets the size of a handle.
	 *
	 * @param handle Handle whose size is to be retrieved.
	 * @return Size of the handle in bytes.
	 */
	EXPORT size_t GetHandleSize(const Handle handle);

	/**
	 * @brief Gets the size of a pointer.
	 *
	 * @param ptr Pointer whose size is to be retrieved.
	 * @return Size of the pointer in bytes.
	 */
	EXPORT size_t GetPtrSize(const void *ptr);

	/**
	 * @brief Checks for memory errors.
	 *
	 * @return Memory error code, 0 if no error occurred.
	 */
	EXPORT short MemError();

	/**
	 * @brief Allocates a new handle with the specified size.
	 *
	 * @param size Size of the handle to be allocated in bytes.
	 * @return Handle to the newly allocated handle, or NULL if memory allocation failed.
	 */
	EXPORT Handle NewHandle(size_t size);

	/**
	 * @brief Allocates a new handle with the specified size and clears it.
	 *
	 * @param size Size of the handle to be allocated in bytes.
	 * @return Handle to the newly allocated and cleared handle, or NULL if memory allocation
	 * failed.
	 */
	EXPORT Handle NewHandleClear(size_t size);

	/**
	 * @brief Allocates a new pointer with the specified size.
	 *
	 * @param size Size of the pointer to be allocated in bytes.
	 * @return Pointer to the newly allocated memory, or NULL if memory allocation failed.
	 */
	EXPORT void *NewPtr(size_t size);

	/**
	 * @brief Allocates a new pointer with the specified size and clears it.
	 *
	 * @param size Size of the pointer to be allocated in bytes.
	 * @return Pointer to the newly allocated and cleared memory, or NULL if memory allocation
	 * failed.
	 */
	EXPORT void *NewPtrClear(size_t size);

	/**
	 * @brief Reallocates a handle to a new size.
	 *
	 * @param handle Handle to be reallocated.
	 * @param size New size for the handle in bytes.
	 */
	EXPORT void ReallocateHandle(Handle handle, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus
