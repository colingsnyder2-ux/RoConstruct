// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/uievent-native
// 2008-06 004672a0..00467497: the out-of-line RBX::UIEvent window-size constructor and three DxUserInput client-rect
// helpers. Every caller (DxUserInput 00467ad0 / 00467f10 / 004684a0 / 00468b90) calls them out of line, so they come
// from a translation unit other than DxUserInput.cpp (defined there, /Ob2 would expand them into those callers).
// Formerly this file held a mined analog of 004672a0 (a volatile-field struct named CSettingsDialog); it is replaced
// by the real constructor, identified from util/UIEvent2008.h (0x14-byte event, windowSize +0x10) and its callers.
#include "util/DxUserInput.h"

namespace RBX
{
	// 004672a0 (registry placeholder func_004672a0): eventType +0, userInput +4, mouse position and delta zero
	// (four 16-bit stores), windowSize +0x10; ret 0xc. Union members in the initialiser list, as the 2007 openrbx
	// util/UIEvent.h position/size constructor writes them.
	UIEvent::UIEvent(UserInputBase* userInput, EventType eventType, G3D::Vector2int16 windowSize)
		: eventType(eventType),
		  userInput(userInput),
		  mousePosition(0, 0),
		  mouseDelta(0, 0),
		  windowSize(windowSize)
	{
	}

	// 00467380 (registry placeholder func_00467380): the client rect's origin equals its screen position, i.e. the
	// view is not offset on the screen. GetClientRect 00802d84 then ClientToScreen 00802d80 on window (+0x16c,
	// m_hWnd +0x20); the shape of the 2007 openrbx DxUserInput::FUN_0046b880 (CRect, two CPoint copies, if/return).
	bool DxUserInput::sub_00467380() const
	{
		CRect rect;
		window->GetClientRect(&rect);

		CPoint clientOrigin = rect.TopLeft();
		CPoint screenOrigin = clientOrigin;
		window->ClientToScreen(&screenOrigin);

		if (screenOrigin == clientOrigin)
			return true;
		return false;
	}

	// 004673f0 (registry placeholder func_004673f0): the client rect as (0,0)-(width,height); the 2007 openrbx
	// FUN_0046bb10 expression G3D::Rect2D(Vector2(rect.Width(), rect.Height())) (fild width, fild height, fldz),
	// returned instead of cached.
	G3D::Rect2D DxUserInput::sub_004673f0() const
	{
		CRect rect;
		window->GetClientRect(&rect);
		return G3D::Rect2D(G3D::Vector2(rect.Width(), rect.Height()));
	}

	// 00467440 (registry placeholder func_00467440): the client size as Vector2int16 (two __ftol2 0x6a17f0
	// conversions of the float width and height, x first); the 2007 openrbx FUN_0046b8f0 shape over the rect above.
	G3D::Vector2int16 DxUserInput::sub_00467440() const
	{
		G3D::Rect2D rect = sub_004673f0();
		return G3D::Vector2int16((G3D::int16)rect.width(), (G3D::int16)rect.height());
	}
}
