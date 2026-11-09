// from server: 92% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/World.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/World.h"

#include "decomp.h"
#include "util/standardout.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Kernel.h"
#include "v8world/Assembly2.h"
#include "v8world/Clump2.h"
#include "v8world/ClumpStage2.h"
#include "v8world/Contact.h"
#include "v8world/Joint.h"
#include "v8world/JointBuilder.h"
#include "v8world/JointStage.h"
#include "v8world/SimJobStage.h"
#include "v8world/SleepStage2.h"
#include "v8world/SpatialHash.h"

#include <G3D/System.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include <cmath>

namespace RBX {

bool World::disableEnvironmentalThrottle;

// FUNCTION: WEBSERVICE 0x100cef80
Kernel* World::getKernel() const
{
	return jointStage->getKernel();
}

// FUNCTION: WEBSERVICE 0x100cef90
int World::getNumBodies() const
{
	return getKernel()->numBodies();
}

// FUNCTION: WEBSERVICE 0x100cefb0
int World::getNumPoints() const
{
	return getKernel()->numPoints();
}

// FUNCTION: WEBSERVICE 0x100cefd0
int World::getNumConstraints() const
{
	return getKernel()->numConnectors();
}

// FUNCTION: WEBSERVICE 0x100ceff0
int World::getMetric(IWorldStage::MetricType metricType) const
{
	return jointStage->getMetric(metricType);
}

// FUNCTION: WEBSERVICE 0x100cf000
int World::getNumHashNodes() const
{
	return contactManager->getSpatialHash()->getNodesOut();
}

// FUNCTION: WEBSERVICE 0x100cf010
int World::getMaxBucketSize() const
{
	return contactManager->getSpatialHash()->getMaxBucket();
}

// FUNCTION: WEBSERVICE 0x100cf020
void World::onPrimitiveContactParametersChanged(Primitive* p)
{
	Contact* c = p->getFirstContact();

	while (c != NULL) {
		c->onPrimitiveContactParametersChanged();
		c = p->getNextContact(c);
	}
}

// FUNCTION: WEBSERVICE 0x100cf050
void World::onPrimitiveExtentsChanged(Primitive* p)
{
	contactManager->onPrimitiveExtentsChanged(p);
}

// FUNCTION: WEBSERVICE 0x100cf060
void World::onAssemblyExtentsChanged(Assembly* a)
{
	PrimIterator pEnd = a->assemblyPrimEnd();

	for (PrimIterator it = a->assemblyPrimBegin(); it != pEnd; ++it) {
		contactManager->onPrimitiveExtentsChanged(*it);
	}
}

// FUNCTION: WEBSERVICE 0x100cf0c0
void World::onPrimitiveGeometryTypeChanged(Primitive* p)
{
	contactManager->onPrimitiveGeometryTypeChanged(p);
}

// FUNCTION: WEBSERVICE 0x100cf0d0
void World::onJointPrimitiveNulling(Joint* j, Primitive* p)
{
	jointStage->onJointPrimitiveNulling(j, p);
}

// FUNCTION: WEBSERVICE 0x100cf0e0
void World::onJointPrimitiveSet(Joint* j, Primitive* p)
{
	jointStage->onJointPrimitiveSet(j, p);
}

// FUNCTION: WEBSERVICE 0x100cf0f0
void World::insertContact(Contact* c)
{
	jointStage->onEdgeAdded(c);
	numContacts++;
}

// FUNCTION: WEBSERVICE 0x100cf110
void World::destroyContact(Contact* c)
{
	jointStage->onEdgeRemoving(c);
	delete c;
	numContacts--;
}

ClumpStage* World::getClumpStage()
{
	return static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE));
}

SleepStage* World::getSleepStage()
{
	return static_cast<SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE));
}

// FUNCTION: WEBSERVICE 0x100cf140
SimJobStage& World::getSimJobStage()
{
	return *static_cast<SimJobStage*>(jointStage->findStage(IStage::SIMJOB_STAGE));
}

// FUNCTION: WEBSERVICE 0x100cf170
const SleepStage* World::getSleepStage() const
{
	return static_cast<const SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE));
}

// FUNCTION: WEBSERVICE 0x100cf1a0
void World::ticklePrimitive(Primitive* p, bool recursive)
{
	Assembly* assembly = p->getAssembly();

	if (assembly != NULL) {
		getSleepStage()->onWakeUpRequest(assembly, recursive);
	}
}

// FUNCTION: WEBSERVICE 0x100cf1f0
void World::onPrimitiveCanSleepChanged(Primitive* p)
{
	getClumpStage()->onPrimitiveCanSleepChanged(p);
}

