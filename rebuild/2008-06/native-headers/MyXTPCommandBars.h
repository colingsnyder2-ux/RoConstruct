#pragma once
#include <XTToolkitPro.h>
// Original runtime class 008107c4; remaining virtual overrides unverified.
class MyXTPCommandBars : public CXTPCommandBars {
    DECLARE_DYNCREATE(MyXTPCommandBars)
protected:
    virtual CXTPToolBar* AddCustomBar(LPCTSTR, UINT, BOOL);
};
