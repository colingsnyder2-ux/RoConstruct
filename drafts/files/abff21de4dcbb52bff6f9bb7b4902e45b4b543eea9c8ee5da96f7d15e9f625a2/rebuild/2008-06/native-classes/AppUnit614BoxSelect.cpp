// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-explicit-shared-assignment
// RBX::BoxSelectCommand (2008-06, inactive) against the committed tool/ToolsArrow.h (read-only).
// Evidence: RTTI .?AVBoxSelectCommand@RBX@@ (bases Named<MouseCommand, sBoxSelectCommand 3PADA>, MouseCommand, INamed,
// IRenderable at +4), vtable 00843b6c / IRenderable 00843b50, new(0x54) at ArrowToolBase::onMouseDown 006179f4 before
// the constructor 00617150 (selection +0x1c/+0x20/+0x24, reverseSelecting +0x28, mouseDownView +0x2a, mouseCurrentView
// +0x2e, previousItemsInBox +0x34, 0x20 bytes).
#undef _RELEASEASSERT
#include "tool/ToolsArrow.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PartInstance.h"
#include "util/ILocation.h"
#include "util/ISelectable3d.h"
#include "RbxGraphics/Adorn.h"
#include <G3D/Rect2D.h>
#include <G3D/Color3.h>

namespace RBX
{
	char sBoxSelectCommand[] = "BoxSelect";   // 0095a9b8, passed to Name::declare by doDeclare 006161d0

	template<> const Name& Named<MouseCommand, sBoxSelectCommand>::getName() const
	{
		return Name::declare<sBoxSelectCommand>();
	}

	BoxSelectCommand::BoxSelectCommand(Workspace* workspace)
		: Base(workspace),
		  selection(workspace)
	{
	}

	MouseCommand* BoxSelectCommand::onMouseDown(const UIEvent& uiEvent)
	{
		previousItemsInBox.clear();
		capture();

		UserInputBase* input = uiEvent.userInput;
		reverseSelecting = input->keyDown(SDLK_RSHIFT) || input->keyDown(SDLK_LSHIFT);

		if (!reverseSelecting)
			selection->clearSelection();

		mouseDownView = uiEvent.mousePosition;
		mouseCurrentView = uiEvent.mousePosition;
		return this;
	}

	void BoxSelectCommand::onMouseMove(const UIEvent& uiEvent)
	{
		mouseCurrentView = uiEvent.mousePosition;

		std::set<Instance*> instances;
		getMouseInstances(instances, uiEvent, G3D::Rect2D::xyxy(mouseDownView.x, mouseDownView.y, mouseCurrentView.x, mouseCurrentView.y));

		if (reverseSelecting)
			selectReverse(instances);
		else
			selectAnd(instances);
	}

	void BoxSelectCommand::render2d(Adorn* adorn)
	{
		G3D::Rect2D temp = G3D::Rect2D::xyxy(mouseDownView.x, mouseDownView.y, mouseCurrentView.x, mouseCurrentView.y);
		adorn->outlineRect2d(temp, 0.5f, G3D::Color3::gray());
	}

	void BoxSelectCommand::getMouseInstances(std::set<Instance*>& instances, const UIEvent& uiEvent, G3D::Rect2D& selectBox)
	{
		Camera* camera = workspace->getCamera();
		G3D::Rect2D viewport = G3D::Rect2D::xyxy(0.0f, 0.0f, uiEvent.windowSize.x, uiEvent.windowSize.y);

		for (size_t i = 0; i < workspace->numChildren(); i++)
		{
			ILocation* location = dynamic_cast<ILocation*>(workspace->getChild(i));
			ISelectable3d* selectable3d = dynamic_cast<ISelectable3d*>(workspace->getChild(i));

			if (location && selectable3d)
			{
				Instance* instance = workspace->getChild(i);
				if (!PartInstance::getLocked(instance))
				{
					G3D::Vector3 gridPos = location->getLocation().translation;
					G3D::Vector3 projection = camera->getGCamera().project(gridPos, viewport);

					if (selectBox.contains(projection.xy()))
						instances.insert(instance);
				}
			}
		}
	}
}
