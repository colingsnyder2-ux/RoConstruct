// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>

// INFERRED: 12-byte theme colour (vtbl/pad, colour, override index); -1 = use colour
struct XTColor {
    DWORD pad;
    COLORREF m_clr;
    COLORREF m_idx;
    operator COLORREF() const { return m_idx == (COLORREF)-1 ? m_clr : m_idx; }
};

// INFERRED: minimal layouts from member offsets in the disassembly
class CXTButton : public CButton {
public:
    BYTE pad1[0x7c - sizeof(CButton)];
    int m_bHover;
    BYTE pad2[0xa0 - 0x80];
    int m_bPressed;
    BYTE GetButtonStyle() const;
};

void __stdcall XTFuncDrawShadedRect(CDC* pDC, CRect& rect);
extern "C" int __fastcall fn_006f7a70(void* self, int unusedEdx, int a1);

class CXTButtonTheme {
public:
    virtual ~CXTButtonTheme();
    BYTE pad0[0x20 - sizeof(void*)];
    XTColor m_crBack;      // 0x20
    XTColor m_c2c, m_c38;  // 0x2c, 0x38
    XTColor m_c44, m_c50, m_c5c, m_c68;
protected:
    virtual int DrawButtonThemeBackground(LPDRAWITEMSTRUCT lpDIS, CXTButton* pButton);
};

typedef DWORD (__thiscall *StateFn)(CXTButton*);

int CXTButtonTheme::DrawButtonThemeBackground(LPDRAWITEMSTRUCT lpDIS, CXTButton* pButton)
{
    CDC* pDC = CDC::FromHandle(lpDIS->hDC);
    CRect rc;
    ::CopyRect(&rc, &lpDIS->rcItem);

    BOOL bFlat = pButton->m_bHover || (lpDIS->itemState & ODS_SELECTED);

    POINT pt;
    // INFERRED: callee is a true thiscall (edx unused); leave edx uninitialised so no xor is emitted
    int unusedEdx;
    fn_006f7a70(&pt, unusedEdx, (int)pButton);

    pDC->FillSolidRect(&rc, m_crBack);

    // INFERRED: the callee at vtable+0x168 returns a state bitmask (bits 1, 2, 0x20)
    DWORD dwState = ((StateFn*)(*(void***)pButton))[0x168 / 4](pButton);

    if (dwState & 0x20) {
        if ((pButton->m_bHover && !::PtInRect(&rc, pt)) || bFlat)
            XTFuncDrawShadedRect(pDC, rc);
    }

    if (dwState & 1) {
        if (pButton->m_bPressed || ::GetCapture() == pButton->m_hWnd || bFlat) {
            XTColor& br = bFlat ? m_c5c : m_c50;
            XTColor& tl = bFlat ? m_c50 : m_c5c;
            pDC->Draw3dRect(&rc, tl, br);
        }
        return 1;
    }

    if (dwState & 2) {
        XTColor& br = bFlat ? m_c5c : m_c50;
        XTColor& tl = bFlat ? m_c50 : m_c5c;
        pDC->Draw3dRect(&rc, tl, br);
        return 1;
    }

    if (pButton->GetButtonStyle() == 1) {
        pDC->Draw3dRect(&rc, m_c68.m_idx == (COLORREF)-1 ? m_c68.m_clr : m_c68.m_idx,
                        m_c68.m_idx == (COLORREF)-1 ? m_c68.m_clr : m_c68.m_idx);
        ::InflateRect(&rc, -1, -1);
    }

    {
        XTColor& br = bFlat ? m_c5c : m_c68;
        XTColor& tl = bFlat ? m_c68 : m_c5c;
        pDC->Draw3dRect(&rc, tl, br);
    }
    ::InflateRect(&rc, -1, -1);

    {
        XTColor& br = bFlat ? m_c44 : m_c50;
        XTColor& tl = bFlat ? m_c50 : m_c44;
        pDC->Draw3dRect(&rc, tl, br);
    }
    return 1;
}
