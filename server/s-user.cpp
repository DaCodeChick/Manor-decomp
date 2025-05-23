#include "s-user.h"

static ServerUserRec *gUserList = NULL;

// manord: 080523e4
bool UsIsUser(ServerUserRec *user)
{
	ServerUserRec *pSVar2;

	pSVar2 = gUserList;
	if (gUserList != NULL)
	{
		do
		{
			if (pSVar2 == user)
			{
				return true;
			}
			pSVar2 = pSVar2->nextUser;
		} while (pSVar2 != NULL);
	}
	return false;
}

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
