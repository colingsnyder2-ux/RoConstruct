#include "CPatchedControlComboBox.h"

IMPLEMENT_XTP_CONTROL(CPatchedControlComboBox, CXTPControlComboBox)

BOOL CPatchedControlComboBox::Compare(CXTPControl* pOther)
{
    if (!CXTPControlComboBox::Compare(pOther))
        return FALSE;
    return GetCount() == ((CPatchedControlComboBox*)pOther)->GetCount();
}

CPatchedControlComboBox::CPatchedControlComboBox(void) : CXTPControlComboBox(NULL)
{
}
