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
// humanoid/Humanoid2008.h, not the donor-shaped humanoid/Humanoid.h: MovingNoPhysicsBase::release 0066ed50 reads the
// 2008 Humanoid world at +0x21c (humanoid/Humanoid.h has it at +0x218). The part-embedded PartInstance chain reaches the
// donor v8kernel/Connector.h, so the donor Connector is selected for the Humanoid base (as Humanoid2008Parts.cpp does).
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "humanoid/Humanoid2008.h"
#include "v8datamodel/PhysicsService.h"
#include <list>
#include "v8world/IWorldStage.h"

// Unit-local SimJobStage, exactly as native-headers/v8world/SimJobStage2008.h declares it (that header includes
// v8world/SimJob2008.h, whose RBX::SimJob cannot share this unit with the native v8world/SimJob.h that
// humanoid/HumanoidStates3.h includes: C2011; both declare stageIterator at +0x1c).
struct NativeKernelStagesLayout;

namespace RBX
{
	class SimJob;
	class Edge;
	class World;

	class SimJobStage : public IWorldStage
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp offset asserts

	private:
		std::list<SimJob*> simJobs;                       // +0x10

	public:
		SimJobStage(IStage* upstream, World* world);      // 0064d300 (SimJobStage2008Ctor.cpp: 2008 Kernel)
		virtual ~SimJobStage()                            // slot 0 (??_G 0064d380)
		{
		}
		virtual StageType getStageType();                 // slot 1 (005cb9d0; NATIVE_KERNEL_STAGES_PENDING)
		virtual void onEdgeAdded(Edge* e);                // slot 4 (0064d060)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (0064d090)

		void addSimJob(SimJob* job);                      // 0064d1e0 (`jmp 0064d0f0`; analog name)
		void removeSimJob(SimJob* job);                   // 0064d1f0 (`jmp 0064d180`; analog name)

	private:
		void insertSimJob(SimJob* job);                   // 0064d0f0 (analog name)
		void eraseSimJob(SimJob* job);                    // 0064d180 (analog name)

		SimJob* getNextSimJob(SimJob* job)                // 004cb480 (folded COMDAT; analog name)
		{
			std::list<SimJob*>::iterator it = job->stageIterator;
			++it;
			if (it == simJobs.end())
			{
				return *simJobs.begin();
			}
			return *it;
		}
	};
}

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
