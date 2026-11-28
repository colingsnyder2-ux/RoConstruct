// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/RunStateOwner.h"

// INFERRED: The constructor is emitted out of line in the target.
template<>
__declspec(noinline) RBX::Reflection::SignalDesc<RBX::RunService, void(float)>::SignalDesc(
    const char* name, const char* arg1name);

RBX::Reflection::SignalDesc<RBX::RunService, void(float)> event_Idled("Idled", "time");
