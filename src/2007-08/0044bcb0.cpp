// from server: 100% by EspClaude
// from server: 53% by colin
// roc 2007-08 0044bcb0  unit: CRobloxControlColorSelector  size: 623 bytes

// CRobloxControlColorSelector::Draw(CDC*) (2008-06 native analog: CRobloxControlColorSelector.cpp).
// 2007-08 offsets from target bytes: m_bEnabled +0x9c, m_pAction +0x158, m_rcControl.left/top
// +0xc0/+0xc4, m_nSelected +0x168, m_clr +0x174; GetPressed vtable +0x78; paint-manager
// DrawRectangle vtable +0x84; palette element 12 bytes (size() divides by 12).
#include <vector>

typedef unsigned long COLORREF;
typedef int BOOL;

struct RECT { long left, top, right, bottom; };
struct POINT { long x, y; };
struct SIZE { long cx, cy; };
struct CPoint : POINT { CPoint(int initX, int initY) { x = initX; y = initY; } };
struct CSize : SIZE { CSize(int initCX, int initCY) { cx = initCX; cy = initCY; } };
extern "C" __declspec(dllimport) int __stdcall InflateRect(RECT*, int, int);

struct CRect : RECT {
    CRect(int l, int t, int r, int b) { left = l; top = t; right = r; bottom = b; }
    void DeflateRect(int x, int y) { ::InflateRect(this, -x, -y); }
    CRect(POINT point, SIZE size)
    {
        right = (left = point.x) + size.cx;
        bottom = (top = point.y) + size.cy;
    }
    operator RECT*() { return this; }
};

class CDC {
public:
    void FillSolidRect(const RECT* lpRect, COLORREF clr);
    void Draw3dRect(const RECT* lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);
};

class CXTPColorManager {
public:
    COLORREF GetColor(int nIndex);
};
CXTPColorManager* XTPColorManager();
inline COLORREF GetXtremeColor(int nIndex) { CXTPColorManager* pManager = XTPColorManager(); return pManager->GetColor(nIndex); }

class CXTPPaintManager {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80();
    virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled,
                               BOOL bChecked, BOOL bPopuped, int barType, int barPosition); // +0x84
};

class CXTPControlAction {
public:
    BOOL GetEnabled() const;
};

class CXTPControl {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74();
    virtual BOOL GetPressed() const;                                   // +0x78

    CXTPPaintManager* GetPaintManager() const;
    BOOL GetEnabled() const
    {
        if (m_bEnabled == -1 && m_pAction)
            return m_pAction->GetEnabled();
        return m_bEnabled;
    }

    char pad04[0x9c - 4];
    BOOL m_bEnabled;                                                   // +0x9c
    char padA0[0xc0 - 0xa0];
    RECT m_rcControl;                                                  // +0xc0
    char padD0[0x158 - 0xd0];
    CXTPControlAction* m_pAction;                                      // +0x158
    char pad15c[0x168 - 0x15c];
};

class CRobloxControlColorSelector : public CXTPControl {
public:
    struct CColorInfo {
        COLORREF clrButton;                                            // +0
        char rest[12 - 4];
    };

    void Draw(CDC* pDC);
    CRect GetRect(int nIndex) const
    {
        unsigned int nColumns = 8;
        int x = m_rcControl.left + ((unsigned)nIndex % nColumns) * 32 + 2;
        int y = m_rcControl.top + ((unsigned)nIndex / nColumns) * 32 + 2;
        return CRect(CPoint(x, y), CSize(32, 32));
    }

    static std::vector<CColorInfo> colors;

    int m_nSelected;                                                   // +0x168
    char pad16c[0x174 - 0x16c];
    COLORREF m_clr;                                                    // +0x174
};

void CRobloxControlColorSelector::Draw(CDC* pDC)
{
    int nCount = (int)colors.size();
    for (int i = 0; i < nCount; i++) {
        CRect rcButton = GetRect(i);
        if (i == m_nSelected || colors[i].clrButton == m_clr) {
            BOOL bPressed = GetPressed() && i == m_nSelected;
            GetPaintManager()->DrawRectangle(pDC, rcButton, i == m_nSelected, bPressed, GetEnabled(),
                                             colors[i].clrButton == m_clr, 0, 1, 5);
        }
        rcButton.DeflateRect(3, 3);
        if (GetEnabled())
            pDC->FillSolidRect(rcButton, colors[i].clrButton);
        pDC->Draw3dRect(rcButton, GetXtremeColor(16), GetXtremeColor(16));
    }
}
