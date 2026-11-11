// Inactive native recovery of the RBX::NullTool / RBX::NewNullTool unit 00617da0..00618377 (2008-06) in the application
// range 00610000..0061c000, against the committed native tool/NullTool.h and v8datamodel/MouseCommand.h (read-only).
// Layout evidence: NewNullTool::isSticky 00618277 news 0x48 before the constructor 00618160; NullTool::isSticky
// 00618218 news 0x1c and inlines NullTool(Workspace*) (MouseCommand base 0x1c, MouseCommand(Workspace*) 006159f0).
// NewNullTool(): cursor std::string +0x1c ("ArrowCursor"), hasWaypoint +0x38, waypoint +0x3c..+0x44 (zeroed).
// RTTI .?AVNullTool@RBX@@ vtable 00843bd4 (IRenderable base vtable 00843bbc at +4), .?AVNewNullTool@RBX@@ vtable
// 00843c44 (IRenderable 00843c28 at +4). Named<MouseCommand, sNewNullTool>::getName 006182e0 call_once's the thunk
// 006181f0 of the function-local Name declare 006180a0 (sNewNullTool 0095ab08); Named<MouseCommand, sNullTool>::getName
// 006182c0 reaches NativeToolName<NullTool> in the StandardVerbs unit (005c6210 / 005c5ec0).
// The helper names (isLocalHeadHidden, queryClickDetectors, NativeToolName) are codegen analogs.
// See tests/record_native_app_unit610_2008.py.
// >>> native-status (generated) -- do not edit >>>
// AppUnit610_2008NullTool | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e324add6 | roc native-status --write
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

	// 00629b20: cdecl ClickDetector query (ClickDetector unit); its C++ symbol is unproven (same local declaration as
	// native-classes/NewNullTool.cpp).
	bool queryClickDetectors(PartInstance*, float, bool);

	void NewNullTool::onMouseIdle(const UIEvent& event)
	{
		PartInstance* part = getUnlockedPartByLocalCharacter(event, waypoint);
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
		PartInstance* part = getUnlockedPartByLocalCharacter(event, waypoint);
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
		PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
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
