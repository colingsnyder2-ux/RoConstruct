// Inactive native recovery of the RBX::GroupDragTool unit 0066a570..0066aa76 (2008-06) against the committed native
// tool/GroupDragTool.h (read-only). Layout evidence: DragTool::onMouseDown 0066061b news 0x38 for the constructor
// 0066a630; MouseCommand base 0x1c bytes (MouseCommand(Workspace*) 006159f0), megaDragger +0x1c (new 0x2c,
// MegaDragger ctor 0060e630), downPoint +0x20/+0x24, dragging +0x28, lastHit +0x2c..+0x34 (ctor stores); RTTI
// .?AVGroupDragTool@RBX@@ vtable 0084d02c with the IRenderable base vtable 0084d014 at +4.
// Named<MouseCommand, sGroupDragTool>::getName 0066aa60 call_once's a thunk 0066a620 of the function-local Name
// declare 0066a5b0 (sGroupDragTool 00962c54, "GroupDragTool"); the helper names come from StandardVerbs.h
// (codegen analogs). See tests/record_native_app_unit660_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// AppUnit660_2008GroupDragTool | 2008-06 | draft (no current byte proof)
// 0/8 mapped addresses byte-exact | 8 unproved | 2 referenced strings (not rechecked) | by king_originala (+2) (mixed 4)
// <<< native-status | src 539d1b86 | roc native-status --write
#include "tool/GroupDragTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Math.h"
#include "tool/Dragger.h"
#include "StandardVerbs.h"

namespace RBX
{
	// 0058c5c0: commits a ChangeHistoryService waypoint (not declared in a shared header; same local declaration as
	// AxisMoveToolMethods.cpp / CSelectionTreeCtrl.cpp).
	void recordCameraHistory(const char*, const Instance*);

	char sGroupDragTool[] = "GroupDragTool";

	template<> struct NativeToolText<GroupDragTool>
	{
		static const char* get() { return sGroupDragTool; }
	};

	GroupDragTool::GroupDragTool(PartInstance* mousePart, const G3D::Vector3&, const std::vector<boost::weak_ptr<PartInstance> >& partArray, Workspace* workspace)
		: Named<MouseCommand, sGroupDragTool>(workspace),
		  dragging(false)
	{
		megaDragger.reset(new MegaDragger(mousePart, partArray, static_cast<RootInstance*>(workspace)));
	}

	GroupDragTool::~GroupDragTool()
	{
	}

	const std::string GroupDragTool::getCursorName() const
	{
		return dragging ? "GrabRotateCursor" : "DragCursor";
	}

	MouseCommand* GroupDragTool::onKeyDown(const UIEvent& uiEvent)
	{
		if (dragging)
		{
			switch (uiEvent.key)
			{
			case SDLK_r:
				megaDragger->safeRotate(Math::matrixRotateY());
				break;
			case SDLK_t:
				megaDragger->safeRotate(Math::matrixTiltZ());
				break;
			}
			return this;
		}
		return NULL;
	}

	MouseCommand* GroupDragTool::onMouseDown(const UIEvent& uiEvent)
	{
		downPoint = uiEvent.mousePosition;
		capture();
		return this;
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

	MouseCommand* GroupDragTool::onMouseUp(const UIEvent&)
	{
		if (dragging)
		{
			megaDragger->finishDragging();
			dragging = false;
			recordCameraHistory(getName().c_str(), workspace);
		}
		releaseCapture();
		return NULL;
	}

	template<> const Name& Named<MouseCommand, sGroupDragTool>::getName() const
	{
		return NativeToolName<GroupDragTool>::get();
	}
}
