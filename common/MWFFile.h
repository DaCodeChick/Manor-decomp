#pragma once

#include "typedefs.h"

class MWFFile
{
public:
	enum
	{
		MWF_READ = 0x0001,
		MWF_WRITE = 0x0002,
		MWF_TRUNCATE = 0x0004,
		MWF_OPEN = 0x0008,
	};

	MWFFile();
	~MWFFile();
	bool Create(LPCSTR lpFileName, ushort flags);
	DWORD GetLastError() const;
	DWORD Read(LPVOID lpBuffer, DWORD dwBytesToRead);
	DWORD Seek(LONG lDistanceToMove, byte bMoveMethod);

private:
	HANDLE m_hFile;
	bool m_bIsOpen;
	DWORD m_dwLastError;
};
