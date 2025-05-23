#include "s-user.h"

static ServerUserRec *gUserList = NULL;

// manord: 080523c4
ServerUserRec *usIsUser(ServerUserRec *user)
{
	ServerUserRec *pSVar1;

	pSVar1 = gUserList;
	if (gUserList != NULL)
	{
		do
		{
			if (pSVar1 == user)
			{
				return pSVar1;
			}
			pSVar1 = pSVar1->nextUser;
		} while (pSVar1 != NULL);
	}
	return pSVar1;
}
