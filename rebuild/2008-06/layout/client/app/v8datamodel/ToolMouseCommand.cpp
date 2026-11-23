// =============================================================================
// ToolMouseCommand.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/ToolMouseCommand.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/ToolMouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Tool.h"
#include "humanoid/Humanoid.h"

namespace RBX
{
	const char sToolMouseCommand[] = "ToolMouseCommand";

	ToolMouseCommand::ToolMouseCommand(Workspace* workspace, Tool* tool)
		: Base(workspace),
		  tool(shared_from(tool))
	{
	}

	ToolMouseCommand::~ToolMouseCommand() {}

	void ToolMouseCommand::onMouseHover(const UIEvent& uiEvent)
	{
		updateTargetPoint(uiEvent);
		ScriptMouseCommand::onMouseHover(uiEvent);
	}

	void ToolMouseCommand::onMouseIdle(const UIEvent& uiEvent)
	{
		updateTargetPoint(uiEvent);
		ScriptMouseCommand::onMouseIdle(uiEvent);
	}

	MouseCommand* ToolMouseCommand::onMouseDown(const UIEvent& uiEvent)
	{
		updateTargetPoint(uiEvent);
		tool->activate();
		return ScriptMouseCommand::onMouseDown(uiEvent);
	}

	MouseCommand* ToolMouseCommand::onMouseUp(const UIEvent& uiEvent)
	{
		updateTargetPoint(uiEvent);
		tool->deactivate();
		return ScriptMouseCommand::onMouseUp(uiEvent);
	}

	void ToolMouseCommand::updateTargetPoint(const UIEvent& uiEvent)
	{
		G3D::Vector3 hitWorld;

		Humanoid* humanoid = Humanoid::getLocalHumanoidFromContext(tool.get());
		if (!humanoid)
			return;

		if (!getPartByLocalCharacter(uiEvent, hitWorld))
		{
			G3D::Ray ray = getSearchRay(uiEvent);
			hitWorld = humanoid->getHead() ? humanoid->getHead()->getCoordinateFrame().translation : ray.origin;
			hitWorld += ray.direction;
		}

		humanoid->setTargetPoint(hitWorld);
	}
}
