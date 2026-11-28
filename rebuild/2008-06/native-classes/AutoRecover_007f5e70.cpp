// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Hopper.cpp defines a static SignalDesc for RunService with signature void(float);
// the vendor headers are not available here, so a minimal local declaration is used.
// The constructor symbol and the global address come from the disassembly.

namespace RBX {
class RunService;
namespace Reflection {
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    ~SignalDesc();
};
}
}

// INFERRED: the constructor is defined elsewhere, so only the template declaration is given.
// The destructor registered through atexit is the function at 0x7fefb0.

namespace RBX {
namespace Reflection {
template<> SignalDesc<RunService, void(float)>::SignalDesc(const char* name, const char* arg);
}
}

namespace RBX {
static Reflection::SignalDesc<RunService, void(float)> desc_Selected("Selected", "mouse");
}
