// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Http::checkHttpResult (00569920) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// HttpResultCheck | 2008-06 | draft (byte proof at 00569920)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src c5db584c | roc native-status --write
#include <windows.h>
#include <stdexcept>
#include <G3D/format.h>
#include "util/Http.h"

void RBX::Http::checkHttpResult(bool success, const char* message)
{
    if (!success) {
        DWORD error = GetLastError();
        char text[256];
        if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), text, sizeof(text), NULL))
            throw std::runtime_error(G3D::format("%s: %s, err=0x%X", url.c_str(), message, error));
        throw std::runtime_error(G3D::format("%s: %s, %s", url.c_str(), message, text));
    }
}
