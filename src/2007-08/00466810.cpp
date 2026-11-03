// from server: 100% by EspClaude
// roc 2007-08 00466810  unit: CWebToolbox
class CWnd {
public:
    CWnd* SetFocus();
};
class CFormView : public CWnd {
protected:
    void OnSetFocus(CWnd* pOldWnd);
};
class CWebToolbox : public CFormView {
    char pad[0xf4];
    CWnd* m_browser;
public:
    void OnSetFocus(CWnd* pOldWnd);
};
void CWebToolbox::OnSetFocus(CWnd* pOldWnd)
{
    CFormView::OnSetFocus(pOldWnd);
    if (m_browser)
        m_browser->SetFocus();
}
