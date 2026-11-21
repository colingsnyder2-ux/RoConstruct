// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::SleepStage rows (inactive); layout evidence in native-headers/v8world/SleepStage2008.h.
// Bodies follow the donor v8world/SleepStage2.cpp shape; 2008 differences are listed per function.
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
	// donor getState (inline in the 2008 bodies, e.g. 0064ae90..0064aebf)
	Sim::AssemblyState SleepStage::getState(Assembly* a)
	{
		return a->inPipeline() && a->inOrDownstreamOfStage(this) ? a->getSleepInfo()->state : Sim::ANCHORED;
	}

	// 0064b330: member destructors only (donor ~SleepStage is empty): the three scoped_ptr profilers (+0x1e8 / +0x1e4 /
	// +0x1e0, virtual delete through slot 0), steppingJoints +0x1b8 (~_Tree 0064b230), the two IndexArrays +0x1ac /
	// +0x1a0 (G3D alignedFree 00507d20), the six assembly sets, the eight vectors, then the donor ~IStage (delete
	// downstream +0x8 through slot 0).
	SleepStage::~SleepStage()
	{
	}

	// 0064a740 (donor SleepStage::preventNeighborSleep; getState inline, okNeighborSleep 0064a660 out of line)
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

	// 0064b890 (donor SleepStage::onWakeUpRequest; 2008 sets externalBodyForceAdded +0x1dc before a recursive wake)
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

	// 0064a550: jump table 0064a598 over state - 1 (1 -> +0xe0, 2 -> +0x100, 4 -> +0x140, 5 -> +0x160, 6 -> +0x180;
	// 3 shares the default block +0x120, the donor SleepStage2.cpp `default: return &awake`).
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

	// 0064ae90
	// PARKED (batch 25, 2 hypotheses + the onAssemblyRemoving trial): 325 B against 337. The first getState expansion evaluates this->getStageType()
	// first (`mov edi, [ebx + 4]` preloaded, this call, then the assembly's stage) where the target calls the
	// assembly's stage first (0064aea3..0064aeba); in the REMOVED test the order is the other way round (target this
	// first and a spill to [esp + 0x20], 0064af9e..0064afbd). Same calls, constants and stores otherwise. The same
	// one-expansion order flip keeps wakeEvent 0064b5e0 / recursiveWakeEvent 0064b6d0 (inlined changeAssemblyState) and
	// onAssemblyRemoving 0064b0a0 from matching. Rejected: getState as if / return instead of the ternary (unchanged),
	// inOrDownstreamOfStage spelled `stage->getStageType() <= currentStage->getStageType()` in a shadow
	// v8kernel/IPipelined2008.h trial (unchanged: still this first, only the jump sense flips).
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

	// 0064ae10 (donor changeJointState: steppingJoints.erase / insert and the downstream edge notification)
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

	// 0064b7f0
	void SleepStage::changeJointState(const std::vector<Joint*>& joints, Sim::EdgeState newState)
	{
		for (unsigned int i = 0; i < joints.size(); i++)
		{
			changeJointState(joints[i], newState);
		}
	}

	// 0064c230
	void SleepStage::changeContactState(const std::vector<Contact*>& contacts, Sim::EdgeState newState)
	{
		for (unsigned int i = 0; i < contacts.size(); i++)
		{
			changeContactState(contacts[i], newState);
		}
	}

	// 0064b840
	void SleepStage::changeAssemblyState(const std::vector<Assembly*>& assemblies, Sim::AssemblyState newState)
	{
		for (unsigned int i = 0; i < assemblies.size(); i++)
		{
			changeAssemblyState(assemblies[i], newState);
		}
	}

	// 0064b5e0
	void SleepStage::wakeEvent(Assembly* a)
	{
		Sim::AssemblyState state = getState(a);

		if (state != Sim::ANCHORED && state != Sim::WAKE_PENDING && state != Sim::RECURSIVE_WAKE_PENDING)
		{
			changeAssemblyState(a, Sim::WAKE_PENDING);
		}
	}

	// 0064b6d0
	void SleepStage::recursiveWakeEvent(Assembly* a)
	{
		Sim::AssemblyState state = getState(a);

		if (state != Sim::ANCHORED && state != Sim::RECURSIVE_WAKE_PENDING)
		{
			changeAssemblyState(a, Sim::RECURSIVE_WAKE_PENDING);
		}
	}

	// 0064b7c0 (the donor loop calls getPrimitive(0) both times)
	void SleepStage::touchEvent(Contact* c)
	{
		for (int i = 0; i < 2; i++)
		{
			Assembly* assembly = c->getPrimitive(0)->getAssemblyNoCheck();
			recursiveWakeEvent(assembly);
		}
	}

	// 0064bf60
	void SleepStage::wakeEvent(Edge* e)
	{
		for (int i = 0; i < 2; i++)
		{
			wakeEvent(e->getPrimitive(i)->getAssembly());
		}
	}

	// 0064c1d0
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

	// 0064bf90
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

	// 0064b1b0
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

	// 0064c130
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
// Both bodies end in World 005e9b80 (`ret 8`, (Assembly*, bool):
// raises the +0x40 / +0x60 notifier with assembly +0x24 -> +0x1c, i.e. the donor AssemblyPhysicsOn / AssemblyPhysicsOff
// events of engine-world v8world/World.h). With a trial World2008.h declaring
// `void notifyAssemblyPhysics(Assembly* a, bool on);  // 005e9b80` (INFERRED name) onAssemblyAdded 0064aff0 is
// IDENTICAL (171 B) and onAssemblyRemoving 0064b0a0 is 263 B with only the getState evaluation-order flip of
// changeAssemblyState 0064ae90 (target this->getStageType() first, `lea ebp, [edi + 0x180]` hoisted). The declaration
// is now in native-headers/v8world/World2008.h (batch 27).
#include "v8world/World2008.h"
namespace RBX
{
	// 0064aff0 (donor openrbx SleepStage2.cpp onAssemblyAdded): putInStage 00645830, new 0x24 SleepInfo 005e5f30,
	// setSleepInfo 005e5fe0, resetAccumulators 00613e80 inline test, wakePending (+0x100) insert 005e8c40, then the
	// World notification 005e9b80 (world +0xc, true).
	void SleepStage::onAssemblyAdded(Assembly* a)
	{
		a->putInStage(this);
		a->setSleepInfo(new SleepInfo());
		a->getRootClump()->getRootPrimitive()->getBody()->resetAccumulators();
		wakePending.insert(a);
		getWorld()->notifyAssemblyPhysics(a, true);
	}

