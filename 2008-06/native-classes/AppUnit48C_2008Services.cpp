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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::RunService>;
template class std::_Vector_iterator<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;
template class std::deque<RBX::Network::AbuseReport,std::allocator<RBX::Network::AbuseReport> >;
