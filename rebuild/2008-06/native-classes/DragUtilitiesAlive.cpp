// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities::anyPartAlive (2008-06 DragUtilities unit, between hitObjectOrPlane and partsToPrimitives 0060eb30).
// Identity: work/2008-06/identity-registry.json decorated signature; callers MegaDragger 0060dd74 / 0060e7d7.
// Callees: weak_ptr<Instance>::lock 005cab00 (folded), PartInstance::nonNullInWorkspace 005995f0 (shared_ptr by value).
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060ead0 ?anyPartAlive@DragUtilities@RBX@@SA_NABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@Z
	bool DragUtilities::anyPartAlive(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		for (size_t i = 0; i < parts.size(); i++)
		{
			if (PartInstance::nonNullInWorkspace(parts[i].lock()))
				return true;
		}
		return false;
	}
}
