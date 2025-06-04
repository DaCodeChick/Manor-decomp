#pragma once

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/**
	 * @brief Decode a string into user ID, expiration date, product ID, and maximum occupancy.
	 *
	 * @param str The string to decode
	 * @param userID Pointer to store the decoded user ID.
	 * @param expires Pointer to store the decoded expiration date (as a Unix timestamp).
	 * @param productID Pointer to store the decoded product ID.
	 * @param maxOccupancy Pointer to store the decoded maximum occupancy.
	 * @param decryptionTable Pointer to a decryption table used for decoding the string.
	 * @return 0 on success, or a non-zero error code on failure.
	 */
	EXPORT int SrgDecode(const char *str, uint *userID, uint *expires, short *productID,
	                     short *maxOccupancy, const void *decryptionTable);

#ifdef __cplusplus
}
#endif // __cplusplus
