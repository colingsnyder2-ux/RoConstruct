// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native RunningBase methods (2008-06). Not in any build list.
// Balancing's constructor is in HumanoidStates1Leaves.cpp: RunningBase(Humanoid*) 00666980 calls
// Balancing(Humanoid*, float, float) 0066e660 out of line, so its body is not visible here.
#include "humanoid/HumanoidStates1.h"
#include "humanoid/Humanoid.h"
#include "util/Velocity.h"
#include "util/Math.h"

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

namespace RBX { namespace HUMAN {
void RunningBase::onStep(float dt, Controller*) {
    desiredAltitude = getDesiredAltitude();
    Velocity velocity = getFloorVelocity(dt);
    floorVelocity = velocity.linear;
    floorRotationalVelocity = velocity.rotational.y;
    desiredVelocity = computeWalkVelocity();
    desiredYRotation = 0;
    if (!desiredVelocity.isZero()) {
        Humanoid* owner = getHumanoid();
        desiredYRotation = Math::radWrap(Math::getHeading(desiredVelocity) - owner->getTorsoHeading()) * 8.0f;
        if (floorFound) {
            float magnitude = desiredVelocity.magnitude();
            desiredVelocity.x *= 0.7f;
            desiredVelocity.y = magnitude * 0.7f;
            desiredVelocity.z *= 0.7f;
        }
    }
}
} }
