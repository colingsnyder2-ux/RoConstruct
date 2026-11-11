// from server: 100% by EspClaude
// from server: 93% by EspClaude
// roc 2007-08 004201a0  unit: CRobloxTreeCtrl
struct HWND__ { int unused; };
typedef HWND__* HWND;
extern "C" __declspec(dllimport) long __stdcall SendMessageA(HWND, unsigned int, unsigned int, long);
struct NMHDR { HWND hwndFrom; unsigned int idFrom; unsigned int code; };
struct TVITEM { unsigned int mask; void* hItem; unsigned int state; unsigned int stateMask; char* pszText; int cchTextMax; int iImage; int iSelectedImage; int cChildren; long lParam; };
struct NMTREEVIEW { NMHDR hdr; unsigned int action; TVITEM itemOld; TVITEM itemNew; };
template<class T> class ScopedAssign {
    T& m_ref;
    T m_old;
public:
    ScopedAssign(T& ref, T value) : m_ref(ref), m_old(ref) { ref = value; }
    ~ScopedAssign() { m_ref = m_old; }
};
class CRobloxTreeCtrlNode {
public:
    virtual void v0();
    virtual ~CRobloxTreeCtrlNode();
};
class CWnd {
public:
    char pad[0x20];
    HWND m_hWnd;
    HWND GetSafeHwnd() const { return this == 0 ? 0 : m_hWnd; }
};
class CRobloxTreeCtrl : public CWnd {
public:
    char pad2[0x70];
    CRobloxTreeCtrlNode* m_root;
    char pad3[0xc];
    bool m_deleting;
    int DeleteAllItems() { return (int)::SendMessageA(m_hWnd, 0x1101, 0, (long)0xffff0000); }
    void DeleteAll();
    void OnDeleteItem(NMHDR* pNMHDR, long* pResult);
};
void CRobloxTreeCtrl::DeleteAll()
{
    ScopedAssign<bool> guard(m_deleting, true);
    if (!m_hWnd)
        return;
    DeleteAllItems();
    if (m_root) {
        delete m_root;
        m_root = 0;
    }
}
void CRobloxTreeCtrl::OnDeleteItem(NMHDR* pNMHDR, long* pResult)
{
    ScopedAssign<bool> guard(m_deleting, true);
    NMTREEVIEW* pNMTreeView = (NMTREEVIEW*)pNMHDR;
    CRobloxTreeCtrlNode* node = (CRobloxTreeCtrlNode*)pNMTreeView->itemOld.lParam;
    delete node;
    *pResult = 0;
}
