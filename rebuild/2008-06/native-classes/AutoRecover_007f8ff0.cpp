// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <new>
#include <stdlib.h>

// INFERRED: global std::string at 0x97da68 holding "q0adorn"; storage defined elsewhere
extern std::string g_0097da68;

// INFERRED: atexit destructor stub for g_0097da68 at 0x801470
extern "C" void __cdecl fn_00801470(void);

extern "C" void __cdecl fn_007f8ff0(void)
{
    new (&g_0097da68) std::string("q0adorn");
    atexit(fn_00801470);
}
