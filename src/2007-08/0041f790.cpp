// from server: 100% by EspClaude
// roc 2007-08 0041f790  unit: CSelectionTreeCtrl
struct RECT { long left, top, right, bottom; };
struct HWND__ { int unused; };
typedef HWND__* HWND;
struct _TREEITEM;
typedef _TREEITEM* HTREEITEM;
#define TVI_ROOT ((HTREEITEM)(long)-0x10000)
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(HWND hWnd, const RECT* lpRect, int bErase);
class CWnd {
public:
    char pad[0x20];
    HWND m_hWnd;
};
class CTreeCtrl : public CWnd {
public:
    int GetItemRect(HTREEITEM hItem, RECT* lpRect, int bTextOnly) const;
};
class CRobloxTreeCtrlNode {
    char pad[0x2c];
    unsigned char m_flags;
    char pad2[3];
    CTreeCtrl* m_tree;
    char pad3[0x10];
    HTREEITEM m_hItem;
public:
    void Redraw();
};
void CRobloxTreeCtrlNode::Redraw()
{
    if (m_flags & 1) {
        if (m_hItem && m_hItem != TVI_ROOT) {
            RECT rc;
            if (m_tree->GetItemRect(m_hItem, &rc, 0))
                ::InvalidateRect(m_tree->m_hWnd, &rc, 1);
        }
        m_flags &= ~1;
    }
}
