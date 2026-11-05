// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/SleepStage2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/SleepStage2.h"

#include "decomp.h"
#include "util/Velocity.h"
#include "v8kernel/Body.h"
#include "v8world/Clump2.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/SimJobStage.h"

#include <cstddef>

namespace RBX {

Sim::AssemblyState SleepStage::getState(Assembly* assembly)
{
	return assembly->inPipeline() && assembly->inOrDownstreamOfStage(this) ? assembly->getSleepInfo()->state
																		   : Sim::ANCHORED;
}

SleepStage::AssemblySet* SleepStage::stateToSet(Sim::AssemblyState state)
{
	switch (state) {
	case Sim::RECURSIVE_WAKE_PENDING:
		return &recursiveWakePending;

	case Sim::WAKE_PENDING:
		return &wakePending;

	case Sim::SLEEPING_CHECKING:
		return &sleepingChecking;

	case Sim::SLEEPING_DEEPLY:
		return &sleepingDeeply;

	default:
		return &awake;
	}
}

int SleepStage::getSleepCount(Assembly* assembly)
{
	return assembly->getSleepInfo()->sleepCount;
}

void SleepStage::incrementSleepCount(Assembly* assembly)
{
	assembly->getSleepInfo()->sleepCount++;
}

void SleepStage::resetSleepCount(Assembly* assembly)
{
	assembly->getSleepInfo()->sleepCount = 0;
}

bool SleepStage::isMoving(Assembly* assembly)
{
	Sim::AssemblyState state = getState(assembly);

	return state == Sim::AWAKE || state == Sim::WAKE_PENDING || state == Sim::RECURSIVE_WAKE_PENDING;
}

bool SleepStage::atLeastOneAssemblyMoving(Assembly* a0, Assembly* a1)
{
	return isMoving(a0) || isMoving(a1);
}

bool SleepStage::canThrottle(Assembly* assembly)
{
	return assembly->getAssemblyPrimitiveConst()->getBody()->getCanThrottle();
}

Sim::EdgeState SleepStage::computeContactState(bool moving, bool touching, bool canCollide, bool wasTouching)
{
	if (moving) {
		return touching && canCollide ? Sim::TOUCHING : Sim::STEPPING;
	}

	if (wasTouching && touching && canCollide) {
		return Sim::TOUCHING_SLEEPING;
	}

	return Sim::SLEEPING;
}

bool SleepStage::isAffecting(Edge* edge)
{
	Sim::EdgeState state = edge->getEdgeState();

	return edge->getEdgeType() != Edge::CONTACT || state == Sim::TOUCHING || state == Sim::TOUCHING_SLEEPING;
}

void SleepStage::wakeAssemblyAndNeighbors(Assembly* assembly)
{
	wakeAssemblyAndNeighbors(assembly, 0);
}

bool SleepStage::edgeIsAwake(Edge* edge)
{
	return edge->inOrDownstreamOfStage(this);
}

bool SleepStage::computeCanSleep(Assembly* assembly)
{
	return !Primitive::disableSleep && assembly->getCanSleep();
}

// FUNCTION: WEBSERVICE 0x10118cd0
bool SleepStage::forceNeighborAwake(Assembly* a)
{
	CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float radius = a->getMaxRadius();
	bool withinTolerance =
		a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, 2.0f * sleepTolerance());

	return !withinTolerance;
}

// FUNCTION: WEBSERVICE 0x10118d40
bool SleepStage::okNeighborSleep(Assembly* a)
{
	CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float radius = a->getMaxRadius();

	return a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, sleepTolerance());
}

// FUNCTION: WEBSERVICE 0x10118da0
bool SleepStage::computeShouldSleep(Assembly* a)
{
	CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float maxRadius = a->getMaxRadius();
	RunningAverageState& runningAverageState = a->getSleepInfo()->runningAverageState;

	runningAverageState.update(cofm, maxRadius);

	return runningAverageState.withinTolerance(cofm, maxRadius, sleepTolerance());
}

