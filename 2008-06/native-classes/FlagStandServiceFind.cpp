// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider template instances for FlagStandService (inactive), split out of the original Flag
// unit (00618380..00619a60) the way AppUnit454_2008ReportStats.cpp holds the StatsService ones: compiled inside
// FlagClone.cpp the unit inlines ~shared_ptr<Instance> (404 B) where the target calls 00600660 (320 B); same
// noinline-destructor profile as ScriptContextServiceFind.cpp / TeamsServiceFind.cpp.
#include "v8tree/Service.h"
#include "v8datamodel/FlagStandService.h"

extern template boost::shared_ptr<RBX::Instance>::~shared_ptr();
// ServiceProvider member templates for FlagStandService, emitted in the Flag unit of the original (00618380..00619a60):
// doGetClassIndex<FlagStandService> 00618520 (call_once 00557330 on callDoGetClassIndex 00618650, once flag 0097bf18),
// find<FlagStandService>() const 00619080 (registry placeholder func_00619080, 320 B: serviceArray +0x190 resize /
// lookup, findServiceByClassName(className()) 00572a90). Its caller create<FlagStandService>() const 00619360 needs the
// inline ~shared_ptr<FlagStandService>, so it is emitted by FlagStand.cpp (onServiceProvider 0062cf40 calls it). The
// static create<FlagStandService>(const Instance*) 00619450 is instantiated by ServiceProviderStaticFind2008.cpp.
// v8tree/Service.h declares these templates without bodies (definitions as ScriptContextServiceFind.cpp).
#include <boost/thread/once.hpp>

namespace RBX
{
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

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

	template FlagStandService* ServiceProvider::find<FlagStandService>() const;   // 00619080
}
