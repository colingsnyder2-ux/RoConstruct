// from server: 100% by EspClaude
// roc 2007-08 004667e0  unit: CWebToolbox
class CView;
class CWnd {
public:
    CWnd* SetFocus();
protected:
    long Default();
};
class CFormView : public CWnd {
protected:
    void OnActivateView(int bActivate, CView* pActivateView, CView* pDeactiveView);
};
class CWebToolbox : public CFormView {
    char pad[0xf4];
    CWnd* m_browser;
public:
    void OnActivateView(int bActivate, CView* pActivateView, CView* pDeactiveView);
    void OnActivate(unsigned int nState, CWnd* pWndOther, int bMinimized);
};
void CWebToolbox::OnActivateView(int bActivate, CView* pActivateView, CView* pDeactiveView)
{
    CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
    if (m_browser)
        m_browser->SetFocus();
}
