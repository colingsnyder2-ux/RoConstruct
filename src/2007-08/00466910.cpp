// from server: 100% by EspClaude
// roc 2007-08 00466910  unit: CWebToolbox
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
void CWebToolbox::OnActivate(unsigned int, CWnd*, int)
{
    Default();
    if (m_browser)
        m_browser->SetFocus();
}

