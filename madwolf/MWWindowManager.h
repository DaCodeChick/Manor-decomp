#pragma once

#include "typedefs.h"

/// @brief Manages windows for the application.
class MWWindowManager
{
public:
	/// @brief Initializes the window manager.
	MWWindowManager();

private:
	undefined1 field0_0x0;
	undefined2 field2_0x2;
	undefined2 field3_0x4;
	HANDLE m_winLstSemaphore, m_winUpdtSemaphore;
};
