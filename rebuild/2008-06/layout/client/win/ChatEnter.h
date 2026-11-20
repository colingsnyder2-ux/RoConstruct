#pragma once
#include "gui/Gui.h"
class CChatPrompt;
class ChatEnter : public RBX::GuiItem {
public:
    CChatPrompt* owner;
    ChatEnter();
    virtual ~ChatEnter();
    virtual RBX::GuiResponse process(const RBX::GuiEvent& event);
};
