// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::SpawnerService member 005d2320 of the original SpawnLocation unit (005d1ba0..005d39f0; the rest is
// native-classes/SpawnLocation.cpp, not assigned to this batch). Flags copied from SpawnLocation.cpp.
#include "v8datamodel/SpawnerService.h"

namespace RBX
{
	// 005d2320 (registry placeholder func_005d2320; thiscall, plain `ret`; only caller 00578f43 in DataModel 00578ef0, after
	// ServiceProvider::find<SpawnerService> 00490c30): std::list<SpawnLocation*>::clear inline on spawners (head +0x144,
	// size +0x148): unlink the head, then operator delete 006a067a of every node. INFERRED name (no symbol, donor or
	// openrbx declaration; named after RegisterSpawner / UnregisterSpawner).
	void SpawnerService::ClearSpawners()
	{
		spawners.clear();
	}
}
