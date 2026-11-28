// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: SignalDesc constructor modeled as a thiscall member on an opaque struct
struct SignalDescOpaque {
    void ctor(const char* name, const char* argName);
};
extern SignalDescOpaque g_0097ac20;

extern "C" void fn_007ff9f0(void);

extern "C" void fn_007f6e60()
{
    g_0097ac20.ctor("AssemblyRemoved", "part");
    atexit(fn_007ff9f0);
}
