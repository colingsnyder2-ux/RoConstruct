// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Stats::Item COMDATs the ScriptContext unit (script/ScriptContext.cpp) instantiates inside the
// application range 005ac000..005b0000 (inactive). Verified by tests/record_native_app_unit5ac.py.
//
// Headers are read-only here: the Stats owner's native stats/Stats.h (Item(const char*) is defined there and cites
// 005ad810; the stats-service receipt leaves "Item(const char*) chain: COMDATs of the script unit (create<Item,
// const char*> 005adb70); not instantiated here") and v8tree/Service.h (ServiceProvider::create<T> is declared there
// without a body; the definitions below are the ones native-classes/AppUnit48C_2008Services.cpp uses).
//
//   * Creatable<Instance>::create<Stats::Item, const char*> 005adb70: malloc 0x158 = sizeof Stats::Item (the stats
//     owner's layout: val +0x130, sValue +0x138), Item(const char*) 005ad810, shared_ptr<Item>(Item*, Deleter) 004ad3c0;
//   * Item(const char*) 005ad810 (val = 0 at +0x130, the Item vtables 00819fc4.., then std::string() at +0x138) and
//     its base DescribedNonCreatable<Item, Instance, sStatsItem>(const char*) 005ad770 (NonFactoryProduct(const char*)
//     005a8dd0, classDescriptor<Item> 0045dc70);
//   * ServiceProvider::create<Stats::StatsService>(const Instance*) 005aecd0: the parent chain (+0x104) with
//     dynamic_cast<const ServiceProvider*> (Instance 0092907c -> ServiceProvider 0092e15c), then a tail jump to
//     create<StatsService>() const 00458610.
#include <boost/thread/once.hpp>
#include "stats/Stats.h"
#include "v8tree/Service.h"

namespace RBX
{
	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->create<Class>();
		}
		return NULL;
	}

	template boost::shared_ptr<Stats::Item> Creatable<Instance>::create<Stats::Item, const char*>(const char*);
	template Stats::StatsService* ServiceProvider::create<Stats::StatsService>(const Instance* context);
}