// FUNCTION: WEBSERVICE 0x100cf230
void World::onPrimitiveAddedAnchor(Primitive* p)
{
	getClumpStage()->onPrimitiveAddedAnchor(p);
}

// FUNCTION: WEBSERVICE 0x100cf270
void World::onPrimitiveRemovedAnchor(Primitive* p)
{
	getClumpStage()->onPrimitiveRemovedAnchor(p);
}

// FUNCTION: WEBSERVICE 0x100cf2b0 FOLDED
void World::onPrimitiveCanCollideChanged(Primitive* p)
{
	getClumpStage()->onPrimitiveCanCollideChanged(p);
}

// FUNCTION: WEBSERVICE 0x100cf2b0 FOLDED
void World::onMotorAngleChanged(MotorJoint* motorJoint)
{
	getClumpStage()->onMotorAngleChanged(motorJoint);
}

// FUNCTION: WEBSERVICE 0x100cf2f0
void World::update()
{
	getClumpStage()->process();
}

// FUNCTION: WEBSERVICE 0x100cf320
void World::addedBodyForce()
{
	getSleepStage()->addedBodyForce();
}

// FUNCTION: WEBSERVICE 0x100cf510
void World::onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP)
{
	touch.append(touchP);
	touchOther.append(touchOtherP);
}

