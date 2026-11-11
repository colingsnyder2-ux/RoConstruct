// >>> native-status (generated) -- do not edit >>>
// ProfiledRakPeer | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/2 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (+1) (chatgpt:gpt-6.1-sol)
// <<< native-status | src 35cf45a4 | roc native-status --write
#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
    RBX::Profiling::Mark mark(*profiler, false);
    return RakPeer::RunUpdateCycle();
}
