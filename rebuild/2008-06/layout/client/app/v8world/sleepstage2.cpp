// =============================================================================
// sleepstage2.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/sleepstage2.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT   // the 2008 bodies carry no release asserts (IndexArray fastAppend / fastRemove)
#include "v8world/SleepStage2008.h"
#include "v8world/SimJobStage2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Contact2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "util/Profiling.h"

namespace RBX
{
	Sim::AssemblyState SleepStage::getState(Assembly* a)
	{
		return a->inPipeline() && a->inOrDownstreamOfStage(this) ? a->getSleepInfo()->state : Sim::ANCHORED;
	}

	SleepStage::~SleepStage()
	{
	}

	bool SleepStage::preventNeighborSleep(Assembly* a)
	{
		if (getState(a) == Sim::AWAKE)
		{
			if (!okNeighborSleep(a))
			{
				return true;
			}
		}

		return false;
	}

	void SleepStage::onWakeUpRequest(Assembly* a, bool recursive)
	{
		if (a->inPipeline() && a->inOrDownstreamOfStage(this))
		{
			if (recursive)
			{
				externalBodyForceAdded = true;
				recursiveWakeEvent(a);
			}
			else
			{
				wakeEvent(a);
			}
		}
	}

	SleepStage::AssemblySet* SleepStage::stateToSet(Sim::AssemblyState state)
	{
		switch (state)
		{
		case Sim::RECURSIVE_WAKE_PENDING:
			return &recursiveWakePending;
		case Sim::WAKE_PENDING:
			return &wakePending;
		case Sim::SLEEPING_CHECKING:
			return &sleepingChecking;
		case Sim::SLEEPING_DEEPLY:
			return &sleepingDeeply;
		case Sim::REMOVED:
			return &removed;
		default:
			return &awake;
		}
	}

	void SleepStage::changeAssemblyState(Assembly* a, Sim::AssemblyState newState)
	{
		Sim::AssemblyState oldState = getState(a);

		stateToSet(oldState)->erase(a);
		stateToSet(newState)->insert(a);

		if ((oldState == Sim::SLEEPING_CHECKING || oldState == Sim::SLEEPING_DEEPLY) &&
			newState != Sim::SLEEPING_CHECKING && newState != Sim::SLEEPING_DEEPLY)
		{
			a->getRootClump()->getRootPrimitive()->getBody()->resetAccumulators();
		}

		if (newState == Sim::AWAKE)
		{
			if (!a->downstreamOfStage(this))
			{
				static_cast<SimJobStage*>(getDownstream())->addAssembly(a);
			}
		}
		else if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY)
		{
			a->getRootClump()->getRootPrimitive()->getBody()->setVelocity(Velocity::zero());
		}

