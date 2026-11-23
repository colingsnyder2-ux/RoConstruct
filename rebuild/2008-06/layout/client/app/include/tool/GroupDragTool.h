// =============================================================================
// GroupDragTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/GroupDragTool.h
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
#include "tool/MegaDragger.h"
#include "util/Name.h"

namespace RBX
{
	extern char sGroupDragTool[];

	class GroupDragTool : public Named<MouseCommand, sGroupDragTool>
	{
	private:
		std::auto_ptr<MegaDragger> megaDragger;
		G3D::Vector2 downPoint;
		bool dragging;
		G3D::Vector3 lastHit;

	public:
		virtual MouseCommand* onKeyDown(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual void onMouseMove(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
		virtual const std::string getCursorName() const;

		GroupDragTool(
			PartInstance* mousePart,
			const G3D::Vector3& hitPointWorld,
			const std::vector<boost::weak_ptr<PartInstance>>& partArray,
			Workspace* workspace);
		virtual ~GroupDragTool();
	};
}
