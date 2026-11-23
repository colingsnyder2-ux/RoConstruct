// =============================================================================
// NullTool.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/tool/NullTool.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/NullTool.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/UserController.h"
#include "Network/Players.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"
#include "StandardVerbs.h"

namespace RBX
{
	char sNewNullTool[] = "NewNullTool";

	template<> struct NativeToolText<NewNullTool>
	{
		static const char* get() { return sNewNullTool; }
	};

	const std::string NullTool::getCursorName() const
	{
		return "ArrowFarCursor";
	}

	NewNullTool::NewNullTool(Workspace* workspace)
		: Named<MouseCommand, sNewNullTool>(workspace),
		  cursor("ArrowCursor"),
		  hasWaypoint(false)
	{
	}

	NewNullTool::~NewNullTool()
	{
	}

	MouseCommand* NewNullTool::onMouseUp(const UIEvent&)
	{
		releaseCapture();
		return this;
	}

	bool NewNullTool::isLocalHeadHidden() const
	{
		ModelInstance* character = Network::Players::findLocalCharacter(workspace);
		if (character)
		{
			Humanoid* humanoid = Humanoid::modelIsCharacter(character);
			if (humanoid)
			{
				PartInstance* head = humanoid->getHead();
				if (head && head->getAlphaModifier() == 0.0f)
					return true;
			}
		}
		return false;
	}

	bool queryClickDetectors(PartInstance*, float, bool);

	void NewNullTool::onMouseIdle(const UIEvent& event)
	{
		PartInstance* part = getPartByLocalCharacter(event, waypoint); // 00617ece calls 00615f90 getPartByLocalCharacter, not the Unlocked filter
		bool clickable = queryClickDetectors(part, distanceFromCharacter(waypoint), false);
		if (part)
		{
			if (clickable)
			{
				cursor = "DragCursor";
				return;
			}
			if (characterCanReach(waypoint) && !isLocalHeadHidden())
			{
				cursor = "ArrowCursor";
				return;
			}
		}
		cursor = "ArrowFarCursor";
	}

	void NewNullTool::onMouseHover(const UIEvent& event)
	{
		PartInstance* part = getPartByLocalCharacter(event, waypoint); // 00617f5e calls 00615f90
		bool clickable = queryClickDetectors(part, distanceFromCharacter(waypoint), false);
		if (part)
		{
			if (clickable)
			{
				cursor = "DragCursor";
				hasWaypoint = false;
				return;
			}
			if (characterCanReach(waypoint) && !isLocalHeadHidden())
			{
				cursor = "ArrowCursor";
				hasWaypoint = true;
				return;
			}
		}
		cursor = "ArrowFarCursor";
		hasWaypoint = false;
	}

	MouseCommand* NewNullTool::onMouseDown(const UIEvent& event)
	{
		G3D::Vector3 point;
		PartInstance* part = getPartByLocalCharacter(event, point); // 00618011 calls 00615f90
		if (queryClickDetectors(part, distanceFromCharacter(point), true))
			return this;
		if (part && characterCanReach(point) && !isLocalHeadHidden())
		{
			ModelInstance* character = Network::Players::findLocalCharacter(workspace);
			if (character && !character->contains(part))
			{
				if (Humanoid* humanoid = Humanoid::modelIsCharacter(character))
					humanoid->moveTo(point, part);
			}
		}
		return this;
	}

	NullTool::NullTool(Workspace* workspace)
		: Named<MouseCommand, sNullTool>(workspace)
	{
	}

	NullTool::~NullTool()
	{
	}

	MouseCommand* NullTool::isSticky() const
	{
		return new NullTool(workspace);
	}

	MouseCommand* NullTool::onMouseUp(const UIEvent&)
	{
		releaseCapture();
		return this;
	}

	template<> const Name& Named<MouseCommand, sNullTool>::getName() const
	{
		return NativeToolName<NullTool>::get();
	}

	template<> const Name& Named<MouseCommand, sNewNullTool>::getName() const
	{
		return NativeToolName<NewNullTool>::get();
	}

	void NewNullTool::render3dAdorn(Adorn* adorn)
	{
		if (hasWaypoint)
		{
			ControllerService* service = ServiceProvider::find<ControllerService>(workspace);
			if (service)
			{
				MovementKeys keys;
				service->getHardwareDevice()->getMovementKeys(keys);
				if (!keys.any())
					Humanoid::renderWaypoint(adorn, waypoint);
			}
		}
	}
}
