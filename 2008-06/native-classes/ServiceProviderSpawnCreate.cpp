// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ServiceProvider service-template rows the original SpawnLocation unit 005d1ba0..005d39f0 emits
// (inactive); the SpawnLocation members themselves are in SpawnLocation.cpp / SpawnLocationTouched.cpp:
//   * doGetClassIndex<DebrisService>() 005d1d70 (index static 00979d9c, guard 00979da0) and its call_once thunk
//     callDoGetClassIndex<DebrisService>() 005d2170 (5 B tail jump);
//   * find<DebrisService>() const 005d2530 calls the shared_ptr destructor out of line: ServiceProviderDebrisFind.cpp;
//   * create<DebrisService>() const 005d2670 (find above, Creatable<Instance>::create<DebrisService> 005c2e10,
//     setParent 0055a8f0) and create<DebrisService>(const Instance*) 005d2b30 (dynamic_cast parent walk, tail jump),
//     called by SpawnerService::SpawnPlayer 005d2b80;
//   * create<SpawnerService>() const 005d33a0 (called by SpawnLocation::onServiceProvider 005d37d0; find 00490c30).
// v8tree/Service.h declares these templates without bodies; the definitions are the ones ServiceProviderTeamsCreate.cpp
// and AppUnit48C_2008Services.cpp use.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/SpawnerService.h"

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

	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->create<Class>();
		}
		return NULL;
	}

	template DebrisService* ServiceProvider::create<DebrisService>() const;                // 005d2670
	template DebrisService* ServiceProvider::create<DebrisService>(const Instance* context); // 005d2b30
	template SpawnerService* ServiceProvider::create<SpawnerService>() const;              // 005d33a0
}
