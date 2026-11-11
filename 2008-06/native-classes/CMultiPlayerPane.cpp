// >>> native-status (generated) -- do not edit >>>
// CMultiPlayerPane | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (mixed 2)
// <<< native-status | src 9cb453fd | roc native-status --write
#include "../native-headers/CMultiPlayerPane.h"
#include "../native-headers/CChatPrompt.h"

CMultiPlayerPane::CMultiPlayerPane() : chatPrompt(0) {}
CMultiPlayerPane::~CMultiPlayerPane() {}

IMPLEMENT_DYNAMIC(CMultiPlayerPane, CWnd)
BEGIN_MESSAGE_MAP(CMultiPlayerPane, CWnd)
    ON_WM_SIZE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

void CMultiPlayerPane::OnSize(UINT type, int width, int height) {
    if (type != SIZE_MINIMIZED && chatPrompt)
        chatPrompt->MoveWindow(0, 0, width, height, TRUE);
    Default();
}
void CMultiPlayerPane::OnDestroy() {
    chatPrompt = 0;
    CWnd::OnDestroy();
}

// 00432e60: create the pane and its chat view.
BOOL CMultiPlayerPane::initialize(CWnd* parent, RBX::DataModel* model) {
    if (!CWnd::Create(0, 0, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), parent, 1002, 0)) return FALSE;
    chatPrompt = static_cast<CChatPrompt*>(RUNTIME_CLASS(CChatPrompt)->CreateObject());
    if (!chatPrompt->Create(0, 0, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1003, 0)) return FALSE;
    chatPrompt->bind(model, parent);
    ::SendMessage(chatPrompt->m_hWnd, 0x364, 0, 0);
    return TRUE;
}
