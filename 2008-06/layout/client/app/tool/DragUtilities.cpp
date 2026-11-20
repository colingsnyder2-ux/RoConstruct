// INFERRED: sub_0060ec60 (placeholder name for 0060ec60 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <vector>
#include <boost/weak_ptr.hpp>
#include <G3D/Array.h>
#include <v8world/World.h>
#include <v8world/Primitive.h>
#include <tool/DragUtilities.h>
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

void __cdecl sub_0060ec60(const std::vector<boost::weak_ptr<PartInstance> >& parts)
{
	G3D::Array<Primitive*> prims;
	World* world = DragUtilities::partsToPrimitives(parts, prims);
	if (world)
		world->destroyJointsToWorld(prims);
}

}

// INFERRED: sub_0060ecd0 (placeholder name for 0060ecd0 from the identity tier; body byte-proved against the native headers by the placeholder lane)

namespace RBX {

void __cdecl sub_0060ecd0(const std::vector<boost::weak_ptr<PartInstance> >& parts)
{
	G3D::Array<Primitive*> prims;
	World* world = DragUtilities::partsToPrimitives(parts, prims);
	if (world)
		world->destroyJointsToWorld(prims);
}

}
