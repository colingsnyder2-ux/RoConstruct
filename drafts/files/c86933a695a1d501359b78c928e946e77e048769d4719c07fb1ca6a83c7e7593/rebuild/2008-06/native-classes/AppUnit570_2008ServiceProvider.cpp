// Inactive 2008-06 native recovery: ServiceProvider::create(Instance*, const Name&) 005726f0 of the v8tree/Service.cpp
// unit 005726a0..00573060, against the committed native v8tree/Service.h and v8tree/Instance.h (read-only).
// Evidence (005726f0, 216 B): walks context -> parent (+0x104) until __RTDynamicCast(context, 0, Instance, ServiceProvider)
// is non-null, then calls createChild through the Instance vtable (slot 0x34) and Instance::setParent 0055a8f0 when the
// returned child is non-null; returns child.get(). See tests/record_native_app_unit570_2008.py.
// >>> native-status (generated) -- do not edit >>>
// AppUnit570_2008ServiceProvider | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f10cbd8a | roc native-status --write
#define NATIVE_APPUNIT570_PENDING
#include "util/Object.h"
#include "/tmp/claude-0/-home-user/28a5ad2c-f9ca-5f88-a52d-b9a089ed390b/scratchpad/svc/v8tree/Service.h"

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

	// Batch 11 (mb04): the remaining Service.cpp vtable bodies. All four are slots of ??_7ServiceProvider@RBX@@6B@
	// 0082f1bc (askAddChild slot 2, onChildAdded slot 7, onChildRemoving slot 8) and need the overrides, plus an
	// Instance* constructor for ServiceAdded/ServiceRemoving (in-place shared_from into the raise argument slot, the
	// Network::CharacterRemoving pattern), declared in v8tree/Service.h (proposal). Built only in the pending header copy.
	void ServiceProvider::onChildAdded(Instance* child)                      // 00572ca0 (272 B)
	{
		// __RTDynamicCast(child, 0, Instance 0092907c, Service 00929844); getNullName 00554270 compared with the
		// DescribedBase (+0x10) getClassName slot 1; serviceMap operator[] (folded 00592610) + shared_ptr assign
		// 004025b0; raise of the ServiceAdded notifier at +0x150 (folded 0048ba70). No Instance::onChildAdded call.
		if (dynamic_cast<Service*>(child))
		{
			if (&child->getClassName() != &Name::getNullName())
				serviceMap[&child->getClassName()] = shared_from(child);
			Notifier<ServiceProvider, ServiceAdded>::raise(ServiceAdded(child));
		}
	}

	void ServiceProvider::onChildRemoving(Instance* child)                   // 00572b40 (120 B)
	{
		// serviceMap.find (folded 00591bd0) against end(); raise of the ServiceRemoving notifier at +0x170 (folded
		// 005728f0). The binary neither erases the map entry nor calls Instance::onChildRemoving.
		if (serviceMap.find(&child->getClassName()) != serviceMap.end())
			Notifier<ServiceProvider, ServiceRemoving>::raise(ServiceRemoving(child));
	}

	void ServiceProvider::clearServices()                                    // 00572db0 (129 B)
	{
		// vector<shared_ptr<Instance>>::erase(begin, end) 00412180 at +0x190, then the map _Erase(root) 004b0d80
		// and head reset at +0x1a8 (same body as openrbx-selective/v8tree/ServiceSelected.cpp).
		serviceArray.clear();
		serviceMap.clear();
	}
}
#endif

#ifdef NATIVE_SERVICE_ASKADDCHILD_PENDING
// 00575240 (36 B) ServiceProvider::askAddChild, vtable slot 2. It lies in the DataModel.cpp COMDAT run
// (00574f10..0057c1af), not in Service.cpp 005726a0..00573060, so it is an in-class inline body of v8tree/Service.h
// emitted out of line; proposal for that header:
//     virtual bool askAddChild(const Instance* instance) const { return dynamic_cast<const Service*>(instance) != NULL; }
// (__RTDynamicCast(instance, 0, Instance, Service); neg/sbb/neg).
#endif
