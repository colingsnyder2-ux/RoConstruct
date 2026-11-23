// =============================================================================
// MultiPlayerPane.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/MultiPlayerPane.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CMultiPlayerPane.h"
#include "CChatPrompt.h"

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

BOOL CMultiPlayerPane::initialize(CWnd* parent, RBX::DataModel* model) {
    if (!CWnd::Create(0, 0, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), parent, 1002, 0)) return FALSE;
    chatPrompt = static_cast<CChatPrompt*>(RUNTIME_CLASS(CChatPrompt)->CreateObject());
    if (!chatPrompt->Create(0, 0, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1003, 0)) return FALSE;
    chatPrompt->bind(model, parent);
    ::SendMessage(chatPrompt->m_hWnd, 0x364, 0, 0);
    return TRUE;
}
