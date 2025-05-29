#pragma once

#include "typedefs.h"

/// @brief Manages threads for the application.
class MWThreadManager
{
public:
	/// @brief Initializes the thread manager.
	MWThreadManager();

private:
	undefined1 field0_0x0;
	undefined2 field2_0x2;
	undefined2 field3_0x4;
	HANDLE m_winLstSemaphore, m_winUpdtSemaphore;
};
