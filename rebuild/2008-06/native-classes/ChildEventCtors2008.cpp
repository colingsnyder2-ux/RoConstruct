// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ChildAdded::ChildAdded(Instance*) 00594e00 (inactive): shared_from(instance) into the payload's shared_ptr
// (call 00618a40). ChildRemoved's constructor is identical code (folded in the exe).
#include "v8tree/Instance.h"

namespace RBX
{
	ChildAdded::ChildAdded(Instance* child)
		: child(shared_from(child))
	{
	}

	ChildRemoved::ChildRemoved(Instance* child)
		: child(shared_from(child))
	{
	}
}
