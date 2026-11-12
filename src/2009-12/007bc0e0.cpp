// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/v8tree/Service.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Service.h"

#include <windows.h>

namespace RBX {

const char sServiceProvider[] = "ServiceProvider";

Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> ServiceProvider::func_service(
	&ServiceProvider::findServiceByClassNameString, "service", "name", Reflection::FunctionDescriptor::AnyCaller
);

Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> ServiceProvider::
	func_GetService(
		&ServiceProvider::findServiceByClassNameString, "GetService", "name", Reflection::FunctionDescriptor::AnyCaller
	);

// FUNCTION: WEBSERVICE 0x10058c20
// FUNCTION: ROBLOX 0x0058bd60
unsigned int ServiceProvider::newIndex()
{
	static long index = -1;

	return InterlockedIncrement(&index);
}

// FUNCTION: WEBSERVICE 0x10058c30
// FUNCTION: ROBLOX 0x0058bd70
void ServiceProvider::onDescendentAdded(Instance* instance)
{
	Instance::onDescendentAdded(instance);
	instance->onServiceProvider(NULL, this);
}

// FUNCTION: WEBSERVICE 0x10058c90
// FUNCTION: ROBLOX 0x0058bd90
void ServiceProvider::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	instance->onServiceProvider(this, NULL);
	Instance::onDescendentRemoving(instance);
}

// FUNCTION: WEBSERVICE 0x10058cc0
// FUNCTION: ROBLOX 0x0058bdc0
Instance* ServiceProvider::create(Instance* context, const Name& name)
{
	while (context != NULL) {
		ServiceProvider* provider = dynamic_cast<ServiceProvider*>(context);
		if (provider) {
			boost::shared_ptr<Instance> child = provider->createChild(name);
			if (child) {
				child->setParent(provider);
			}
			return child.get();
		}

		context = context->getParent();
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100591a0
// FUNCTION: ROBLOX 0x0058c2a0
boost::shared_ptr<Instance> ServiceProvider::findServiceByClassNameString(std::string sName)
{
	const Name& name = Name::lookup(sName);
	if (&Name::getNullName() == &name) {
		throw std::runtime_error(G3D::format("'%s' is not a valid Service name", sName.c_str()));
	}

	return shared_from(create(this, name));
}

// FUNCTION: WEBSERVICE 0x10059270
// FUNCTION: ROBLOX 0x0058c370
boost::shared_ptr<Instance> ServiceProvider::findServiceByClassName(const Name& className) const
{
	std::map<const Name*, boost::shared_ptr<Instance> >::const_iterator iter = serviceMap.find(&className);

	if (iter != serviceMap.end()) {
		return iter->second;
	}

	return boost::shared_ptr<Instance>();
}

// FUNCTION: WEBSERVICE 0x10059320
// FUNCTION: ROBLOX 0x0058c420
void ServiceProvider::onChildRemoving(Instance* instance)
{
	std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = serviceMap.find(&instance->getClassName());

	if (iter != serviceMap.end()) {
		Notifier<ServiceProvider, ServiceRemoving>::raise(instance);
	}
}

// FUNCTION: WEBSERVICE 0x100593a0
// FUNCTION: ROBLOX 0x0058c4a0
void ServiceProvider::onAddListener(Listener<ServiceProvider, ServiceAdded>* listener) const
{
	if (getChildren()) {
		std::vector<boost::shared_ptr<Instance> >::const_iterator end = getChildren()->end();
		for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = getChildren()->begin(); iter != end;
			 ++iter) {
			if (dynamic_cast<Service*>(iter->get())) {
				Notifier<ServiceProvider, ServiceAdded>::raise(iter->get(), listener);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10059550
// FUNCTION: ROBLOX 0x0058c560
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
// FUNCTION: ROBLOX 0x0058c670
void ServiceProvider::clearServices()
{
	serviceArray.clear();
	serviceMap.clear();
}

// FUNCTION: WEBSERVICE 0x10059750
// FUNCTION: ROBLOX 0x0058c750
shared_ptr<Instance> ServiceProvider::createChild(const Name& className)
{
	boost::shared_ptr<Instance> instance = findServiceByClassName(className);
	if (instance) {
		return instance;
	}

	return Instance::create(className);
}

// FUNCTION: WEBSERVICE 0x1007ab90
// FUNCTION: ROBLOX 0x005825b0
bool ServiceProvider::askAddChild(const Instance* instance) const
{
	return dynamic_cast<const Service*>(instance) != NULL;
}

} // namespace RBX
