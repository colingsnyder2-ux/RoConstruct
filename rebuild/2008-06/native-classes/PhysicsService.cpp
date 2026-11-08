// 2008-06 native RBX::PhysicsService (inactive); evidence in native-headers/v8datamodel/PhysicsService.h.
// Verified by tests/record_native_services.py. The onEvent bodies need the AssemblyPhysicsOn/Off definitions
// (World.h proposal): they compile only under NATIVE_PHYSICSSERVICE_PENDING against a generated World.h copy.
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/signal.h"
#include "v8tree/Service.h"
#include <boost/thread/once.hpp>

namespace RBX
{
	const char sPhysicsService[] = "PhysicsService"; // 0083f858

	// Template members the shared headers only declare.
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	// Dynamic initializers 007f6e40, 007f6e60 (atexit 007ffa50 / 007ffa10 region).
	static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> event_AssemblyAdded("AssemblyAdded", "part");
	static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> event_AssemblyRemoved("AssemblyRemoved", "part");

	PhysicsService::PhysicsService()
	{
		setName("PhysicsService");
	}

	PhysicsService::~PhysicsService()
	{
	}

	void PhysicsService::onAdded(PartInstance* part)
	{
		event_AssemblyAdded.fire(this, shared_from(part));
		// The named result keeps the original 0x18-byte frame (a discarded insert result uses 0x10).
		std::pair<std::set<PartInstance*>::iterator, bool> result = parts.insert(part);
	}

	void PhysicsService::onRemoved(PartInstance* part)
	{
		parts.erase(part);
		event_AssemblyRemoved.fire(this, shared_from(part));
	}

#ifdef NATIVE_PHYSICSSERVICE_PENDING
	void PhysicsService::onEvent(const World* source, AssemblyPhysicsOn event)
	{
		onAdded(PartInstance::fromPrimitive(event.primitive));
	}

	void PhysicsService::onEvent(const World* source, AssemblyPhysicsOff event)
	{
		onRemoved(PartInstance::fromPrimitive(event.primitive));
	}
#endif

	// ServiceProvider find support (unsplit from PhysicsServiceFind; pattern adapted)
	template<class Class> size_t ServiceProvider::doGetClassIndex() {
		static size_t index = newIndex();
		return index;
	}
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex() {
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}
	template<> PhysicsService* ServiceProvider::find<PhysicsService>() const {
		size_t index = getClassIndex<PhysicsService>();
		if (index + 1 > serviceArray.size()) {
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
		} else {
			PhysicsService* service = static_cast<PhysicsService*>(serviceArray[index].get());
			if (service) return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(PhysicsService::className());
		if (!item) return NULL;
		serviceArray[index] = item;
		return static_cast<PhysicsService*>(item.get());
	}
}
