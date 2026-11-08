#pragma once
// >>> native-status (generated) -- do not edit >>>
// ToolMouseCommand | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src b6f64a40 | roc native-status --write
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
		virtual boost::shared_ptr<Mouse> getMouse();
	};
}
