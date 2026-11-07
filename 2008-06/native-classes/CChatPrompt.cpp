// >>> native-status (generated) -- do not edit >>>
// CChatPrompt | 2008-06 | linked
// 2/2 exact by name (100%) | 2/2 exact bodies | no strings | verified 2026-11-07| by king_originala (+1) (mixed 2)
// <<< native-status | src 79ddb860 | roc native-status --write
#include "../native-headers/CChatPrompt.h"
#include "../native-headers/ChatEnter.h"
#include "../native-headers/v8datamodel/DataModel.h"
CChatPrompt::CChatPrompt() : hostWindow(0), players(0) {}

// 00412800: bind the chat widget to a DataModel and its player service.
void CChatPrompt::bind(RBX::DataModel* model, CWnd* host) {
    context = RBX::shared_from(model);
    RBX::DataModel::Lock lock(context);
    if (chat) {
        chat->owner = 0;
        chat->setParent(0);
        chat.reset();
    }
    hostWindow = host;
    players = model ? model->create<RBX::Network::Players>() : 0;
    if (model) {
        chat = RBX::Creatable<RBX::Instance>::create<ChatEnter>();
        chat->owner = this;
        chat->setParent(model->guiHooks.get());
    }
    if (m_hWnd) EnableWindow(players != 0);
}
