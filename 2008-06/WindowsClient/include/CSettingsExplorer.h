#pragma once
// >>> native-status (generated) -- do not edit >>>
// CSettingsExplorer | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 7ba92d21 | roc native-status --write
#include "CInstanceExplorer.h"

// CRuntimeClass 0081bdac (DYNCREATE, size 0x3cc == CInstanceExplorer, create 00466b90: the implicit constructor
// inlined as CInstanceExplorer 00421940 plus the three vtables 0081bdf4/0081bde0/0081bdcc). No members and no
// destructor of its own: vtable slot 1 and both thunk slots equal CInstanceExplorer's (00421c90/004219d0/004219e0).
// RTTI vtables 0081bde0/0081bdcc replace only Listener::onEvent, both by 00466d40 (identical-COMDAT fold).
class CSettingsExplorer : public CInstanceExplorer {
    DECLARE_DYNCREATE(CSettingsExplorer)
public:
    virtual void onEvent(const RBX::Instance* source, RBX::DescendantAdded event);    // 00466d40
    virtual void onEvent(const RBX::Instance* source, RBX::DescendantRemoving event); // 00466d40
};
