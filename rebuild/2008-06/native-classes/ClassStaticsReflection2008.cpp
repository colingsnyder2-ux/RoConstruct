// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Reflection::ClassDescriptor::lockedDown (inactive): bool 00974c85 (.bss, 0; DescribedBase ctor
// 0055b780 sets it to 1 -- see DescribedInstanceCtor.cpp). Header: native-headers/reflection/object.h.
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		bool ClassDescriptor::lockedDown = false;
	}
}
