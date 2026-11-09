// from server: 100% by EspClaude
// roc 2007-08 00458d00  unit: CRobloxWnd
class CWnd {
protected:
    long Default();
};
class CRobloxView {
public:
    void Activate(int);
};
class CRobloxWnd : public CWnd {
    char pad[0x74];
    CRobloxView* m_view;
    void ReleaseInput();
public:
    void OnKillFocus(CWnd* pNewWnd);
};
void CRobloxWnd::OnKillFocus(CWnd*)
{
    ReleaseInput();
    Default();
    if (m_view)
        m_view->Activate(0);
}
