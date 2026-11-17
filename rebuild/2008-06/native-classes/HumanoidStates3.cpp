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

// 0066f070 (589 bytes; decorated ??0MovingNoPhysicsBase@HUMAN@RBX@@QAE@PAVHumanoid@2@@Z in the identity registry).
// Decoded order: HumanoidState(humanoid) 00643e00; SimJob() 005e50f0 at +0xa0; vtables 0084d168/0084d160/0084d150;
// torso/physicsService/connection zeroed; CoordinateFrame() 004782d0 at +0xe4. Then torso = shared_from(
// humanoid->005d76d0()) (00618a40; shared_count assignment 004025b0); if (torso): frame = torso->getCoordinateFrame()
// (00598cb0, rep movsd 9 dwords + 3 fld/fstp), torso->getPrimitive() (lea +0x228, no null test)->setJointAnchored(true)
// 005e8140; connection = Instance::event_ancestryChanged (00973c38).connect(torso, boost::bind(&0066edc0, this), 10)
// (function ctor 0066ef70, TSignalDesc::connect 004a3340, scoped_connection::operator= 00595540); physicsService =
// ServiceProvider::find<PhysicsService>(humanoid) 0066f020; physicsService->onAdded(torso) 005e8f70; humanoid world
// +0x21c ->getSimJobStage() 005e93b0 ->addSimJob(this +0xa0) 0064d1e0. Always: Humanoid::event_Running.fire(humanoid,
// 0.0f) (0097a504). getTorsoSlow 005d76d0 (Humanoid2008.h) and onTorsoAncestryChanged 0066edc0 are analog names.
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

// 0066edc0 (33 bytes, no arguments; bound by the constructor 0066f070 to event_ancestryChanged). The target calls
// getHumanoid 00793d50 / getTorsoSlow 005d76d0 before it reads torso +0xc4 (`cmp [esi + 0xc4], eax`). Trial 1,
// `torso.get() != getHumanoid()->getTorsoSlow()`: torso loaded into edi before the calls (rejected, 37 B); trial 2,
// operands swapped: same edi preload (rejected, 37 B); trial 3, this local: 33 B, only `cmp eax, [esi + 0xc4]` where the
// target has `cmp [esi + 0xc4], eax` (rejected); trial 4, the same local with `torso.get() != current`: exact.
void MovingNoPhysicsBase::onTorsoAncestryChanged()
{
    PartInstance* current = getHumanoid()->getTorsoSlow();
    if (torso.get() != current)
        release();
}

#ifdef NATIVE_MOVING_NO_PHYSICS_ONSTEP_PENDING
// Not compiled: three declarations outside this unit's files are missing (see below). No trials yet.
// 0066eb90 (259 bytes, `ret 4`; analog name applyFloorImpulse). getHumanoid 00793d50 -> getRootBody 005d9180 (early out
// on NULL), getFloorPrimitive 00643d30 (early out on NULL); masses: root body first (Cofm::getMass 0065ff10 or +0x8c),
// then the floor primitive's body (+0xa0) branch mass, std::min(root, floor) (`fcomp; test ah, 5; jnp` keeps the floor
// mass only when it is smaller); the guarded static (0, -9.81f [008438c0], 0) at 0097bec8 is initialised after the
// min; Units::kmsAccelerationToRbx 00660180 (20.0f [008222f0]) .y * mass * dt * 0.5f [00819bac]; Vector3(0, y, 0); the
// floor primitive body is reloaded (+0xa0) -> root +0x10 -> simBody +0x2c, tested, then 00629bb0(&impulse,
// &floorTouchInWorld). 00629bb0 (167 bytes) is a second SimBody accumulator with the accumulateForce shape that adds
// to the impulse accumulators +0x9c / +0xa8 (Body2008.h analog names) instead of force +0x84 / torque +0x90.
// BLOCKER: v8kernel/Body2008.h declares neither SimBody 00629bb0 (e.g. `void accumulateImpulse(const G3D::Vector3&
// impulse, const G3D::Vector3& worldPos); // 00629bb0`) nor the inline Body wrapper (root->simBody test, as the inline
// Body::accumulateForce does), and this unit does not include Body2008.h / util/Units.h.
void MovingNoPhysicsBase::applyFloorImpulse(float dt)
{
    Body* body = getHumanoid()->getRootBody();
    if (!body)
        return;
    Primitive* floor = getFloorPrimitive();
    if (!floor)
        return;
    float mass = std::min(body->getBranchMass(), floor->getBody()->getBranchMass());
    static const G3D::Vector3 kmsGravity(0.0f, -9.81f, 0.0f);
    G3D::Vector3 impulse(0.0f, Units::kmsAccelerationToRbx(kmsGravity).y * mass * dt * 0.5f, 0.0f);
    floor->getBody()->accumulateImpulse(impulse, floorTouchInWorld);
}

