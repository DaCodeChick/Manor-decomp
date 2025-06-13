#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/**
	 * @brief Encrypts or decrypts data using a key and a permutation table.
	 *
	 * @param data Pointer to the data to encrypt or decrypt.
	 * @param key Pointer to the encryption key.
	 * @param table Pointer to the permutation table.
	 */
	EXPORT void EnCrypt(void *data, void *key, const void *table);

	/**
	 * @brief Decrypts data using a key and a permutation table.
	 *
	 * @param data Pointer to the data to decrypt.
	 * @param key Pointer to the decryption key.
	 * @param table Pointer to the permutation table.
	 */
	EXPORT void EnDecrypt(void *data, void *key, const void *table);

	/**
	 * @brief Generates a permutation table based on a seed.
	 *
	 * @param seed Pointer to the seed value.
	 * @param forward Pointer to the forward permutation table.
	 * @param reverse Pointer to the reverse permutation table.
	 */
	EXPORT void EnPermtable(short seed, void *forward, const void *reverse);

	/**
	 * @brief Converts a float from host byte order to network byte order.
	 *
	 * @param f The float value to convert.
	 * @return The converted float value in network byte order.
	 */
	EXPORT float htonf(float f);

	/**
	 * @brief Converts a float from network byte order to host byte order.
	 *
	 * @param f The float value to convert.
	 * @return The converted float value in host byte order.
	 */
	EXPORT float ntohf(float f);

#ifdef __cplusplus
}
#endif // __cplusplus
