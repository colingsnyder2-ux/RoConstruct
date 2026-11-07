// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native Balancing constructor and Running/Landed/Climbing (Named<RunningBase>) methods (2008-06).
// Not in any build list.
// Separate unit: the leaves' deleting destructor 00643580 calls ~RunningBase 006663f0 out of line,
// so RunningBase's destructor body is not visible here (it is in HumanoidStates1.cpp, where the
// RunningBase deleting destructor 00666520 inlines it).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates1Leaves | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 42576653 | roc native-status --write
#include "humanoid/HumanoidStates1.h"
#include "humanoid/Humanoid.h"

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
