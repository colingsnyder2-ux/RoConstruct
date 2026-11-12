// 2008-06 native RBX::PhysicsService (inactive); evidence in native-headers/v8datamodel/PhysicsService.h.
// Verified by tests/record_native_services.py. The onEvent bodies need the AssemblyPhysicsOn/Off definitions
// (World.h proposal): they compile only under NATIVE_PHYSICSSERVICE_PENDING against a generated World.h copy.
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "reflection/signal.h"

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

	// 005e8ec0: detach/attach the AssemblyPhysicsOn/Off listeners through the provider's workspace world.
	void PhysicsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
		{
			Workspace* workspace = ServiceProvider::create<Workspace>(oldProvider);
			if (workspace)
			{
				World* world = workspace->getWorld();
				if (world)
				{
					static_cast<Notifier<World, AssemblyPhysicsOn>*>(world)->removeListener(dynamic_cast<Listener<World, AssemblyPhysicsOn>*>(this));
					static_cast<Notifier<World, AssemblyPhysicsOff>*>(world)->removeListener(dynamic_cast<Listener<World, AssemblyPhysicsOff>*>(this));
				}
			}
		}
		if (newProvider)
		{
			Workspace* workspace = ServiceProvider::create<Workspace>(newProvider);
			if (workspace)
			{
				World* world = workspace->getWorld();
				if (world)
				{
					static_cast<Notifier<World, AssemblyPhysicsOn>*>(world)->addListener(dynamic_cast<Listener<World, AssemblyPhysicsOn>*>(this));
					static_cast<Notifier<World, AssemblyPhysicsOff>*>(world)->addListener(dynamic_cast<Listener<World, AssemblyPhysicsOff>*>(this));
				}
			}
		}
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
}
