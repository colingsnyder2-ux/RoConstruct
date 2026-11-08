#pragma once
// >>> native-status (generated) -- do not edit >>>
// SimJob | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 75943d17 | roc native-status --write
// 2008-06 native RBX::SimJob declaration (inactive). Proposed from RTTI and the
// MovingNoPhysicsBase family; see tests/NativeHumanoidStates3SimJob.h for evidence.
#include <vector>
#include <list>
#include <boost/noncopyable.hpp>

namespace RBX {
class Assembly;
class SimJobTracker;

class SimJob : boost::noncopyable {
public:
    std::vector<SimJobTracker*> trackers;        // +0x04 (0x18 bytes)
    std::list<SimJob*>::iterator stageIterator;  // +0x1c
    SimJob();                                    // 005e50f0
    virtual ~SimJob() {}                         // 005e5150 (inlined by derived destructors)
    virtual Assembly* getAssembly() = 0;         // slot 1
    virtual Assembly* getAssembly2() = 0;        // slot 2
};
}