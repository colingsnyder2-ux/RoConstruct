#pragma once
// >>> native-status (generated) -- do not edit >>>
// MyXTPCommandBars | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 798ccb07 | roc native-status --write
#include <XTToolkitPro.h>
// Original runtime class 008107c4; remaining virtual overrides unverified.
class MyXTPCommandBars : public CXTPCommandBars {
    DECLARE_DYNCREATE(MyXTPCommandBars)
protected:
    virtual CXTPToolBar* AddCustomBar(LPCTSTR, UINT, BOOL);
};
