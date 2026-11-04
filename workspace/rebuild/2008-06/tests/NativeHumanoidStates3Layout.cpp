#include "../native-headers/humanoid/HumanoidStates3.h"
#include <stddef.h>
using namespace RBX::HUMAN;
// Factory 00643660 allocates 0xa0 for Seated, Dead and FallingDown and 0x114 for
// RunningNoPhysics/StrafingNoPhysics; MovingNoPhysicsBase ctor 0066f070 and dtor 0066ee10
// touch SimJob at +0xa0, +0xc4/+0xc8, +0xcc, +0xd0..+0xe0 and the CoordinateFrame at +0xe4.
typedef char SeatedSize[sizeof(Seated) == 0xa0 ? 1 : -1];
typedef char DeadSize[sizeof(Dead) == 0xa0 ? 1 : -1];
typedef char FallingDownSize[sizeof(FallingDown) == 0xa0 ? 1 : -1];
typedef char FallingDownValue0c[offsetof(FallingDown, value0c) == 0x0c ? 1 : -1];
RBX::HitTestFilter* seatedFilter(Seated* state) { return state; }
#ifdef NATIVE_SIMJOB_PENDING
typedef char SimJobSize[sizeof(RBX::SimJob) == 0x24 ? 1 : -1];
typedef char SimJobTrackers[offsetof(RBX::SimJob, trackers) == 0x04 ? 1 : -1];
typedef char SimJobIterator[offsetof(RBX::SimJob, stageIterator) == 0x1c ? 1 : -1];
typedef char MovingTorso[offsetof(MovingNoPhysicsBase, torso) == 0xc4 ? 1 : -1];
typedef char MovingPhysics[offsetof(MovingNoPhysicsBase, physicsService) == 0xcc ? 1 : -1];
typedef char MovingConnection[offsetof(MovingNoPhysicsBase, connection) == 0xd0 ? 1 : -1];
typedef char MovingFrame[offsetof(MovingNoPhysicsBase, frame) == 0xe4 ? 1 : -1];
typedef char MovingSize[sizeof(MovingNoPhysicsBase) == 0x114 ? 1 : -1];
typedef char RunningNoPhysicsSize[sizeof(RunningNoPhysics) == 0x114 ? 1 : -1];
typedef char StrafingNoPhysicsSize[sizeof(StrafingNoPhysics) == 0x114 ? 1 : -1];
RBX::SimJob* movingJob(RunningNoPhysics* state) { return state; }
#endif
