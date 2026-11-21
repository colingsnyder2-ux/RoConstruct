// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities::joinToOutsiders (2008-06 DragUtilities unit, flags of DragUtilitiesJoin.cpp).
// Identity: the registry gives 0060ecd0 the same decorated name as 0060ec60 (unJoinFromOutsiders), but 0060ecd0 calls
// World 005eae10, which calls World::createJoints(Primitive*, set*) 005ea4d0 (so 005eae10 is createJointsToWorld),
// and its only caller is 0060ef30, the body that clears dragging and zeroes the velocities (joinAndStopDragging,
// which the donor starts with joinToOutsiders). Donor tools/rbxgs tool/DragUtilities.cpp body.
#include "tool/DragUtilities.h"
#include "v8world/World.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060ecd0 ?joinToOutsiders@DragUtilities@RBX@@SAXABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@Z
	void DragUtilities::joinToOutsiders(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		G3D::Array<Primitive*> primitives;
		World* world = partsToPrimitives(parts, primitives);

		if (world)
			world->createJointsToWorld(primitives);
	}
}
