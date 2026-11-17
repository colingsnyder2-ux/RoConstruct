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
//                state 1 -> +0xe0, 2 -> +0x100, 3 -> +0x140, 4 -> +0x160, 5 -> +0x180, everything else -> +0x120.
//   AssemblyState 2008: 0 ANCHORED, 1 RECURSIVE_WAKE_PENDING (0064b6d0 stores 1 and inserts into +0xe0), 2 WAKE_PENDING
//                (0064b5e0 stores 2 and inserts into +0x100), 3 AWAKE (0064ae90 hands the assembly to SimJobStage
//                0064d200), 4 SLEEPING_CHECKING, 5 SLEEPING_DEEPLY (0064ae90 removes it again through 0064d2a0), 6 the
//                state onAssemblyRemoving 0064b0a0 stores last. Names follow the donor SleepStage / Sim enum.
// Names of the assembly sets follow the donor SleepStage2.h; +0x120 and the vector element types are INFERRED.
#include <set>
#include <vector>
#include <G3D/Array.h>
#include "v8world/IWorldStage.h"
#include "AppUnit658/Edge.h"
#include "v8world/Contact2008.h"
#include "util/IndexArray.h"
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
	// state); the remaining 0x1c bytes (the donor runningAverageState) are not touched by the recovered bodies.
	class SleepInfo
	{
	public:
		Sim::AssemblyState state;                         // +0x0
		int sleepCount;                                   // +0x4
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
		AssemblySet recursiveWakePending;                 // +0xe0
		AssemblySet wakePending;                          // +0x100
		AssemblySet sleepingUnknown;                      // +0x120 INFERRED: stateToSet default (state 6 / out of range)
		AssemblySet awake;                                // +0x140
		AssemblySet sleepingChecking;                     // +0x160
		AssemblySet sleepingDeeply;                       // +0x180
		typedef IndexArray<Contact, &Contact::steppingIndexFunc> ContactList;   // donor SleepStage typedef (12 bytes)
		ContactList steppingContacts;                     // +0x1a0
		ContactList touchingContacts;                     // +0x1ac
		JointSet steppingJoints;                          // +0x1b8
		int field1d8;                                     // +0x1d8 INFERRED: ctor zero, unread by the recovered bodies
		bool externalBodyForceAdded;                      // +0x1dc INFERRED: ctor false, donor field
		Profiling::CodeProfiler* profilingCollision;      // +0x1e0 (owned; boost::scoped_ptr in the donor)
		Profiling::CodeProfiler* profilingWake;           // +0x1e4
		Profiling::CodeProfiler* profilingSleep;          // +0x1e8

	public:
		SleepStage(IStage* upstream, World* world);       // 0064b8e0 (not built: needs the 8-vector / 7-set EH layout)
		virtual ~SleepStage();                            // slot 0 (0064b330)
		virtual StageType getStageType();                 // slot 1 (007359e0)
		virtual void onEdgeAdded(Edge* e);                // slot 4 (0064b1b0)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (0064c130)

	private:
		// Donor SleepStage inlines (no code of their own): 0064ae90 / 0064b5e0 / 0064b6d0 test currentStage and its type.
		Sim::AssemblyState getState(Assembly* a);
		void resetSleepCount(Assembly* a)
		{
			a->getSleepInfo()->sleepCount = 0;
		}
		AssemblySet* stateToSet(Sim::AssemblyState state);                      // 0064a550
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
	};
}
