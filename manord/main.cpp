#include "../madwolf/typedefs.h"

#ifdef _WIN32
HANDLE gHeap = NULL;
#endif // _WIN32

// manord: 080a421c
const char gSrvRev[] = "Manor Server 1.1 decompiled";

// Manorsrvr.exe: 0041b9c0
static void InitMemory()
{
#ifdef _WIN32
	gHeap = GetProcessHeap();
#endif // _WIN32
	return;
}
