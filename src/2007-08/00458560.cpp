// from server: 100% by EspClaude
// roc 2007-08 00458560  unit: CRobloxWnd
class CWndBase {
public:
    void OnShowWindowBase(int);
};
class CRobloxView {
public:
    void Activate(int);
};
class CRobloxWnd : public CWndBase {
    char pad[0x74];
    CRobloxView* m_view;
public:
    void OnShow(int a);
};
void CRobloxWnd::OnShow(int a)
{
    OnShowWindowBase(a);
    if (m_view)
        m_view->Activate(1);
}
