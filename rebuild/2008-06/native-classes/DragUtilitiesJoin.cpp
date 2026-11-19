// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// RBX::DragUtilities part-array helpers (2008-06 DragUtilities unit, after MegaDragger 0060dd60..0060e8ff).
// Identities from work/2008-06/identity-registry.json (decorated-signature votes); bodies after the donor
// tools/rbxgs tool/DragUtilities.cpp (join) and the target bytes (partsToPrimitives has no donor body).
// Callees: weak_ptr<Instance>::lock 005cab00 (folded), PartInstance::nonNullInWorkspace 005995f0,
// PartInstance::join 00598c90, G3D::Array<const void*>::append 0059a190 (folded), Workspace::getMyWorldFast 005a0560.
#include "tool/DragUtilities.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0060eb30 ?partsToPrimitives@DragUtilities@RBX@@SAPAVWorld@2@ABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@AAV?$Array@PAVPrimitive@RBX@@@G3D@@@Z
	World* DragUtilities::partsToPrimitives(const std::vector<boost::weak_ptr<PartInstance> >& parts, G3D::Array<Primitive*>& primitives)
	{
		World* answer = NULL;

		for (size_t i = 0; i < parts.size(); i++)
		{
			boost::shared_ptr<PartInstance> part = parts[i].lock();
			if (PartInstance::nonNullInWorkspace(part))
			{
				primitives.append(part->getPrimitive());
				if (!answer)
					answer = Workspace::getMyWorldFast(part.get());
			}
		}

		return answer;
	}

	// 0060ed40 ?join@DragUtilities@RBX@@SAXABV?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@...@Z
	void DragUtilities::join(const std::vector<boost::weak_ptr<PartInstance> >& parts)
	{
		for (size_t i = 0; i < parts.size(); i++)
		{
			boost::shared_ptr<PartInstance> part = parts[i].lock();
			if (PartInstance::nonNullInWorkspace(part))
				part->join();
		}
	}
}
