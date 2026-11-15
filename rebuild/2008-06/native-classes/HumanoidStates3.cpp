// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Inactive native Seated/Dead/FallingDown and MovingNoPhysicsBase/RunningNoPhysics/StrafingNoPhysics
// methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid);
// the MovingNoPhysicsBase family needs the proposed SimJob declaration (NATIVE_SIMJOB_PENDING).
// v8world/SimJob2008.h is the native SimJob header (SimJob vptr, noncopyable, vector +4, list iterator +0x1c), so the
// MovingNoPhysicsBase block is enabled here. Flags follow the sibling HumanoidStateFloor.cpp: getTorsoAssembly needs
// the complete part-embedded Primitive (Primitive::getAssembly 005e7570); Dead needs ModelInstance::breakJoints.
#define NATIVE_SIMJOB_PENDING
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "humanoid/HumanoidStates3.h"
// humanoid/Humanoid2008.h, not the donor-shaped humanoid/Humanoid.h: MovingNoPhysicsBase::release 0066ed50 reads the
// 2008 Humanoid world at +0x21c (humanoid/Humanoid.h has it at +0x218). The part-embedded PartInstance chain reaches the
// donor v8kernel/Connector.h, so the donor Connector is selected for the Humanoid base (as Humanoid2008Parts.cpp does).
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "humanoid/Humanoid2008.h"
#include "v8datamodel/PhysicsService.h"
#include "v8world/SimJobStage2008.h" // SimJobStage::removeSimJob 0064d1f0 (MovingNoPhysicsBase::release 0066ed50)

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

// 00667160 (SimJob slot 1; `add ecx,-0xa0; jmp 0066eaa0`)
Assembly* MovingNoPhysicsBase::getAssemblyConst()
{
    return getTorsoAssembly();
}

// 00667160 (SimJob slot 2; identical code, folded)
Assembly* MovingNoPhysicsBase::getAssembly()
{
    return getTorsoAssembly();
}

// 0066ed50 (103 bytes, called by the destructor 0066ee10 when torso +0xc4 is set; not inlined there).
// Evidence: torso->getPrimitive() (PartInstance +0x228, lea + test: the primitive is fetched twice, as Humanoid::onEvent
// 005dc740 does with getTorsoPrimitive) -> Primitive::setJointAnchored 005e8140 (the +0xaa anchor-flag setter, analog
// name, `ret 4`, called with false); connection.disconnect() 00595230 (+0xd0); getHumanoid() 00793d50 -> Humanoid2008
// world +0x21c -> World::getSimJobStage 005e93b0 -> SimJobStage::removeSimJob 0064d1f0 (`jmp 0064d180`) with the SimJob
// base (this +0xa0); physicsService (+0xcc)->onRemoved(torso.get()) 005e9040 (private: PhysicsService.h befriends
// HUMAN::MovingNoPhysicsBase); torso.reset() tail-jumps 00456e80 (shared_ptr<Instance>::reset, identical-code folded).
// Trials: (1) `if (Primitive* primitive = torso->getPrimitive()) primitive->...` with humanoid/Humanoid.h: add ecx,
// 0x228 + je instead of lea + test, and world read at +0x218 (rejected); (2) Humanoid2008.h (world +0x21c): world fixed,
// the add/lea difference remained (rejected); (3) the primitive fetched twice: identical with relocations masked.
void MovingNoPhysicsBase::release()
{
    if (torso->getPrimitive())
        torso->getPrimitive()->setJointAnchored(false);
    connection.disconnect();
    getHumanoid()->getWorld()->getSimJobStage().removeSimJob(this);
    physicsService->onRemoved(torso.get());
    torso.reset();
}

