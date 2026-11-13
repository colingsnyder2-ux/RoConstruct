// >>> native-status (generated) -- do not edit >>>
// PlayersServiceFind | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by colin
// <<< native-status | src pending | roc native-status --write
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
#include <boost/thread/once.hpp>
#include "Network/Players.h"

extern template boost::shared_ptr<RBX::Instance>::~shared_ptr();

namespace RBX
{
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className()
	{
		return Name::declare<N>();
	}

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
	Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		Class* service;
		if (index + 1 > serviceArray.size())
		{
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
			service = NULL;
		}
		else
		{
			service = static_cast<Class*>(serviceArray[index].get());
			if (service)
				return service;
		}

		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;

		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template Network::Players* ServiceProvider::find<Network::Players>() const;
}
