// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native HumanoidState base methods (2008-06). Not in any build list.
// >>> native-status (generated) -- do not edit >>>
// HumanoidState | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src ff825017 | roc native-status --write
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

HumanoidState::HumanoidState(Humanoid* humanoid)
    : humanoid(humanoid), value0c(0.0f), flag10(false), flag11(false),
      speed38(0.0f), speed3c(0.0f)
{
    humanoid->setJump(false);
    humanoid->setStrafe(false);
    setLimbFlag(false);
}

HumanoidState::~HumanoidState()
{
    setLimbFlag(false);
}

Humanoid* HumanoidState::getHumanoid() const
{
    return humanoid;
}

bool HumanoidState::speedSettled() const
{
    return (speed38 < speed3c * 0.5f) || (speed38 > speed3c * 2.0f);
}

G3D::Vector3 HumanoidState::computeWalkVelocity()
{
    G3D::Vector3 velocity = humanoid->getIntendedMovementVector() * 16.0f;
    speed3c = speed38;
    speed38 = velocity.length();
    return velocity;
}

void HumanoidState::setLegsFlag(bool value)
{
    if (humanoid->getLeftLegPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getLeftLegPrimitive()->setFlagAB(disabled);
    }
    if (humanoid->getRightLegPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getRightLegPrimitive()->setFlagAB(disabled);
    }
}

void HumanoidState::setArmsFlag(bool value)
{
    if (humanoid->getLeftArmPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getLeftArmPrimitive()->setFlagAB(disabled);
    }
    if (humanoid->getRightArmPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getRightArmPrimitive()->setFlagAB(disabled);
    }
}

void HumanoidState::setTorsoHeadFlag(bool value)
{
    if (humanoid->getTorsoPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getTorsoPrimitive()->setFlagAB(disabled);
    }
    if (humanoid->getHeadPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getHeadPrimitive()->setFlagAB(disabled);
    }
}

}
}
