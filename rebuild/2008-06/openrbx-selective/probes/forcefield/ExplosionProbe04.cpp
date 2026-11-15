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
void Explosion::onEvent(const RunService* source, Stepped event)
{
	age += event.step;

	if (age > renderTime()) {
		if (blastRadius > 0.0f) {
			G3D::Array<Primitive*> primitives;
			World* world = Workspace::getMyWorldFast(this);

			float radius = blastRadius;
			Extents blastExtents = Extents::fromCenterCorner(position, G3D::Vector3(radius, radius, radius));

			world->getContactManager().getPrimitivesTouchingExtents(blastExtents, NULL, primitives);

			signalBlast(primitives);
			doBlast(primitives);
		}

		setParent(NULL);
	}
}
} // namespace RBX
