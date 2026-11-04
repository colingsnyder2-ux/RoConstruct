#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
    RBX::Profiling::Mark mark(*profiler, false);
    return RakPeer::RunUpdateCycle();
}
