// =============================================================================
// ToolMouseCommand.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/ToolMouseCommand.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8datamodel/ScriptMouseCommand.h"
#include "util/Name.h"

namespace RBX
{
	extern const char sToolMouseCommand[];

	class Tool;

	class ToolMouseCommand : public Named<ScriptMouseCommand, sToolMouseCommand>
	{
	private:
		boost::shared_ptr<Tool> tool;

	private:
		void updateTargetPoint(const UIEvent& uiEvent);
	public:
		ToolMouseCommand(Workspace* workspace, Tool* tool);
		virtual ~ToolMouseCommand();
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseHover(const UIEvent& uiEvent);
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
	public:
		MouseCommand* sub_0064dee0(const UIEvent& uiEvent);   // INFERRED: 0064dee0, placeholder name (identity tier), body byte-proved (Inferred_0064dee0.cpp)
	public:
		MouseCommand* sub_0064df30(const UIEvent& uiEvent);   // INFERRED: 0064df30, placeholder name (identity tier), body byte-proved (Inferred_0064df30.cpp)
	};
}
