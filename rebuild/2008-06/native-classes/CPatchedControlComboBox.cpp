// >>> native-status (generated) -- do not edit >>>
// CPatchedControlComboBox | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by colin (roc repair)
// <<< native-status | src 928be26b | roc native-status --write
#include "CPatchedControlComboBox.h"

IMPLEMENT_XTP_CONTROL(CPatchedControlComboBox, CXTPControlComboBox)

// 0042eac0: the stock comparison plus equal list counts (LB_GETCOUNT on both list bars).
BOOL CPatchedControlComboBox::Compare(CXTPControl* pOther)
{
    if (!CXTPControlComboBox::Compare(pOther))
        return FALSE;
    return GetCount() == ((CPatchedControlComboBox*)pOther)->GetCount();
}
