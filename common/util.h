#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/**
	 * @brief Encrypts or decrypts data using a key and a permutation table.
	 *
	 * @param data
	 * @param key
	 * @param table
	 */
	EXPORT void EnCrypt(void *data, void *key, const void *table);

	/**
	 * @brief Decrypts data using a key and a permutation table.
	 *
	 * @param data
	 * @param key
	 * @param table
	 */
	EXPORT void EnDecrypt(void *data, void *key, const void *table);

	/**
	 * @brief Generates a permutation table based on a seed.
	 *
	 * @param seed
	 * @param forward
	 * @param reverse
	 */
	EXPORT void EnPermtable(short seed, void *forward, const void *reverse);

	EXPORT float htonf(float f);

	EXPORT float ntohf(float f);

#ifdef __cplusplus
}
#endif // __cplusplus
