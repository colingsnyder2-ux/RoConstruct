// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <new>
#include <stdlib.h>

// INFERRED: global std::string object at 0x97da84 being dynamically initialized
extern "C" std::string g_0097da84;
// INFERRED: string literal data at 0x84da30 used as the initializer
extern "C" const char g_0084da30[];

// INFERRED: atexit destructor thunk for g_0097da84
extern "C" void __cdecl fn_008014b0(void);

extern "C" void __cdecl fn_007f9070(void)
{
    new (&g_0097da84) std::string(g_0084da30);
    atexit(fn_008014b0);
}
