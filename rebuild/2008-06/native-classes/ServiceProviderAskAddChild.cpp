// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// ServiceProvider::askAddChild 00575240 (vtable slot 2): only Service instances may be children.
#include "v8tree/Service.h"

namespace RBX {
	bool ServiceProvider::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Service*>(instance) != NULL;
	}
}
