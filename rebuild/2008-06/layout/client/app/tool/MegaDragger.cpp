#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX
{
	MegaDragger::MegaDragger(PartInstance* mousePartPtr, const std::vector<PVInstance*>& pvInstances, RootInstance* rootInstance)
		: mousePart(shared_from(mousePartPtr)),
		  dragParts(),
		  joined(true),
		  rootInstance(rootInstance),
		  contactManager(rootInstance->getWorld()->getContactManager())
	{
		DragUtilities::pvsToParts(pvInstances, dragParts);
	}

	MegaDragger::MegaDragger(PartInstance* mousePartPtr, const std::vector<boost::weak_ptr<PartInstance> >& partArray, RootInstance* rootInstance)
		: mousePart(shared_from(mousePartPtr)),
		  dragParts(partArray),
		  joined(true),
		  rootInstance(rootInstance),
		  contactManager(rootInstance->getWorld()->getContactManager())
	{
	}

	void MegaDragger::startDragging()
	{
		DragUtilities::unJoinAndSetDragging(dragParts);

		if (PartInstance::nonNullInWorkspace(mousePart.lock()))
		{
			rootInstance->setCameraIgnoreParts(mousePart.lock().get());
		}
		joined = false;
	}

	void MegaDragger::continueDragging()
	{
		DragUtilities::unJoinAndSetDragging(dragParts);
	}

	void MegaDragger::finishDragging()
	{
		rootInstance->clearCameraIgnoreParts();
		DragUtilities::joinAndStopDragging(dragParts);
		if (DragUtilities::anyPartAlive(dragParts))
		{
			rootInstance->setInsertPoint(DragUtilities::computeExtents(dragParts).topCenter());
		}
		joined = true;
	}

	G3D::Vector3 MegaDragger::hitObjectOrPlane(const UIEvent& uiEvent)
	{
		G3D::Vector3 result;
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);
		DragUtilities::hitObjectOrPlane(contactManager, MouseCommand::getUnitMouseRay(uiEvent, rootInstance), &primitives, result);
		return result;
	}

	void MegaDragger::alignAndCleanParts()
	{
		if (PartInstance::nonNullInWorkspace(mousePart.lock()))
		{
			PartInstance* part = mousePart.lock().get();

			if (!part->aligned())
			{
				G3D::CoordinateFrame snap = part->worldSnapLocation();
				G3D::CoordinateFrame snapToGrid = Math::snapToGrid(snap, Dragger::dragSnap());
				DragUtilities::move(dragParts, snap, snapToGrid);
			}
		}
		DragUtilities::clean(dragParts);
	}

	G3D::Vector3 MegaDragger::safeMoveYDrop(const G3D::Vector3& tryDrag)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		G3D::Vector3 result = Dragger::safeMoveYDrop(primitives, tryDrag, contactManager);
		return result;
	}

	G3D::Vector3 MegaDragger::safeMoveNoDrop(const G3D::Vector3& tryDrag)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		G3D::Vector3 result = Dragger::safeMoveNoDrop(primitives, tryDrag, contactManager);
		return result;
	}

	void MegaDragger::safeRotate(const G3D::Matrix3& rotMatrix)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		Dragger::safeRotate(primitives, rotMatrix, contactManager);
	}
}

namespace RBX {
bool MegaDragger::mousePartAlive()
	{
		return PartInstance::nonNullInWorkspace(mousePart.lock());
	}
}

namespace RBX {
bool MegaDragger::anyDragPartAlive() { return DragUtilities::anyPartAlive(dragParts); }
G3D::Vector3 MegaDragger::safeMoveAlongLine(const G3D::Vector3& delta) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    if (primitives.size() > 0) {
        G3D::Vector3 result = Dragger::safeMoveAlongLine(primitives, delta, contactManager);
        return result;
    }
    return G3D::Vector3::zero();
}
}
