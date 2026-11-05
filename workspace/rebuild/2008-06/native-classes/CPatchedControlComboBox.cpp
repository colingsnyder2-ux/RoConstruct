#include "CPatchedControlComboBox.h"

IMPLEMENT_XTP_CONTROL(CPatchedControlComboBox, CXTPControlComboBox)

// 0042eac0: the stock comparison plus equal list counts (LB_GETCOUNT on both list bars).
BOOL CPatchedControlComboBox::Compare(CXTPControl* pOther)
{
    if (!CXTPControlComboBox::Compare(pOther))
        return FALSE;
    return GetCount() == ((CPatchedControlComboBox*)pOther)->GetCount();
}
