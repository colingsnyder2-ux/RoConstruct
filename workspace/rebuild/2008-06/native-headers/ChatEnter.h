#pragma once
// >>> native-status (generated) -- do not edit >>>
// ChatEnter | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f3e02336 | roc native-status --write
#include "gui/Gui.h"
class CChatPrompt;
// Inactive candidate: original RTTI and factory establish base and owner offset.
class ChatEnter : public RBX::GuiItem {
public:
    CChatPrompt* owner;
    ChatEnter();
    virtual ~ChatEnter();
};
