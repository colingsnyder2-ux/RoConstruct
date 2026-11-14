// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// MegaDragger drag/move methods (2008-06). Identities from work/2008-06/identity-registry.json
// (decorated-signature + identity-closure votes); callees: DragUtilities 0060eb30/0060ead0/0060f2d0,
// Dragger::safeMoveYDrop 00610830, Dragger::safeMoveNoDrop 00610930, MouseCommand::getUnitMouseRay 00615c30,
// ICameraOwner::setCameraIgnoreParts 00641f40, RootInstance::setInsertPoint 00590030.
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX
{
	// 0060de00
	void MegaDragger::startDragging()
	{
		DragUtilities::unJoinAndSetDragging(dragParts);

		if (PartInstance::nonNullInWorkspace(mousePart.lock()))
		{
			rootInstance->setCameraIgnoreParts(mousePart.lock().get());
		}
		joined = false;
	}

	// 0060dd60
	void MegaDragger::continueDragging()
	{
		DragUtilities::unJoinAndSetDragging(dragParts);
	}

	// 0060e780
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

	// 0060dec0
	G3D::Vector3 MegaDragger::hitObjectOrPlane(const UIEvent& uiEvent)
	{
		G3D::Vector3 result;
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);
		DragUtilities::hitObjectOrPlane(contactManager, MouseCommand::getUnitMouseRay(uiEvent, rootInstance), &primitives, result);
		return result;
	}

	// 0060df80
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

	// 0060e100
	G3D::Vector3 MegaDragger::safeMoveYDrop(const G3D::Vector3& tryDrag)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		G3D::Vector3 result = Dragger::safeMoveYDrop(primitives, tryDrag, contactManager);
		return result;
	}

	// 0060e180
	G3D::Vector3 MegaDragger::safeMoveNoDrop(const G3D::Vector3& tryDrag)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		G3D::Vector3 result = Dragger::safeMoveNoDrop(primitives, tryDrag, contactManager);
		return result;
	}

	// 0060e310
	void MegaDragger::safeRotate(const G3D::Matrix3& rotMatrix)
	{
		G3D::Array<Primitive*> primitives;
		DragUtilities::partsToPrimitives(dragParts, primitives);

		Dragger::safeRotate(primitives, rotMatrix, contactManager);
	}
}
