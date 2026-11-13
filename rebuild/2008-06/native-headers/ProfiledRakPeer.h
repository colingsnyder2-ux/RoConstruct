#pragma once
// >>> native-status (generated) -- do not edit >>>
// ProfiledRakPeer | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src cde609bb | roc native-status --write

#include "RakPeer.h"
#include "util/Profiling.h"

class ProfiledRakPeer : public RakPeer
{
    RBX::Profiling::CodeProfiler* profiler;

public:
    explicit ProfiledRakPeer(RBX::Profiling::CodeProfiler* profiler) : profiler(profiler) {}
    virtual bool RunUpdateCycle();
};
