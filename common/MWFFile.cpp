#include "MWFFile.h"

// Manorsrvr.exe: 004165c0
MWFFile::MWFFile()
{
	m_bIsOpen = false;
	m_dwLastError = 0;
}

// Manorsrvr.exe: 004165d0
MWFFile::~MWFFile()
{
	if (m_bIsOpen != false)
	{
		CloseHandle(m_hFile);
	}
}

// Manorsrvr.exe: 004165f0
bool MWFFile::Create(LPCSTR lpFileName, ushort flags)
{
	HANDLE pvVar1;
	DWORD DVar2;
	DWORD dwCreationDisposition;

	m_bIsOpen = true;
	DVar2 = 0;
	if ((flags & MWF_READ) != 0)
	{
		DVar2 = GENERIC_READ;
	}
	if ((flags & MWF_WRITE) != 0)
	{
		DVar2 = DVar2 | GENERIC_WRITE;
	}
	if ((flags & MWF_TRUNCATE) == 0)
	{
		if ((flags & MWF_OPEN) == 0)
		{
			dwCreationDisposition = OPEN_EXISTING;
		}
		else
		{
			dwCreationDisposition = TRUNCATE_EXISTING;
		}
	}
	else
	{
		dwCreationDisposition = OPEN_ALWAYS;
	}
	pvVar1 =
	    CreateFileA(lpFileName, DVar2, 0, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);
	m_hFile = pvVar1;
	if ((m_hFile == (HANDLE)INVALID_HANDLE_VALUE) &&
	    ((m_dwLastError != ERROR_ALREADY_EXISTS || (dwCreationDisposition != OPEN_ALWAYS))))
	{
		DVar2 = ::GetLastError();
		m_dwLastError = DVar2;
		m_bIsOpen = false;
	}
	return m_bIsOpen;
}

// Manorsrvr.exe: 00416750
DWORD MWFFile::GetLastError() const
{
	return m_dwLastError;
}

// Manorsrvr.exe: 004166d0
DWORD MWFFile::Read(LPVOID lpBuffer, DWORD dwBytesToRead)
{
	BOOL BVar1;
	DWORD DVar2;
	DWORD local_c;

	BVar1 = ReadFile(m_hFile, lpBuffer, dwBytesToRead, &local_c, NULL);
	if (BVar1 == 0)
	{
		DVar2 = ::GetLastError();
		m_dwLastError = DVar2;
		local_c = 0xffffffff;
	}
	return local_c;
}

// Manorsrvr.exe: 00416690
DWORD MWFFile::Seek(LONG lDistanceToMove, byte bMoveMethod)
{
	DWORD DVar1;

	DVar1 = SetFilePointer(m_hFile, lDistanceToMove, NULL, (uint)bMoveMethod);
	if (DVar1 == INVALID_FILE_SIZE)
	{
		DVar1 = ::GetLastError();
		m_dwLastError = DVar1;
		DVar1 = INVALID_FILE_SIZE;
	}
	return DVar1;
}

// Manorsrvr.exe: 00416710
DWORD MWFFile::Write(LPCVOID lpBuffer, DWORD dwBytesToWrite)
{
	BOOL BVar1;
	DWORD DVar2;
	DWORD local_c;

	BVar1 = WriteFile(this->m_hFile, lpBuffer, dwBytesToWrite, &local_c, NULL);
	if (BVar1 == 0)
	{
		DVar2 = ::GetLastError();
		this->m_dwLastError = DVar2;
		local_c = INVALID_FILE_SIZE;
	}
	return local_c;
}
