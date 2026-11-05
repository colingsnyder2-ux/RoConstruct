#include "tool/PartDragTool.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
	MouseCommand* PartDragTool::onMouseDown(const UIEvent& uiEvent)
	{
		downPoint = uiEvent.mousePosition;
		capture();

		return this;
	}

	void PartDragTool::onMouseIdle(const UIEvent& uiEvent)
	{

		if (captured() && dragging && megaDragger->mousePartAlive())
		{
			megaDragger->continueDragging();
			runDragger->snap(getUnitMouseRay(uiEvent));
		}
	}

	void PartDragTool::onMouseDelta(const UIEvent& uiEvent)
	{

		if (!dragging && megaDragger->mousePartAlive())
		{
			dragging = true;

			megaDragger->startDragging();
			runDragger->init(workspace, megaDragger->getMousePart(), hitWorld);
		}

		onMouseIdle(uiEvent);
	}


void PartDragTool::onMouseMove(const UIEvent& event) {
    if ((G3D::Vector2(event.mousePosition) - downPoint).length() > 4.0f) onMouseDelta(event);
    else onMouseIdle(event);
}

	MouseCommand* PartDragTool::onKeyDown(const UIEvent& uiEvent)
	{
		if (megaDragger->mousePartAlive())
		{
			if (dragging)
			{
				switch (uiEvent.key)
				{
				case SDLK_r:
					runDragger->rotatePart(megaDragger->getMousePart().lock().get());
					break;
				case SDLK_t:
					runDragger->tiltPart(megaDragger->getMousePart().lock().get(), workspace->getCamera()->getCameraCoordinateFrame());
					break;
				}
			}

			return this;
		}
		else
		{
			return NULL;
		}
	}

	void PartDragTool::render3dAdorn(Adorn* adorn)
	{
		if (megaDragger->mousePartAlive())
			megaDragger->getMousePart().lock()->render3dSelect(adorn, SELECT_NORMAL);
	}
MouseCommand* PartDragTool::onMouseUp(const UIEvent& event) {
    if (dragging) {
        if (megaDragger->mousePartAlive()) runDragger->snap(getUnitMouseRay(event));
        megaDragger->finishDragging();
        dragging = false;
        recordCameraHistory(getName().c_str(), workspace);
    } else if (dragDecal) {
        ServiceClient<Selection> selection(workspace);
        selection->clearSelection();
        Selection* selected = selection.operator->();
        selected->addToSelection(dragDecal.get());
    }
    releaseCapture();
    return NULL;
}

}
