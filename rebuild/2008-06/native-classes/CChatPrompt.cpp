// >>> native-status (generated) -- do not edit >>>
// CChatPrompt | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src d9f3c2f2 | roc native-status --write
#include "../native-headers/CChatPrompt.h"
#include "../native-headers/ChatEnter.h"
#include "../native-headers/v8datamodel/DataModel.h"

IMPLEMENT_DYNCREATE(CChatPrompt, CEditView)

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::GuiRoot>;

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS

CChatPrompt::~CChatPrompt()
{
    bind(NULL, NULL);
}
