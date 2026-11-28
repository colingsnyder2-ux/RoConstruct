// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <stdlib.h>

namespace RBX {
class RunService;
namespace Reflection {
template<class C, class S>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    char pad[64]; // INFERRED: size unknown
};
}
}

typedef RBX::Reflection::SignalDesc<RBX::RunService, void(float)> StrafingDesc;

// INFERRED: global signal descriptor at 0x97a348
extern StrafingDesc g_0097a348;

// INFERRED: atexit destructor thunk for g_0097a348 at 0x7ff500
extern "C" void __cdecl fn_007ff500(void);

extern "C" void __cdecl fn_007f6910(void)
{
    new (&g_0097a348) StrafingDesc("Strafing", "active");
    atexit(fn_007ff500);
}
