// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: SignalDesc<RunService, void(float)> modeled as a struct with a thiscall constructor-like member
struct SignalDescObj {
    void init(const char* name, const char* arg);
};

// INFERRED: global SignalDesc object
extern SignalDescObj g_00976164;

// INFERRED: atexit destructor stub for the global descriptor
extern "C" void __cdecl fn_007fdfa0();

extern "C" void fn_007f4b70()
{
    // INFERRED: string literals "Touched" and "part"
    g_00976164.init("Touched", "part");
    atexit(fn_007fdfa0);
}
