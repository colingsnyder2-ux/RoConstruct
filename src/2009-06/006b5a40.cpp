// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_90d96c1d696700ef.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/MouseCommand.h", "roc_unit_9958a7131e20354c.cpp")
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"

namespace RBX
{
	ScriptMouseCommand::ScriptMouseCommand(Workspace* workspace)
		: MouseCommand(workspace)
	{
		mouse = Creatable<Instance>::create<Mouse>();
		mouse->setCommand(this);
	}

	ScriptMouseCommand::~ScriptMouseCommand()
	{
		mouse->setCommand(NULL);
		mouse->disconnect_all_slots();
	}

	TextureId ScriptMouseCommand::getCursorId() const
	{
		return mouse->getIcon();
	}

	MouseCommand* ScriptMouseCommand::onMouseDown(const UIEvent& uiEvent)
	{
		mouse->update(uiEvent);
		return this;
	}

	MouseCommand* ScriptMouseCommand::onMouseUp(const UIEvent& uiEvent)
	{
		mouse->update(uiEvent);
		return this;
	}

	MouseCommand* ScriptMouseCommand::onPeekKeyDown(const UIEvent& uiEvent)
	{
		mouse->update(uiEvent);
		return this;
	}

	void ScriptMouseCommand::onMouseIdle(const UIEvent& uiEvent)
	{
		mouse->update(uiEvent);
	}

	void ScriptMouseCommand::onMouseHover(const UIEvent& uiEvent)
	{
		mouse->update(uiEvent);
	}
}
