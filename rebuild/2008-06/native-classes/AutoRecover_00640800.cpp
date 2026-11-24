// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "v8datamodel/Selection.h"
#include "util/Math.h"

// INFERRED: the original object was built with /fp:fast (inline fsqrt, no float spills).
// The flag line is fixed, so the pragma reproduces fp:fast for this function.
#pragma float_control(precise, off, push)

namespace RBX {

void AxisMoveTool::onMouseMove(const UIEvent& event) {
	if (!dragging && (G3D::Vector2(event.mousePosition) - G3D::Vector2(mouseDownView)).length() > 4.0f) {
		ServiceClient<FilteredSelection<PVInstance> > selection(workspace);
		megaDragger.reset(new MegaDragger(0, selection->items(), workspace));
		megaDragger->startDragging();
		megaDragger->alignAndCleanParts();
		dragging = true;
	}
	if (dragging && megaDragger->anyDragPartAlive()) {
		G3D::Vector3 hit = Math::closestPointOnRay(dragRay, getUnitMouseRay(event));
		hit = Math::toGrid(hit, axisMoveGrid());
		G3D::Vector3 delta = Math::toGrid(hit - dragPoint, axisMoveGrid());
		if (delta != G3D::Vector3::zero()) {
			megaDragger->continueDragging();
			G3D::Vector3 moved = megaDragger->safeMoveAlongLine(delta);
			if (moved != G3D::Vector3::zero())
				dragPoint = Math::toGrid(dragPoint + moved, axisMoveGrid());
		}
	}
}

}

#pragma float_control(pop)
