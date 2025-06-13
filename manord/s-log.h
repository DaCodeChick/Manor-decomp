#pragma once

#include "../madwolf/typedefs.h"

/// @brief Closes the log file and releases any resources.
void CloseLog();

/**
 * @brief Dumps the contents of a memory block in hexadecimal format.
 *
 * @param data Pointer to the memory block to dump.
 * @param size Size of the memory block in bytes.
 */
void DbHexDump(const void *data, size_t size);