// FUNCTION: WEBSERVICE 0x100cf540
void World::computeFallen(G3D::Array<Primitive*>& fallen) const
{
	const SleepStage::AssemblySet& awake = getSleepStage()->getAwakeAssemblies();

	for (SleepStage::CAssemblySetIt cIt = awake.begin(); cIt != awake.end(); cIt++) {

		Assembly* assembly = *cIt;

		if (assembly->getAssemblyPrimitive()->getCoordinateFrame().translation.y < -500.0f) {

			PrimIterator pEnd = assembly->assemblyPrimEnd();

			for (PrimIterator it = assembly->assemblyPrimBegin(); it != pEnd; ++it) {

				Primitive* p = *it;

				if (p->getCoordinateFrame().translation.y < -500.0f) {
					fallen.append(p);
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cf6b0
void World::insertPrimitive(Primitive* p)
{
	primitives.fastAppend(p);
	p->world = this;

	jointStage->onPrimitiveAdded(p);
	contactManager->onPrimitiveAdded(p);
}

static bool inIgnoreGroup(std::set<Primitive*>* ignoreGroup, Primitive* p)
{
	return ignoreGroup != NULL && ignoreGroup->find(p) != ignoreGroup->end();
}

inline void World::destroyJoint(Joint* joint)
{
	inJointNotification = true;
	Notifier<World, AutoDestroy>::raise(AutoDestroy(joint));
	inJointNotification = false;
}

inline void World::removeFromBreakable(Joint* j)
{
	if (j->isBreakable()) {
		breakableJoints.erase(j);
	}
}

// FUNCTION: WEBSERVICE 0x100cfaf0
void World::doBreakJoints()
{
	std::set<Joint*>::iterator it = breakableJoints.begin();

	while (it != breakableJoints.end()) {

		Joint* joint = *it;
		++it;

		if (joint->inKernel() && joint->isBroken()) {
			destroyJoint(joint);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cfcd0
float World::step(float desiredInterval)
{
	Profiling::Mark mark(*profilingWorldStep, true);

	update();

	double startTime = G3D::System::getTick();

	bool throttling = false;

	int steps = std::max(1, G3D::iRound((float) floor(Constants::worldStepsPerSec() * desiredInterval)));

	for (int j = 0; j < steps; j++) {

		int uiStepId = worldStepId / Constants::worldStepsPerUiStep();

		if (worldStepId % Constants::worldStepsPerUiStep() == 0) {

			Profiling::Mark mark(*profilingUiStep, false);

			doBreakJoints();

			touch.resize(0, false);
			touchOther.resize(0, false);

			inStepCode = true;

			getClumpStage()->stepUi(uiStepId);

			getSimJobStage().notifyMovingPrimitives();

			inStepCode = false;
		}

		{
			inStepCode = true;

			Profiling::Mark mark(*profilingBroadphase, false);

			contactManager->stepWorld();

			inStepCode = false;
		}

		inStepCode = true;

		jointStage->stepWorld(worldStepId, uiStepId, throttling);

		inStepCode = false;

		throttling = !disableEnvironmentalThrottle && canThrottle &&
					 G3D::System::getTick() > startTime + Constants::worldDt() * (j + 1);

		worldStepId++;
	}

	return Constants::worldDt() * steps;
}

// FUNCTION: WEBSERVICE 0x100d0020
void World::insertJoint(Joint* j)
{
	Primitive* p0 = j->getPrimitive(0);
	Primitive* p1 = j->getPrimitive(1);

	if (p0 != NULL && p1 != NULL) {
		Joint* existing = Primitive::getJoint(p0, p1);

		if (existing != NULL) {
			destroyJoint(existing);
		}
	}

	jointStage->onEdgeAdded(j);

	numJoints++;

	if (j->isBreakable()) {
		breakableJoints.insert(j);
	}
}

// FUNCTION: WEBSERVICE 0x100d0090
void World::destroyJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
{
	Joint* j = p->getFirstJoint();

	while (j != NULL) {
		Joint* joint = j;
		j = p->getNextJoint(j);

		if (Joint::isAutoJoinJoint(joint)) {
			Primitive* other = joint->otherPrimitive(p);

			if (!inIgnoreGroup(ignoreGroup, other)) {
				destroyJoint(joint);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d0140
void World::destroyJoints(Primitive* p)
{
	destroyJoints(p, NULL);
}

// FUNCTION: WEBSERVICE 0x100d0150
void World::createJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
{
	numLinkCalls++;

	tempPrimitives.resize(0, false);

	contactManager->getPrimitivesTouchingExtents(p->getFastFuzzyExtents(), p, tempPrimitives);

	for (int i = 0; i < tempPrimitives.size(); i++) {

		Primitive* other = tempPrimitives[i];

		if (!inIgnoreGroup(ignoreGroup, other) && Primitive::getJoint(p, other) == NULL) {

			Joint* joint = JointBuilder::canJoin(p, other);

			if (joint != NULL) {

				insertJoint(joint);

				inJointNotification = true;
				Notifier<World, AutoJoin>::raise(AutoJoin(joint));
				inJointNotification = false;
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d0250
void World::createJoints(Primitive* p)
{
	createJoints(p, NULL);
}

// FUNCTION: WEBSERVICE 0x100d0260
World::~World()
{
	delete jointStage;

	delete contactManager;
}

// FUNCTION: WEBSERVICE 0x100d0420
void World::removeJoint(Joint* j)
{
	removeFromBreakable(j);

	jointStage->onEdgeRemoving(j);

	numJoints--;
}

// FUNCTION: WEBSERVICE 0x100d0460
void World::joinAll()
{
	for (int i = 0; i < getNumPrimitives(); i++) {
		createJoints(primitives[i]);
	}
}

// FUNCTION: WEBSERVICE 0x100d0490
void World::removePrimitive(Primitive* p)
{
	destroyJoints(p);

	contactManager->onPrimitiveRemoved(p);

	jointStage->onPrimitiveRemoving(p);

	primitives.fastRemove(p);

	p->world = NULL;
}

// FUNCTION: WEBSERVICE 0x100d04f0
World::World()
	: contactManager(new ContactManager(this)), jointStage(new JointStage(NULL, this)), canThrottle(true),
	  inStepCode(false), inJointNotification(false), worldStepId(0), numJoints(0), numContacts(0), numLinkCalls(0),
	  profilingWorldStep(new Profiling::CodeProfiler("World Step")),
	  profilingUiStep(new Profiling::CodeProfiler("UI Step")),
	  profilingBroadphase(new Profiling::CodeProfiler("Broadphase"))
{
	profilingBroadphase->parent = profilingWorldStep.get();
	profilingUiStep->parent = profilingWorldStep.get();

	getSleepStage()->profilingCollision->parent = profilingWorldStep.get();
	getSleepStage()->profilingWake->parent = profilingWorldStep.get();
	getSleepStage()->profilingSleep->parent = profilingWorldStep.get();

	getKernel()->profilingKernel->parent = profilingWorldStep.get();
}

// FUNCTION: WEBSERVICE 0x100d07f0
void World::destroyJointsToWorld(const G3D::Array<Primitive*>& primitives)
{
	std::set<Primitive*> ignore;

	for (int i = 0; i < primitives.size(); i++) {
		ignore.insert(primitives[i]);
	}

	for (int i = 0; i < primitives.size(); i++) {
		destroyJoints(primitives[i], &ignore);
	}
}

// FUNCTION: WEBSERVICE 0x100d08d0
void World::createJointsToWorld(const G3D::Array<Primitive*>& primitives)
{
	std::set<Primitive*> ignore;

	for (int i = 0; i < primitives.size(); i++) {
		ignore.insert(primitives[i]);
	}

	for (int i = 0; i < primitives.size(); i++) {
		createJoints(primitives[i], &ignore);
	}
}

} // namespace RBX
