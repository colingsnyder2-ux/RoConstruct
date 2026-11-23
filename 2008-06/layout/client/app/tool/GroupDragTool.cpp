// =============================================================================
// GroupDragTool.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/tool/GroupDragTool.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/GroupDragTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Math.h"
#include "tool/Dragger.h"
#include "StandardVerbs.h"

namespace RBX
{
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
