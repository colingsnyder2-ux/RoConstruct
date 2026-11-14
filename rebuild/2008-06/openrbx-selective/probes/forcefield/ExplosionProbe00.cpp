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
void Explosion::render3dAdorn(Adorn* adorn)
{
	adorn->setObjectToWorldMatrix(CoordinateFrame(position));
	G3D::Sphere sphere(G3D::Vector3::zero(), blastRadius);

	adorn->explosion(sphere, G3D::Color4(G3D::Color3::red()), G3D::Color4::clear());
}
} // namespace RBX
