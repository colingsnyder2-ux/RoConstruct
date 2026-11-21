// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ChatEnter::process (inactive), the GuiTarget::process override of the chat widget (ChatEnter.h).
// It sits with CChatPrompt in the application range 00411000 (ChatEnter ctor / dtor in ChatEnter.cpp).
#include "CChatPrompt.h"
#include "ChatEnter.h"

// 00411300: thiscall on the GuiTarget subobject (owner at +0x14 = GuiTarget vptr +4, GuiItem focus +8, guiSize +0x10,
// ChatEnter::owner after them), hidden GuiResponse return, `ret 8`. A KEY_DOWN (10) of SDLK_SLASH (0x2f) posts
// WM_USER + 0x68 (0x468, CChatPrompt::OnFocusMessage in its message map) to the prompt window (m_hWnd +0x20) and
// returns GuiResponse::used() {USED, NULL}; anything else returns notUsed() {NOT_USED, NULL}.
RBX::GuiResponse ChatEnter::process(const RBX::GuiEvent& event)
{
	if (event.eventType == RBX::UIEvent::KEY_DOWN && event.key == SDLK_SLASH)
	{
		owner->PostMessage(WM_USER + 0x68, 0, 0);
		return RBX::GuiResponse::used();
	}
	return RBX::GuiResponse::notUsed();
}
