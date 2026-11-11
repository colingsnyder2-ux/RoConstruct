// Inactive 2008-06 native recovery: ServiceProvider::create(Instance*, const Name&) 005726f0 of the v8tree/Service.cpp
// unit 005726a0..00573060, against the committed native v8tree/Service.h and v8tree/Instance.h (read-only).
// Evidence (005726f0, 216 B): walks context -> parent (+0x104) until __RTDynamicCast(context, 0, Instance, ServiceProvider)
// is non-null, then calls createChild through the Instance vtable (slot 0x34) and Instance::setParent 0055a8f0 when the
// returned child is non-null; returns child.get(). See tests/record_native_app_unit570_2008.py.
// >>> native-status (generated) -- do not edit >>>
// AppUnit570_2008ServiceProvider | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f10cbd8a | roc native-status --write
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
}
#endif
