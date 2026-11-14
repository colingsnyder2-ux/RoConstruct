// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Inactive native Seated/Dead/FallingDown and MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics
// methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid);
// the MovingNoPhysicsBase family needs the proposed SimJob declaration (NATIVE_SIMJOB_PENDING).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates3 | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src 0e4ae394 | roc native-status --write
// v8world/SimJob.h is now a native header (SimJob vptr, noncopyable, vector +4, list iterator +0x1c), so the
// MovingNoPhysicsBase block is enabled here. Flags follow the sibling HumanoidStateFloor.cpp: getTorsoAssembly needs
// the complete part-embedded Primitive (Primitive::getAssembly 005e7570); Dead needs ModelInstance::breakJoints.
#define NATIVE_SIMJOB_PENDING
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
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

#ifdef NATIVE_MOVING_NO_PHYSICS_RELEASE_PENDING
// 0066ed50 (103 bytes, called by the destructor 0066ee10 when torso +0xc4 is set). Draft, not compiled.
// Evidence: torso->getPrimitive() (PartInstance +0x228, null-tested) -> Primitive 005e8140 (the +0xaa anchor-flag
// setter, `ret 4`, called with false); connection.disconnect() 00595230 (+0xd0); getHumanoid() 00793d50 -> world
// +0x21c -> World::getSimJobStage 005e93b0 (walks the stage list from World +0x88 to getStageType 6) -> 0064d1f0
// (`jmp 0064d180`: the SimJobStage job-removal entry, erases the job's list iterator +0x1c/+0x20) with the SimJob
// base (this +0xa0); physicsService (+0xcc)->onRemoved(torso.get()) 005e9040; torso.reset() tail-jumps 00456e80
// (shared_ptr<Instance>::reset, identical-code folded).
// BLOCKED on header proposals (not this unit's files):
//   1. part-embedded/v8world/Primitive.h: declare the +0xaa setter 005e8140 (`void setJointAnchored(bool)`,
//      analog name; PrimitiveState.cpp already names the field jointAnchored and defines its two siblings).
//   2. v8world/SimJobStage2008.h: declare the removal entry 0064d1f0 (`void removeSimJob(SimJob* job);`, analog name)
//      and its body 0064d180; reachable from this unit without the donor v8world/SimJobStage.h.
//   3. v8datamodel/PhysicsService.h: onRemoved 005e9040 is private (decorated `?onRemoved@PhysicsService@RBX@@AAE...`):
//      the original granted access, e.g. `friend class HUMAN::MovingNoPhysicsBase;`.
// 0 compile trials, 0 rejected variants.
void MovingNoPhysicsBase::release()
{
    if (Primitive* primitive = torso->getPrimitive())
        primitive->setJointAnchored(false);
    connection.disconnect();
    getHumanoid()->getWorld()->getSimJobStage().removeSimJob(this);
    physicsService->onRemoved(torso.get());
    torso.reset();
}
#endif

RunningNoPhysics::RunningNoPhysics(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_Running.fire(humanoid, 0.0f);
}

void RunningNoPhysics::onStep(float dt, Controller* controller)
{
    MovingNoPhysicsBase::onStep(dt, controller);
}

// 00667210. Pending header: humanoid/Humanoid.h declares no event_Strafing (0097a348; Humanoid2008.h does).
#ifdef NATIVE_HUMANOID_EVENT_STRAFING_PENDING
StrafingNoPhysics::StrafingNoPhysics(Humanoid* humanoid)
    : Base(humanoid)
{
    Humanoid::event_Strafing.fire(humanoid, false);
}
#endif

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
