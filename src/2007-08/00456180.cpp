// from server: 100% by EspClaude
// roc 2007-08 00456180  unit: CRobloxView
class CFrameWnd;
class CWnd {
};
class CView : public CWnd {
protected:
    void OnActivateFrame(unsigned int nState, CFrameWnd* pFrameWnd);
};
class CRobloxWnd {
public:
    void OnActivate(bool active);
};
class CRobloxView : public CView {
    char pad[0x88];
    CRobloxWnd m_wnd;
public:
    void OnActivateFrame(unsigned int nState, CFrameWnd* pFrameWnd);
};
void CRobloxView::OnActivateFrame(unsigned int nState, CFrameWnd* pFrameWnd)
{
    if (nState)
        m_wnd.OnActivate(true);
    else
        m_wnd.OnActivate(false);
    CView::OnActivateFrame(nState, pFrameWnd);
}
