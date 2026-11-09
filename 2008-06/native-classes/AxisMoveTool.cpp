// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// Unsplit: combined from AxisMoveToolCore/Bounds/Down/Move/Render/Methods (mew 5fe2214 layout unsplit for native-doc).
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"
#include "v8datamodel/Selection.h"
#include "tool/Dragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/Extents.h"
#include "util/Math.h"
#include "AppDraw/DrawAdorn.h"
#include <algorithm>

namespace RBX {

char sAxisMoveTool[] = "AxisMove";

bool hitMoveHandles(const Extents&, const G3D::Ray&, G3D::Vector3&, NormalId&);
void recordCameraHistory(const char*, const Instance*);

AxisMoveTool::AxisMoveTool(Workspace* w)
	: Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}

template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
	return new AxisMoveTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const {
	return NativeToolName<AxisMoveTool>::get();
}

void __cdecl collectPart(boost::shared_ptr<Instance> value, std::vector<Primitive*>* parts) {
	DragUtilities::getPrimitives(value.get(), *parts);
}
struct AxisBoundsCallback {
	void (__cdecl* function)(boost::shared_ptr<Instance>, std::vector<Primitive*>*);
	std::vector<Primitive*>* parts;
	AxisBoundsCallback(void (__cdecl* f)(boost::shared_ptr<Instance>, std::vector<Primitive*>*), std::vector<Primitive*>* p)
		: function(f), parts(p) {}
	void operator()(const boost::shared_ptr<Instance>& p) { function(p, parts); }
};
bool AxisMoveTool::bounds(Extents& out) {
	ServiceClient<Selection> selection(workspace);
	std::vector<Primitive*> parts;
	std::for_each(selection->selection->begin(), selection->selection->end(), AxisBoundsCallback(collectPart, &parts));
	if (parts.size() > 0) { out = Dragger::computeExtents(parts); return true; }
	return false;
}

bool AxisMoveTool::hitHandle(const UIEvent& event, G3D::Vector3& point, NormalId& face) {
	Extents box;
	if (bounds(box)) {
		if (hitMoveHandles(box, getUnitMouseRay(event), point, face)) return true;
	}
	return false;
}
MouseCommand* AxisMoveTool::onMouseDown(const UIEvent& event) {
	G3D::Vector3 point;
	NormalId face;
	if (hitHandle(event, point, face)) {
		mouseDownView = event.mousePosition;
		axis = face % 3;
		dragPoint = Math::toGrid(point, axisMoveGrid());
		dragRay = G3D::Ray::fromOriginAndDirection(dragPoint, normalIdToVector3(face));
		capture();
		return this;
	}
	return ArrowToolBase::onMouseDown(event);
}

void AxisMoveTool::onMouseMove(const UIEvent& event) {
	if (!dragging && (G3D::Vector2(event.mousePosition) - G3D::Vector2(mouseDownView)).length() > 4.0f) {
		ServiceClient<FilteredSelection<PVInstance> > selection(workspace);
		megaDragger.reset(new MegaDragger(0, selection->items(), workspace));
		megaDragger->startDragging(); megaDragger->alignAndCleanParts(); dragging = true;
	}
	if (dragging && megaDragger->anyDragPartAlive()) {
		G3D::Vector3 hit = Math::closestPointOnRay(dragRay, getUnitMouseRay(event));
		hit = Math::toGrid(hit, axisMoveGrid());
		G3D::Vector3 delta = Math::toGrid(hit - dragPoint, axisMoveGrid());
		if (delta != G3D::Vector3::zero()) {
			megaDragger->continueDragging();
			G3D::Vector3 moved = megaDragger->safeMoveAlongLine(delta);
			if (moved != G3D::Vector3::zero()) dragPoint = Math::toGrid(dragPoint + moved, axisMoveGrid());
		}
	}
}

void AxisMoveTool::render2d(Adorn* adorn) {
	Extents box;
	if (bounds(box)) {
		G3D::CoordinateFrame frame(box.center());
		G3D::Vector3 size = box.size();
		DrawAdorn::handles2d(size, frame, workspace->getGCamera(), adorn, G3D::Color3::orange());
	}
}
void AxisMoveTool::render3dAdorn(Adorn* adorn) {
	Extents box;
	if (bounds(box)) {
		G3D::CoordinateFrame frame(box.center());
		G3D::Vector3 size = box.size();
		DrawAdorn::handles3d(size, frame, adorn, HANDLE_MOVE,
			workspace->getGCamera().getCoordinateFrame().translation);
	}
}

MouseCommand* AxisMoveTool::isSticky() const { return new AxisMoveTool(workspace); }
MouseCommand* AxisMoveTool::onMouseUp(const UIEvent&) {
	if (dragging) {
		megaDragger->finishDragging();
		megaDragger.release();
		dragging = false;
		recordCameraHistory(getName().c_str(), workspace);
	}
	releaseCapture();
	return NULL;
}
void AxisMoveTool::onMouseIdle(const UIEvent& event) {
	ArrowToolBase::onMouseIdle(event);
	if (captured()) cursor = "DragCursor";
	else {
		G3D::Vector3 point;
		NormalId face;
		if (hitHandle(event, point, face)) cursor = "ResizeCursor";
		else cursor = ArrowToolBase::getCursorName();
	}
}

}