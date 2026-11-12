// from server: 100% by EspClaude
// roc 2007-08 00665c30  unit: CRobloxTreeCtrl  size: 858 bytes
// Codegen analog of Codejock CXTTreeBase::SetItemState (XTP 11.x shape, without the
// later "if (!hItem) return FALSE" guard, which the target lacks).
// Layout from the target bytes: m_bMultiSelect +0x04, m_pTreeCtrl +0x34,
// SendNotify vtable +0x48, CWnd::m_hWnd +0x20, NMTREEVIEW frame 0x68 bytes.

typedef unsigned int UINT;
typedef int BOOL;
typedef long LRESULT;
typedef long LPARAM;
typedef unsigned int WPARAM;
struct HWND__;
typedef HWND__* HWND;
struct _TREEITEM;
typedef _TREEITEM* HTREEITEM;

extern "C" {
    __declspec(dllimport) LRESULT __stdcall SendMessageA(HWND, UINT, WPARAM, LPARAM);
    __declspec(dllimport) BOOL __stdcall UpdateWindow(HWND);
    __declspec(dllimport) int __stdcall GetDlgCtrlID(HWND);
}

#define TVIS_FOCUSED   0x0001
#define TVIS_SELECTED  0x0002
#define TVIF_PARAM     0x0004
#define TVIF_STATE     0x0008
#define TVIF_HANDLE    0x0010
#define TVGN_CARET     0x0009
#define TVM_GETNEXTITEM 0x110A
#define TVM_SELECTITEM  0x110B
#define TVN_SELCHANGINGA (0U-401)
#define TVN_SELCHANGEDA  (0U-402)

struct NMHDR { HWND hwndFrom; UINT idFrom; UINT code; };
struct TVITEMA {
    UINT mask; HTREEITEM hItem; UINT state; UINT stateMask;
    char* pszText; int cchTextMax; int iImage; int iSelectedImage; int cChildren; LPARAM lParam;
};
struct POINT { long x, y; };
struct NMTREEVIEWA { NMHDR hdr; UINT action; TVITEMA itemOld; TVITEMA itemNew; POINT ptDrag; };

class CWnd {
public:
    char pad[0x20];
    HWND m_hWnd;
    BOOL UpdateWindow() { return ::UpdateWindow(m_hWnd); }
};

class CTreeCtrl : public CWnd {
public:
    BOOL SetItem(HTREEITEM hItem, UINT nMask, const char* lpszItem, int nImage,
        int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam);
    UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const;
    unsigned long GetItemData(HTREEITEM hItem) const;
    HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode) const
        { return (HTREEITEM)::SendMessageA(m_hWnd, TVM_GETNEXTITEM, nCode, (LPARAM)hItem); }
    HTREEITEM GetSelectedItem() const { return GetNextItem(0, TVGN_CARET); }
    BOOL Select(HTREEITEM hItem, UINT nCode)
        { return (BOOL)::SendMessageA(m_hWnd, TVM_SELECTITEM, nCode, (LPARAM)hItem); }
    BOOL SelectItem(HTREEITEM hItem) { return Select(hItem, TVGN_CARET); }
    BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask)
        { return SetItem(hItem, TVIF_STATE, 0, 0, 0, nState, nStateMask, 0); }
};

class CXTPSystemVersion {
public:
    bool IsWinVistaOrGreater() const;
};
CXTPSystemVersion* __stdcall XTPSystemVersion();

#define V1(n) virtual void v##n();

class CXTTreeBase {
public:
    V1(0) V1(1) V1(2) V1(3) V1(4) V1(5) V1(6) V1(7) V1(8)
    V1(9) V1(10) V1(11) V1(12) V1(13) V1(14) V1(15) V1(16) V1(17)
    virtual LRESULT SendNotify(NMHDR* pNMHDR);   // vtable +0x48

    BOOL IsSelected(HTREEITEM hItem) const {
        return !!(TVIS_SELECTED & m_pTreeCtrl->GetItemState(hItem, TVIS_SELECTED));
    }
    BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask);

    BOOL m_bMultiSelect;                 // +0x04
    char pad08[0x34 - 0x08];
    CTreeCtrl* m_pTreeCtrl;              // +0x34
};

