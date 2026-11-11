// UNSPLIT CANDIDATE (2026-11-08): AppUnit48C_2008 family
// Originals preserved; review before promotion.

// ---- BEGIN AppUnit48C_2008ClothingThunks.cpp ----
// 2008-06 native rows of the clothing adjustor-thunk runs inside the application range 0048c000..00498000 (Network/
// Player.cpp unit, inactive). Verified by tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The unit emits the Clothing / Pants / Shirt vtables (it creates those classes), and with them the vector deleting
// destructor thunks of their non-primary bases (`sub ecx, N; jmp ??_G`):
//   * FactoryProduct<Clothing, CharacterAppearance, sClothing>: 0048f890 (-0x10), 0048f8a0 (-0x130), 0048f8b0 (-0x64),
//     0048f8c0 (-0x84), 0048f8d0 (-0xa4), each jumping to its ??_G 0048f8e0 (counted by clothing-working.json);
//   * Pants: 0048fb30 (-0x44), 0048fb40 (-0xa4), 0048fb50 (-0xc4), 00493360 (-0x64), 00493370 (-0x84), 00493380 (-0x10),
//     00493390 (-0x14), 00493990 (-0x24), 004939a0 (-0x130) -> ??_GPants 004933a0 (clothing-working.json);
//   * Shirt: 00493460 (-0x130), 00493470 (-0x24), 00493480 (-0x44), 00493490 (-0xa4), 00493a20 (-0x64), 00493a30
//     (-0x84), 00493a40 (-0xc4), 00493a50 (-0x10), 00493a60 (-0x14) -> ??_GShirt 00493a70 (clothing-working.json;
//     evidence names ??_EShirt@RBX@@W...). The Pants / Shirt thunks need the inline constructors (pending build only).
// The adjustments are the base offsets of the native Clothing.h hierarchy (RTTI of the FactoryProduct<Clothing>
// vtables 008218c8..00821850 at +0x10/+0x64/+0x84/+0xa4/+0x130).
// >>> native-status (generated) -- do not edit >>>
// AppUnit48C_2008_unsplit | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2b76acc1 | roc native-status --write
#include "v8datamodel/Clothing.h"

namespace RBX
{
	// The FactoryProduct constructor util/Object.h only declares (the same definition AppUnit480_2008Player.cpp uses).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}
}

// FactoryProduct<Clothing, CharacterAppearance, sClothing>: its vtables and their thunks.
template class RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>;

#ifdef NATIVE_APPUNIT48C_PENDING
// Pending build only (generated v8datamodel/Clothing.h copy with the inline constructors `Pants() {}` / `Shirt() {}`;
// proposal for the Clothing.h owner). The original emitted Pants() 00493920 / Shirt() 004939b0 as COMDATs in this
// unit (create<Pants> 004941d0 / create<Shirt> 00494250 call them out of line), and with them the Pants / Shirt
// vtables and the thunks above. The current header declares the constructors out of line (native-classes/Clothing.cpp
// defines them), so the current-header build emits no Pants / Shirt vtable.
namespace RBX
{
	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

template boost::shared_ptr<RBX::Pants> RBX::Creatable<RBX::Instance>::create<RBX::Pants>();
template boost::shared_ptr<RBX::Shirt> RBX::Creatable<RBX::Instance>::create<RBX::Shirt>();
#endif
// ---- END AppUnit48C_2008ClothingThunks.cpp ----

// ---- BEGIN AppUnit48C_2008Creators.cpp ----
// 2008-06 native rows of the Creatable / FactoryProduct block 0048e6e0..004907ff and 00494940..00494a9f inside the
// application range 0048c000..00498000 (Network/Player.cpp unit, inactive). Verified by
// tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The block is one run of compiler-emitted template instances. Each class has up to four bodies:
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable 00821768..00821b30):
//     calls Creatable<Instance>::create<C>() and returns it as shared_ptr<Object>;
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 / 122 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter())).
// Classes in link order: HopperBin, StarterPackService, LegacyHopperService, Backpack (Creator only; create<Backpack>
// 0048bc20 is counted by app-unit480), SpawnLocation, SpawnerService, ShirtGraphic, Clothing, Pants / Shirt (shared_ptr ctors here,
// create / Creator at 004941d0..004949ff), BodyColors, Skin, Teams, TimerService (Creator only; create<TimerService>
// 0048bcf0 is counted by app-unit480). Humanoid is in AppUnit48C_2008CreatorsHumanoid.cpp (humanoid/Humanoid2008.h).
// sizeof(C) comes from the native headers and is checked by the malloc size each create<C> passes.
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/TimerService.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::HopperBin> RBX::Creatable<RBX::Instance>::create<RBX::HopperBin>();
template boost::shared_ptr<RBX::StarterPackService> RBX::Creatable<RBX::Instance>::create<RBX::StarterPackService>();
template boost::shared_ptr<RBX::LegacyHopperService> RBX::Creatable<RBX::Instance>::create<RBX::LegacyHopperService>();
template boost::shared_ptr<RBX::SpawnLocation> RBX::Creatable<RBX::Instance>::create<RBX::SpawnLocation>();
template boost::shared_ptr<RBX::SpawnerService> RBX::Creatable<RBX::Instance>::create<RBX::SpawnerService>();
template boost::shared_ptr<RBX::ShirtGraphic> RBX::Creatable<RBX::Instance>::create<RBX::ShirtGraphic>();
template boost::shared_ptr<RBX::Clothing> RBX::Creatable<RBX::Instance>::create<RBX::Clothing>();
template boost::shared_ptr<RBX::Pants> RBX::Creatable<RBX::Instance>::create<RBX::Pants>();
template boost::shared_ptr<RBX::Shirt> RBX::Creatable<RBX::Instance>::create<RBX::Shirt>();
template boost::shared_ptr<RBX::BodyColors> RBX::Creatable<RBX::Instance>::create<RBX::BodyColors>();
template boost::shared_ptr<RBX::Skin> RBX::Creatable<RBX::Instance>::create<RBX::Skin>();
template boost::shared_ptr<RBX::Teams> RBX::Creatable<RBX::Instance>::create<RBX::Teams>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Backpack, RBX::Hopper, RBX::sBackpack>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Pants, RBX::Clothing, RBX::sPants>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Shirt, RBX::Clothing, RBX::sShirt>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::Creator::create() const;
// ---- END AppUnit48C_2008Creators.cpp ----

