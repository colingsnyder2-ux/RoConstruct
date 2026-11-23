#pragma once
// 2008-06 native RBX::SpawnerService (inactive). Shape after the donor tools/rbxgs SpawnLocation.h; every base,
// field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 0083bd2c .?AVSpawnerService@RBX@@ -> DescribedCreatable<SpawnerService, Instance, sSpawnerService>
//              (name mangled $1?sSpawnerService@2@3QBDB, a const char array in .rdata at 0083ba38) and the empty
//              Service at mdisp 0x130.
//   size       0x14c: Creatable<Instance>::create<SpawnerService> 0048f220 allocates 0x14c and calls 005d30c0.
//   spawners   std::list<SpawnLocation*> at +0x130 (shares the offset with the empty Service base): the
//              constructor 005d30c0 builds it with the list ctor 0061a200, the destructor 005d2410 tidies it
//              (0x682b40) and frees its aux block; SpawnLocation::onServiceProvider 005d37d0 inlines push_back
//              (head +0x144) and calls list::remove 0062c0c0.
//   vtable     no Instance virtual is overridden; the destructor 005d2410 resets every vtable, so it is
//              user-declared (deleting 005d2510).
//   ctor       005d30c0: setName("SpawnerService") then Instance::propArchivable.setValue(this, false) through
//              GetSet vtable slot 3 (pending: see native-classes/SpawnLocation.cpp).
//   SpawnPlayer 005d2b80 (1084 bytes, thiscall, ret 0xc = shared_ptr<ModelInstance> by value + Player*): string
//              0083bda0 "SpawnPlayer couldn't get the workspace" (the name is the donor openrbx SpawnLocation.cpp
//              SpawnerService::SpawnPlayer); the only caller is Player::loadCharacter 004957a0 after
//              find<SpawnerService> 00491ea0. Reads spawners size (+0x148), SpawnLocation::neutral +0x400, teamColor
//              +0x3e8 (getTeamColor 005d1ba0 inlined: same original unit 005d1ba0..005d39f0), duration +0x404.
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
		// 005d2320 (registry placeholder func_005d2320; out of line, only caller DataModel 00578ef0 at 00578f43 after
		// find<SpawnerService> 00490c30): spawners.clear() inline (head +0x144, size +0x148). INFERRED name (no symbol, donor
		// or openrbx declaration); body native-classes/SpawnerServiceClear.cpp.
		void ClearSpawners();                          // 005d2320
	};
}
