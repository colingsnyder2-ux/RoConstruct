#include "v8tree/Service.h"

namespace RBX
{
	Instance* ServiceProvider::create(Instance* context, const Name& name)
	{
		ServiceProvider* provider = NULL;
		for (Instance* item = context; item != NULL; item = item->getParent())
		{
			provider = dynamic_cast<ServiceProvider*>(item);
			if (provider)
				break;
		}
		if (!provider)
			return NULL;

		boost::shared_ptr<Instance> child = provider->createChild(name);
		if (child)
			child->setParent(provider);

		return child.get();
	}
}

#ifdef NATIVE_APPUNIT570_PENDING
// Needs the ServiceProvider overrides declared in v8tree/Service.h (proposal; the recorder builds these only against a
// generated copy of that header under out/app-unit570-2008/pending/ and records them exact=false).
namespace RBX
{
	void ServiceProvider::onDescendentAdded(Instance* instance)            // 005726a0: Instance::onDescendentAdded 0055ae20
	{
		Instance::onDescendentAdded(instance);
		instance->onServiceProvider(NULL, this);
	}

	void ServiceProvider::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)   // 005726c0: 0055ae90
	{
		instance->onServiceProvider(this, NULL);
		Instance::onDescendentRemoving(instance);
	}

	boost::shared_ptr<Instance> ServiceProvider::createChild(const Name& className)            // 00572e40
	{
		boost::shared_ptr<Instance> instance = findServiceByClassName(className);
		if (instance)
			return instance;

		return AbstractFactoryProduct<Instance>::create(className);
	}

	void ServiceProvider::onChildAdded(Instance* child)                      // 00572ca0 (272 B)
	{
		if (dynamic_cast<Service*>(child))
		{
			// Trial 3: Name::operator!=(const Name&): the argument (getNullName) is evaluated before the object, as in
			// the binary. Rejected: trial 1 (&child->getClassName() != &Name::getNullName()) and trial 2 (operands
			// swapped) both called getClassName first (273 B).
			if (child->getClassName() != Name::getNullName())
				serviceMap[&child->getClassName()] = shared_from(child);
			Notifier<ServiceProvider, ServiceAdded>::raise(ServiceAdded(child));
		}
	}

	void ServiceProvider::onChildRemoving(Instance* child)                   // 00572b40 (120 B)
	{
		std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = serviceMap.find(&child->getClassName());
		if (iter != serviceMap.end())
			Notifier<ServiceProvider, ServiceRemoving>::raise(ServiceRemoving(child));
	}

	void ServiceProvider::clearServices()                                    // 00572db0 (129 B)
	{
		serviceArray.clear();
		serviceMap.clear();
	}
}
#endif

#ifdef NATIVE_SERVICE_ASKADDCHILD_PENDING
#endif

size_t RBX::ServiceProvider::newIndex()
{
    static size_t index = 0xffffffff;
    return InterlockedIncrement(reinterpret_cast<LONG*>(&index));
}

boost::shared_ptr<RBX::Instance> RBX::ServiceProvider::findServiceByClassName(const Name& name) const
{
    std::map<const Name*, boost::shared_ptr<Instance> >::const_iterator it = serviceMap.find(&name);
    if (it != serviceMap.end()) return it->second;
    return boost::shared_ptr<Instance>();
}

template class std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0> >;

namespace RBX {
void ServiceProvider::clearServices(void)
{
    serviceArray.clear();
    serviceMap.clear();
}
}
