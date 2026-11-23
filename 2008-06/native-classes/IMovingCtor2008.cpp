// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::IMoving::IMoving 00614bd0 (inactive): the novtable base stores no vptr, only
// iMovingManager (+4) = NULL and stepsToSleep (+8) = 0. Header: native-headers/v8world/IMoving.h.
#include "v8world/IMoving.h"

namespace RBX
{
	IMoving::IMoving()
		: iMovingManager(NULL),
		  stepsToSleep(0)
	{
	}
}
