// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080b716[];   // INFERRED: unnamed global at 0x0080b716 in the original
// INFERRED: header path for RBX::Name; the global at 0x9739d0 is a pointer to the null Name.
#include "util/Name.h"

const RBX::Name* g_009739d0;

void initNullName()
{
    // INFERRED: string literal at ((int)&g_0080b716) is the null name text (likely "")
    g_009739d0 = &RBX::Name::declare((const char*)((int)&g_0080b716), 0);
}
