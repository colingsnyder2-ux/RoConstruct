// =============================================================================
// NullTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/NullTool.h
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
	extern char sNewNullTool[];

	class NewNullTool : public Named<MouseCommand, sNewNullTool>
	{
	private:
		std::string cursor;
		bool hasWaypoint;
		G3D::Vector3 waypoint;

	private:
		// Descriptive name; original symbol name unproven.
		bool isLocalHeadHidden() const;
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual void onMouseHover(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);

		virtual const std::string getCursorName() const
		{
			return cursor;
		}

		virtual MouseCommand* isSticky() const
		{
			return new NewNullTool(workspace);
		}

		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);

		virtual bool shouldRender3dAdorn() const
		{
			return true;
		}

		virtual void render3dAdorn(Adorn* adorn);
	public:
		NewNullTool(Workspace* workspace);
		virtual ~NewNullTool();
	};

	extern char sNullTool[];

	// this class is completely unused in RBXGS
	class NullTool : public Named<MouseCommand, sNullTool>
	{
	private:
		virtual const std::string getCursorName() const;
	public:
		NullTool(Workspace*);
		virtual ~NullTool();
		virtual MouseCommand* isSticky() const;
		virtual MouseCommand* onMouseUp(const UIEvent&);
	};
}
