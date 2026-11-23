// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Instance::getClassNameStr 0041f2b0 (inactive): the std::string copy of the Name returned by the
// virtual AbstractFactoryProduct::getClassName (slot 1 of the sub-object at +0x10), Name::name at +4.
#include "v8tree/Instance.h"
#include "util/Name.h"

namespace RBX
{
	std::string Instance::getClassNameStr() const
	{
		return getClassName().toString();
	}
}
