// Inactive 2008-06 native recovery: ServiceProvider::create(Instance*, const Name&) 005726f0 of the v8tree/Service.cpp
// unit 005726a0..00573060, against the committed native v8tree/Service.h and v8tree/Instance.h (read-only).
// Evidence (005726f0, 216 B): walks context -> parent (+0x104) until __RTDynamicCast(context, 0, Instance, ServiceProvider)
// is non-null, then calls createChild through the Instance vtable (slot 0x34) and Instance::setParent 0055a8f0 when the
// returned child is non-null; returns child.get(). See tests/record_native_app_unit570_2008.py.
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
// Batch 32 measurement against a scratch v8tree/Service.h that declares the five protected overrides below and
// gives ServiceAdded / ServiceRemoving an `X(Instance* service) : service(shared_from(service)) {}` constructor:
// onChildRemoving 00572b40, onChildAdded 00572ca0, onDescendentAdded 005726a0, onDescendentRemoving 005726c0 and
// clearServices 00572db0 IDENTICAL (relocs masked). createChild 00572e40 stays a near miss (224 B vs 191 B: the
// target shares one release of `instance` between both returns; the ternary `instance ? instance : create(...)`
// was worse, 263 B).
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
		// serviceMap.find (folded 00591bd0) against end(); raise of the ServiceRemoving notifier at +0x170 (folded
		// 005728f0). The binary neither erases the map entry nor calls Instance::onChildRemoving.
		// Trial 2: named iterator, end() read after find (trial 1 compared find() with end() directly: end() was
		// loaded before the find call and the returned iterator was used through its address, 129 B).
		std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = serviceMap.find(&child->getClassName());
		if (iter != serviceMap.end())
			Notifier<ServiceProvider, ServiceRemoving>::raise(ServiceRemoving(child));
	}

	// 00572bc0 (registry placeholder func_00572bc0, 223 B, ret 4): ServiceProvider::onAddListener, slot 1 of the
	// Notifier<ServiceProvider, ServiceAdded> subobject vtables at +0x150 (ServiceProvider 0082f130, GlobalSettings,
	// DataModel and their DescribedNonCreatable/NonFactoryProduct vtables; util/Events.h declares the virtual). Children
	// at [this-0x48] (Instance +0x108); __RTDynamicCast(child, 0, Instance 0092907c, Service 00929844); the event built
	// in place by shared_from 00618a40 and raise(event, listener) 0048b030. Body: the 2007 openrbx
	// v8tree/Service.cpp ServiceProvider::onAddListener. Needs the override and ServiceAdded(Instance*) declared in
	// v8tree/Service.h (proposal).
	void ServiceProvider::onAddListener(Listener<ServiceProvider, ServiceAdded>* listener) const
	{
		// The 2008 Instance exposes the CopyOnWrite children member (+0x108) in place of the 2007 getChildren().
		if (children) {
			std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
			for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = children->begin(); iter != end;
				 ++iter) {
				if (dynamic_cast<Service*>(iter->get())) {
					Notifier<ServiceProvider, ServiceAdded>::raise(iter->get(), listener);
				}
			}
		}
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

#ifdef NATIVE_SERVICE_FINDBYSTRING_PENDING
// Batch 32 measurement (scratch copy of v8tree/Service.h with the proposal below plus the NATIVE_APPUNIT570_PENDING
// declarations, compiled with this unit's default flags): 005729c0 IDENTICAL (relocs masked, 197 B).
// 005729c0 (197 B, ret 0x20): ?findServiceByClassNameString@ServiceProvider@RBX@@AAE?AV?$shared_ptr@VInstance@RBX@@@
// boost@@V?$basic_string@...@@Z (registry; private, by-value std::string). Name::lookup(const std::string&) 00554180
// compared by address with getNullName 00554270; on a miss G3D::format 00509b10 of "'%s' is not a valid Service name"
// (0082f7e8) into std::runtime_error 00409d50, thrown (_CxxThrowException, 008d1bc8); else create(this, name) 005726f0
// and shared_from 00618a40 (folded) into the return slot; the argument string is destroyed (MSVCP90 import).
// Blocked: v8tree/Service.h (core) does not declare it. Proposal for that header, in the private section:
//     boost::shared_ptr<Instance> findServiceByClassNameString(std::string className);
namespace RBX
{
	boost::shared_ptr<Instance> ServiceProvider::findServiceByClassNameString(std::string className)
	{
		// Batch 32: getNullName on the left gives the target `cmp eax, esi` (the reverse order compared esi, eax).
		const Name& name = Name::lookup(className);
		if (&Name::getNullName() == &name)
			throw std::runtime_error(G3D::format("'%s' is not a valid Service name", className.c_str()));
		return shared_from(create(this, name));
	}
}
#endif
