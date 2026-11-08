// >>> native-status (generated) -- do not edit >>>
// ProfiledRakPeer | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 35cf45a4 | roc native-status --write
#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
    RBX::Profiling::Mark mark(*profiler, false);
    return RakPeer::RunUpdateCycle();
}
