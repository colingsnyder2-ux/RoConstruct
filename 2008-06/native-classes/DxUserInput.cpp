// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 RBX::DxUserInput (004675e0..004690f0): DirectInput 8 keyboard/mouse input source. Inactive native unit.
#include "util/DxUserInput.h"

namespace RBX
{
	// 00467530: remember the key while it is down, clear it on release (neg/sbb/and = down ? key : 0)
	void DxUserInput::setKeyState(SDLKey key, bool down)
	{
		heldKey = down ? key : (SDLKey)0;
	}

	// 00467550: the mouse device (GUID_SysMouse, c_dfDIMouse2) with a 0x800-entry buffer (DIPROP_BUFFERSIZE = guid 1)
	void DxUserInput::createMouse()
	{
		AfxCheckError(directInput->CreateDevice(GUID_SysMouse, &mouse, NULL));
		AfxCheckError(mouse->SetDataFormat(c_dfDIMouse2));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		AfxCheckError(mouse->SetProperty((const GUID*)1, &prop));
	}

	// 004675e0: the keyboard device (GUID_SysKeyboard, c_dfDIKeyboard) with the same buffer size
	void DxUserInput::createKeyboard()
	{
		AfxCheckError(directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL));
		AfxCheckError(keyboard->SetDataFormat(c_dfDIKeyboard));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		AfxCheckError(keyboard->SetProperty((const GUID*)1, &prop));
	}

	// 00469070 / 00469080
	void DxUserInput::setWrapMode(WrapMode mode)
	{
		wrapMode = mode;
	}

	UserInputBase::WrapMode DxUserInput::getWrapMode() const
	{
		return wrapMode;
	}
}