		if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY || newState == Sim::REMOVED)
		{
			if (a->downstreamOfStage(this))
			{
				static_cast<SimJobStage*>(getDownstream())->removeAssembly(a);
			}
		}

		resetSleepCount(a);
		a->getSleepInfo()->state = newState;
	}

	void SleepStage::changeJointState(Joint* j, Sim::EdgeState newState)
	{
		bool wasStepping = j->getEdgeState() == Sim::STEPPING, isStepping = newState == Sim::STEPPING;

		if (wasStepping != isStepping)
		{
			if (wasStepping)
			{
				steppingJoints.erase(j);
				static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
			}
			else
			{
				steppingJoints.insert(j);
				static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(j);
			}
		}

		j->setEdgeState(newState);
	}

	void SleepStage::changeJointState(const std::vector<Joint*>& joints, Sim::EdgeState newState)
	{
		for (unsigned int i = 0; i < joints.size(); i++)
		{
			changeJointState(joints[i], newState);
		}
	}

	void SleepStage::changeContactState(const std::vector<Contact*>& contacts, Sim::EdgeState newState)
	{
		for (unsigned int i = 0; i < contacts.size(); i++)
		{
			changeContactState(contacts[i], newState);
		}
	}

	void SleepStage::changeAssemblyState(const std::vector<Assembly*>& assemblies, Sim::AssemblyState newState)
	{
		for (unsigned int i = 0; i < assemblies.size(); i++)
		{
			changeAssemblyState(assemblies[i], newState);
		}
	}

	void SleepStage::wakeEvent(Assembly* a)
	{
		Sim::AssemblyState state = getState(a);

		if (state != Sim::ANCHORED && state != Sim::WAKE_PENDING && state != Sim::RECURSIVE_WAKE_PENDING)
		{
			changeAssemblyState(a, Sim::WAKE_PENDING);
		}
	}

	void SleepStage::recursiveWakeEvent(Assembly* a)
	{
		Sim::AssemblyState state = getState(a);

		if (state != Sim::ANCHORED && state != Sim::RECURSIVE_WAKE_PENDING)
		{
			changeAssemblyState(a, Sim::RECURSIVE_WAKE_PENDING);
		}
	}

	void SleepStage::touchEvent(Contact* c)
	{
		for (int i = 0; i < 2; i++)
		{
			Assembly* assembly = c->getPrimitive(0)->getAssemblyNoCheck();
			recursiveWakeEvent(assembly);
		}
	}

	void SleepStage::wakeEvent(Edge* e)
	{
		for (int i = 0; i < 2; i++)
		{
			wakeEvent(e->getPrimitive(i)->getAssembly());
		}
	}

	void SleepStage::wakeEdge(Edge* e)
	{
		Sim::EdgeState state = e->getEdgeState();

		if (e->getEdgeType() == Edge::CONTACT)
		{
			if (state == Sim::TOUCHING_SLEEPING)
			{
				changeContactState(static_cast<Contact*>(e), Sim::TOUCHING);
			}
			else if (state == Sim::SLEEPING)
			{
				changeContactState(static_cast<Contact*>(e), Sim::STEPPING);
			}
		}
		else if (state == Sim::SLEEPING)
		{
			changeJointState(static_cast<Joint*>(e), Sim::STEPPING);
		}
	}

	void SleepStage::changeContactState(Contact* c, Sim::EdgeState newState)
	{
		Sim::EdgeState currentState = c->getEdgeState();

		bool wasStepping = currentState == Sim::STEPPING;
		bool wasTouching = currentState == Sim::TOUCHING;
		bool desiredInStepping = newState == Sim::STEPPING;
		bool isTouching = newState == Sim::TOUCHING;

		if (wasStepping != desiredInStepping)
		{
			if (wasStepping)
			{
				steppingContacts.fastRemove(c);
			}
		}

		if (wasTouching != isTouching)
		{
			if (wasTouching)
			{
				touchingContacts.fastRemove(c);
			}
		}

		if (wasStepping != desiredInStepping)
		{
			if (desiredInStepping)
			{
				steppingContacts.fastAppend(c);
			}
		}

		if (wasTouching != isTouching)
		{
			if (isTouching)
			{
				touchingContacts.fastAppend(c);
			}
		}

		if (wasTouching != isTouching)
		{
			if (wasTouching)
			{
				static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(c);
				numContactsInKernel--;
			}
			else
			{
				static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(c);
				numContactsInKernel++;
			}
		}

		if (currentState == Sim::STEPPING && newState == Sim::TOUCHING)
		{
			touchEvent(c);
		}
		else if (currentState == Sim::TOUCHING && newState == Sim::STEPPING)
		{
			wakeEvent(c);
		}

		c->setEdgeState(newState);
	}

	void SleepStage::onEdgeAdded(Edge* e)
	{
		Assembly* a0 = e->getPrimitive(0)->getAssemblyNoCheck();
		Assembly* a1 = e->getPrimitive(1)->getAssemblyNoCheck();

		e->putInStage(this);

		if (e->getEdgeType() == Edge::CONTACT)
		{
			steppingContacts.fastAppend(static_cast<Contact*>(e));
			e->setEdgeState(Sim::STEPPING);
			numContactsInStage++;
		}
		else
		{
			e->setEdgeState(Sim::SLEEPING);
			changeJointState(static_cast<Joint*>(e), Sim::STEPPING);
		}
	}

	void SleepStage::onEdgeRemoving(Edge* e)
	{
		if (e->getEdgeType() == Edge::CONTACT)
		{
			if (e->getEdgeState() == Sim::TOUCHING_SLEEPING || e->getEdgeState() == Sim::TOUCHING)
			{
				wakeEvent(e);
			}

			if (e->getEdgeState() != Sim::SLEEPING)
			{
				changeContactState(static_cast<Contact*>(e), Sim::SLEEPING);
			}

			numContactsInStage--;
		}
		else if (e->getEdgeState() == Sim::SLEEPING)
		{
			wakeEvent(e);
		}
		else
		{
			changeJointState(static_cast<Joint*>(e), Sim::SLEEPING);
		}

		e->setEdgeState(Sim::UNDEFINED);
		e->removeFromStage(this);
	}

}
// `void notifyAssemblyPhysics(Assembly* a, bool on);  // 005e9b80` (INFERRED name) onAssemblyAdded 0064aff0 is
#include "v8world/World2008.h"

