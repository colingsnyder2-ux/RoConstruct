// =============================================================================
// dragutilities.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/tool/dragutilities.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"

namespace RBX
{
	void DragUtilities::moveAndClean(PartInstance* part, const G3D::Vector3& pos)
	{
		G3D::CoordinateFrame frame = part->getCoordinateFrame();
		frame.translation += pos;
		if (part->aligned())
		{
			frame = Math::snapToGrid(frame, 0.1f);
		}
		part->setCoordinateFrame(frame);
	}
}

#include "v8datamodel/Workspace.h"

namespace RBX
{
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

namespace RBX
{
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
