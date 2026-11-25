// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the disassembly's callee comment names SignalDesc<RunService, void(float)>'s
// constructor, but the target's own symbol is SignalDesc<Humanoid, void(float)>, so I declare it by hand here.
// INFERRED: the object is at 0x97a504 and the constructor and atexit helper are at the addresses shown.

namespace RBX {
class Humanoid;
namespace Reflection {
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* arg);
    ~SignalDesc();
};
}
class Humanoid {
public:
    static Reflection::SignalDesc<Humanoid, void(float)> event_Running;
};
Reflection::SignalDesc<Humanoid, void(float)> Humanoid::event_Running("Running", "speed");
}
