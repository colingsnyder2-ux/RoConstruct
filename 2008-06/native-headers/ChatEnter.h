#pragma once
#include "gui/Gui.h"
class CChatPrompt;
// Inactive candidate: original RTTI and factory establish base and owner offset.
class ChatEnter : public RBX::GuiItem {
public:
    CChatPrompt* owner;
    ChatEnter();
    virtual RBX::GuiResponse process(const RBX::GuiEvent& event);
};
