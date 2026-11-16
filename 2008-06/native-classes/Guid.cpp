// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// Inactive: globals and initializer require original data/link proof.
#include "util/Guid.h"
#include <windows.h>
#include <objbase.h>
#include <boost/thread/once.hpp>
#include "../../../tools/rbxgs/Client/App/include/util/Guid.h"

const RBX::Name* localScope = NULL;
LONG nextIndex = 0;
void initLocalScope()
{
    std::string guid;
    RBX::Guid::generateGUID(guid);
    localScope = &RBX::Name::declare(guid.c_str(), -1);
}
namespace RBX {
__declspec(noinline) void makeGuidString(std::string& result)
{
    GUID guid;
    CoCreateGuid(&guid);
    wchar_t wide[64] = {0};
    StringFromGUID2(guid, wide, 64);
    char ansi[64];
    WideCharToMultiByte(0, 0, wide, 64, ansi, 64, 0, 0);
    result = ansi;
}
void Guid::generateGUID(std::string& result)
{
    makeGuidString(result);
    result = "RBX" + result;
    result.erase(40, 1);
    result.erase(27, 1);
    result.erase(22, 1);
    result.erase(17, 1);
    result.erase(12, 1);
    result.erase(3, 1);
}
Guid::Guid()
{
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(initLocalScope, flag);
    data.scope = localScope;
    data.index = InterlockedIncrement(&nextIndex);
}
}

namespace RBX {
int Guid::compare(const Guid* a, const Guid* b)
{
	Name* x = a ? const_cast<Name*>(a->data.scope) : 0;
	Name* y = b ? const_cast<Name*>(b->data.scope) : 0;
	int r = Name::compare(*x, *y);
	switch (r)
	{
	case -1:
		return -1;
	case 0:
	{
		int i = a ? a->data.index : 0;
		int j = b ? b->data.index : 0;
		if (i > j)
			return 1;
		return i < j ? -1 : 0;
	}
	default:
		return r == 1;
	}
}
}

