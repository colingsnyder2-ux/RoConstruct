#include "v8world/SeparateStage.h"
#include "v8world/SleepStage.h"
#include "v8world/SimJobStage.h"
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"
#include "v8world/Contact.h"

namespace RBX
{
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	SeparateStage::SeparateStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new SimJobStage(this, world), world)
	{
	}
#pragma warning (pop)

	SeparateStage::~SeparateStage()
	{
		RBXASSERT(inContact.empty());
	}

	SleepStage* SeparateStage::getSleepStage()
	{
		return rbx_static_cast<SleepStage*>(getUpstreamWS());
	}

	void SeparateStage::onAssemblyAdded(Assembly* assembly)
	{
		assembly->putInStage(this);
		rbx_static_cast<SimJobStage*>(getDownstreamWS())->onAssemblyAdded(assembly);
	}

	void SeparateStage::onAssemblyRemoving(Assembly* assembly)
	{
		rbx_static_cast<SimJobStage*>(getDownstreamWS())->onAssemblyRemoving(assembly);
		assembly->removeFromStage(this);
	}

	void SeparateStage::stepWorld(int worldStepId, int uiStepId, bool throttling)
	{
		separating.fastClear();

		typedef std::set<Contact*>::const_iterator Iterator;
		for (Iterator it = inContact.begin(); it != inContact.end(); it++)
		{
			Contact* c = *it;
			if (!throttling ||
				!c->getPrimitive(0)->getBody()->getCanThrottle() ||
				!c->getPrimitive(1)->getBody()->getCanThrottle())
			{
				if (!c->step(uiStepId))
					separating.append(c);
			}
		}

		for (int i = 0; i < separating.size(); ++i)
			onEdgeRemoving(separating[i]);

		getSleepStage()->onLosingContact(separating);
		
		IWorldStage::stepWorld(worldStepId, uiStepId, throttling);
	}

	void SeparateStage::onEdgeAdded(Edge* e)
	{
		RBXASSERT(!e->inOrDownstreamOfStage(this));

		e->putInStage(this);
		if (e->getEdgeType() == Edge::CONTACT)
		{
			Contact* c = rbx_static_cast<Contact*>(e);

			bool inserted = inContact.insert(c).second;
			RBXASSERT(inserted);
		}

		getDownstreamWS()->onEdgeAdded(e);
	}

	void SeparateStage::onEdgeRemoving(Edge* e)
	{
		getDownstreamWS()->onEdgeRemoving(e);

		if (e->getEdgeType() == Edge::CONTACT)
		{
			Contact* c = rbx_static_cast<Contact*>(e);

			size_t removed = inContact.erase(c);
			RBXASSERT(removed == 1);
		}

		e->removeFromStage(this);
	}

	int SeparateStage::getMetric(MetricType metricType)
	{
		if (metricType == NUM_TOUCHING_CONTACTS)
			return (int)inContact.size();
		
		return IWorldStage::getMetric(metricType);
	}
}
