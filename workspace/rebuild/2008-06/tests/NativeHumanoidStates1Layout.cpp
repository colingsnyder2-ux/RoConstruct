#include "../native-headers/humanoid/HumanoidStates1.h"
#include <stddef.h>
using namespace RBX::HUMAN;
// Balancing ctor 0066e660 stores +0xa0/+0xa4; RunningBase ctor 00666980 zeroes +0xa8..+0xc8;
// factory 00643660 allocates 0xcc for Running, Landed and Climbing.
typedef char BalancingKP[offsetof(Balancing, kP) == 0xa0 ? 1 : -1];
typedef char BalancingKD[offsetof(Balancing, kD) == 0xa4 ? 1 : -1];
typedef char BalancingSize[sizeof(Balancing) == 0xa8 ? 1 : -1];
typedef char RunningBaseFloorVelocity[offsetof(RunningBase, floorVelocity) == 0xa8 ? 1 : -1];
typedef char RunningBaseFloorRot[offsetof(RunningBase, floorRotationalVelocity) == 0xb4 ? 1 : -1];
typedef char RunningBaseDesiredVelocity[offsetof(RunningBase, desiredVelocity) == 0xb8 ? 1 : -1];
typedef char RunningBaseDesiredYRotation[offsetof(RunningBase, desiredYRotation) == 0xc4 ? 1 : -1];
typedef char RunningBaseDesiredAltitude[offsetof(RunningBase, desiredAltitude) == 0xc8 ? 1 : -1];
typedef char RunningBaseSize[sizeof(RunningBase) == 0xcc ? 1 : -1];
typedef char RunningSize[sizeof(Running) == 0xcc ? 1 : -1];
typedef char LandedSize[sizeof(Landed) == 0xcc ? 1 : -1];
typedef char ClimbingSize[sizeof(Climbing) == 0xcc ? 1 : -1];
RBX::HitTestFilter* runningFilter(Running* state) { return state; }
