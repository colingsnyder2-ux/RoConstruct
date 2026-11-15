// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Inactive native HumanoidState base methods (2008-06). Not in any build list.
// Flags and includes follow the sibling unit HumanoidStateFloor.cpp (same original HumanoidState.cpp, 00643xxx):
// the limb flag setters need a complete part-embedded Primitive (Primitive::setCanSleep 005e75e0, +0xab).
// Batch 13: switched from the native humanoid/Humanoid.h to humanoid/Humanoid2008.h, which declares setStrafe 005dc230
// and the const limb-primitive getters 005d90a0..005d9140 (the decorated names HumanoidCamera.cpp defines). The
// part-embedded PartInstance.h reaches the donor v8kernel/Connector.h, so this unit selects
// NATIVE_HUMANOID2008_DONOR_CONNECTOR as HumanoidCamera.cpp / Humanoid2008Parts.cpp do (no Humanoid vtable built here).
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid2008.h"
// The state factories 00643660 / 00643280 construct every leaf state (constructors out of line in their own units).
#include "humanoid/HumanoidStates1.h"
#include "humanoid/HumanoidStates2.h"
#define NATIVE_SIMJOB_PENDING  // RunningNoPhysics / StrafingNoPhysics (humanoid/HumanoidStates3.h, v8world/SimJob.h)
#include "humanoid/HumanoidStates3.h"

namespace RBX {
namespace HUMAN {

// 00643e00: setJump 005dc270(false), setStrafe 005dc230(false) (bit 4 of +0x1e8), setLimbFlag(false).
HumanoidState::HumanoidState(Humanoid* humanoid)
    : humanoid(humanoid), value0c(0.0f), flag10(false), flag11(false),
      speed38(0.0f), speed3c(0.0f)
{
    humanoid->setJump(false);
    humanoid->setStrafe(false);
    setLimbFlag(false);
}

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

// 00643d30 (16 bytes): floorPart +0x24, then its embedded Primitive (part + 0x228) or NULL.
Primitive* HumanoidState::getFloorPrimitive() const
{
    PartInstance* part = floorPart.get();
    return part ? part->getPrimitive() : NULL;
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

// 00643660 (836 bytes, cdecl; analog name): the state factory. Jump table 00643974 for cases 0..11 in getStateType order
// (tests/record_native_humanoid_factory.py: allocation sizes 0xa0..0x114 and constructor RTTI per case); every case
// news its state with EH state = case index, and the default (EH state 0xc) news Running, whose tail case 6 shares.
HumanoidState* HumanoidState::create(int stateType, Humanoid* humanoid)
{
    switch (stateType)
    {
    case 0:  return new FallingDown(humanoid);          // 0xa0, 00666e30
    case 1:  return new GettingUp(humanoid);            // 0xa8, 00667e20
    case 2:  return new Jumping(humanoid);              // 0xa8, 00667c40
    case 3:  return new Freefall(humanoid);             // 0xc0, 00667810
    case 4:  return new Flying(humanoid);               // 0xa8, 006674b0
    case 5:  return new Landed(humanoid);               // 0xcc, 00643550
    case 6:  return new Running(humanoid);              // 0xcc, 00666ac0
    case 7:  return new RunningNoPhysics(humanoid);     // 0x114, 00667370
    case 8:  return new StrafingNoPhysics(humanoid);    // 0x114, 00667210
    case 9:  return new Climbing(humanoid);             // 0xcc, 006435a0
    case 10: return new Seated(humanoid);               // 0xa0, 00667010
    case 11: return new Dead(humanoid);                 // 0xa0, 00666d30
    default: return new Running(humanoid);              // 0xcc, 00666ac0
    }
}

// 00643280 (94 bytes, cdecl; analog name): new Running(humanoid) (0xcc, constructor 00666ac0). Caller
// Humanoid::onAncestorChanged 005db560 stores the result in currentState (+0x220) when the humanoid enters a world.
HumanoidState* HumanoidState::createDefault(Humanoid* humanoid)
{
    return new Running(humanoid);
}

}
}
