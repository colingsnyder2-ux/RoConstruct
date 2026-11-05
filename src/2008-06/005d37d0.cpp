// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_797e59479ecaa6a1.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/connection.hpp>
#include <boost/signals/slot.hpp>

namespace RBX
{
	class Instance;
	class SignalSource { public: virtual ~SignalSource(); void* signals; };
	template<class CallbackSignature> class SignalDesc
	{
	public:
		boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature> >& slot, int position);
	};
	class PartInstance { public: static SignalDesc<void(boost::shared_ptr<Instance>)> event_Touched; };
	class ServiceProvider
	{
	public:
		template<class Class> Class* create() const;
		template<class Class> Class* find() const;
		template<class Class> static Class* create(const ServiceProvider* serviceProvider)
		{
			if (serviceProvider)
				return serviceProvider->create<Class>();
			return NULL;
		}
		template<class Class> static Class* find(const ServiceProvider* serviceProvider)
		{
			if (serviceProvider)
				return serviceProvider->find<Class>();
			return NULL;
		}
	};
	class SpawnLocation;
	class SpawnerService
	{
	public:
		char layout[0x130];
		std::list<SpawnLocation*> spawners;
		void RegisterSpawner(SpawnLocation* spawner) { spawners.push_back(spawner); }
		void UnregisterSpawner(SpawnLocation* spawner) { spawners.remove(spawner); }
	};
	class InstanceHead { public: virtual ~InstanceHead(); char layout[0x10]; };
	class __declspec(novtable) ISelectable { public: virtual void select(); };
	class SpawnLocation : public InstanceHead, public SignalSource, public virtual ISelectable
	{
	public:
		char layout[0x3ec - 0x20];
		boost::signals::scoped_connection spawnerTouched;
		void onEvent_spawnerTouched(boost::shared_ptr<Instance>);
		void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};

	void SpawnLocation::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			spawnerTouched = PartInstance::event_Touched.connect(this, boost::bind(&SpawnLocation::onEvent_spawnerTouched, this, _1), 10);
			SpawnerService* spawnerService = ServiceProvider::create<SpawnerService>(newProvider);
			spawnerService->RegisterSpawner(this);
		}
		if (!newProvider)
		{
			spawnerTouched.disconnect();
			SpawnerService* spawnerService = ServiceProvider::find<SpawnerService>(oldProvider);
			spawnerService->UnregisterSpawner(this);
		}
	}
}
