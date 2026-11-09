// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_8c0f052e407cf60b.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_8560789a45294a3d.cpp")
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
namespace RBX {
const RBX::PartInstance* PartInstance::fromPrimitiveConst(const Primitive* p)
	{
		RBXASSERT(!p || dynamic_cast<PartInstance*>(p->getOwner()));

		if (p)
			return p->getOwner() ? reinterpret_cast<PartInstance*>(reinterpret_cast<char*>(p->getOwner()) - 0x1c0) : NULL;
		else
			return NULL;
	}
PartInstance* PartInstance::fromPrimitive(Primitive* p)
	{
		return const_cast<PartInstance*>(fromPrimitiveConst(p));
	}
void PartInstance::primitivesToParts(const G3D::Array<Primitive*>& primitives, G3D::Array<boost::shared_ptr<PartInstance>>& parts)
	{
		for (int i = 0; i < primitives.size(); i++)
		{
			PartInstance* part = fromPrimitive(primitives[i]);
			parts.push_back(shared_from(part));
		}
	}
}
