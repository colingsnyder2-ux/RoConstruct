#pragma once
// 2008-06 native RBX::SleepStage (inactive). Declared under a non-colliding name: the original path
// v8world/SleepStage.h is reached through the donor v8world/World.h (and the native-world 2007 port), so a header at that
// path would shadow it. A unit must not include both this header and the donor v8world/SleepStage.h (or World.h).
// Bases IStage / IWorldStage are the donor headers (see CleanStage2008.h); units opt in to native-headers/kernel-stages
// for the 2008 StageType (SLEEP_STAGE 5).
// Every field below is read from the 2008-06 binary (the 2007 PDB layout has size 0x90; the 2008 class is 0x1ec):
//   RTTI/vtable  ??_7 0084b088 (stored by the ctor 0064b8e0 and dtor 0064b330): 7 slots like every 2008 stage.
//   size         0x1ec (AssemblyStage() 0066f800 news 0x1ec and calls SleepStage(this, world) 0064b8e0).
//   ctor         0064b8e0: downstream = new SimJobStage (0x2c, 0064d300), upstream +0x4, world +0xc; then eight
//                std::vector containers at +0x10 .. +0xb8 (stride 0x18: the ctor allocates the 4-byte iterator
//                proxy and zeroes first/last/end at +0xc/+0x10/+0x14 of each), uiStepId, six std::set containers at
//                +0xe0 .. +0x180 (stride 0x20, _Tree ctor 0064b2a0), two IndexArray-shaped G3D::Array triples at +0x1a0 /
//                +0x1ac, one more set at +0x1b8, then three Profiler objects (0xc048 bytes, ctor 005c43a0) at
//                +0x1e0 / +0x1e4 / +0x1e8.
//   dtor         0064b330 (reverse order: profilers, set +0x1b8 (0064b230), the two arrays released with
//                G3D::System::alignedFree 00507d20, six sets, the eight vectors).
//   fields       numContactsInStage +0xd0 (onEdgeAdded 0064b1b0 ++ when a contact joins the stepping array),
//                numContactsInKernel +0xd4 (changeContactState 0064bf90 ++/-- around the downstream onEdgeAdded /
//                onEdgeRemoving), steppingContacts +0x1a0 (onEdgeAdded appends, steppingIndex +0x24 of the contact),
//                touchingContacts +0x1ac (changeContactState 0064bf90), steppingJoints +0x1b8 (changeJointState 0064ae10:
//                erase 005e9f60 / insert 005e8c40), assembly sets +0xe0 .. +0x180 selected by stateToSet 0064a550:
//                state 1 -> +0xe0, 2 -> +0x100, 4 -> +0x140, 5 -> +0x160, 6 -> +0x180, 3 and everything else -> +0x120
//                (jump table 0064a598).
//   AssemblyState 2008: 0 ANCHORED, 1 RECURSIVE_WAKE_PENDING (0064b6d0 stores 1 and inserts into +0xe0), 2 WAKE_PENDING
//                (0064b5e0 stores 2 and inserts into +0x100), 3 AWAKE (0064ae90 hands the assembly to SimJobStage
//                0064d200), 4 SLEEPING_CHECKING, 5 SLEEPING_DEEPLY (0064ae90 removes it again through 0064d2a0), 6 the
//                state onAssemblyRemoving 0064b0a0 stores last. Names follow the donor SleepStage / Sim enum.
// Names of the assembly sets follow the donor SleepStage2.h; the +0x180 set name and the vector element types are INFERRED.
#include <set>
#include <vector>
#include <deque>
#include <G3D/Array.h>
#include <boost/scoped_ptr.hpp>
#include "v8world/IWorldStage.h"
#include "AppUnit658/Edge.h"
#include "v8world/Contact2008.h"
#include "util/IndexArray.h"
#include "util/RunningAverage.h"
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

struct NativeKernelStagesLayout;

namespace RBX
{
	class Assembly;
	class Contact;
	class Joint;
	class World;
	namespace Profiling { class CodeProfiler; }

	namespace Sim
	{
		enum AssemblyState
		{
			ANCHORED,
			RECURSIVE_WAKE_PENDING,
			WAKE_PENDING,
			AWAKE,
			SLEEPING_CHECKING,
			SLEEPING_DEEPLY,
			REMOVED                       // INFERRED: 0064b0a0 stores 6 at the end of onAssemblyRemoving; donor has no such state
		};
	}

	// The 2008 per-assembly sleep record (new 0x24 in onAssemblyAdded 0064aff0, ctor 005e5f30): state +0x0 and sleepCount
	// +0x4 are the two fields the SleepStage bodies read and write (0064afc8..0064afd7 zero the count, then store the
	// state); the remaining 0x1c bytes are the donor runningAverageState (Vector3 + Quaternion; okNeighborSleep 0064a660
	// passes SleepInfo +0x8 to RunningAverageState::withinTolerance 00668af0). Constructor and destructor are out of line
	// as in the donor openrbx v8world/Assembly2.h: onAssemblyAdded 0064b034 calls ??0SleepInfo 005e5f30 and
	// onAssemblyRemoving 0064b17e calls the (empty, folded 0047d410) destructor before operator delete.
	class SleepInfo
	{
	public:
		SleepInfo();                                      // 005e5f30
		~SleepInfo();                                     // folded 0047d410

