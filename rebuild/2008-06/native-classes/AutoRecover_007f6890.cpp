// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local declarations; the real headers are not shown, so the types are reproduced here.
#include <stdlib.h>

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
    static Reflection::SignalDesc<Humanoid, void(float)> event_Climbing;
};
}

// INFERRED: the original constructor is SignalDesc<RunService,...>; the matching address 0x5dac60 is shared.
// The definition below constructs the static with the two string arguments.
RBX::Reflection::SignalDesc<RBX::Humanoid, void(float)> RBX::Humanoid::event_Climbing("Climbing", "speed");
