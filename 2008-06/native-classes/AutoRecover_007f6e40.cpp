// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <stdlib.h>

// INFERRED: opaque storage for the SignalDesc global at 0x97abec
struct SignalDescObj {
    void ctor(const char* name, const char* part);
};
extern SignalDescObj g_0097abec;

extern "C" void fn_007ffa30(void);

extern "C" void fn_007f6e40(void)
{
    g_0097abec.ctor("AssemblyAdded", "part");
    atexit(fn_007ffa30);
}
