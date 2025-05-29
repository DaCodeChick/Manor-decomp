#pragma once

#include "../common/typedefs.h"

/// @brief Manages threads for the MWF (Multi-Window Framework) application.
class MWFThreadManager
{
public:
	/// @brief Initializes the thread manager.
	MWFThreadManager();

private:
	undefined1 field0_0x0;
	undefined2 field2_0x2;
	undefined2 field3_0x4;
	HANDLE m_winLstSemaphore, m_winUpdtSemaphore;
};
