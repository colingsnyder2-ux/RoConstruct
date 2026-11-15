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
void Explosion::signalBlast(const G3D::Array<Primitive*>& primitives)
{
	if (!signal_Hit.empty(this)) {
		for (int i = 0; i < primitives.size(); i++) {
			Primitive* primitive = primitives[i];

			if (primitive->getRadius() < blastMaxObjectRadius()) {
				PartInstance* part = PartInstance::fromPrimitive(primitive);

				if (part) {
					G3D::Vector3 delta = primitive->getCoordinateFrame().translation - position;
					signal_Hit.fire(this, shared_from<Instance>(part), delta.magnitude());
				}
			}
		}
	}
}
} // namespace RBX
