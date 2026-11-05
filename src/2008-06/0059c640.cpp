// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_64aa12fe31ddf0b7.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_a8aed7660be8b02c.cpp")
#include "v8datamodel/PartInstance.h"
namespace RBX {
	void PartInstance::findParts(Instance* instance, std::vector<boost::weak_ptr<RBX::PartInstance>>& parts)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
			parts.push_back(shared_from(part));

		for (size_t i = 0; i < instance->numChildren(); i++)
		{
			findParts(instance->getChild(i), parts);
		}
	}
}
