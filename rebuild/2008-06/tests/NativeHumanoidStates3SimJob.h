#pragma once
// Proposed declaration for RBX::SimJob (2008-06); no native or donor header exists.
// tests/record_native_humanoid_states3.py copies this to out/humanoid-states3-overlay/v8world/SimJob.h.
// Evidence:
// - RTTI .?AVSimJob@RBX@@ (vtable 0083f72c: 005e5190 deleting dtor, two __purecall slots);
//   bases SimJob, boost::noncopyable at +4.
// - constructor 005e50f0: vptr; new(4) storing &this->+4 (VS2008 secure-SCL container aux
//   pointer) at +4; zeroes +0x10/+0x14/+0x18 (vector first/last/end) and +0x1c/+0x20.
// - destructor 005e5150: delete +0x10 when non-null, zero +0x10..+0x18, delete +4: the
//   inline std::vector destructor. 005e5200 searches the vector with 4-byte elements whose
//   +0 is a SimJob* (removal from 005e5320/005e5350); element type name is an analog.
// - SimJobStage 0064d0f0 inserts the job into a std::list<SimJob*> at stage+0x10 and stores
//   the resulting iterator (container, node) at +0x1c/+0x20; it calls vtable slot 2.
// - AssemblySimJob (vtable 0083f73c, ctor 005e51e0) stores an Assembly* at +0x24 and
//   returns it from both slots 1 and 2 (0074eed0). Slot names are analog names.
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