// FUNCTION: WEBSERVICE 0x10118e20
bool SleepStage::preventNeighborSleep(Assembly* a)
{
	if (getState(a) == Sim::AWAKE) {
		if (!okNeighborSleep(a)) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10118e70
Sim::AssemblyState SleepStage::computeAssemblyState(Assembly* assembly)
{
	if (!computeCanSleep(assembly)) {
		return Sim::AWAKE;
	}

	bool allNeighborsSleeping = true;

	for (EdgeIterator it = assembly->externalEdgeBegin(); it != assembly->externalEdgeEnd(); ++it) {
		Edge* edge = *it;

		if (edgeIsAwake(edge)) {
			if (isAffecting(edge)) {
				Assembly* other = assembly->otherAssembly(edge);

				if (getState(other) == Sim::AWAKE) {
					allNeighborsSleeping = false;

					if (forceNeighborAwake(other)) {
						return Sim::AWAKE;
					}
				}
			}
		}
	}

	return allNeighborsSleeping ? Sim::SLEEPING_DEEPLY : Sim::SLEEPING_CHECKING;
}

// FUNCTION: WEBSERVICE 0x10118f90
int SleepStage::getMetric(MetricType metricType)
{
	switch (metricType) {
	case NUM_CONTACTSTAGE_CONTACTS:
		return numContactsInStage;

	case NUM_STEPPING_CONTACTS:
		return steppingContacts.size();

	case NUM_TOUCHING_CONTACTS:
		return numContactsInKernel;

	default:
		return IWorldStage::getMetric(metricType);
	}
}

// FUNCTION: WEBSERVICE 0x10118fd0
bool SleepStage::shouldSleep(Assembly* assembly)
{
	if (!computeCanSleep(assembly)) {
		return false;
	}

	if (!computeShouldSleep(assembly)) {
		return false;
	}

	for (EdgeIterator it = assembly->externalEdgeBegin(); it != assembly->externalEdgeEnd(); ++it) {
		Edge* edge = *it;

		if (edgeIsAwake(edge)) {
			if (isAffecting(edge)) {
				if (preventNeighborSleep(assembly->otherAssembly(edge))) {
					return false;
				}
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x101193f0
void SleepStage::onAssemblyAdded(Assembly* assembly)
{
	assembly->putInPipeline(this);
	assembly->setSleepInfo(new SleepInfo());
	assembly->getAssemblyPrimitiveConst()->getBody()->resetAccumulators();

	wakePending.insert(assembly);
}

// FUNCTION: WEBSERVICE 0x10119530
SleepStage::~SleepStage()
{
}

// FUNCTION: WEBSERVICE 0x10119740
void SleepStage::changeJointState(Joint* j, Sim::EdgeState newState)
{
	bool wasStepping = j->getEdgeState() == Sim::STEPPING, isStepping = newState == Sim::STEPPING;

	if (wasStepping != isStepping) {
		if (wasStepping) {
			steppingJoints.erase(j);

			getDownstreamWS()->onEdgeRemoving(j);
		}
		else {
			steppingJoints.insert(j);

			getDownstreamWS()->onEdgeAdded(j);
		}
	}

	j->setEdgeState(newState);
}

// FUNCTION: WEBSERVICE 0x101197c0
void SleepStage::changeAssemblyState(Assembly* a, Sim::AssemblyState newState)
{
	Sim::AssemblyState oldState = getState(a);

	AssemblySet* oldSet = stateToSet(oldState);
	AssemblySet* newSet = stateToSet(newState);

	oldSet->erase(a);

	newSet->insert(a);

	if ((oldState == Sim::SLEEPING_CHECKING || oldState == Sim::SLEEPING_DEEPLY) &&
		newState != Sim::SLEEPING_CHECKING && newState != Sim::SLEEPING_DEEPLY) {
		a->getAssemblyPrimitiveConst()->getBody()->resetAccumulators();
	}

	if (newState == Sim::AWAKE) {
		if (!a->downstreamOfStage(this)) {
			static_cast<SimJobStage*>(getDownstream())->onAssemblyAdded(a);

			if (!externalBodyForceAdded) {
				const Primitive* primitive = a->getAssemblyPrimitiveConst();
			}
		}
	}
	else if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY) {
		a->getAssemblyPrimitiveConst()->getBody()->setVelocity(Velocity::zero());

		if (a->downstreamOfStage(this)) {
			static_cast<SimJobStage*>(getDownstream())->onAssemblyRemoving(a);
		}
	}

	resetSleepCount(a);
	a->getSleepInfo()->state = newState;
}

// STUB: WEBSERVICE 0x10119970
void SleepStage::onAssemblyRemoving(Assembly* assembly)
{
	if (getState(assembly) != Sim::SLEEPING_DEEPLY) {
		changeAssemblyState(assembly, Sim::SLEEPING_DEEPLY);
	}

	sleepingDeeply.erase(assembly);

	delete assembly->getSleepInfo();

	assembly->setSleepInfo(NULL);
	assembly->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x10119ae0
void SleepStage::onEdgeAdded(Edge* e)
{
	Assembly* a0 = e->getPrimitive(0)->getAssembly();
	Assembly* a1 = e->getPrimitive(1)->getAssembly();

	e->putInPipeline(this);

	if (e->getEdgeType() == Edge::CONTACT) {
		steppingContacts.fastAppend(static_cast<Contact*>(e));
		e->setEdgeState(Sim::STEPPING);
		numContactsInStage++;
	}
	else {
		e->setEdgeState(Sim::SLEEPING);
		changeJointState(static_cast<Joint*>(e), Sim::STEPPING);
	}
}

// FUNCTION: WEBSERVICE 0x10119ba0
SleepStage::SleepStage(IStage* upstream, World* world)
	: IWorldStage(upstream, new SimJobStage(this, world), world), externalBodyForceAdded(false), numContactsInStage(0),
	  numContactsInKernel(0), throttling(false), uiStepId(-1),
	  profilingCollision(new Profiling::CodeProfiler("Collision")), profilingWake(new Profiling::CodeProfiler("Wake")),
	  profilingSleep(new Profiling::CodeProfiler("Sleep"))
{
}

// STUB: WEBSERVICE 0x10119e00
void SleepStage::wakeEvent(Assembly* a)
{
	Sim::AssemblyState state = getState(a);

	if (state != Sim::ANCHORED && state != Sim::WAKE_PENDING && state != Sim::RECURSIVE_WAKE_PENDING) {
		changeAssemblyState(a, Sim::WAKE_PENDING);
	}
}

// STUB: WEBSERVICE 0x10119e50
void SleepStage::recursiveWakeEvent(Assembly* a)
{
	Sim::AssemblyState state = getState(a);

	if (state != Sim::ANCHORED && state != Sim::RECURSIVE_WAKE_PENDING) {
		changeAssemblyState(a, Sim::RECURSIVE_WAKE_PENDING);
	}
}

// STUB: WEBSERVICE 0x10119ea0
void SleepStage::touchEvent(Contact* c)
{
	for (int i = 0; i < 2; i++) {
		Assembly* assembly = c->getPrimitive(0)->getAssembly();
		recursiveWakeEvent(assembly);
	}
}

// FUNCTION: WEBSERVICE 0x10119f10
void SleepStage::changeJointState(const std::vector<Joint*>& joints, Sim::EdgeState newState)
{
	for (unsigned int i = 0; i < joints.size(); i++) {
		changeJointState(joints[i], newState);
	}
}

// FUNCTION: WEBSERVICE 0x10119f70
void SleepStage::changeAssemblyState(const std::vector<Assembly*>& assemblies, Sim::AssemblyState newState)
{
	for (unsigned int i = 0; i < assemblies.size(); i++) {
		changeAssemblyState(assemblies[i], newState);
	}
}

// FUNCTION: WEBSERVICE 0x10119fd0
void SleepStage::onWakeUpRequest(Assembly* assembly, bool recursive)
{
	if (assembly->inPipeline() && assembly->inOrDownstreamOfStage(this)) {
		if (recursive) {
			recursiveWakeEvent(assembly);
		}
		else {
			wakeEvent(assembly);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1011a020
void SleepStage::stepJoints()
{
	static std::vector<Joint*> toSleeping;

	toSleeping.resize(0);

	JointSet::iterator it;

	for (it = steppingJoints.begin(); it != steppingJoints.end(); ++it) {
		Joint* j = *it;

		Primitive* prim0 = j->getPrimitive(0);
		Primitive* prim1 = j->getPrimitive(1);

		if (!throttling || !prim0->getBody()->getCanThrottle() || !prim1->getBody()->getCanThrottle()) {
			if (!atLeastOneAssemblyMoving(prim0->getAssembly(), prim1->getAssembly())) {
				toSleeping.push_back(j);
			}
		}
	}

	changeJointState(toSleeping, Sim::SLEEPING);
}

// FUNCTION: WEBSERVICE 0x1011a1b0
void SleepStage::stepAssembliesAwake()
{
	static std::vector<Assembly*> toSleepingChecking;

	toSleepingChecking.resize(0);

	for (AssemblySetIt it = awake.begin(); it != awake.end(); ++it) {
		Assembly* assembly = *it;

		if (!throttling || !canThrottle(assembly)) {
			if (shouldSleep(assembly)) {
				incrementSleepCount(assembly);

				if (getSleepCount(assembly) > 20) {
					toSleepingChecking.push_back(assembly);
				}
			}
			else {
				resetSleepCount(assembly);
			}
		}
	}

	changeAssemblyState(toSleepingChecking, Sim::SLEEPING_CHECKING);
}

// FUNCTION: WEBSERVICE 0x1011a310
void SleepStage::stepAssembliesSleepingChecking()
{
	static std::vector<Assembly*> toWake;
	static std::vector<Assembly*> toDeep;

	toWake.resize(0);
	toDeep.resize(0);

	for (AssemblySetIt it = sleepingChecking.begin(); it != sleepingChecking.end(); ++it) {
		Assembly* assembly = *it;

		Sim::AssemblyState state = computeAssemblyState(assembly);

		switch (state) {
		case Sim::AWAKE:
			toWake.push_back(assembly);
			break;

		case Sim::SLEEPING_DEEPLY:
			toDeep.push_back(assembly);
			break;
		}
	}

	changeAssemblyState(toWake, Sim::WAKE_PENDING);
	changeAssemblyState(toDeep, Sim::SLEEPING_DEEPLY);
}

// STUB: WEBSERVICE 0x1011a480
void SleepStage::wakeEvent(Edge* e)
{
	for (int i = 0; i < 2; i++) {
		wakeEvent(e->getPrimitive(i)->getAssembly());
	}
}

// STUB: WEBSERVICE 0x1011a500
void SleepStage::changeContactState(Contact* c, Sim::EdgeState newState)
{
	Sim::EdgeState currentState = c->getEdgeState();

	bool wasStepping = currentState == Sim::STEPPING;
	bool wasTouching = currentState == Sim::TOUCHING;
	bool desiredInStepping = newState == Sim::STEPPING;
	bool isTouching = newState == Sim::TOUCHING;

	if (wasStepping != desiredInStepping) {
		if (wasStepping) {
			steppingContacts.fastRemove(c);
		}
	}

	if (wasTouching != isTouching) {
		if (wasTouching) {
			touchingContacts.fastRemove(c);
		}
	}

	if (wasStepping != desiredInStepping) {
		if (desiredInStepping) {
			steppingContacts.fastAppend(c);
		}
	}

	if (wasTouching != isTouching) {
		if (isTouching) {
			touchingContacts.fastAppend(c);
		}
	}

	if (wasTouching != isTouching) {
		if (wasTouching) {
			getDownstreamWS()->onEdgeRemoving(c);
			numContactsInKernel--;
		}
		else {
			getDownstreamWS()->onEdgeAdded(c);
			numContactsInKernel++;
		}
	}

	if (currentState == Sim::STEPPING && newState == Sim::TOUCHING) {
		touchEvent(c);
	}
	else if (currentState == Sim::TOUCHING && newState == Sim::STEPPING) {
		wakeEvent(c);
	}

	c->setEdgeState(newState);
}

// FUNCTION: WEBSERVICE 0x1011a680
void SleepStage::onEdgeRemoving(Edge* e)
{
	if (e->getEdgeType() == Edge::CONTACT) {
		if (e->getEdgeState() == Sim::TOUCHING_SLEEPING || e->getEdgeState() == Sim::TOUCHING) {
			wakeEvent(e);
		}

		if (e->getEdgeState() != Sim::SLEEPING) {
			changeContactState(static_cast<Contact*>(e), Sim::SLEEPING);
		}

		numContactsInStage--;
	}
	else if (e->getEdgeState() == Sim::SLEEPING) {
		wakeEvent(e);
	}
	else {
		changeJointState(static_cast<Joint*>(e), Sim::SLEEPING);
	}

	e->setEdgeState(Sim::UNDEFINED);
	e->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x1011a720
void SleepStage::wakeEdge(Edge* e)
{
	Sim::EdgeState state = e->getEdgeState();

	if (e->getEdgeType() == Edge::CONTACT) {
		if (state == Sim::TOUCHING_SLEEPING) {
			changeContactState(static_cast<Contact*>(e), Sim::TOUCHING);
		}
		else if (state == Sim::SLEEPING) {
			changeContactState(static_cast<Contact*>(e), Sim::STEPPING);
		}
	}
	else if (state == Sim::SLEEPING) {
		changeJointState(static_cast<Joint*>(e), Sim::STEPPING);
	}
}

// FUNCTION: WEBSERVICE 0x1011a780
void SleepStage::changeContactState(const std::vector<Contact*>& contacts, Sim::EdgeState newState)
{
	for (unsigned int i = 0; i < contacts.size(); i++) {
		changeContactState(contacts[i], newState);
	}
}

// FUNCTION: WEBSERVICE 0x1011a7e0
void SleepStage::stepContacts(ContactList& contacts)
{
	static std::vector<Contact*> toSleeping;
	static std::vector<Contact*> toStepping;
	static std::vector<Contact*> toTouching;
	static std::vector<Contact*> toTouchingSleeping;

	toSleeping.resize(0);
	toStepping.resize(0);
	toTouching.resize(0);
	toTouchingSleeping.resize(0);

	for (int i = 0; i < contacts.size(); i++) {
		Contact* c = contacts[i];

		Primitive* p0 = c->getPrimitive(0);
		Primitive* p1 = c->getPrimitive(1);

		if (!throttling || !p0->getBody()->getCanThrottle() || !p1->getBody()->getCanThrottle()) {
			bool moving = atLeastOneAssemblyMoving(p0->getAssembly(), p1->getAssembly());

			bool touching = c->step(uiStepId);

			bool canCollide = !p0->getDragging() && p0->getCanCollide() && !p1->getDragging() && p1->getCanCollide();

			// clang-format off
			Sim::EdgeState edgeState = c->getEdgeState(); bool wasTouching = edgeState == Sim::TOUCHING;
			// clang-format on

			Sim::EdgeState state = computeContactState(moving, touching, canCollide, wasTouching);

			if (state != edgeState) {
				switch (state) {
				case Sim::SLEEPING:
					toSleeping.push_back(c);
					break;

				case Sim::TOUCHING_SLEEPING:
					toTouchingSleeping.push_back(c);
					break;

				case Sim::STEPPING:
					toStepping.push_back(c);
					break;

				case Sim::TOUCHING:
					toTouching.push_back(c);
					break;
				}
			}
		}
	}

	changeContactState(toSleeping, Sim::SLEEPING);
	changeContactState(toStepping, Sim::STEPPING);
	changeContactState(toTouching, Sim::TOUCHING);
	changeContactState(toTouchingSleeping, Sim::TOUCHING_SLEEPING);
}

// STUB: WEBSERVICE 0x1011ab10
void SleepStage::wakeAssemblyAndNeighbors(Assembly* assembly, int recurseDepth)
{
	Sim::AssemblyState state = getState(assembly);

	if (state != Sim::ANCHORED) {
		if (state != Sim::AWAKE) {
			changeAssemblyState(assembly, Sim::AWAKE);
		}

		for (EdgeIterator it = assembly->externalEdgeBegin(); it != assembly->externalEdgeEnd(); ++it) {
			Edge* edge = *it;

			if (edgeIsAwake(edge)) {
				wakeEdge(edge);

				if (isAffecting(edge)) {
					Assembly* other = assembly->otherAssembly(edge);

					if (recurseDepth > 0) {
						if (getState(other) != Sim::AWAKE) {
							wakeAssemblyAndNeighbors(other, recurseDepth - 1);
						}
					}
					else if (getState(other) == Sim::SLEEPING_DEEPLY) {
						changeAssemblyState(other, Sim::SLEEPING_CHECKING);
					}
				}
			}
		}
	}
}

// STUB: WEBSERVICE 0x1011ac80
void SleepStage::stepAssembliesRecursiveWakePending()
{
	static std::vector<Assembly*> toWake;

	toWake.resize(0);

	for (AssemblySetIt it = recursiveWakePending.begin(); it != recursiveWakePending.end(); ++it) {
		toWake.push_back(*it);
	}

	for (unsigned int i = 0; i < toWake.size(); i++) {
		Assembly* assembly = toWake[i];

		if (getState(assembly) != Sim::RECURSIVE_WAKE_PENDING) {
			changeAssemblyState(assembly, Sim::RECURSIVE_WAKE_PENDING);
		}

		wakeAssemblyAndNeighbors(assembly, 8);
	}
}

// FUNCTION: WEBSERVICE 0x1011afa0
void SleepStage::stepAssembliesWakePending()
{
	static std::vector<Assembly*> toWake;

	toWake.resize(0);

	for (AssemblySetIt it = wakePending.begin(); it != wakePending.end(); ++it) {
		toWake.push_back(*it);
	}

	for (unsigned int i = 0; i < toWake.size(); i++) {
		wakeAssemblyAndNeighbors(toWake[i]);
	}
}

// FUNCTION: WEBSERVICE 0x1011b110
void SleepStage::stepWorld(int worldStepId, int _uiStepId, bool _throttling)
{
	throttling = _throttling;
	uiStepId = _uiStepId;

	{
		Profiling::Mark mark(*profilingWake, false);

		stepAssembliesRecursiveWakePending();
		stepAssembliesWakePending();
	}

	{
		Profiling::Mark mark(*profilingCollision, false);

		stepContacts(steppingContacts);

		stepJoints();

		stepAssembliesRecursiveWakePending();
		stepAssembliesWakePending();
	}

	{
		Profiling::Mark mark(*profilingSleep, false);

		stepAssembliesAwake();

		if (worldStepId % 4 == 0) {
			stepAssembliesSleepingChecking();
		}

		stepAssembliesWakePending();
	}

	stepContacts(touchingContacts);

	stepAssembliesRecursiveWakePending();
	stepAssembliesWakePending();

	externalBodyForceAdded = false;
	getDownstream()->stepWorld(worldStepId, uiStepId, throttling);
}

} // namespace RBX
