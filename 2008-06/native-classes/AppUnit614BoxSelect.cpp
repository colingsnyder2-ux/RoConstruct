// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AppUnit614BoxSelect | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 51a852e6 | roc native-status --write
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
namespace RBX {
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

namespace RBX {
void BoxSelectCommand::render2d(Adorn* adorn)
	{
		G3D::Rect2D temp = G3D::Rect2D::xyxy(mouseDownView.x, mouseDownView.y, mouseCurrentView.x, mouseCurrentView.y);
		adorn->outlineRect2d(temp, 0.5f, G3D::Color3::gray());
	}
}

namespace RBX {
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
}

namespace RBX {
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
}

namespace RBX {
BoxSelectCommand::BoxSelectCommand(Workspace* workspace)
		: Base(workspace),
		  selection(workspace)
	{
	}
}
