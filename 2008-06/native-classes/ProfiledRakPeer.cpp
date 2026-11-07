// >>> native-status (generated) -- do not edit >>>
// ProfiledRakPeer | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 35cf45a4 | roc native-status --write
#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
    RBX::Profiling::Mark mark(*profiler, false);
    return RakPeer::RunUpdateCycle();
}
