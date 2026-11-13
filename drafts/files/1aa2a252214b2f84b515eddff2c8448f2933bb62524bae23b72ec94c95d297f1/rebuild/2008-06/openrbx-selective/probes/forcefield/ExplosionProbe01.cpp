#include "v8datamodel/Explosion.h"

#include "rbxgraphics/Adorn.h"
#include "reflection/signal.h"
#include "util/Extents.h"
// PORT: omitted unavailable ForceField include; probed methods do not use it.
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8kernel/Body.h"
#include "v8kernel/Constants.h"
#include "v8world/Primitive.h"
#include "v8world/SpatialHash.h"
#include "v8world/World.h"

#include <G3D/Sphere.h>

namespace RBX {

// PORT: selective donor method; remaining bodies use the 2008 object.
void Explosion::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	stopListening(oldProvider ? oldProvider->find<RunService>() : NULL, this);

	DescribedCreatable<Explosion, Instance, sExplosion>::onServiceProvider(oldProvider, newProvider);

	startListening(newProvider ? newProvider->find<RunService>() : NULL, this);
}
} // namespace RBX
