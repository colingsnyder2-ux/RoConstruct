// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <stdlib.h>

namespace RBX {
class RunService;
namespace Reflection {
template<class T, class Signature>
class SignalDesc {
public:
    SignalDesc(const char*, const char*);
};
}
}

// INFERRED: Storage type follows the constructor at 0x0064e590.
extern "C" RBX::Reflection::SignalDesc<RBX::RunService, void(float)> g_0097d878;
extern "C" void __cdecl fn_00801380();

extern "C" void __cdecl fn_007f8dc0()
{
    new (&g_0097d878) RBX::Reflection::SignalDesc<RBX::RunService, void(float)>(
        "KeyDown", "Key");
    atexit(fn_00801380);
}
