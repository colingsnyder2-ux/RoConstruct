// 2008-06 native rows of the RBX template instances the CRobloxDoc translation unit (RobloxDoc.cpp, 0044f1a0..
// 00454000+ of the application range 00448000..00454000) emits, inactive. CRobloxDoc's own members are excluded
// (maintainer exclusion); only the RBX ServiceProvider / Creatable / FactoryProduct / Name instances are built here.
// Verified by tests/record_native_app_unit448_2008.py. Every header is a committed native header, read-only here.
//
//   * ServiceProvider::doGetClassIndex<C>() (91 B: `static size_t index = newIndex()`, newIndex 00572690) for
//     ChangeHistoryService 0044f360, RunService 0044f3c0, Soundscape::SoundService 0044f420 and Visit 0044f4a0, and
//     callDoGetClassIndex<C>() (5 B tail jumps) 00450850 / 00450860 / 00450870 / 00450880;
//   * Name::doDeclare<sVisit>() 0044f2f0 (`static const Name& n = declare("Visit", -1)`, literal 0094f6cc) and
//     callDoDeclare<sVisit>() 00450840;
//   * ServiceProvider::find<C>() const (320 B) 00452a00 / 00452b40 / 00452c80 / 00452dc0: getClassIndex<C>()
//     (call_once 00557330 on callDoGetClassIndex<C>), serviceArray (+0x190) resize 004124c0 / lookup, else
//     findServiceByClassName(C::className()) 00572a90 and the serviceArray store;
//   * ServiceProvider::create<C>() const (228 B) 00453000 / 004530f0 / 004531e0: find<C>(), else
//     Creatable<Instance>::create<C>() (004150d0 / 00405fa0 / 00440980), the serviceArray store and setParent(this)
//     0055a8f0;
//   * Creatable<Instance>::create<Visit>() 004528d0 (new 0x150 = sizeof(Visit) of v8datamodel/Visit.h, Visit()
//     005c5220, shared_ptr<Visit>(p, Deleter())), shared_ptr<Visit>(Visit*, Creatable<Instance>::Deleter) 00452820
//     (calls the shared_count instance 00452790 counted by creatable-shared-count) and
//     FactoryProduct<Visit, Instance, sVisit>::Creator::create() const 00452950 (slot 0 of the Creator vtable whose
//     RTTI is .?AVCreator@?$FactoryProduct@VVisit@RBX@@VInstance@2@$1?sVisit@2@3PADA@RBX@@).
// v8tree/Service.h, util/Object.h and util/Name.h declare these templates; the definitions below are the same ones
// native-classes/AppUnit48C_2008Services.cpp and AppUnit48C_2008Creators.cpp use.
// >>> native-status (generated) -- do not edit >>>
// AppUnit448_2008Services | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 33f07573 | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "util/RunStateOwner.h"
#include "util/Sound.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/GameSettings.h"
#include "util/Object.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

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

	template ChangeHistoryService* ServiceProvider::find<ChangeHistoryService>() const;
	template Visit* ServiceProvider::find<Visit>() const;
	template RunService* ServiceProvider::find<RunService>() const;
	template Soundscape::SoundService* ServiceProvider::find<Soundscape::SoundService>() const;
	template ChangeHistoryService* ServiceProvider::create<ChangeHistoryService>() const;
	template RunService* ServiceProvider::create<RunService>() const;
	template Soundscape::SoundService* ServiceProvider::create<Soundscape::SoundService>() const;
}

template boost::shared_ptr<RBX::Visit> RBX::Creatable<RBX::Instance>::create<RBX::Visit>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Visit, RBX::Instance, RBX::sVisit>::Creator::create() const;

// The CRobloxApp unit (RobloxApp.cpp, 00449460..0044ddcf) emits two more instances of the same families for
// GameSettings: boost::detail::shared_count(GameSettings*, Creatable<Instance>::Deleter) 0044a8c0 (131 B; stores the
// sp_counted_impl_pd<GameSettings*, Deleter> vtable 00816914; the shared_ptr<GameSettings> constructor 0044b850 that
// settings-items counts calls it) and FactoryProduct<GameSettings, GlobalSettings::Item, sGameSettings>::Creator::
// create() const 0044d560 (slot 0 of the Creator vtable 00816db4; calls create<GameSettings>() 0044bdc0, counted by
// settings-items).
template boost::detail::shared_count::shared_count(RBX::GameSettings*, RBX::Creatable<RBX::Instance>::Deleter);
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::GameSettings, RBX::GlobalSettings::Item, RBX::sGameSettings>::Creator::create() const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::ChangeHistoryService>;
template class boost::shared_ptr<RBX::GameSettings>;
template class boost::shared_ptr<RBX::Soundscape::SoundService>;
template class boost::shared_ptr<RBX::Visit>;
