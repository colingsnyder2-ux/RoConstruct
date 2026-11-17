#undef _RELEASEASSERT   // the 2008 bodies carry no release asserts (IndexArray fastAppend / fastRemove)
#include "v8world/SleepStage2008.h"
#include "v8world/SimJobStage2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Contact2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	Sim::AssemblyState SleepStage::getState(Assembly* a)
	{
		return a->inPipeline() && a->inOrDownstreamOfStage(this) ? a->getSleepInfo()->state : Sim::ANCHORED;
	}

	SleepStage::AssemblySet* SleepStage::stateToSet(Sim::AssemblyState state)
	{
		switch (state)
		{
		case Sim::RECURSIVE_WAKE_PENDING:
			return &recursiveWakePending;
		case Sim::WAKE_PENDING:
			return &wakePending;
		case Sim::AWAKE:
			return &awake;
		case Sim::SLEEPING_CHECKING:
			return &sleepingChecking;
		case Sim::SLEEPING_DEEPLY:
			return &sleepingDeeply;
		case Sim::REMOVED:
			return &sleepingUnknown;
		default:
			return &sleepingUnknown;
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

// INFERRED: RBX::JointStage::sub_00668d30 (placeholder name for 00668d30 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/JointStage2008.h"
#include "AppUnit658/Edge.h"

void RBX::JointStage::sub_00668d30(Edge* e)
{
    e->putInStage(this);
}

// INFERRED: RBX::JointStage::sub_00668d40 (placeholder name for 00668d40 from the identity tier; body byte-proved against the native headers by the placeholder lane)

void RBX::JointStage::sub_00668d40(RBX::Primitive* primitive) { primitive->removeFromStage(this); }
