#include "v8datamodel/SpawnLocation.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "v8datamodel/DebrisService.h"
// PORT: omitted unavailable ForceField include; probed methods do not use it.
#include "v8datamodel/Workspace.h"

#include <boost/bind.hpp>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

namespace RBX {

// PORT: selective donor method; remaining bodies use the 2008 object.
void SpawnLocation::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	if (oldProvider == NULL) {
		spawnerTouched = PartInstance::event_Touched.connect(
			this, boost::bind(&SpawnLocation::onEvent_spawnerTouched, this, _1), 10
		);

		SpawnerService* spawnerService = newProvider ? newProvider->create<SpawnerService>() : NULL;
		spawnerService->RegisterSpawner(this);
	}

	if (newProvider == NULL) {
		spawnerTouched.disconnect();

		SpawnerService* spawnerService = oldProvider ? oldProvider->find<SpawnerService>() : NULL;
		spawnerService->UnregisterSpawner(this);
	}
}
} // namespace RBX