namespace RBX
{
	void SleepStage::onAssemblyAdded(Assembly* a)
	{
		a->putInStage(this);
		a->setSleepInfo(new SleepInfo());
		a->getRootClump()->getRootPrimitive()->getBody()->resetAccumulators();
		wakePending.insert(a);
		getWorld()->notifyAssemblyPhysics(a, true);
	}

	void SleepStage::onAssemblyRemoving(Assembly* a)
	{
		changeAssemblyState(a, Sim::REMOVED);
		getWorld()->notifyAssemblyPhysics(a, false);
		removed.erase(a);
		delete a->getSleepInfo();
		a->setSleepInfo(NULL);
		a->removeFromStage(this);
	}
}

namespace RBX
{
	void SleepStage::wakeAssemblyAndNeighbors(Assembly* a, std::deque<Assembly*>& toWake, int recurseDepth)
	{
		Sim::AssemblyState state = getState(a);
		int depth = a->sleepStepCount;

		if (state != Sim::ANCHORED)
		{
			if (state != Sim::AWAKE)
			{
				changeAssemblyState(a, Sim::AWAKE);
			}

			const G3D::Array<Edge*>& edges = a->getExternalEdges();

			for (int i = 0; i < edges.size(); i++)
			{
				Edge* edge = edges[i];

				if (edgeIsAwake(edge))
				{
					wakeEdge(edge);

					if (isAffecting(edge))
					{
						Assembly* other = a->otherAssembly(edge);

						if (depth < recurseDepth)
						{
							if (externalBodyForceAdded || getState(other) != Sim::AWAKE)
							{
								if (other->sleepStepId != field1d8)
								{
									other->sleepStepId = field1d8;
									other->sleepStepCount = depth + 1;
									toWake.push_back(other);
								}
							}
						}
						else if (getState(other) == Sim::SLEEPING_DEEPLY)
						{
							changeAssemblyState(other, Sim::SLEEPING_CHECKING);
						}
					}
				}
			}
		}
	}

	void SleepStage::wakeAssemblies(const AssemblySet& assemblies, int recurseDepth, Sim::AssemblyState state)
	{
		std::deque<Assembly*> toWake;

		field1d8++;

		for (AssemblySet::const_iterator it = assemblies.begin(); it != assemblies.end(); ++it)
		{
			Assembly* a = *it;
			a->sleepStepId = field1d8;
			a->sleepStepCount = 0;
			toWake.push_back(a);
		}

		while (!toWake.empty())
		{
			Assembly* a = toWake.front();
			toWake.pop_front();
			wakeAssemblyAndNeighbors(a, toWake, recurseDepth);
			a->sleepStepCount = -1;
		}

		externalBodyForceAdded = false;
	}
}

namespace RBX
{
	bool SleepStage::computeCanSleep(Assembly* a)
	{
		return !Primitive::disableSleep && a->getCanSleep();
	}

