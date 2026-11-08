// Inactive: globals and initializer require original data/link proof.
// >>> native-status (generated) -- do not edit >>>
// Guid | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 510e7432 | roc native-status --write
#include "util/Guid.h"
#include <windows.h>
#include <objbase.h>
#include <boost/thread/once.hpp>
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