// ---- BEGIN AppUnit48C_2008CreatorsHumanoid.cpp ----
// 2008-06 native rows of the Humanoid Creatable instances inside the application range 0048c000..00498000 (inactive).
// Verified by tests/record_native_app_unit48c_2008.py. Built against the native 2008 humanoid/Humanoid2008.h (sizeof
// 0x22c, extern char sHumanoid[]: RTTI 3PADA), which cannot share a unit with humanoid/Humanoid.h; headers read-only.
//   * FactoryProduct<Humanoid, Instance, sHumanoid>::Creator::create() const 004907f0 (Creator vtable 00821b30 slot 0);
//   * Creatable<Instance>::create<Humanoid>() 00490770 (malloc 0x22c, Humanoid() 005db280);
//   * boost::shared_ptr<Humanoid>(Humanoid*, Creatable<Instance>::Deleter) 004906c0 (shared_count 00490630, counted
//     by creatable-shared-count).
#include "humanoid/Humanoid2008.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; the same definition as AppUnit48C_2008Creators.cpp.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Humanoid> RBX::Creatable<RBX::Instance>::create<RBX::Humanoid>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>::Creator::create() const;
// ---- END AppUnit48C_2008CreatorsHumanoid.cpp ----

// ---- BEGIN AppUnit48C_2008Services.cpp ----
// 2008-06 native rows of the ServiceProvider lookups the RBX::Network::Player unit instantiates, inside the
// application range 0048c000..00498000 (inactive). Verified by tests/record_native_app_unit48c_2008.py. Headers are
// read-only here.
//
//   * ServiceProvider::find<C>() const (320 B) for Workspace 00490af0, SpawnerService 00490c30, StarterPackService
//     00490d70 and TimerService 00490f10: getClassIndex<C>() (call_once 00557330 on callDoGetClassIndex<C>, then
//     doGetClassIndex<C>), serviceArray (+0x190) resize / lookup, else findServiceByClassName(C::className())
//     00572a90 and the serviceArray store;
//   * ServiceProvider::create<TimerService>() const 00492020 (228 B): find<TimerService>() 00490f10, else
//     Creatable<Instance>::create<TimerService>() 0048bcf0, the serviceArray store and setParent(this) 0055a8f0;
//   * ServiceProvider::find<C>(const Instance*) (65 B) for Workspace 00491e50, SpawnerService 00491ea0 and
//     StarterPackService 00491ef0, and create<TimerService>(const Instance*) 00492e50: the parent chain (+0x104) with
//     dynamic_cast<const ServiceProvider*> (Instance 0092907c -> ServiceProvider 0092e15c), then a tail call of the
//     member template; the same for find<Players>(const Instance*) 00491d50 (-> find<Players>() const 004125d0) and
//     create<RunService>(const Instance*) 00492e00 (-> create<RunService>() const 004530f0);
//   * FactoryProduct<Player, Instance, sPlayer>::getClassName() const 0048c480 (23 B: className(), i.e.
//     Name::declare<sPlayer>(): call_once 00557330 on callDoDeclare<sPlayer> 00406eb0, then doDeclare 00406850);
//   * Player::getPlayerBackpack() const 0048c470 (5 B: a tail jump to findFirstChildOfType<Backpack>() 0048bb80);
//     Network/Player.h declares it ("2008 body not located"); its evidence name is
//     ?getPlayerBackpack@Player@Network@RBX@@QBEPAVBackpack@3@XZ.
// v8tree/Service.h and util/Object.h declare these templates without bodies; the definitions below are the ones
// native-classes/ServiceProvider.cpp (find / create / getClassIndex / className) and AppUnit588_2008RootInstance.cpp
// (the const Instance* forms) use.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/Backpack.h"
#include "util/RunStateOwner.h"
#include "Network/Player.h"
#include "Network/Players.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

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

	template<class Class> Class* ServiceProvider::find(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->find<Class>();
		}
		return NULL;
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

	template Workspace* ServiceProvider::find<Workspace>() const;
	template SpawnerService* ServiceProvider::find<SpawnerService>() const;
	template StarterPackService* ServiceProvider::find<StarterPackService>() const;
	template TimerService* ServiceProvider::find<TimerService>() const;
	template TimerService* ServiceProvider::create<TimerService>() const;
	template Workspace* ServiceProvider::find<Workspace>(const Instance* context);
	template SpawnerService* ServiceProvider::find<SpawnerService>(const Instance* context);
	template StarterPackService* ServiceProvider::find<StarterPackService>(const Instance* context);
	template TimerService* ServiceProvider::create<TimerService>(const Instance* context);
	template Network::Players* ServiceProvider::find<Network::Players>(const Instance* context);
	template RunService* ServiceProvider::create<RunService>(const Instance* context);

	template const Name& FactoryProduct<Network::Player, Instance, Network::sPlayer>::getClassName() const;

	namespace Network
	{
		Backpack* Player::getPlayerBackpack() const
		{
			return findFirstChildOfType<Backpack>();
		}
	}
}
// ---- END AppUnit48C_2008Services.cpp ----

