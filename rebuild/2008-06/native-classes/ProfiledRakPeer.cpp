// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
    RBX::Profiling::Mark mark(*profiler, false);
    return RakPeer::RunUpdateCycle();
}
