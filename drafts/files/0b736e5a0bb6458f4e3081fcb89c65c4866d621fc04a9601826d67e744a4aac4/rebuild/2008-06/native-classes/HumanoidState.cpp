// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Inactive native HumanoidState base methods (2008-06). Not in any build list.
// >>> native-status (generated) -- do not edit >>>
// HumanoidState | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by colin (+3) (mixed 3)
// <<< native-status | src ff825017 | roc native-status --write
// Flags and includes follow the sibling unit HumanoidStateFloor.cpp (same original HumanoidState.cpp, 00643xxx):
// the limb flag setters need a complete part-embedded Primitive (Primitive::setCanSleep 005e75e0, +0xab).
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

// 00643e00. Pending header: humanoid/Humanoid.h has no setStrafe (005dc230, bit 4 of +0x1e8; declared in
// Humanoid2008.h, which lacks the limb primitive getters used below). Kept unchanged until Humanoid.h gains it.
#ifdef NATIVE_HUMANOID_SETSTRAFE_PENDING
HumanoidState::HumanoidState(Humanoid* humanoid)
    : humanoid(humanoid), value0c(0.0f), flag10(false), flag11(false),
      speed38(0.0f), speed3c(0.0f)
{
    humanoid->setJump(false);
    humanoid->setStrafe(false);
    setLimbFlag(false);
}
#endif

// 006435c0
HumanoidState::~HumanoidState()
{
    setLimbFlag(false);
}

// 00793d50 (identical-code-folded getter)
Humanoid* HumanoidState::getHumanoid() const
{
    return humanoid;
}

// 00643330
bool HumanoidState::speedSettled() const
{
    return (speed38 < speed3c * 0.5f) || (speed38 > speed3c * 2.0f);
}

// 00643b60. The callee 005d9c10 is Humanoid::updateWalkDirection: its body calls getIntendedMovementVector(true)
// 005d9a50 (Humanoid2008.h/.cpp). The registry currently names 005d9c10 G3D::CoordinateFrame::upVector, which that body
// contradicts; updateWalkDirection is listed there only as a folded/conflicting candidate (registry proposal);
// the earlier overlay called it getIntendedMovementVector, which Humanoid.h declares private (005d9bf0 is the
// virtual of that name).
G3D::Vector3 HumanoidState::computeWalkVelocity()
{
    G3D::Vector3 velocity = humanoid->updateWalkDirection() * 16.0f;
    speed3c = speed38;
    speed38 = velocity.length();
    return velocity;
}

// 00643bc0 (Primitive::setCanSleep 005e75e0 stores the inverted flag at +0xab)
void HumanoidState::setLegsFlag(bool value)
{
    if (humanoid->getLeftLegPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getLeftLegPrimitive()->setCanSleep(disabled);
    }
    if (humanoid->getRightLegPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getRightLegPrimitive()->setCanSleep(disabled);
    }
}

// 00643c20 (Primitive::setCanSleep 005e75e0 stores the inverted flag at +0xab)
void HumanoidState::setArmsFlag(bool value)
{
    if (humanoid->getLeftArmPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getLeftArmPrimitive()->setCanSleep(disabled);
    }
    if (humanoid->getRightArmPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getRightArmPrimitive()->setCanSleep(disabled);
    }
}

// 00643c80 (Primitive::setCanSleep 005e75e0 stores the inverted flag at +0xab)
void HumanoidState::setTorsoHeadFlag(bool value)
{
    if (humanoid->getTorsoPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getTorsoPrimitive()->setCanSleep(disabled);
    }
    if (humanoid->getHeadPrimitive()) {
        Humanoid* owner = humanoid;
        bool disabled = !value;
        owner->getHeadPrimitive()->setCanSleep(disabled);
    }
}

}
}