#ifdef NATIVE_MOVING_NO_PHYSICS_CTOR_PENDING
// 0066f070 (589 bytes; decorated ??0MovingNoPhysicsBase@HUMAN@RBX@@QAE@PAVHumanoid@2@@Z in the identity registry).
// Decoded order: HumanoidState(humanoid) 00643e00; SimJob() 005e50f0 at +0xa0; vtables 0084d168/0084d160/0084d150;
// torso/physicsService/connection zeroed; CoordinateFrame() 004782d0 at +0xe4. Then torso = shared_from(
// humanoid->005d76d0()) (00618a40; shared_count assignment 004025b0); if (torso): frame = torso->getCoordinateFrame()
// (00598cb0, rep movsd 9 dwords + 3 fld/fstp), torso->getPrimitive() (lea +0x228, no null test)->setJointAnchored(true)
// 005e8140; connection = Instance::event_ancestryChanged (00973c38).connect(torso, boost::bind(&0066edc0, this), 10)
// (function ctor 0066ef70, TSignalDesc::connect 004a3340, scoped_connection::operator= 00595540); physicsService =
// ServiceProvider::find<PhysicsService>(humanoid) 0066f020; physicsService->onAdded(torso) 005e8f70; humanoid world
// +0x21c ->getSimJobStage() 005e93b0 ->addSimJob(this +0xa0) 0064d1e0. Always: Humanoid::event_Running.fire(humanoid,
// 0.0f) (0097a504). Not compiled: 005d76d0 (parent->findFirstChildByName("Torso") dynamic_cast<PartInstance>, no
// cache; callers only 0066edc0/0066f070) is not declared in humanoid/Humanoid2008.h, and the ancestry handler 0066edc0
// (`if (torso.get() != getHumanoid()->005d76d0()) release();`) is not declared in humanoid/HumanoidStates3.h.
// Placeholder names below (getTorsoSlow, onTorsoAncestryChanged) are analog names pending those declarations.
MovingNoPhysicsBase::MovingNoPhysicsBase(Humanoid* humanoid)
    : Base(humanoid), physicsService(0)
{
    torso = shared_from(humanoid->getTorsoSlow());
    if (torso)
    {
        frame = torso->getCoordinateFrame();
        torso->getPrimitive()->setJointAnchored(true);
        connection = Instance::event_ancestryChanged.connect(torso.get(),
            boost::bind(&MovingNoPhysicsBase::onTorsoAncestryChanged, this), 10);
        physicsService = ServiceProvider::find<PhysicsService>(humanoid);
        physicsService->onAdded(torso.get());
        humanoid->getWorld()->getSimJobStage().addSimJob(this);
    }
    Humanoid::event_Running.fire(humanoid, 0.0f);
}

// 0066edc0 (33 bytes, no arguments; bound by the constructor 0066f070 to event_ancestryChanged).
void MovingNoPhysicsBase::onTorsoAncestryChanged()
{
    if (torso.get() != getHumanoid()->getTorsoSlow())
        release();
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

// 00667210: MovingNoPhysicsBase(humanoid) 0066f070, then event_Strafing (0097a348, declared by humanoid/Humanoid2008.h,
// which this unit includes) fired with false through the argument.
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

#ifdef NATIVE_SIMJOB_PENDING
// 0066f020 (65 bytes, cdecl): ServiceProvider::find<PhysicsService>(const Instance*), emitted in this unit for the
// MovingNoPhysicsBase constructor 0066f070 (0066f23e, called with the humanoid). Walks the context up through
// getParent (+0x104) until __RTDynamicCast(context, 0, Instance 0092907c, ServiceProvider 0092e15c, 0) succeeds,
// then tail-jumps to the member find<PhysicsService>() const 004ccca0; NULL when no provider is found. Same shape as
// the create<PhysicsService>(const Instance*) 004cd8d0 in AppUnit4C8_2008PhysicsServiceCreate.cpp.
template<class Class> Class* ServiceProvider::find(const Instance* context)
{
    while (context)
    {
        if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context))
            return provider->find<Class>();
        context = context->getParent();
    }
    return NULL;
}

template PhysicsService* ServiceProvider::find<PhysicsService>(const Instance* context);
#endif
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sSeated>::getName() const { return Name::declare<HUMAN::sSeated>(); }
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sDead>::getName() const { return Name::declare<HUMAN::sDead>(); }
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sFallingDown>::getName() const { return Name::declare<HUMAN::sFallingDown>(); }
#ifdef NATIVE_SIMJOB_PENDING
template<> const Name& Named<HUMAN::HumanoidState, HUMAN::sMovingNoPhysicsBase>::getName() const { return Name::declare<HUMAN::sMovingNoPhysicsBase>(); }
template<> const Name& Named<HUMAN::MovingNoPhysicsBase, HUMAN::sRunningNoPhysics>::getName() const { return Name::declare<HUMAN::sRunningNoPhysics>(); }
template<> const Name& Named<HUMAN::MovingNoPhysicsBase, HUMAN::sStrafingNoPhysics>::getName() const { return Name::declare<HUMAN::sStrafingNoPhysics>(); }
#endif
}
