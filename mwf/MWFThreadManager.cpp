#include "MWFThreadManager.h"
#include "MWF.h"

// The Manor.exe: 0041e4e0
MWFThreadManager::MWFThreadManager()
{
	HANDLE pvVar1;

	this->field2_0x2 = 0;
	this->field3_0x4 = 100;
	pvVar1 = MWF_CreateSemaphore("WinLstSemaphore");
	this->m_winLstSemaphore = pvVar1;
	pvVar1 = MWF_CreateSemaphore("WinUpdtSemaphore");
	this->m_winUpdtSemaphore = pvVar1;
	this->field0_0x0 = 0;
}
