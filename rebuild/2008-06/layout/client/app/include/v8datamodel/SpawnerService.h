#pragma once
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <list>

struct NativeSpawnLayout;

namespace RBX
{
	class ModelInstance;
	namespace Network
	{
		class Player;
	}
}

namespace RBX
{
	class SpawnLocation;

	extern const char sSpawnerService[];

	class SpawnerService : public DescribedCreatable<SpawnerService, Instance, sSpawnerService>,
						   public Service
	{
		friend struct ::NativeSpawnLayout; // tests/NativeSpawnLayout.cpp offset asserts

	private:
		std::list<SpawnLocation*> spawners;  // +0x130

	public:
		SpawnerService();                    // 005d30c0
		virtual ~SpawnerService();           // 005d2410 (deleting 005d2510)

		void SpawnPlayer(boost::shared_ptr<ModelInstance> model, Network::Player* p); // 005d2b80

		void RegisterSpawner(SpawnLocation* spawner)   // inlined into SpawnLocation::onServiceProvider 005d37d0
		{
			spawners.push_back(spawner);
		}
		void UnregisterSpawner(SpawnLocation* spawner) // inlined; calls list::remove 0062c0c0
		{
			spawners.remove(spawner);
		}
	};
}