	Sim::AssemblyState SleepStage::computeAssemblyState(Assembly* a)
	{
		if (!computeCanSleep(a))
		{
			return Sim::AWAKE;
		}

		bool allNeighborsSleeping = true;
		const G3D::Array<Edge*>& edges = a->getExternalEdges();

		for (int i = 0; i < edges.size(); i++)
		{
			Edge* edge = edges[i];

			if (edgeIsAwake(edge))
			{
				if (isAffecting(edge))
				{
					Assembly* other = a->otherAssembly(edge);

					if (getState(other) == Sim::AWAKE)
					{
						allNeighborsSleeping = false;

						if (forceNeighborAwake(other))
						{
							return Sim::AWAKE;
						}
					}
				}
			}
		}

		if (allNeighborsSleeping)
		{
			return Sim::SLEEPING_DEEPLY;
		}

		return Sim::SLEEPING_CHECKING;
	}
}

namespace
{
	// INFERRED: donor SleepStage.h `static float sleepTolerance() { return 0.02f; }`; .rdata 00827488 holds 0.02f and
	inline float sleepTolerance()
	{
		return 0.02f;
	}
}

namespace RBX
{
	bool SleepStage::forceNeighborAwake(Assembly* a)
	{
		G3D::CoordinateFrame cofm = a->getRootClump()->getRootPrimitive()->getBody()->getBranchCofmCoordinateFrame();
		float radius = a->getMaxRadius();
		bool withinTolerance = a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, 2.0f * sleepTolerance());

		return !withinTolerance;
	}

	bool SleepStage::okNeighborSleep(Assembly* a)
	{
		G3D::CoordinateFrame cofm = a->getRootClump()->getRootPrimitive()->getBody()->getBranchCofmCoordinateFrame();
		float radius = a->getMaxRadius();

		return a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, sleepTolerance());
	}
}

#ifdef SLEEPSTAGE_HEADER_DECLARES_SHOULDSLEEP
namespace RBX
{
	bool SleepStage::computeShouldSleep(Assembly* a)
	{
		G3D::CoordinateFrame cofm = a->getRootClump()->getRootPrimitive()->getBody()->getBranchCofmCoordinateFrame();
		float maxRadius = a->getMaxRadius();
		RunningAverageState& runningAverageState = a->getSleepInfo()->runningAverageState;

		runningAverageState.update(cofm, maxRadius);

		return runningAverageState.withinTolerance(cofm, maxRadius, sleepTolerance());
	}

	bool SleepStage::shouldSleep(Assembly* a)
	{
		if (!computeCanSleep(a))
		{
			return false;
		}

		if (!computeShouldSleep(a))
		{
			return false;
		}

		const G3D::Array<Edge*>& edges = a->getExternalEdges();

		for (int i = 0; i < edges.size(); i++)
		{
			Edge* edge = edges[i];

			if (edgeIsAwake(edge))
			{
				if (isAffecting(edge))
				{
					Assembly* other = a->otherAssembly(edge);

					if (preventNeighborSleep(other))
					{
						return false;
					}
				}
			}
		}

		return true;
	}
}
#endif

// native-headers/v8world/SleepStage2008.h (not assigned): its INFERRED vector element types are wrong for +0x10 /
#ifdef SLEEPSTAGE_HEADER_DECLARES_STEP_PASSES
namespace RBX
{
	bool SleepStage::isMoving(Assembly* a)
	{
		SleepInfo* info = a->getSleepInfo();
		if (!info)
			return false;

		Sim::AssemblyState state = info->state;
		return state == Sim::AWAKE || state == Sim::RECURSIVE_WAKE_PENDING || state == Sim::WAKE_PENDING;
	}

	bool SleepStage::atLeastOneAssemblyMoving(Assembly* a0, Assembly* a1)
	{
		return isMoving(a0) || isMoving(a1);
	}

	bool SleepStage::canThrottle(Assembly* a)
	{
		return a->getRootClump()->getRootPrimitive()->getBody()->getCanThrottle();
	}

