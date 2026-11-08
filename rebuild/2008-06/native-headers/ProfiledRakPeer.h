#pragma once

#include "RakPeer.h"
#include "util/Profiling.h"

class ProfiledRakPeer : public RakPeer
{
    RBX::Profiling::CodeProfiler* profiler;

public:
    explicit ProfiledRakPeer(RBX::Profiling::CodeProfiler* profiler) : profiler(profiler) {}
    virtual bool RunUpdateCycle();
};
