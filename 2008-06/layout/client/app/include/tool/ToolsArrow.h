// =============================================================================
// ToolsArrow.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/ToolsArrow.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Vector2int16.h>
#include <set>
#include "v8datamodel/MouseCommand.h"
#include "v8tree/Service.h"
#include "util/Name.h"

namespace RBX
{
	class Selection;

	class ArrowToolBase : public MouseCommand
	{
	protected:
		bool overInstance;

	protected:
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual void onMouseHover(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual const std::string getCursorName() const;
	public:
		ArrowToolBase(Workspace* workspace)
			: MouseCommand(workspace),
			  overInstance(false)
		{
		}
	};

	extern char sArrowTool[];

	class ArrowTool : public Named<ArrowToolBase, sArrowTool>
	{
	public:
		ArrowTool(Workspace* workspace)
			: Base(workspace)
		{
		}

		virtual MouseCommand* isSticky() const
		{
			return new ArrowTool(workspace);
		}
	};

	extern char sBoxSelectCommand[];

	class BoxSelectCommand : public Named<MouseCommand, sBoxSelectCommand>
	{
	private:
		ServiceClient<Selection> selection;
		bool reverseSelecting;
		G3D::Vector2int16 mouseDownView;
		G3D::Vector2int16 mouseCurrentView;
		std::set<Instance*> previousItemsInBox;

	private:
		void getMouseInstances(std::set<Instance*>& instances, const UIEvent& uiEvent, G3D::Rect2D& selectBox);
		void selectAnd(const std::set<Instance*>&);
		void selectReverse(const std::set<Instance*>&);
	public:
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseMove(const UIEvent& uiEvent);
		virtual void render2d(Adorn* adorn);
		BoxSelectCommand(Workspace* workspace);
	};
}
