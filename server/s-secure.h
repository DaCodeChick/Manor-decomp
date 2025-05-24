#pragma once

#include "../common/typedefs.h"

int SrgDecode(const char *str, uint *userID, uint *expires, short *productID, short *maxOccupancy,
              const void *decryptionTable);
