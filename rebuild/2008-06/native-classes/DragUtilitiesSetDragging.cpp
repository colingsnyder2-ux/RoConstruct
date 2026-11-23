// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities::unJoinAndSetDragging 0060ee30 (2008-06 DragUtilities unit, after join 0060ed40; callers
// MegaDragger::startDragging 0060de00 / continueDragging 0060dd60). Declared in tool/DragUtilities.h, defined by no
// other unit; its own unit only because DragUtilitiesJoin.cpp (flags copied from it) is not owned by this batch.
// Statement shape after the 2007 openrbx tool/DragUtilities.cpp. Callees: unJoinFromOutsiders 0060ec60, weak_ptr
// lock 005cab00 (folded), PartInstance::nonNullInWorkspace 005995f0 (shared_ptr by value), setDragging 0059dd20.
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060ee30
	void DragUtilities::unJoinAndSetDragging(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		unJoinFromOutsiders(parts);

		for (unsigned int i = 0; i < parts.size(); i++)
		{
			boost::shared_ptr<PartInstance> part = parts[i].lock();

			if (PartInstance::nonNullInWorkspace(part))
				part->setDragging(true);
		}
	}
}
