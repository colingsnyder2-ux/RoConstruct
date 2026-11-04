#include "CWrapperView.h"

IMPLEMENT_DYNCREATE(CWrapperView, CView)

CWrapperView::CWrapperView() {}

void CWrapperView::OnDraw(CDC*) {}

BOOL CWrapperView::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CView::PreCreateWindow(cs))
        return FALSE;
    cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    return TRUE;
}

BOOL CWrapperView::OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* handler)
{
    if (CView::OnCmdMsg(id, code, extra, handler))
        return TRUE;
    return tree.OnCmdMsg(id, code, extra, handler);
}

BOOL CWrapperView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    BOOL handled = CView::OnWndMsg(message, wParam, lParam, result);
    if (handled && *result)
        return TRUE;

    switch (message)
    {
    case WM_CREATE:
        if (!tree.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
                         CRect(0, 0, 100, 100), this, 0))
        {
            *result = -1;
            return TRUE;
        }
        tree.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
        break;
    case WM_SIZE:
        if (tree.m_hWnd)
            tree.MoveWindow(0, 0, LOWORD(lParam), HIWORD(lParam));
        break;
    default:
        return handled;
    }
    return TRUE;
}
