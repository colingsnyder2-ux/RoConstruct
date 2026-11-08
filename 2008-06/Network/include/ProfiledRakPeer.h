#pragma once
// >>> native-status (generated) -- do not edit >>>
// ProfiledRakPeer | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
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
