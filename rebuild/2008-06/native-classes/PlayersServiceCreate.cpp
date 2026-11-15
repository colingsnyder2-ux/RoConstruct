// >>> native-status (generated) -- do not edit >>>
// PlayersServiceCreate | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by colin
// <<< native-status | src pending | roc native-status --write
#include <boost/thread/once.hpp>
#include "Network/Players.h"

namespace RBX
{
	extern template boost::shared_ptr<Network::Players> Creatable<Instance>::create<Network::Players>();

	template<class Class>
	size_t ServiceProvider::doGetClassIndex()
	{
		static size_t index = newIndex();
		return index;
	}

	template<class Class>
	void ServiceProvider::callDoGetClassIndex()
	{
		doGetClassIndex<Class>();
	}

	template<class Class>
	size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class>
	Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (!service)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template Network::Players* ServiceProvider::create<Network::Players>() const;
}
