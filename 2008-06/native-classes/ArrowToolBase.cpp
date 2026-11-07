// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-explicit-shared-assignment
// >>> native-status (generated) -- do not edit >>>
// ArrowToolBase | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 9ac22ea5 | roc native-status --write
#undef _RELEASEASSERT
#include "tool/ToolsArrow.h"
#include "tool/DragTool.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include <G3D/Rect2D.h>

namespace RBX
{
	const std::string ArrowToolBase::getCursorName() const
	{
		return overInstance ? "DragCursor" : "ArrowCursor";
	}

	void ArrowToolBase::onMouseIdle(const UIEvent& uiEvent)
	{
		overInstance = getUnlockedPart(uiEvent) != NULL;
	}

	void ArrowToolBase::onMouseHover(const UIEvent& uiEvent)
	{
		onMouseIdle(uiEvent);
	}

	MouseCommand* ArrowToolBase::onMouseDown(const UIEvent& uiEvent)
	{
		RBXASSERT(uiEvent.eventType == UIEvent::MOUSE_LEFT_BUTTON_DOWN);

		G3D::Vector3 hitWorld;

		PartInstance* part = getUnlockedPart(uiEvent, hitWorld);
		if (part)
		{
			Instance* top = getTopSelectable3d(part);
			UserInputBase* input = uiEvent.userInput;

			ServiceClient<Selection> selection(workspace);

			if (!input->keyDown(SDLK_RSHIFT) && !input->keyDown(SDLK_LSHIFT) &&
				!input->keyDown(SDLK_RCTRL) && !input->keyDown(SDLK_LCTRL))
			{
				boost::shared_ptr<Decal> decal;
				if (selection->isSelected(top))
				{
					decal = shared_from(getDecal(part, uiEvent));
				}
				else
				{
					selection->setSelection(top);
				}
				ServiceClient<FilteredSelection<Instance>> instanceSelection(workspace);
				return DragTool::onMouseDown(part, hitWorld, instanceSelection->items(), uiEvent, workspace, decal);
			}
			else
			{
				if (selection->isSelected(top))
					selection->removeFromSelection(top);
				else
					selection->addToSelection(top);
			}

			return NULL;
		}
		else
		{
			MouseCommand* newCommand = new BoxSelectCommand(workspace);
			return newCommand->onMouseDown(uiEvent);
		}
	}

}