		Sim::AssemblyState state;                         // +0x0
		int sleepCount;                                   // +0x4
		RunningAverageState runningAverageState;          // +0x8
	};

	class SleepStage : public IWorldStage
	{
		friend struct ::NativeKernelStagesLayout;

	public:
		typedef std::set<Assembly*> AssemblySet;
		typedef std::set<Joint*> JointSet;

	private:
		// INFERRED: element types. Eight std::vector shapes (stride 0x18); the donor SleepStage.cpp keeps these as
		// function-local statics (toStepping / toTouching / toSleeping ... in stepContacts, stepJoints and the
		// stepAssemblies* functions), which 2008 turned into members. Only the vector shape is proven by 0064b8e0 / 0064b330.
		std::vector<Contact*> contactsA;                  // +0x10
		std::vector<Contact*> contactsB;                  // +0x28
		std::vector<Contact*> contactsC;                  // +0x40
		std::vector<Contact*> contactsD;                  // +0x58
		std::vector<Joint*> jointsE;                      // +0x70
		std::vector<Assembly*> assembliesF;               // +0x88
		std::vector<Assembly*> assembliesG;               // +0xa0
		std::vector<Assembly*> assembliesH;               // +0xb8
		int numContactsInStage;                           // +0xd0
		int numContactsInKernel;                          // +0xd4
		bool throttling;                                  // +0xd8 INFERRED: donor field after the two counters
		int uiStepId;                                     // +0xdc (ctor -1, donor shape)
		// stateToSet 0064a550 jump table (0064a598: 0064a561 / 0064a56a / 0064a58e / 0064a573 / 0064a57c / 0064a585 for
		// states 1..6): 3 and the default share +0x120 (donor `default: return &awake`), 6 has its own set +0x180, which
		// onAssemblyRemoving 0064b0a0 inserts into (its inline changeAssemblyState(a, 6)) and erases again.
		AssemblySet recursiveWakePending;                 // +0xe0
		AssemblySet wakePending;                          // +0x100
		AssemblySet awake;                                // +0x120
		AssemblySet sleepingChecking;                     // +0x140
		AssemblySet sleepingDeeply;                       // +0x160
		AssemblySet removed;                              // +0x180 INFERRED: name; the set of state 6 (REMOVED)
		typedef IndexArray<Contact, &Contact::steppingIndexFunc> ContactList;   // donor SleepStage typedef (12 bytes)
		ContactList steppingContacts;                     // +0x1a0
		ContactList touchingContacts;                     // +0x1ac
		JointSet steppingJoints;                          // +0x1b8
		int field1d8;                                     // +0x1d8 INFERRED: ctor zero; the wake pass id (0064c6b0 increments it,
		                                                  // 0064c470 compares / stores it at Clump +0x44)
		bool externalBodyForceAdded;                      // +0x1dc INFERRED: ctor false, donor field
		// boost::scoped_ptr as in the donor: ~SleepStage 0064b330 deletes +0x1e8 / +0x1e4 / +0x1e0 through slot 0
		// (`push 1; call [vtbl]`), each under its own EH state (0x13 / 0x12 / 0x11), i.e. three member destructors.
		boost::scoped_ptr<Profiling::CodeProfiler> profilingCollision;   // +0x1e0
		boost::scoped_ptr<Profiling::CodeProfiler> profilingWake;        // +0x1e4
		boost::scoped_ptr<Profiling::CodeProfiler> profilingSleep;       // +0x1e8

	public:
		SleepStage(IStage* upstream, World* world);       // 0064b8e0 (not built: needs the 8-vector / 7-set EH layout)
		virtual ~SleepStage();                            // slot 0 (0064b330)
		virtual StageType getStageType();                 // slot 1 (007359e0)
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest); // INFERRED: vtable slot 2, 0064ca00
		virtual int getMetric(MetricType metricType);     // INFERRED: vtable slot 6, 0064a8c0
		virtual void onEdgeAdded(Edge* e);                // slot 4 (0064b1b0)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (0064c130)

		// 0064b890 (`ret 8`; donor SleepStage::onWakeUpRequest): the target of World::ticklePrimitive 005e9410. 2008 adds
		// the externalBodyForceAdded +0x1dc store on the recursive path.
		void onWakeUpRequest(Assembly* a, bool recursive);  // 0064b890

		// Donor openrbx SleepStage2 members; callers AssemblyStage::onAssemblyAdded 0066f530 / onAssemblyRemoving 0066f550.
		void onAssemblyAdded(Assembly* a);                // 0064aff0 (`ret 4`)
		void onAssemblyRemoving(Assembly* a);             // 0064b0a0 (`ret 4`)

