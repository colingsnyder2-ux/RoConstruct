// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net IdManager.cpp

// Candidate translation unit (score above; library headers required).
#include "IdManager.h"
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace RBX
{

	void IdManager::addInstance(Instance* instance)
	{
		Guid::Data extractedData;
		instance->getGuid().extract(extractedData);

		RBXASSERT(getInstance(extractedData) == NULL || getInstance(extractedData) == instance);

		items[extractedData] = instance;
	}

	void IdManager::removeInstance(boost::shared_ptr<Instance> instance)
	{
		Guid::Data extractedData;
		instance->getGuid().extract(extractedData);

		items.erase(extractedData);
	}

	void IdManager::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (newProvider)
		{
			removeInstanceConnection = event_descendentRemoving.connect(getRootAncestor(), boost::bind(&IdManager::removeInstance, this, _1));
		}
	}
}
