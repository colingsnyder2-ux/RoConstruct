#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxControlColorSelector | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c7b05cec | roc native-status --write
#include <XTToolkitPro.h>
#include <vector>

namespace RBX { class BrickColor; }

// Inactive layout recovery. CRuntimeClass 00931c34 (writable: IMPLEMENT_SERIAL) gives size 0x184,
// schema 0x80000020, CreateObject 0044edf0 and base getter 00745620 (-> CXTPControl class).
// Constructor 0044ec60 calls CXTPControl::CXTPControl (006adad0) directly and stores vptrs
// 00816e74 (+0) and 00816e14 (+0x20); the deleting destructor 0044edd0 calls only
// CXTPControl::~CXTPControl (006ad180), so no member has a destructor.
// The class is a Roblox copy of CXTPControlColorSelector with a BrickColor palette.
class CRobloxControlColorSelector : public CXTPControl {
    DECLARE_XTP_CONTROL(CRobloxControlColorSelector)
public:
    // Element of the shared palette vector (12 bytes; copy 0044deb0, assignment loop 0044dee0).
    struct CColorInfo {
        CColorInfo(COLORREF _clrButton, UINT _toolTipID)
        {
            clrButton = _clrButton;
            toolTipID = _toolTipID;
        }
        COLORREF clrButton;
        UINT toolTipID;
        CString strTip;
    };

    CRobloxControlColorSelector();
    COLORREF GetColor() const;
    void SetColor(COLORREF clr);

protected:
    virtual CSize GetSize(CDC* pDC);
    virtual void Draw(CDC* pDC);
    virtual void OnMouseMove(CPoint point);
    virtual BOOL OnSetSelected(int bSelected);
    virtual void OnClick(BOOL bKeyboard = FALSE, CPoint pt = CPoint(0, 0));
    virtual void OnExecute();
    virtual void OnLButtonUp(CPoint point);

private:
    CRect GetRect(int nIndex) const;
    int HitTest(CPoint point) const;
    static void addColor(RBX::BrickColor color);

    static int nextColorId;                // 0096dd20
    static std::vector<CColorInfo> colors;  // 0096dd24

protected:
    int m_nSelected;      // +0x174
    int m_nPressed;       // +0x178
    bool m_bColorPicked;  // +0x17c, set when OnExecute takes a palette color
    COLORREF m_clr;       // +0x180
};
