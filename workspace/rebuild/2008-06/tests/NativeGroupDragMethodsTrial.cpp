#include "tool/GroupDragTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Math.h"
#include "tool/Dragger.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* GroupDragTool::onKeyDown(const UIEvent& event) {
    if (dragging) {
        switch (event.key) {
        case SDLK_r: megaDragger->safeRotate(Math::matrixRotateY()); break;
        case SDLK_t: megaDragger->safeRotate(Math::matrixTiltZ()); break;
        }
        return this;
    }
    return NULL;
}
MouseCommand* GroupDragTool::onMouseDown(const UIEvent& event) { downPoint = event.mousePosition; capture(); return this; }
const std::string GroupDragTool::getCursorName() const { return dragging ? "GrabRotateCursor" : "DragCursor"; }
MouseCommand* GroupDragTool::onMouseUp(const UIEvent&) {
    if (dragging) { megaDragger->finishDragging(); dragging = false; recordCameraHistory(getName().c_str(), workspace); }
    releaseCapture(); return NULL;
}
	void GroupDragTool::onMouseIdle(const UIEvent& uiEvent)
	{

		G3D::Vector3 hit;

		if (captured() && dragging && megaDragger->mousePartAlive() &&
			Math::intersectRayPlane(getSearchRay(uiEvent), G3D::Plane(G3D::Vector3::unitY(), G3D::Vector3::zero()), hit))
		{
			hit = megaDragger->hitObjectOrPlane(uiEvent);
			megaDragger->continueDragging();

			G3D::Vector3 hitSnapped = Dragger::toGrid(hit);
			G3D::Vector3 delta = Dragger::toGrid(hitSnapped - lastHit);
			lastHit = hitSnapped;

			megaDragger->safeMoveYDrop(delta);
		}
	}

	void GroupDragTool::onMouseMove(const UIEvent& uiEvent)
	{

		if (!dragging && (G3D::Vector2(uiEvent.mousePosition) - downPoint).length() > 4.0f)
		{
			dragging = true;

			megaDragger->startDragging();
			megaDragger->alignAndCleanParts();
			lastHit = megaDragger->hitObjectOrPlane(uiEvent);
		}

		onMouseIdle(uiEvent);
	}


}
