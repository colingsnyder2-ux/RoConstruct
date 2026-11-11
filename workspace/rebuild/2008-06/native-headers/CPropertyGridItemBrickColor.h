#pragma once
// >>> native-status (generated) -- do not edit >>>
// CPropertyGridItemBrickColor | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e827221d | roc native-status --write
#include <XTToolkitPro.h>

// Inactive layout recovery of the BrickColor property-grid row.
// RTTI (vtable 00813644 COL): CPropertyGridItemBrickColor : CXTPPropertyGridItemColor : CXTPPropertyGridItem
// : CCmdTarget, CXTPAccessible at +0x20 (second vtable 008135e4, 23 slots).
// No DECLARE_DYNAMIC: primary slot 0 is CXTPPropertyGridItemColor::GetRuntimeClass (00713750).
// Size 0x118 == sizeof(CXTPPropertyGridItemColor): the only constructing site, the
// XItem<RBX::BrickColor, CPropertyGridItemBrickColor, ...> constructor 0043b400, builds the
// CPropGrid::Item base at +0x118 right after calling constructor 00437ae0, and 0043d560 allocates
// 0x13c for that editor (Item 0x20 + descriptor 4). No member of this class has a destructor
// (deleting destructor 00438290, folded with CXTPPropertyGridItemColor's, calls only 00713760).
// Constructor 00437ae0 (ret 8): CString caption by value + COLORREF, calls
// CXTPPropertyGridItemColor(LPCTSTR, clr, NULL) (00713b80), then m_nFlags (+0x8c) = 4 and
// m_clrValue (+0x10c), m_strDefaultValue (+0xa8) = m_strValue (+0xa4).
class CPropertyGridItemBrickColor : public CXTPPropertyGridItemColor {
public:
    CPropertyGridItemBrickColor(CString strCaption, COLORREF clr);

    virtual void SetColor(COLORREF clr);            // primary slot 57: 00437ab0
    virtual void SetValue(CString strValue);        // primary slot 24: 004381f0

protected:
    virtual void OnInplaceButtonDown(CXTPPropertyGridInplaceButton* pButton);  // slot 52: 004382b0

private:
    static CString brickColorName(COLORREF clr);    // 00437a20: closest BrickColor name
    static COLORREF brickColorRef(CString strName); // 00437b90: parsed BrickColor as COLORREF
};
