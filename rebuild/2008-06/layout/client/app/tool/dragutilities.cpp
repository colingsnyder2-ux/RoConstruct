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
