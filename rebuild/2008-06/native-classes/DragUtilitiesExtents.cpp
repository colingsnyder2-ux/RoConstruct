// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities::computeExtents (2008-06 DragUtilities unit, flags of DragUtilitiesJoin.cpp).
// Identity: registry 0060f2d0 ?computeExtents@DragUtilities@RBX@@SA?AVExtents@2@ABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@Z
// (reference votes); callees partsToPrimitives 0060eb30 and Dragger::computeExtents(Array) 00610070; caller
// MegaDragger::finishDragging 0060e780. Donor tools/rbxgs tool/DragUtilities.cpp body.
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060f2d0
	Extents DragUtilities::computeExtents(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		G3D::Array<Primitive*> primitives;

		partsToPrimitives(parts, primitives);
		return Dragger::computeExtents(primitives);
	}
}
