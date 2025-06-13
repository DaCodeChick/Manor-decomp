#pragma once

#include "../madwolf/typedefs.h"

/// @brief Structure to hold information about banned IP addresses.
struct IPBanRec
{
	IPBanRec *nextRec; ///< Pointer to the next record in the linked list.
};
