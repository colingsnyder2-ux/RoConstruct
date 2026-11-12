// 2008-06 native ServiceProvider::find<C>() const instances of the CRobloxDoc translation unit (RobloxDoc.cpp) in the
// application range 00450000..00454000, inactive. CRobloxDoc's own members are a maintainer exclusion; only these RBX
// template instances are built here. Verified by tests/record_native_app_unit450.py. Every header is a committed
// native header, read-only here.
//
//   * ServiceProvider::find<ChangeHistoryService>() const 00452a00, find<Visit>() const 00452b40,
//     find<RunService>() const 00452c80 and find<Soundscape::SoundService>() const 00452dc0 (320 B each):
//     getClassIndex<C>() (call_once 00557330 on callDoGetClassIndex<C> 00450850 / 00450880 / 00450860 / 00450870,
//     then doGetClassIndex<C> 0044f360 / 0044f4a0 / 0044f3c0 / 0044f420), the serviceArray resize 004124c0 / lookup,
//     else findServiceByClassName(C::className()) 00572a90 (Name::declare<sC>: call_once on callDoDeclare<sC>, then
//     doDeclare<sC>) and the serviceArray store (shared_count assignment 004025b0).
//   * The original calls the shared_ptr<Instance> destructor out of line (00600660, twice per row), while the
//     create<C>() const rows of the same unit (counted by app-unit448) inline it. The recorder therefore compiles this
//     unit with native-headers/boost-noinline-shared-destructor first on the include path, the profile
//     record_native_app_unit454_2008.py and record_native_service_history.py use for their find rows.
// The template definitions are the ones native-classes/AppUnit448_2008Services.cpp, AppUnit454_2008WndServices.cpp
// and AppUnit48C_2008Services.cpp use (v8tree/Service.h and util/Object.h declare them without bodies).
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "util/RunStateOwner.h"
#include "util/Sound.h"
#include "v8datamodel/Visit.h"
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

	template ChangeHistoryService* ServiceProvider::find<ChangeHistoryService>() const;
	template Visit* ServiceProvider::find<Visit>() const;
	template RunService* ServiceProvider::find<RunService>() const;
	template Soundscape::SoundService* ServiceProvider::find<Soundscape::SoundService>() const;
}
