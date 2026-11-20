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
		// No getMouse override: the ToolMouseCommand vtable 0084183c has the same 16 slots as ScriptMouseCommand's
		// 0084a894, and Tool::getMouse 005ff680 calls the inherited non-virtual ScriptMouseCommand::getMouse 005cf8d0
		// directly (005ff6c7), as the donor ToolMouseCommand.h (which declares none).
	public:
		MouseCommand* sub_0064dee0(const UIEvent& uiEvent);   // INFERRED: 0064dee0, placeholder name (identity tier), body byte-proved (Inferred_0064dee0.cpp)
	public:
		MouseCommand* sub_0064df30(const UIEvent& uiEvent);   // INFERRED: 0064df30, placeholder name (identity tier), body byte-proved (Inferred_0064df30.cpp)
	};
}