	void SleepStage::stepJoints()
	{
		JointSet::iterator it;

		for (it = steppingJoints.begin(); it != steppingJoints.end(); ++it)
		{
			Joint* j = *it;

			Primitive* prim0 = j->getPrimitive(0);
			Primitive* prim1 = j->getPrimitive(1);

			if (!throttling || !prim0->getBody()->getCanThrottle() || !prim1->getBody()->getCanThrottle())
			{
				if (!atLeastOneAssemblyMoving(prim0->getAssemblyNoCheck(), prim1->getAssemblyNoCheck()))
				{
					toSleepingJoints.push_back(j);
				}
			}
		}

		changeJointState(toSleepingJoints, Sim::SLEEPING);
		toSleepingJoints.resize(0);
	}

	void SleepStage::stepAssembliesAwake()
	{
		for (AssemblySet::iterator it = awake.begin(); it != awake.end(); ++it)
		{
			Assembly* a = *it;

			if (!throttling || !canThrottle(a))
			{
				if (shouldSleep(a))
				{
					a->getSleepInfo()->sleepCount++;

					if (a->getSleepInfo()->sleepCount > 20)
					{
						toSleepingChecking.push_back(a);
					}
				}
				else
				{
					resetSleepCount(a);
				}
			}
		}

		changeAssemblyState(toSleepingChecking, Sim::SLEEPING_CHECKING);
		toSleepingChecking.resize(0);
	}

	void SleepStage::stepAssembliesSleepingChecking()
	{
		for (AssemblySet::iterator it = sleepingChecking.begin(); it != sleepingChecking.end(); ++it)
		{
			Assembly* a = *it;

			Sim::AssemblyState state = computeAssemblyState(a);

			switch (state)
			{
			case Sim::AWAKE:
				toWake.push_back(a);
				break;

			case Sim::SLEEPING_DEEPLY:
				toDeep.push_back(a);
				break;
			}
		}

		changeAssemblyState(toWake, Sim::WAKE_PENDING);
		changeAssemblyState(toDeep, Sim::SLEEPING_DEEPLY);
		toWake.resize(0);
		toDeep.resize(0);
	}
}
#endif

// INFERRED: RBX::SleepStage::sub_0064b7f0 (placeholder name for 0064b7f0 from the identity tier; body byte-proved against the native headers by the placeholder lane)

void RBX::SleepStage::sub_0064b7f0(const std::vector<RBX::Joint*>& joints, RBX::Sim::EdgeState state)
{
	for (size_t i = 0; i < joints.size(); ++i)
		changeJointState(joints[i], state);
}

// INFERRED: RBX::SleepStage::sub_0064b840 (placeholder name for 0064b840 from the identity tier; body byte-proved against the native headers by the placeholder lane)

void RBX::SleepStage::sub_0064b840(const std::vector<Joint*>& joints, Sim::EdgeState state)
{
	for (size_t i = 0; i < joints.size(); ++i) {
		changeJointState(joints[i], state);
	}
}

// INFERRED: RBX::SleepStage::sub_0064c230 (placeholder name for 0064c230 from the identity tier; body byte-proved against the native headers by the placeholder lane)

void RBX::SleepStage::sub_0064c230(const std::vector<Joint*>& joints, Sim::EdgeState newState)
{
	for (size_t i = 0; i < joints.size(); ++i) {
		changeContactState(reinterpret_cast<Contact*>(joints[i]), newState);
	}
}

// INFERRED: RBX::JointStage::sub_00668d30 (placeholder name for 00668d30 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/JointStage2008.h"
#include "AppUnit658/Edge.h"

void RBX::JointStage::sub_00668d30(Edge* e)
{
	e->putInStage(this);
}

// INFERRED: RBX::JointStage::sub_00668d40 (placeholder name for 00668d40 from the identity tier; body byte-proved against the native headers by the placeholder lane)

void RBX::JointStage::sub_00668d40(RBX::Primitive* primitive) { primitive->removeFromStage(this); }
