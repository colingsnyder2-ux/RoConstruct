// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_06906e269c7d4d71.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/ICharacterSubject.h","roc_unit_2a20899c3d3be979.cpp")
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8datamodel/PartInstance.h","roc_unit_ea83e629b1338927.cpp")
#include "humanoid/Humanoid.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
ModelInstance* Humanoid::getCharacterFromHumanoid(Humanoid* humanoid)
	{
		if (humanoid)
		{
			if (ModelInstance* character = dynamic_cast<ModelInstance*>(humanoid->getParent()))
				return character;
		}

		return NULL;
	}
static void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(descendent.get()))
		{
			primitives.push_back(part->getPrimitive());
		}
	}
void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
	{
		if (ModelInstance* character = getCharacterFromHumanoid(this))
			character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref((std::vector<Primitive*>&)ignore)));
	}
}
