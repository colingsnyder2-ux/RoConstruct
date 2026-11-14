// 2008-06 native ServiceProvider::find<Network::Server>() const instance of the Network::Server unit (Network/Server.cpp)
// inside the application range 004a0000..004a4000 (inactive). Verified by tests/record_native_app_unit4a0.py. Every
// header is a committed native header, read-only here.
//
//   * ServiceProvider::find<Server>() const 004a3e40 (320 B; reached from Server::serverIsPresent 004a40d0):
//     getClassIndex<Server>() (call_once 00557330 on callDoGetClassIndex<Server> 004a1d00 with the flag 00970d18, then
//     doGetClassIndex<Server> 004a1760: function-local static newIndex() 00572690), the serviceArray resize 004124c0 /
//     lookup, else findServiceByClassName(Server::className()) 00572a90 and the serviceArray store.
//   * Built with native-headers/boost-noinline-shared-destructor first on the include path (the original calls the
//     shared_ptr<Instance> destructor out of line), the profile of native-classes/AppUnit450ServiceFind.cpp.
// The template definitions are the ones native-classes/AppUnit450ServiceFind.cpp uses (v8tree/Service.h and
// util/Object.h declare them without bodies).
#include <boost/thread/once.hpp>
#include "Network/Server2008.h"
#include "util/Object.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::find() const
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
			if (service != NULL)
				return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;
		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template Network::Server* ServiceProvider::find<Network::Server>() const;
}