// 0066f2c0 (581 bytes, vtable 0084d168 slot 1, `ret 8`; RunningNoPhysics / StrafingNoPhysics forward to it 006672b0).
// getHumanoid()->getTorsoPrimitive() 005d90a0 (early out on NULL); getFloorVelocity 00643a70 (linear only),
// computeWalkVelocity 00643b60, getDesiredAltitude 00643360 - 0.1f [0081e704]; the sum floor + walk is formed after the
// altitude call; error = altitude - frame.translation.y (+0x10c); if fabs(error) > 0.025f [00837878] the inline
// G3D::sign(error) (fld1 / -1.0f [0081c3b8] / 0) is added to v.y; frame.translation (+0x108..+0x110) += v * dt.
// Humanoid strafe bit (+0x1e8 bit 4): 005df0c0(&frame, walkRotationalVelocity +0x1b0 * 16.0f [00826918] * dt); else when
// Vector3::xz 005185f0 is not (0, 0) (fldz compares): getHumanoid() kept in ebx, Math::getHeading 005de650(v),
// Humanoid::getTorsoHeading 005d91a0, Math::radWrap 005cbec0, * 8.0f [0082ca40] * dt, 005df0c0(&frame, ...).
// primitive->setCoordinateFrame(frame) 005e8200; if (!v.isZero()) 006662f0: primitive->setVelocity 005e7760 with
// 0066eb30(v); if speedSettled 00643330: Humanoid::event_Running (0097a504) fired with v.length(); applyFloorImpulse(dt).
// 005df0c0 (120 bytes, cdecl (CoordinateFrame&, float)) lies in the Math unit (between orthonormalizeIfNecessary
// 005df0a0 and sortVector3 005df1b0, followed by 005df140 = rotation = fromAxisAngle(unitY, a) * rotation); in the
// donor Math.h order (rotateAboutYLocal, rotateAboutYGlobal) it is Math::rotateAboutYLocal (lookAt 00518e20 of
// translation + lookVector (getColumn(2) * -1.0f [00828b60]) turned by the angle).
// BLOCKERS: 0066eb30 (91 bytes, thiscall, `ret 4`) is a one-argument Velocity(const G3D::Vector3& linear) constructor
// (rotational from the function-local static Vector3::zero() 0096f044, guard 0096f050) that the donor util/Velocity.h
// (core) does not declare; applyFloorImpulse 0066eb90 above; the registry names 005df0c0 func_005df0c0.
void MovingNoPhysicsBase::onStep(float dt, Controller* controller)
{
    Primitive* primitive = getHumanoid()->getTorsoPrimitive();
    if (!primitive)
        return;
    Velocity floorVelocity = getFloorVelocity(dt);
    G3D::Vector3 walk = computeWalkVelocity();
    float altitude = getDesiredAltitude() - 0.1f;
    G3D::Vector3 velocity = floorVelocity.linear + walk;
    float error = altitude - frame.translation.y;
    if (fabs(error) > 0.025f)
        velocity.y += G3D::sign(error);
    frame.translation += velocity * dt;
    if (getHumanoid()->getStrafe())
        Math::rotateAboutYLocal(frame, getHumanoid()->walkRotationalVelocity * 16.0f * dt);
    else if (velocity.xz() != G3D::Vector2(0.0f, 0.0f))
    {
        Humanoid* humanoid = getHumanoid();
        Math::rotateAboutYLocal(frame, Math::radWrap(Math::getHeading(velocity) - humanoid->getTorsoHeading()) * 8.0f * dt);
    }
    primitive->setCoordinateFrame(frame);
    if (!velocity.isZero())
        primitive->setVelocity(Velocity(velocity));
    if (speedSettled())
        Humanoid::event_Running.fire(getHumanoid(), velocity.length());
    applyFloorImpulse(dt);
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::HUMAN::sFallingDown>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sSeated>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sStrafingNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sRunningNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sMovingNoPhysicsBase>();

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::HUMAN::sFallingDown>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sSeated>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sStrafingNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sRunningNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sMovingNoPhysicsBase>();

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::HUMAN::sFallingDown>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sSeated>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sStrafingNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sRunningNoPhysics>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sMovingNoPhysicsBase>();
