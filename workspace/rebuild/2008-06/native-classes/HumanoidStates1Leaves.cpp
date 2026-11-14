// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native Balancing constructor and Running/Landed/Climbing (Named<RunningBase>) methods (2008-06).
// Not in any build list.
// Separate unit: the leaves' deleting destructor 00643580 calls ~RunningBase 006663f0 out of line,
// so RunningBase's destructor body is not visible here (it is in HumanoidStates1.cpp, where the
// RunningBase deleting destructor 00666520 inlines it).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates1Leaves | 2008-06 | draft (no current byte proof)
// 0/4 mapped addresses byte-exact | 4 unproved | no mapped strings | by king_originala (+1) (mixed 3)
// <<< native-status | src 42576653 | roc native-status --write
#include "humanoid/HumanoidStates1.h"
#include "humanoid/Humanoid.h"
#include "util/Math.h"

namespace RBX {
namespace HUMAN {

Balancing::Balancing(Humanoid* humanoid, float kP, float kD)
    : HumanoidState(humanoid), kP(kP), kD(kD)
{
}

const char sRunning[] = "Running";
const char sLanded[] = "Landed";
const char sClimbing[] = "Climbing";

Running::Running(Humanoid* humanoid)
    : Base(humanoid)
{
    value0c = 0.25f;
}

Landed::Landed(Humanoid* humanoid)
    : Base(humanoid)
{
    value0c = 0.45f;
}

Climbing::Climbing(Humanoid* humanoid)
    : Base(humanoid)
{
}

}
template<> const Name& Named<HUMAN::RunningBase, HUMAN::sRunning>::getName() const { return Name::declare<HUMAN::sRunning>(); }
template<> const Name& Named<HUMAN::RunningBase, HUMAN::sLanded>::getName() const { return Name::declare<HUMAN::sLanded>(); }
template<> const Name& Named<HUMAN::RunningBase, HUMAN::sClimbing>::getName() const { return Name::declare<HUMAN::sClimbing>(); }
}

// onStep bodies use the base getHumanoid() (folded getter 00793d50), bool speedSettled() and the
// bool floor query 006444f0 (onFloorStep) declared in HumanoidState.h.
namespace RBX {
namespace HUMAN {
// 00666410 (vtable 0084cc38 slot 1; Landed inherits it). Callees: getDesiredAltitude 00643360,
// getFloorVelocity 00643a70 (linear -> +0xa8, rotational.y -> +0xb4), computeWalkVelocity 00643b60,
// Vector3::isZero 006662f0 (out-of-line G3D inline), getHumanoid 00793d50, Math::getHeading 005de650,
// Humanoid::getTorsoHeading 005d91a0, Math::radWrap 005cbec0, 8.0f [0082ca40], 0.7f [008288b8];
// floorFound is HumanoidState +0x20.
// PARKED (not exact): all calls, stores and the getHumanoid-before-getHeading order match (the local
// Humanoid* reproduces 00666493 push ebx / 0066649c mov ebx,eax). The only remaining difference is the
// floorFound tail: the original 006664d4 loads z,y,x for the length, then reloads x, stores x*0.7, stores
// sqrt*0.7 to y and multiplies z from memory (fmul [esi+0xc0]); this body loads x before the length and
// stores all three from the stack. Rejected tail variants (one per trial):
//   1. desiredVelocity = Vector3(desiredVelocity.x, desiredVelocity.length(), desiredVelocity.z) * 0.7f
//      (x loaded first, fxch-ordered stores; same bytes as variant 3);
//   2. desiredVelocity.y = desiredVelocity.length(); desiredVelocity *= 0.7f (stores the unscaled length to
//      +0xbc and reloads y);
//   3. float speed = length(); desiredVelocity = Vector3(x, speed, z) * 0.7f (identical to variant 1).
// Unit placement: the original body lies between ~RunningBase 006663f0 and the RunningBase deleting
// destructor 00666520, i.e. RunningBase's own unit (HumanoidStates1.cpp); kept here only because that file
// is not in this assignment. Running::onStep 00666b20 / Climbing::onStep 00666bc0 stay exact (not inlined).
void RunningBase::onStep(float dt, Controller* controller)
{
    desiredAltitude = getDesiredAltitude();
    Velocity floor = getFloorVelocity(dt);
    floorVelocity = floor.linear;
    floorRotationalVelocity = floor.rotational.y;
    desiredVelocity = computeWalkVelocity();
    desiredYRotation = 0.0f;
    if (!desiredVelocity.isZero())
    {
        Humanoid* humanoid = getHumanoid();
        desiredYRotation = Math::radWrap(Math::getHeading(desiredVelocity) - humanoid->getTorsoHeading()) * 8.0f;
        if (floorFound)
        {
            float speed = desiredVelocity.length();
            desiredVelocity = G3D::Vector3(desiredVelocity.x, speed, desiredVelocity.z) * 0.7f;
        }
    }
}

void Running::onStep(float dt, Controller* controller)
{
    RunningBase::onStep(dt, controller);
    if (onFloorStep())
        value0c = 0.25f;
    if (speedSettled())
        Humanoid::event_Running.fire(getHumanoid(), desiredVelocity.length());
}

void Climbing::onStep(float dt, Controller* controller)
{
    RunningBase::onStep(dt, controller);
    if (speedSettled())
        Humanoid::event_Climbing.fire(getHumanoid(), desiredVelocity.length());
}
}
}