	private:
		// Donor SleepStage inlines (no code of their own): 0064ae90 / 0064b5e0 / 0064b6d0 test currentStage and its type.
		Sim::AssemblyState getState(Assembly* a);
		void resetSleepCount(Assembly* a)
		{
			a->getSleepInfo()->sleepCount = 0;
		}
		void sub_0064c850(); // INFERRED: 0064ca27 call
		void sub_0064c8a0(int worldStepId); // INFERRED: 0064ca2f call
		AssemblySet* stateToSet(Sim::AssemblyState state);                      // 0064a550
		bool okNeighborSleep(Assembly* a);                                      // 0064a660 (donor name: RunningAverageState::withinTolerance 00668af0 on SleepInfo +0x8)
		bool preventNeighborSleep(Assembly* a);                                 // 0064a740 (donor name)
		void changeAssemblyState(Assembly* a, Sim::AssemblyState state);        // 0064ae90
		void changeAssemblyState(const std::vector<Assembly*>& assemblies, Sim::AssemblyState state);   // 0064b840
		void changeJointState(Joint* j, Sim::EdgeState state);                  // 0064ae10
		void changeJointState(const std::vector<Joint*>& joints, Sim::EdgeState state);                 // 0064b7f0
		void changeContactState(Contact* c, Sim::EdgeState state);              // 0064bf90
		void changeContactState(const std::vector<Contact*>& contacts, Sim::EdgeState state);           // 0064c230
		void wakeEvent(Assembly* a);                                            // 0064b5e0
		void recursiveWakeEvent(Assembly* a);                                   // 0064b6d0
		void touchEvent(Contact* c);                                            // 0064b7c0
		void wakeEvent(Edge* e);                                                // 0064bf60
		void wakeEdge(Edge* e);                                                 // 0064c1d0
		// Donor SleepStage inlines (no code of their own in 2008): currentStage +0x4 slot 1 against this slot 1, and the
		// edge type (slot 3) / state (+0x8) test, both inlined in 0064a790 and 0064c470.
		bool edgeIsAwake(Edge* e)
		{
			return e->inOrDownstreamOfStage(this);
		}
		bool isAffecting(Edge* e)
		{
			Sim::EdgeState state = e->getEdgeState();
			return e->getEdgeType() != Edge::CONTACT || state == Sim::TOUCHING || state == Sim::TOUCHING_SLEEPING;
		}
		// Donor SleepStage::computeCanSleep (`!Primitive::disableSleep && assembly->getCanSleep()`), inline in 0064a790 and
		// 0064a950 (the two readers of 0097abc1); no code of its own.
		bool computeCanSleep(Assembly* a);
		bool forceNeighborAwake(Assembly* a);                                   // 0064a5f0 (donor name; only callee of 0064a790)
		// 0064a790 (registry func_0064a790; donor SleepStage::computeAssemblyState, only caller 0064bedd): AWAKE 3 /
		// SLEEPING_CHECKING 4 / SLEEPING_DEEPLY 5.
		Sim::AssemblyState computeAssemblyState(Assembly* a);
		// 0064c470 (registry func_0064c470, `ret 0xc`; only caller 0064c804): the 2008 breadth-first form of the donor
		// wakeAssemblyAndNeighbors(assembly, recurseDepth); neighbours go to the queue (deque push_back 00589330, folded with
		// deque<HistoryItem*>) with their depth at Clump +0x48 and the pass id +0x1d8 at Clump +0x44. INFERRED: name.
		void wakeAssemblyAndNeighbors(Assembly* a, std::deque<Assembly*>& toWake, int recurseDepth);
		// 0064c6b0 (registry func_0064c6b0, `ret 0xc`): callers 0064c850 / 0064c8a0 pass (set, depth, state) for the sets
		// +0x100 / 2, +0xe0 / 1 (depth 8 for recursiveWakePending, as the donor stepAssembliesRecursiveWakePending), +0x140 / 4
		// and +0x160 / 5; the state argument is never read. INFERRED: name.
		void wakeAssemblies(const AssemblySet& assemblies, int recurseDepth, Sim::AssemblyState state);
	public:
		void sub_0064b840(const std::vector<Joint*>& joints, Sim::EdgeState state);   // INFERRED: 0064b840, placeholder name (identity tier), body byte-proved (Inferred_0064b840.cpp)
	public:
		void sub_0064c230(const std::vector<Joint*>& joints, Sim::EdgeState newState);   // INFERRED: 0064c230, placeholder name (identity tier), body byte-proved (Inferred_0064c230.cpp)
	public:
		void sub_0064b7f0(const std::vector<RBX::Joint*>& joints, RBX::Sim::EdgeState state);   // INFERRED: 0064b7f0, placeholder name (identity tier), body byte-proved (Inferred_0064b7f0.cpp)
	};
}
