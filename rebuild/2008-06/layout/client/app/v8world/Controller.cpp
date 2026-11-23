// =============================================================================
// Controller.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/Controller.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8world/Controller.h"

namespace RBX
{
	G3D::Color3 Controller::controllerTypeToColor(ControllerType controllerType)
	{
		switch (controllerType)
		{
		case PLAYER_CONTROLLER:
			return G3D::Color3::purple();
		case PRIMARY_CONTROLLER:
			return G3D::Color3::blue();
		case SECONDARY_CONTROLLER:
			return G3D::Color3::red();
		case AI_CHASE_CONTROLLER:
			return G3D::Color3::black();
		case AI_FLEE_CONTROLLER:
			return G3D::Color3::yellow();
		default:
			return G3D::Color3::gray();
		}
	}
}