// ---- BEGIN AppUnit48C_2008Signals.cpp ----
// 2008-06 native rows of the reflection-signal instances of the Network::Player / Players units inside
// 0048c000..00498000 (inactive). Verified by tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The Player unit declares two signal signatures (original RTTI of SignalDesc<Player, Sig> vtables 00821db0 / 00821dd8):
// void(std::string, shared_ptr<Instance>) and void(float). Rows built here:
//   * boost::any::holder<function<Sig> > (vtables 00821728 / 00821738): constructor 0048dc30 / 0048dfb0, type()
//     0048dc90 / 0048e010, clone() 0048dca0 / 0048e020; boost::any::any(const function<Sig>&) 0048ddf0 / 0048e110;
//   * boost::signal2 / signal1 ::connect(slot) 0048de50 / 0048e170;
//   * TSignalDesc<void(std::string, shared_ptr<Instance>)>: TSignalInstance constructor 0048e2d0 and newSignalInstance
//     0048e4f0 (slot 2 of SignalDesc<Player / Client / Server, Sig>; the void(float) pair 0048e340 / 0048e560 is
//     counted by humanoid2008);
//   * the void(float) call path: slot_call_iterator caller 004934a0, signal1<void, float>::operator() 004937f0 and
//     SignalDescImpl<1, void(float)>::fire 004940e0;
//   * the void(std::string, shared_ptr<Instance>) helpers in the Players unit: signals::detail::args2 destructor
//     00496740 / constructor 004967c0, function2::operator() 00496ac0 and the caller 00497430;
//   * boost::any::holder<shared_ptr<Instance> > (vtable 00821718): ??_G 0048dc10, type() 0048db50, clone() 0048db60,
//     destructor 0048dba0, and boost::any::operator=<shared_ptr<Instance> > 0048dd00.
#include "reflection/signal.h"
#include "v8tree/Instance.h"
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <string>

template class RBX::Reflection::SignalDescImpl<1, void(float)>;
template class RBX::Reflection::SignalDescImpl<2, void(std::string, boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TSignalDesc<void(float)>;
template class RBX::Reflection::TSignalDesc<void(std::string, boost::shared_ptr<RBX::Instance>)>;

template class boost::any::holder<boost::shared_ptr<RBX::Instance> >;
template boost::any& boost::any::operator=<boost::shared_ptr<RBX::Instance> >(const boost::shared_ptr<RBX::Instance>&);
// ---- END AppUnit48C_2008Signals.cpp ----

