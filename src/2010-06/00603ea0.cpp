// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8tree/Service.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Service.h"

namespace RBX {

const char sServiceProvider[] = "ServiceProvider";

// FUNCTION: WEBSERVICE 0x10058c30
void ServiceProvider::onDescendentAdded(Instance* instance)
{
	Instance::onDescendentAdded(instance);
	instance->onServiceProvider(NULL, this);
}

// FUNCTION: WEBSERVICE 0x10058c90
void ServiceProvider::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	instance->onServiceProvider(this, NULL);
	Instance::onDescendentRemoving(instance);
}

// STUB: WEBSERVICE 0x10059270
Instance* ServiceProvider::findServiceByClassName(const Name& className) const
{
	STUB(0x10059270);

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10059320
void ServiceProvider::onChildRemoving(Instance* instance)
{
	std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = serviceMap.find(&instance->getClassName());

	if (iter != serviceMap.end()) {
		Notifier<ServiceProvider, ServiceRemoving>::raise(instance);
	}
}

// FUNCTION: WEBSERVICE 0x10059550
void ServiceProvider::onChildAdded(Instance* instance)
{
	if (dynamic_cast<Service*>(instance) != NULL) {
		const Name& nullName = Name::getNullName();

		if (&instance->getClassName() != &nullName) {
			serviceMap[&instance->getClassName()] = shared_from(instance);
		}

		Notifier<ServiceProvider, ServiceAdded>::raise(instance);
	}
}

// FUNCTION: WEBSERVICE 0x10059660
void ServiceProvider::clearServices()
{
	serviceArray.clear();
	serviceMap.clear();
}

// FUNCTION: WEBSERVICE 0x1007ab90
bool ServiceProvider::askAddChild(const Instance* instance) const
{
	return dynamic_cast<const Service*>(instance) != NULL;
}

} // namespace RBX
