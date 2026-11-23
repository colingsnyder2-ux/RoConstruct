// =============================================================================
// ScriptMouseCommand.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/ScriptMouseCommand.h
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

namespace RBX
{
	class Mouse;

	class ScriptMouseCommand : public MouseCommand
	{
	private:
		boost::shared_ptr<Mouse> mouse;

	public:
		ScriptMouseCommand(Workspace* workspace);
		virtual ~ScriptMouseCommand();

		boost::shared_ptr<Mouse> getMouse()
		{
			return mouse;
		}

		virtual TextureId getCursorId() const;
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseHover(const UIEvent& uiEvent);
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
		virtual MouseCommand* onPeekKeyDown(const UIEvent& uiEvent);
		virtual const Name& getName() const;
	};
}
