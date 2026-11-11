// >>> native-status (generated) -- do not edit >>>
// GuidGeneration | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src dfcd999b | roc native-status --write
#include "util/Guid.h"
#include <windows.h>
#include <objbase.h>

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
}
