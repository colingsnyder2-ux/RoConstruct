// Layout probe for the inactive native TimerService / SpawnerService / SpawnLocation headers;
// tests/record_native_spawn.py checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(TimerService)   0x158  constructor 005d71b0 (list ctor on +0x13c; onEvent reads head/size +0x150/+0x154)
//   sizeof(SpawnerService) 0x14c  Creatable<Instance>::create<SpawnerService> 0048f220 allocates 0x14c
//   TimerService           runService +0x134, items +0x13c (constructor 005d71b0, onServiceProvider 005d73a0)
//   SpawnerService         spawners +0x130 (constructor 005d30c0, destructor 005d2410)
// Field offsets are compile-time asserts (NativeSpawnLayout is a friend of each class).
// SpawnLocation (0x424, fields +0x3e8..+0x404) is not asserted: the current native PartInstance.h does not have
// the 2008 non-virtual size 0x3e8, so its asserts stay behind NATIVE_SPAWNLOCATION_LAYOUT until it does.
#include <stddef.h>
#include "v8datamodel/TimerService.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/SpawnLocation.h"

struct NativeSpawnLayout
{
	typedef char RunService[offsetof(RBX::TimerService, runService) == 0x134 ? 1 : -1];
	typedef char Items[offsetof(RBX::TimerService, items) == 0x13c ? 1 : -1];
	typedef char Spawners[offsetof(RBX::SpawnerService, spawners) == 0x130 ? 1 : -1];
#ifdef NATIVE_SPAWNLOCATION_LAYOUT
	typedef char TeamColor[offsetof(RBX::SpawnLocation, teamColor) == 0x3e8 ? 1 : -1];
	typedef char SpawnerTouched[offsetof(RBX::SpawnLocation, spawnerTouched) == 0x3ec ? 1 : -1];
	typedef char Neutral[offsetof(RBX::SpawnLocation, neutral) == 0x400 ? 1 : -1];
	typedef char AllowTeamChange[offsetof(RBX::SpawnLocation, allowTeamChangeOnTouch) == 0x401 ? 1 : -1];
	typedef char Duration[offsetof(RBX::SpawnLocation, duration) == 0x404 ? 1 : -1];
#endif
};

size_t nativeTimerServiceSize() { return sizeof(RBX::TimerService); }
size_t nativeSpawnerServiceSize() { return sizeof(RBX::SpawnerService); }
size_t nativeSpawnInstanceSize() { return sizeof(RBX::Instance); }
