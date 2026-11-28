// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

namespace RBX {
class RunService;
namespace Reflection {
template<class C, class Sig> class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    char data[0x40];
};
}
}

typedef RBX::Reflection::SignalDesc<RBX::RunService, void(float)> DescendantAddedDesc;

// INFERRED: global signal descriptor at 0x973e40, constructed by static initializer
extern DescendantAddedDesc g_00973e40;

extern "C" void fn_007fca80();

// INFERRED: the original is the static-initializer for a global with a constructor
// and an atexit-registered destructor; the callee is declared as a plain function.
extern "C" void fn_007f2b50()
{
    // INFERRED: call the constructor directly on the global, no EH frame needed
    DescendantAddedDesc* p = &g_00973e40;
    p->DescendantAddedDesc::SignalDesc("DescendantAdded", "descendant");
    atexit(fn_007fca80);
}
