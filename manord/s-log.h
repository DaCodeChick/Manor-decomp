#pragma once

#include "s-user.h"

/// @brief Closes the log file and releases any resources.
void CloseLog();

/**
 * @brief Dumps the contents of a memory block in hexadecimal format.
 *
 * @param data Pointer to the memory block to dump.
 * @param size Size of the memory block in bytes.
 */
void DbHexDump(const void *data, size_t size);

/**
 * @brief Logs a formatted error message and exits the program.
 *
 * @param format Format string (printf-style).
 * @param ... Additional arguments for the format string.
 */
void ErrorExit(const char *format, ...);

/** @brief Logs a formatted string to the log file.
 *
 * @param user Pointer to the user record.
 * @param level Logging level (e.g., "debug", "errext").
 * @param format Format string (printf-style).
 * @param ... Additional arguments for the format string.
 * @return Number of characters written to the log file, or a negative value on error.
 */
int LogString(const ServerUserRec *user, const char *level, const char *format, ...);
