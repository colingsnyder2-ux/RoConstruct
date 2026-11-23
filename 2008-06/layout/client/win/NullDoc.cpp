// =============================================================================
// NullDoc.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/NullDoc.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CBrowserFrameWnd.h"

IMPLEMENT_DYNCREATE(CBrowserFrameWnd, CXTPFrameWnd)

BEGIN_MESSAGE_MAP(CBrowserFrameWnd, CFrameWnd)
    ON_WM_DESTROY()
    ON_WM_CREATE()
    ON_WM_NCDESTROY()
END_MESSAGE_MAP()

int CBrowserFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    CMenu* menu = GetMenu();
    if (menu && ::IsMenu(menu->m_hMenu)) {
        menu->DestroyMenu();
        SetMenu(NULL);
    }
    CWnd* pane = GetDescendantWindow(m_hWnd, AFX_IDW_PANE_FIRST, TRUE);
    pane->ModifyStyle(WS_BORDER, 0, SWP_FRAMECHANGED);
    pane->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
    return 0;
}

template class CXTPFrameWndBase<CFrameWnd>;
