// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: stand-in for RBX::Reflection::SignalDesc<RBX::RunService, void(float)>.
// Its constructor is a __thiscall member, so ecx = object and edx is never loaded.
struct SignalDescStub {
    // ??0?$SignalDesc@VRunService@RBX@@$$A6AXM@Z@Reflection@RBX@@QAE@PBD0@Z (0x0041bd20)
    void ctor(const char* name, const char* arg);
};

// INFERRED: global object at 0x96ce90
extern SignalDescStub g_0096ce90;

// INFERRED: compiler-generated atexit destructor stub for the global above
extern "C" void fn_007fa760();

extern "C" void fn_007eef20()
{
    g_0096ce90.ctor("DocumentComplete", "url");
    atexit(fn_007fa760);
}
