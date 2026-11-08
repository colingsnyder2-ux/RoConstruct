#pragma once
// >>> native-status (generated) -- do not edit >>>
// NullTool | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4f6a3c9f | roc native-status --write
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
