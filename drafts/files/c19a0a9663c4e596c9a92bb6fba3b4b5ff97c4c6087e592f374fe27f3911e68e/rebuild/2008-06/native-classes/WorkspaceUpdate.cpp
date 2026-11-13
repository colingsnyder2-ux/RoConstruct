// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Workspace input / heartbeat / render / service-provider members (inactive), original unit
// v8datamodel/Workspace.cpp (005a01e0..005a66af). Built against the committed native v8datamodel/Workspace.h
// (read-only); sibling members of the same unit live in AppUnit5A0_2008Workspace.cpp / AppUnit5A4WorkspaceReflection.cpp.
//
// Header inline bodies (not repeated here, emitted where Workspace's vtables are emitted):
//   render3dSelect 00458e90 (`ret 8`, ICF-shared empty body), computeCameraOwnerExtents 005a2c30,
//   cameraMoved 005a2d90, onExtentsChanged 005a2db0 -- all defined inline in v8datamodel/Workspace.h.
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX
{
	// @005a20e0 ?process@Workspace@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z
	// Entered with the GuiTarget subobject (Workspace+0x2e8): currentCommand +0xc8, idleMouseEvent +0xd0,
	// inMouselookMode +0x110, Notifier<Workspace, DrawChanged> +0x5c. Jump table 005a2250 (event types 1..13).
	// MouseCommand slots: onMouseDown +4, onMouseIdle +8, onMouseHover +0xc, onKeyDown +0x10, onPeekKeyDown +0x14,
	// onMouseMove +0x18, onMouseDelta +0x1c, onMouseUp +0x20. UserInputBase slot +8 is setWrapMode.
	GuiResponse Workspace::process(const GuiEvent& event)
	{
		if (event.isMouseEvent())
		{
			idleMouseEvent = event;
			idleMouseEvent.eventType = UIEvent::MOUSE_IDLE;
		}

		switch (event.eventType)
		{
		// Event types 12 and 13 are past the donor UIEvent enum (KEY_UP = 11); the 2008 enumerator names are not
		// recovered (header proposal for util/UIEvent.h). Both raise DrawChanged and leave mouselook.
		case 12:
		case 13:
			raiseDrawChanged();
		case UIEvent::MOUSE_RIGHT_BUTTON_UP:
			inMouselookMode = false;
			event.userInput->setWrapMode(UserInputBase::WRAP_AUTO);
			break;
		case UIEvent::MOUSE_RIGHT_BUTTON_DOWN:
			inMouselookMode = true;
			event.userInput->setWrapMode(UserInputBase::WRAP_CENTER);
			break;
		case UIEvent::KEY_DOWN:
			currentCommand->onPeekKeyDown(event);
			if (!currentCommand->captured())
				return GuiResponse::notUsed();
			setMouseCommand(currentCommand->onKeyDown(event));
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			if (!currentCommand->captured())
				setMouseCommand(currentCommand->onMouseDown(event));
			break;
		case UIEvent::MOUSE_MOVE:
			if (currentCommand->captured())
				currentCommand->onMouseMove(event);
			else
				currentCommand->onMouseHover(event);
			break;
		case UIEvent::MOUSE_DELTA:
			if (currentCommand->captured())
				currentCommand->onMouseDelta(event);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			setMouseCommand(currentCommand->onMouseUp(event));
			break;
		default:
			return GuiResponse::notUsed();
		}

		if (currentCommand->captured())
			return GuiResponse::used(this);
		else
			return GuiResponse::used();
	}
}
