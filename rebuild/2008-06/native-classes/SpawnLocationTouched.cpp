// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/boost-function-pod-vtable
// 2008-06 native RBX::SpawnLocation touch/registration members of the original SpawnLocation unit 005d1ba0..005d39f0
// (the rest is native-classes/SpawnLocation.cpp). Flags copied from SpawnLocation.cpp.
// native-headers/v8datamodel/SpawnLocation.h declares the private slot member onEvent_spawnerTouched (005d1ec0, openrbx
// SpawnLocation.h) since batch 46, so the /I{headers}/spawn-touched overlay is no longer used here (the overlay folder is
// left for its owner to retire). Proposal: move both bodies into SpawnLocation.cpp, their original unit (getTeamColor
// 005d1ba0 is then inlined through the accessor as in the original).
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include <boost/bind.hpp>

namespace RBX
{
	// 005d1ec0 (placeholder func_005d1ec0): allowTeamChangeOnTouch +0x401, parent +0x104, Humanoid::modelIsCharacter
	// 005d9a20, Players::getPlayerFromCharacter 0049acd0, Player::setTeamColor 00494600 with teamColor +0x3e8 read
	// directly (INFERRED: openrbx calls getTeamColor(), which the original unit inlines; it is out of line here),
	// Player::setNeutral 00494620 (neutral +0x400). openrbx SpawnLocation::onEvent_spawnerTouched.
	// NEAR MISS (190 B vs 222 B): identical instruction stream except that the original keeps a separate partial copy
	// of the shared_ptr parameter release on the early-return path (laid out first, tail-merged at its lock xadd) where
	// this build merges both exits. Rejected (batch 42): early return + combined test; nested if with a named Humanoid*;
	// positive if wrapping the body with an inner return. Parked.
	void SpawnLocation::onEvent_spawnerTouched(boost::shared_ptr<Instance> other)
	{
		if (!allowTeamChangeOnTouch)
			return;

		Instance* character = other->getParent();
		if (character && Humanoid::modelIsCharacter(character))
		{
			Network::Player* player = Network::Players::getPlayerFromCharacter(character);
			if (player)
			{
				player->setTeamColor(teamColor);
				player->setNeutral(neutral);
			}
		}
	}

	// 005d37d0 (placeholder func_005d37d0, vtable slot 12): the 2008 body makes no base onServiceProvider call.
	// event_Touched 00976164 connect 004a3340 (third argument 10), slot ctor 005d2a60, scoped_connection assign
	// 00595540; create<SpawnerService>() 005d33a0 with RegisterSpawner (list push_back) inlined; find<SpawnerService>()
	// 00490c30 with UnregisterSpawner (list remove 0062c0c0) inlined.
	void SpawnLocation::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider == NULL)
		{
			spawnerTouched = PartInstance::event_Touched.connect(this, boost::bind(&SpawnLocation::onEvent_spawnerTouched, this, _1), 10);

			SpawnerService* spawnerService = newProvider ? newProvider->create<SpawnerService>() : NULL;
			spawnerService->RegisterSpawner(this);
		}

		if (newProvider == NULL)
		{
			spawnerTouched.disconnect();

			SpawnerService* spawnerService = oldProvider ? oldProvider->find<SpawnerService>() : NULL;
			spawnerService->UnregisterSpawner(this);
		}
	}
}
