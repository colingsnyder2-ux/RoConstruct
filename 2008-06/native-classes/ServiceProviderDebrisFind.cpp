// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider::find<DebrisService>() const 005d2530 (placeholder func_005d2530; inactive), emitted by
// the original SpawnLocation unit 005d1ba0..005d39f0 with the boost::shared_ptr<Instance> destructor called out of line
// (00600660), so it is compiled here with the boost-noinline-shared-destructor variant, the same split as
// PlayerServiceFinds.cpp. getClassIndex: call_once 00557330 on callDoGetClassIndex<DebrisService> 005d2170,
// doGetClassIndex 005d1d70 (index 00979d9c); className 005bfe20 (sDebrisService). Its caller create<DebrisService>()
// const 005d2670 inlines the destructor and lives in ServiceProviderSpawnCreate.cpp. The registry's 548 B for 005d2530
// also covers create<DebrisService>() const (005d2670 = 005d2530 + 320).
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/DebrisService.h"

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

	template DebrisService* ServiceProvider::find<DebrisService>() const; // 005d2530
}
