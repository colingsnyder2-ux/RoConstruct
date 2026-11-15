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

// PORT: isolated donor method; 2008 header has no forcefieldDuration field.
SpawnerService::SpawnerService()
{
	setName(sSpawnerService);
	propArchivable.setValue(this, false);
}
} // namespace RBX
