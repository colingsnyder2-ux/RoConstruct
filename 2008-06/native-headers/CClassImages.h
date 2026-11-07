#pragma once
// >>> native-status (generated) -- do not edit >>>
// CClassImages | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6e745f38 | roc native-status --write
#include <afxwin.h>
#include <afxcmn.h>

// Inactive layout recovery. Original RTTI vtable 0080e864 (two slots: scalar deleting
// destructor 00413400 and the inherited 0047d410). CInsertObjectDialog constructs it at
// +0xa0 through 00413230 and destroys it through 00412f30; the dialog's 8-byte span and
// the CImageList base leave no room for further members. Constructor and destructor bodies
// match (native-classes/CClassImages.cpp, compiled with the XTP 11.2.2 headers).
class CClassImages : public CImageList {
public:
    CClassImages();
    virtual ~CClassImages();
};