BOOL CXTTreeBase::SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask)
{
    if (!m_bMultiSelect)
    {
        return m_pTreeCtrl->SetItemState(hItem, nState, nStateMask);
    }

    HTREEITEM hFocus = m_pTreeCtrl->GetSelectedItem();
    BOOL bWasFocus = (hFocus == hItem);
    BOOL bFocusWasSel = hFocus && IsSelected(hFocus);
    BOOL bWasSel = IsSelected(hItem);

    UINT nS = (nState & ~TVIS_FOCUSED);
    UINT nSM = (nStateMask & ~TVIS_FOCUSED);

    BOOL bVista = XTPSystemVersion()->IsWinVistaOrGreater();

    if (nStateMask & TVIS_FOCUSED)
    {
        if (nState & TVIS_FOCUSED)
        {
            if (bVista)
            {
                if (!bWasFocus && hFocus)
                {
                    m_pTreeCtrl->SelectItem(0);
                    m_pTreeCtrl->SetItemState(hFocus, TVIS_SELECTED, TVIS_SELECTED);
                }

                if (!m_pTreeCtrl->SelectItem(hItem))
                {
                    return 0;
                }

                if (!bWasFocus && hFocus)
                {
                    m_pTreeCtrl->SetItemState(hFocus, bFocusWasSel ? TVIS_SELECTED : 0, TVIS_SELECTED);
                }
            }
            else
            {
                if (!bWasFocus && bFocusWasSel)
                {
                    m_pTreeCtrl->SelectItem(0);
                    m_pTreeCtrl->SetItemState(hFocus, TVIS_SELECTED, TVIS_SELECTED);
                    m_pTreeCtrl->UpdateWindow();
                }

                if (!m_pTreeCtrl->SelectItem(hItem))
                {
                    return 0;
                }
            }

            if (nStateMask & TVIS_SELECTED)
            {
                if (nState & TVIS_SELECTED)
                {
                    if (!bVista && (!bWasFocus || bFocusWasSel))
                    {
                        nS &= ~TVIS_SELECTED;
                        nSM &= ~TVIS_SELECTED;
                    }
                }
            }
            else
            {
                if (!bWasSel)
                {
                    nS &= ~TVIS_SELECTED;
                    nSM |= TVIS_SELECTED;
                }
            }
        }
        else
        {
            if (bWasFocus)
            {
                m_pTreeCtrl->SelectItem(0);
                if (!(nStateMask & TVIS_SELECTED))
                {
                    if (bWasSel)
                    {
                        m_pTreeCtrl->SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
                    }
                }
                else if (nState & TVIS_SELECTED)
                {
                    if (bWasSel)
                    {
                        m_pTreeCtrl->SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
                    }
                    nS &= ~TVIS_SELECTED;
                    nSM &= ~TVIS_SELECTED;
                }
            }
        }
    }

    if (!nSM)
    {
        return 1;
    }

    if (nSM & TVIS_SELECTED)
    {
        NMTREEVIEWA nmtv;
        nmtv.hdr.hwndFrom = m_pTreeCtrl->m_hWnd;
        nmtv.hdr.idFrom = ::GetDlgCtrlID(m_pTreeCtrl->m_hWnd);
        nmtv.hdr.code = TVN_SELCHANGINGA;
        nmtv.itemOld.mask = nmtv.itemNew.mask = 0;
        nmtv.itemOld.hItem = nmtv.itemNew.hItem = 0;

        TVITEMA& item = (nS & TVIS_SELECTED) ? nmtv.itemNew : nmtv.itemOld;
        item.mask = TVIF_HANDLE | TVIF_PARAM;
        item.hItem = hItem;
        item.lParam = m_pTreeCtrl->GetItemData(hItem);
        item.state = nS;
        item.stateMask = nSM;

        if (SendNotify(&nmtv.hdr))
        {
            return 0;
        }

        m_pTreeCtrl->SetItemState(hItem, nS, nSM);
        nmtv.hdr.code = TVN_SELCHANGEDA;
        SendNotify(&nmtv.hdr);
        nS &= ~TVIS_SELECTED;
        nSM &= ~TVIS_SELECTED;
    }

    if (!nSM)
    {
        return 1;
    }

    return m_pTreeCtrl->SetItemState(hItem, nS, nSM);
}
