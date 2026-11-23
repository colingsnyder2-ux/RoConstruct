// =============================================================================
// SpawnerService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/SpawnerService.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
