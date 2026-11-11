// Source-derived world pipeline port from openrbx include/v8world/SleepStage2.h.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
// >>> native-status (generated) -- do not edit >>>
// SleepStage | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5bbb2415 | roc native-status --write
#ifndef V8WORLD_SLEEPSTAGE2_H
#define V8WORLD_SLEEPSTAGE2_H

#include "util/IndexArray.h"
#include "util/Profiling.h"
#include "v8world/Assembly.h"
#include "v8world/Contact.h"
#include "v8world/IWorldStage.h"

#include <G3D/Array.h>
#include <boost/scoped_ptr.hpp>
#include <set>
#include <vector>

namespace RBX {

class Joint;
class SimJobStage;

// VTABLE: WEBSERVICE 0x10247df8
// SIZE 0x90
class SleepStage : public IWorldStage
{
public:
	typedef std::set<Assembly*> AssemblySet;
	typedef std::set<Joint*> JointSet;
	typedef AssemblySet::iterator AssemblySetIt;
	typedef AssemblySet::const_iterator CAssemblySetIt;
	typedef IndexArray<Contact, &Contact::steppingIndexFunc> ContactList;

	SleepStage(IStage* upstream, World* world);

	virtual ~SleepStage(); // vtable+0x00

	// SYNTHETIC: WEBSERVICE 0x10119de0
	// RBX::SleepStage::`scalar deleting destructor'

	// FUNCTION: WEBSERVICE 0x1011b580 FOLDED
	virtual StageType getStageType() { return SLEEP_STAGE; } // vtable+0x04

	virtual void stepWorld(int worldStepId, int _uiStepId, bool _throttling); // vtable+0x0c

	virtual void onEdgeAdded(Edge* edge);         // vtable+0x10
	virtual void onEdgeRemoving(Edge* edge);      // vtable+0x14
	virtual int getMetric(MetricType metricType); // vtable+0x18

	void onAssemblyAdded(Assembly* assembly);
	void onAssemblyRemoving(Assembly* assembly);

	void onWakeUpRequest(Assembly* assembly, bool recursive);

	void onLosingContact(const G3D::Array<Contact*>& contacts);

	void addedBodyForce() { externalBodyForceAdded = true; }

	int numTouchingContacts() { return touchingContacts.size(); }

	const AssemblySet& getAwakeAssemblies() const { return awake; }

private:
	static float sleepTolerance() { return 0.02f; }
	static int stepsToSleep() { return 6; }

	bool isMoving(Assembly* assembly);
	bool canThrottle(Assembly* assembly);
	bool atLeastOneAssemblyMoving(Assembly* a0, Assembly* a1);

	bool edgeIsAwake(Edge* edge);
	bool isAffecting(Edge* edge);

	bool computeShouldSleep(Assembly* a);
	bool computeCanSleep(Assembly* assembly);
	bool shouldSleep(Assembly* assembly);
	bool okNeighborSleep(Assembly* assembly);
	bool preventNeighborSleep(Assembly* assembly);
	bool forceNeighborAwake(Assembly* assembly);

	Sim::AssemblyState computeAssemblyState(Assembly* assembly);

	Sim::AssemblyState getState(Assembly* assembly);
	AssemblySet* stateToSet(Sim::AssemblyState state);

	int getSleepCount(Assembly* assembly);
	void incrementSleepCount(Assembly* assembly);
	void resetSleepCount(Assembly* assembly);

	void changeAssemblyState(Assembly* assembly, Sim::AssemblyState state);
	void changeAssemblyState(const std::vector<Assembly*>& assemblies, Sim::AssemblyState state);
	void changeContactState(Contact* contact, Sim::EdgeState state);
	void changeContactState(const std::vector<Contact*>& contacts, Sim::EdgeState state);
	void changeJointState(Joint* joint, Sim::EdgeState state);
	void changeJointState(const std::vector<Joint*>& joints, Sim::EdgeState state);

	void wakeAssembly(Assembly* assembly);
	void wakeAssemblyAndNeighbors(Assembly* assembly);
	void wakeAssemblyAndNeighbors(Assembly* assembly, int depth);
	void wakeEdge(Edge* edge);

	Sim::EdgeState computeContactState(bool moving, bool touching, bool canCollide, bool wasTouching);

	void wakeEvent(Assembly* assembly);
	void wakeEvent(Edge* edge);
	void recursiveWakeEvent(Assembly* assembly);
	void touchEvent(Contact* contact);

	void stepContacts(ContactList& contacts);
	void stepJoints();
	void stepAssembliesAwake();
	void stepAssembliesSleepingChecking();
	void stepAssembliesWakePending();
	void stepAssembliesRecursiveWakePending();

	bool validate();

	bool externalBodyForceAdded;      // 0x10
	int numContactsInStage;           // 0x14
	int numContactsInKernel;          // 0x18
	bool throttling;                  // 0x1c
	int uiStepId;                     // 0x20
	AssemblySet recursiveWakePending; // 0x24
	AssemblySet wakePending;          // 0x30
	ContactList steppingContacts;     // 0x3c
	ContactList touchingContacts;     // 0x48
	JointSet steppingJoints;          // 0x54
	AssemblySet awake;                // 0x60
	AssemblySet sleepingChecking;     // 0x6c
	AssemblySet sleepingDeeply;       // 0x78

public:
	boost::scoped_ptr<Profiling::CodeProfiler> profilingCollision; // 0x84
	boost::scoped_ptr<Profiling::CodeProfiler> profilingWake;      // 0x88
	boost::scoped_ptr<Profiling::CodeProfiler> profilingSleep;     // 0x8c
};


// clang-format off
// SYNTHETIC: WEBSERVICE 0x102252e0
// `RBX::SleepStage::stepAssembliesRecursiveWakePending'::`2'::`dynamic atexit destructor for 'toWake''

// SYNTHETIC: WEBSERVICE 0x10225320
// `RBX::SleepStage::stepAssembliesWakePending'::`2'::`dynamic atexit destructor for 'toWake''

// SYNTHETIC: WEBSERVICE 0x10225360
// `RBX::SleepStage::stepContacts'::`2'::`dynamic atexit destructor for 'toTouchingSleeping''

// SYNTHETIC: WEBSERVICE 0x102253a0
// `RBX::SleepStage::stepContacts'::`2'::`dynamic atexit destructor for 'toTouching''

// SYNTHETIC: WEBSERVICE 0x102253e0
// `RBX::SleepStage::stepContacts'::`2'::`dynamic atexit destructor for 'toStepping''

// SYNTHETIC: WEBSERVICE 0x10225420
// `RBX::SleepStage::stepContacts'::`2'::`dynamic atexit destructor for 'toSleeping''

// SYNTHETIC: WEBSERVICE 0x10225460
// `RBX::SleepStage::stepJoints'::`2'::`dynamic atexit destructor for 'toSleeping''

// SYNTHETIC: WEBSERVICE 0x102254a0
// `RBX::SleepStage::stepAssembliesAwake'::`2'::`dynamic atexit destructor for 'toSleepingChecking''

// SYNTHETIC: WEBSERVICE 0x102254e0
// `RBX::SleepStage::stepAssembliesSleepingChecking'::`2'::`dynamic atexit destructor for 'toDeep''

// SYNTHETIC: WEBSERVICE 0x10225520
// `RBX::SleepStage::stepAssembliesSleepingChecking'::`2'::`dynamic atexit destructor for 'toWake''
// clang-format on

} // namespace RBX

#endif // V8WORLD_SLEEPSTAGE2_H
