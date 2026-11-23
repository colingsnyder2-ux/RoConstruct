// =============================================================================
// PartDragTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/PartDragTool.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8datamodel/MouseCommand.h"
#include "util/Name.h"

namespace RBX
{
	class RunDragger;
	class MegaDragger;

	extern char sPartDragTool[];

	class PartDragTool : public Named<MouseCommand, sPartDragTool>
	{
	private:
		std::auto_ptr<RunDragger> runDragger;
		std::auto_ptr<MegaDragger> megaDragger;
		boost::shared_ptr<Instance> dragDecal;
		G3D::Vector2 downPoint;
		bool dragging;
		G3D::Vector3 hitWorld;

	public:
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual void onMouseMove(const UIEvent&);
		virtual void onMouseDelta(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
		virtual MouseCommand* onKeyDown(const UIEvent& uiEvent);
		virtual void render3dAdorn(Adorn* adorn);

		virtual const std::string getCursorName() const
		{
			return dragging ? "GrabRotateCursor" : "DragCursor";
		}

		PartDragTool(PartInstance* mousePart, const G3D::Vector3& hitPointWorld, Workspace* workspace, boost::shared_ptr<Instance> decal);
		virtual ~PartDragTool();
	};
}
