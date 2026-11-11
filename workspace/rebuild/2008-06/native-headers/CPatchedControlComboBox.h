#pragma once
// >>> native-status (generated) -- do not edit >>>
// CPatchedControlComboBox | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src b9bd1d97 | roc native-status --write
#include <XTToolkitPro.h>

// Inactive layout recovery. CRuntimeClass 0092ecc8 (writable: IMPLEMENT_SERIAL) gives size 0x1e0,
// schema 0x80000020, CreateObject 0042fd50 and base getter 0042eb20 (jmp 006a6ab0, the
// CXTPControlComboBox class getter). CreateObject calls operator new(0x1e0), then
// CXTPControlComboBox::CXTPControlComboBox(NULL) (006a7960) and stores vptrs 00810914 (+0) and
// 008108b4 (+0x20, CXTPAccessible per RTTI); the deleting destructor 0042fdb0 calls only
// CXTPControlComboBox::~CXTPControlComboBox (006a6ac0). sizeof(CXTPControlComboBox) is 0x1e0,
// so the class adds no data members and only overrides Compare (vtable slot 34).
class CPatchedControlComboBox : public CXTPControlComboBox {
    DECLARE_XTP_CONTROL(CPatchedControlComboBox)
protected:
    virtual BOOL Compare(CXTPControl* pOther);
};
