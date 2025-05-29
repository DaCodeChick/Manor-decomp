#pragma once

#include "../common/typedefs.h"

/// @brief A class for handling file operations in a platform-independent manner.
class EXPORT MWFFile
{
public:
	enum
	{
		MWF_READ = 0x0001,     /// Open the file for reading.
		MWF_WRITE = 0x0002,    /// Open the file for writing.
		MWF_TRUNCATE = 0x0004, /// Truncate the file to zero length if it exists.
		MWF_OPEN = 0x0008,     /// Open the file if it exists.
	};

	/// @brief Default constructor for the MWFFile class.
	MWFFile();

	/// @brief Destructor for the MWFFile class.
	~MWFFile();

	/**
	 * @brief Opens a file with the specified name and flags.
	 *
	 * @param lpFileName The name of the file to open.
	 * @param flags The flags to use when opening the file (e.g., read, write, truncate).
	 * @return True if the file was opened successfully, false otherwise.
	 */
	bool Create(LPCSTR lpFileName, ushort flags);

	DWORD GetLastError() const;

	DWORD Read(LPVOID lpBuffer, DWORD dwBytesToRead);

	/**
	 * @brief Moves the file pointer to a specified position in the file.
	 *
	 * @param lDistanceToMove The distance to move the file pointer.
	 * @param bMoveMethod The method to use for moving the file pointer (e.g., beginning, current
	 * position, end).
	 * @return The new position of the file pointer, or INVALID_SET_FILE_POINTER if an error
	 * occurred.
	 */
	DWORD Seek(LONG lDistanceToMove, byte bMoveMethod);

	/**
	 * @brief Writes data to the file.
	 *
	 * @param lpBuffer Pointer to the data to write.
	 * @param dwBytesToWrite Number of bytes to write.
	 * @return The number of bytes written, or 0 if an error occurred.
	 */
	DWORD Write(LPCVOID lpBuffer, DWORD dwBytesToWrite);

private:
	HANDLE m_hFile;
	bool m_bIsOpen;
	DWORD m_dwLastError;
};