	// 0064b0a0: changeAssemblyState(a, REMOVED) inline (insert into the state-6 set +0x180), the World notification
	// 005e9b80 (false), erase from +0x180, delete the SleepInfo (~SleepInfo 0047d410, operator delete), setSleepInfo(NULL),
	// removeFromStage 00645840.
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

// Batch 28: the 2008 wake pass and computeAssemblyState (identity: SleepStage unit 0064a550..0064ca5f; callers and
// callees cited per body; donor tools/openrbx v8world/SleepStage2.cpp shapes).
namespace RBX
{
	// 0064c470 (registry func_0064c470; only caller 0064c6b0): donor wakeAssemblyAndNeighbors, breadth-first in 2008.
	// getState inline, changeAssemblyState 0064ae90 to AWAKE, getExternalEdges 005e6c70, wakeEdge 0064c1d0,
	// otherAssembly 005e61b0, getState 0064a5b0 out of line for the neighbour, deque push_back 00589330, and
	// changeAssemblyState(other, SLEEPING_CHECKING) inline at the depth limit.
	// PARKED (batch 28, 543 B against 568): same calls, constants and control flow. Residuals: (1) the inline
	// edgeIsAwake and the inline getState(other) of the SLEEPING_DEEPLY test evaluate this->getStageType() first in the
	// target (edge / other currentStage preloaded into ebp, this call, spill, then the other call), the same one-expansion
	// order flip as changeAssemblyState 0064ae90 (parked batch 25); computeAssemblyState 0064a790 expands the same inlines
	// edge first and matches; (2) the target materialises `getState(other) != AWAKE` (setne al / test al, al).
	// Rejected: a named bool for the `externalBodyForceAdded || getState(other) != AWAKE` test (unchanged).
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

	// 0064c6b0 (registry func_0064c6b0): ++field1d8, every assembly of the set marked (+0x44 pass id, +0x48 depth 0) and
	// queued (std::deque<Assembly*>, push_back 00589330), then popped front first through 0064c470 with its depth reset
	// to -1; externalBodyForceAdded (+0x1dc) cleared last; ~deque 0064fa10.
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

// 0064a790 (registry func_0064a790; donor SleepStage::computeAssemblyState with computeCanSleep inline): the byte
// 0097abc1 (only readers 0064a795 and 0064a95a; .bss between the Clump-unit statics 0097abb8 / 0097abbc and the
// Primitive-unit statics from 0097abc4) is the donor trialDisableSleep, then the canSleep ComputeProp (+0x68).
// Primitive::disableSleep is declared in native-headers/v8world/Primitive2008.h (batch 29). Batch 28 trial: the donor
// computeCanSleep spelling is required (written out as `disableSleep || !getCanSleep()` the AWAKE return merges into the
// tail, 304 B; the ternary return gives setne / add, 293 B).
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
