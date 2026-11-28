// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: stand-in for RBX::Reflection::SignalDesc<RBX::RunService, void(float)>.
// Its constructor is a __thiscall member, so ecx = object and edx is never loaded.
struct SignalDescStub {
    // ??0?$SignalDesc@VRunService@RBX@@$$A6AXM@Z@Reflection@RBX@@QAE@PBD0@Z (0x005e1490)
    void ctor(const char* name, const char* arg);
};

// INFERRED: global object at 0x96ce90
extern SignalDescStub g_0097a88c;

// INFERRED: compiler-generated atexit destructor stub for the global above
extern "C" void fn_007ff8c0();

extern "C" void fn_007f69b0()
{
    g_0097a88c.ctor("DocumentComplete", "url");
    atexit(fn_007ff8c0);
}
