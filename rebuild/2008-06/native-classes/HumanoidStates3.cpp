// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native Seated/Dead/FallingDown and MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics
// methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid);
// the MovingNoPhysicsBase family needs the proposed SimJob declaration (NATIVE_SIMJOB_PENDING).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates3 | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 0e4ae394 | roc native-status --write
#include "humanoid/HumanoidStates3.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

const char sSeated[] = "Seated";
const char sDead[] = "Dead";
const char sFallingDown[] = "FallingDown";

Seated::Seated(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_Seated.fire(humanoid, true);
    setLimbFlag(true);
}

Dead::Dead(Humanoid* humanoid)
    : Base(humanoid)
{
    if (ModelInstance* character = Humanoid::getCharacterFromHumanoid(humanoid))
        character->breakJoints();
}

Seated::~Seated()
{
    Humanoid::event_Seated.fire(getHumanoid(), false);
}

FallingDown::FallingDown(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_FallingDown.fire(getHumanoid(), true);
    value0c = 3.0f;
}

FallingDown::~FallingDown()
{
    Humanoid::event_FallingDown.fire(getHumanoid(), false);
}

#ifdef NATIVE_SIMJOB_PENDING
const char sMovingNoPhysicsBase[] = "MovingNoPhysicsBase";
const char sRunningNoPhysics[] = "RunningNoPhysics";
const char sStrafingNoPhysics[] = "StrafingNoPhysics";

MovingNoPhysicsBase::~MovingNoPhysicsBase()
{
    if (torso.get())
        release();
}

// The SimJob overrides 00667160 tail-call 0066eaa0 out of line ('add ecx,-0xa0; jmp'), so the
// helper was not inlined in the original; noinline keeps that boundary here.
__declspec(noinline) Assembly* MovingNoPhysicsBase::getTorsoAssembly()
{
    Primitive* primitive = getHumanoid()->getTorsoPrimitive();
    return primitive ? primitive->getAssembly() : 0;
}

Assembly* MovingNoPhysicsBase::getAssembly()
{
    return getTorsoAssembly();
}

Assembly* MovingNoPhysicsBase::getAssembly2()
{
    return getTorsoAssembly();
}

RunningNoPhysics::RunningNoPhysics(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_Running.fire(humanoid, 0.0f);
}

void RunningNoPhysics::onStep(float dt, Controller* controller)
{
    MovingNoPhysicsBase::onStep(dt, controller);
}

StrafingNoPhysics::StrafingNoPhysics(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_Strafing.fire(humanoid, false);
}

void StrafingNoPhysics::onStep(float dt, Controller* controller)
{
    MovingNoPhysicsBase::onStep(dt, controller);
}
#endif

}
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sSeated>::getName() const { return Name::declare<HUMAN::sSeated>(); }
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sDead>::getName() const { return Name::declare<HUMAN::sDead>(); }
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sFallingDown>::getName() const { return Name::declare<HUMAN::sFallingDown>(); }
#ifdef NATIVE_SIMJOB_PENDING
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sMovingNoPhysicsBase>::getName() const { return Name::declare<HUMAN::sMovingNoPhysicsBase>(); }
template<> const Name& Named<HUMAN::MovingNoPhysicsBase, HUMAN::sRunningNoPhysics>::getName() const { return Name::declare<HUMAN::sRunningNoPhysics>(); }
template<> const Name& Named<HUMAN::MovingNoPhysicsBase, HUMAN::sStrafingNoPhysics>::getName() const { return Name::declare<HUMAN::sStrafingNoPhysics>(); }
#endif
}
