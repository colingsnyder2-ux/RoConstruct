// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities::unJoinFromOutsiders (2008-06 DragUtilities unit, flags of DragUtilitiesJoin.cpp).
// Identity: registry 0060ec60 ?unJoinFromOutsiders@DragUtilities@RBX@@SAXABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@Z;
// callees partsToPrimitives 0060eb30 and World 005ead30, which calls World::destroyJoints(Primitive*, set*) 005ea3f0
// (so 005ead30 is destroyJointsToWorld); caller DragUtilities::unJoinAndSetDragging. Donor tools/rbxgs
// tool/DragUtilities.cpp body (RBXASSERT compiled out).
#include "tool/DragUtilities.h"
#include "v8world/World.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060ec60
	void DragUtilities::unJoinFromOutsiders(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		G3D::Array<Primitive*> primitives;
		World* world = partsToPrimitives(parts, primitives);

		if (world)
			world->destroyJointsToWorld(primitives);
	}
}
