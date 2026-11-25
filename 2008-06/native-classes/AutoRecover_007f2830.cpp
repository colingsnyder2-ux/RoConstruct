// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the original defines a static SignalDesc in RunStateOwner.cpp.
// A header for this template is not available, so a minimal local declaration is used.
// Its constructor is emitted at 0x556960 and the destructor at 0x7fc810 (the atexit handler).

namespace RBX {
class RunService;
namespace Reflection {
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg0);
    ~SignalDesc();
};
}

// INFERRED: the object lives at 0x973b40 as a static of type SignalDesc<RunService, void(float)>
static Reflection::SignalDesc<RunService, void(float)> event_Heartbeat("Heartbeat", "interval");
}
