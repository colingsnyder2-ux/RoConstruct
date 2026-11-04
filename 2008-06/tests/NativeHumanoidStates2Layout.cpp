#include "../native-headers/humanoid/HumanoidStates2.h"
#include <stddef.h>
using namespace RBX::HUMAN;
// Freefall ctor 00667810 zeroes +0xac/+0xb0/+0xb4..+0xbc, onStep 00667510 writes +0xa8 and
// +0xb4..+0xbc; factory 00643660 allocates 0xc0 for Freefall and 0xa8 for Flying, Jumping
// and GettingUp.
typedef char FreefallYRot[offsetof(Freefall, desiredYRotationalVelocity) == 0xa8 ? 1 : -1];
typedef char FreefallTorsoFriction[offsetof(Freefall, torsoFriction) == 0xac ? 1 : -1];
typedef char FreefallHeadFriction[offsetof(Freefall, headFriction) == 0xb0 ? 1 : -1];
typedef char FreefallDesiredVelocity[offsetof(Freefall, desiredVelocity) == 0xb4 ? 1 : -1];
typedef char FreefallSize[sizeof(Freefall) == 0xc0 ? 1 : -1];
typedef char FlyingSize[sizeof(Flying) == 0xa8 ? 1 : -1];
typedef char JumpingSize[sizeof(Jumping) == 0xa8 ? 1 : -1];
typedef char GettingUpSize[sizeof(GettingUp) == 0xa8 ? 1 : -1];
typedef char JumpingValue0c[offsetof(Jumping, value0c) == 0x0c ? 1 : -1];
RBX::HitTestFilter* jumpingFilter(Jumping* state) { return state; }
