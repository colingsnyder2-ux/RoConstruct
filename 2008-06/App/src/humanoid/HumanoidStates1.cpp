// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native RunningBase methods (2008-06). Not in any build list.
// Balancing's constructor is in HumanoidStates1Leaves.cpp: RunningBase(Humanoid*) 00666980 calls
// Balancing(Humanoid*, float, float) 0066e660 out of line, so its body is not visible here.
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates1 | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src a1b60095 | roc native-status --write
#include "humanoid/HumanoidStates1.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

RunningBase::RunningBase(Humanoid* humanoid)
    : Balancing(humanoid, 300.0f, 50.0f),
      floorVelocity(0.0f, 0.0f, 0.0f), floorRotationalVelocity(0.0f),
      desiredVelocity(0.0f, 0.0f, 0.0f), desiredYRotation(0.0f), desiredAltitude(0.0f)
{
    Humanoid::event_Running.fire(humanoid, 0.0f);
}

RunningBase::~RunningBase()
{
}

float RunningBase::getIntendedRotationAboutYAxis() const
{
    return desiredYRotation;
}

}
}
