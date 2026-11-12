// from server: 97% by EspClaude
// roc 2007-08 00644280  unit: CXTPCommandBar  size: 349 bytes
// XTP CXTPCommandBar::OnMouseMove(UINT, CPoint). Offsets/vtable slots read off the target:
// m_hWnd +0x20, m_nSelected +0xc8, m_nPopuped +0xcc, m_bTracking +0xdc, m_pControls +0xf8,
// m_barPosition +0xfc (xtpBarPopup = 5), m_bKeyboardSelect +0x12c, m_bTrackOnHover +0x160;
// CXTPCommandBars: m_pDragSelected +0x58, m_bCustomizeMode +0x5c; CXTPControl: m_nIndex +0x80,
// OnMouseMove vtable +0xfc; CXTPCommandBar::SetSelected vtable +0x148.
typedef int BOOL;
typedef unsigned int UINT;
struct HWND__; typedef HWND__* HWND;
struct CPoint { long x; long y; };

#define V4(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3();
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)

class CXTPControl {
public:
    V16(pa) V16(pb) V16(pc) V4(pd0) V4(pd1) V4(pd2) virtual void pe0(); virtual void pe1(); virtual void pe2();
    virtual void OnMouseMove(CPoint point);              // +0xfc
    void OnCustomizeMouseMove(CPoint point);
    int GetIndex() const { return m_nIndex; }
    char pad04[0x80 - 4];
    int m_nIndex;                                        // +0x80
};

class CXTPControls {
public:
    CXTPControl* HitTest(CPoint point) const;
};

class CXTPCommandBar;

class CXTPMouseManager {
public:
    static BOOL __cdecl IsTopParentActive(HWND hWnd);
    BOOL IsTrackedLock(const CXTPCommandBar* pItem);
    void TrackMouseLeave(HWND hWnd);
};

class CXTPCommandBars {
public:
    CXTPMouseManager* GetMouseManager() const;
    BOOL IsCustomizeMode() const { return m_bCustomizeMode; }
    char pad00[0x58];
    CXTPControl* m_pDragSelected;                        // +0x58
    BOOL m_bCustomizeMode;                               // +0x5c
};

enum XTPBarPosition { xtpBarPopup = 5 };

class CXTPCommandBar {
public:
    V16(qa) V16(qb) V16(qc) V16(qd) V16(qe) virtual void qf0(); virtual void qf1();
    virtual void SetSelected(int nSelected, BOOL bKeyboard = 0);   // +0x148

    CXTPCommandBars* GetCommandBars() const;
    BOOL IsMouseLocked() const;
    BOOL IsTrackingMode() const { return m_bTracking; }
    XTPBarPosition GetPosition() const { return m_barPosition; }
    void OnMouseMove(UINT nFlags, CPoint point);

    char pad04[0x20 - 4];
    HWND m_hWnd;                                         // +0x20
    char pad24[0xc8 - 0x24];
    int m_nSelected;                                     // +0xc8
    int m_nPopuped;                                      // +0xcc
    char padd0[0xdc - 0xd0];
    BOOL m_bTracking;                                    // +0xdc
    char pade0[0xf8 - 0xe0];
    CXTPControls* m_pControls;                           // +0xf8
    XTPBarPosition m_barPosition;                        // +0xfc
    char pad100[0x12c - 0x100];
    BOOL m_bKeyboardSelect;                              // +0x12c
    char pad130[0x160 - 0x130];
    BOOL m_bTrackOnHover;                                // +0x160
};

void CXTPCommandBar::OnMouseMove(UINT /*nFlags*/, CPoint point)
{
    CXTPCommandBars* pCommandBars = GetCommandBars();
    CXTPMouseManager* pMouseManager = pCommandBars->GetMouseManager();

    BOOL bActive = IsTrackingMode() || pMouseManager->IsTopParentActive(m_hWnd);

    if (!m_hWnd || pMouseManager->IsTrackedLock(this) ||
        (!bActive && GetPosition() != xtpBarPopup) || IsMouseLocked())
        return;

    if (pCommandBars && pCommandBars->IsCustomizeMode())
    {
        CXTPControl* pControl = pCommandBars->m_pDragSelected;
        if (pControl)
            pControl->OnCustomizeMouseMove(point);
        return;
    }

    if (m_nPopuped != -1 && !m_bTrackOnHover)
        return;

    BOOL bLockSelected = ((GetPosition() != xtpBarPopup) || m_nPopuped != -1) || m_bKeyboardSelect;
    int nSelected = (IsTrackingMode() && bLockSelected) ? m_nSelected : -1;

    CXTPControl* pControl = m_pControls->HitTest(point);
    if (pControl)
    {
        nSelected = pControl->GetIndex();
        pMouseManager->TrackMouseLeave(m_hWnd);
        pControl->OnMouseMove(point);
    }

    SetSelected(nSelected);
}
