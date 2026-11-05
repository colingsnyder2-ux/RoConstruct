#include "v8world/CollisionStage.h"
#include "v8world/SleepStage.h"
#include "v8world/Assembly.h"
#include "v8world/Primitive.h"
#include "v8world/Clump.h"
#include "v8world/Joint.h"

namespace RBX
{
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	CollisionStage::CollisionStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new SleepStage(this, world), world),
		  numContactsInStage(0),
		  stepping(),
		  profilingCollision(new Profiling::CodeProfiler("Collision"))
	{
	}
#pragma warning (pop)

	CollisionStage::~CollisionStage()
	{
		RBXASSERT(stepping.size() == 0);
		RBXASSERT(numContactsInStage == 0);
	}

	void CollisionStage::removeContact(Contact* c)
	{
		RBXASSERT(c->inOrDownstreamOfStage(this));
		if (c->downstreamOfStage(this))
			removeContactFromDownstreamStage(c);

		if (c->steppingIndexFunc() >= 0)
			stepping.fastRemove(c);
	}

	bool CollisionStage::getOkToSim(Contact* c, bool& okToStep)
	{
		Primitive* p0 = c->getPrimitive(0);
		Primitive* p1 = c->getPrimitive(1);

		bool hasJoint = Primitive::getJoint(p0, p1) != NULL;
		okToStep = 
			((!p0->getClump()->getAnchored() && p0->getClump()->getSleepStatus() == Sim::AWAKE) ||
			 (!p1->getClump()->getAnchored() && p1->getClump()->getSleepStatus() == Sim::AWAKE)) &&
			!hasJoint;

		return okToStep && (!p0->getDragging() && p0->getCanCollide()) && (!p1->getDragging() && p1->getCanCollide());
	}

	void CollisionStage::stepWorld(int worldStepId, int uiStepId, bool throttling)
	{
		{
			Profiling::Mark mark(*profilingCollision.get(), false);

			std::vector<Contact*> toErase;

			for (int i = 0; i < stepping.size(); ++i)
			{
				Contact* c = stepping[i];

				RBXASSERT(c->inStage(this));
				if (!throttling || !c->getPrimitive(0)->getBody()->getCanThrottle() || !c->getPrimitive(1)->getBody()->getCanThrottle())
				{
					bool okToStep;
					bool okToSim = getOkToSim(c, okToStep);
					if (!okToStep)
					{
						toErase.push_back(c);
					}
					else
					{
						if (c->step(uiStepId) && okToSim)
						{
							toErase.push_back(c);
							getDownstreamWS()->onEdgeAdded(c);
							RBXASSERT(c->downstreamOfStage(this));
						}
					}
				}
			}

			for (size_t i = 0; i < toErase.size(); ++i)
				stepping.fastRemove(toErase[i]);
		}

		IWorldStage::stepWorld(worldStepId, uiStepId, throttling);
	}

	void CollisionStage::onSleepChanged(const Assembly* assembly)
	{
		typedef std::set<Edge*>::const_iterator Iterator;

		Iterator it = assembly->externalEdgeBegin();
		Iterator itEnd = assembly->externalEdgeEnd();
		for (; it != itEnd; it++)
		{
			Edge* e = *it;
			if (e->getEdgeType() == Edge::CONTACT)
			{
				Contact* c = rbx_static_cast<Contact*>(e);
				if (c->inStage(this))
					updateContact(c);
			}
		}
	}

	void CollisionStage::onLosingContact(const G3D::Array<Contact*>& separating)
	{
		for (int i = 0; i < separating.size(); ++i)
		{
			Contact* c = separating[i];
			RBXASSERT(!c->downstreamOfStage(this));
			RBXASSERT(c->inStage(this));
			updateContact(c);
		}
	}

	void CollisionStage::removeContactFromDownstreamStage(Contact* c)
	{
		RBXASSERT(c->downstreamOfStage(this));
		RBXASSERT(c->steppingIndexFunc() < 0);

		getDownstreamWS()->onEdgeRemoving(c);
	}

	void CollisionStage::updateContact(Contact* c)
	{
		RBXASSERT(c->inOrDownstreamOfStage(this));
		if (c->downstreamOfStage(this))
		{
			bool temp;
			if (getOkToSim(c, temp))
				return;

			removeContactFromDownstreamStage(c);
		}

		RBXASSERT(c->inStage(this));

		if (c->steppingIndexFunc() < 0)
			stepping.fastAppend(c);
	}

	void CollisionStage::onJointAdded(Joint* j)
	{
		RBXASSERT(!j->inKernel());
		getDownstreamWS()->onEdgeAdded(j);

		Contact* c = Primitive::getContact(j->getPrimitive(0), j->getPrimitive(1));
		if (c && c->inOrDownstreamOfStage(this))
			updateContact(c);
	}

	void CollisionStage::onJointRemoved(Joint* j)
	{
		Contact* c = Primitive::getContact(j->getPrimitive(0), j->getPrimitive(1));
		if (c && c->inOrDownstreamOfStage(this))
			RBXASSERT(c->inStage(this));

		getDownstreamWS()->onEdgeRemoving(j);

		if (c && c->inOrDownstreamOfStage(this))
			updateContact(c);
	}

	inline bool isAssemblyInOrDownstreamOfStage(Edge* e, IStage* stage)
	{
		Assembly* a0 = e->getPrimitive(0)->getAssembly();
		Assembly* a1 = e->getPrimitive(1)->getAssembly();
		return a0->inOrDownstreamOfStage(stage) || a1->inOrDownstreamOfStage(stage);
	}

	void CollisionStage::onEdgeAdded(Edge* e)
	{
		RBXASSERT(!e->inKernel());
		RBXASSERT(!e->inOrDownstreamOfStage(this));
		RBXASSERT(isAssemblyInOrDownstreamOfStage(e, this));

		e->putInStage(this);
		if (e->getEdgeType() == Edge::CONTACT)
		{
			++numContactsInStage;
			Contact* c = rbx_static_cast<Contact*>(e);
			RBXASSERT(c->steppingIndexFunc() < 0);
			updateContact(c);
		}
		else
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			onJointAdded(j);
		}
	}

	void CollisionStage::onEdgeRemoving(Edge* e)
	{
		RBXASSERT(isAssemblyInOrDownstreamOfStage(e, this));
		RBXASSERT(e->inOrDownstreamOfStage(this));

		if (e->getEdgeType() == Edge::CONTACT)
		{
			--numContactsInStage;
			Contact* c = rbx_static_cast<Contact*>(e);
			removeContact(c);
		}
		else
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			onJointRemoved(j);
		}

		e->removeFromStage(this);
		RBXASSERT(!e->inOrDownstreamOfStage(this));
	}

	void CollisionStage::onPrimitiveCanCollideChanged(Primitive* p)
	{
		for (Contact* c = p->getFirstContact(); c != NULL; c = p->getNextContact(c))
		{
			if (c->inOrDownstreamOfStage(this))
				updateContact(c);
		}
	}

	int CollisionStage::getMetric(MetricType metricType)
	{
		switch (metricType)
		{
		case NUM_CONTACTSTAGE_CONTACTS:
			return numContactsInStage;
		case NUM_STEPPING_CONTACTS:
			return stepping.size();
		default:
			return IWorldStage::getMetric(metricType);
		}
	}

	void CollisionStage::onAssemblyAdded(Assembly* assembly)
	{
		assembly->putInStage(this);
		rbx_static_cast<SleepStage*>(getDownstreamWS())->onAssemblyAdded(assembly);
	}

	void CollisionStage::onAssemblyRemoving(Assembly* assembly)
	{
		rbx_static_cast<SleepStage*>(getDownstreamWS())->onAssemblyRemoving(assembly);
		assembly->removeFromStage(this);
	}
}
