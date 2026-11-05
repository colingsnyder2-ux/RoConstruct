#include "../native-headers/CChatPrompt.h"
#include "../native-headers/ChatEnter.h"
ChatEnter::ChatEnter() {}

RBX::GuiResponse ChatEnter::process(const RBX::GuiEvent& event)
{
    if (event.eventType == RBX::UIEvent::KEY_DOWN && event.key == SDLK_SLASH) {
        ::PostMessage(owner->m_hWnd, WM_USER + 0x68, 0, 0);
        return RBX::GuiResponse::used();
    }
    return RBX::GuiResponse::notUsed();
}
