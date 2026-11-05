// from server: 100% by sophus
struct CXTPControlComboBoxListTarget;
typedef void (__thiscall *CXTPControlComboBoxListProc)(CXTPControlComboBoxListTarget*, int);

struct CXTPControlComboBoxListTarget {
    void** vtbl;
};

struct CXTPControlComboBoxList {
    char reserved[0x180];
    CXTPControlComboBoxListTarget* target;
    void f(int value);
};

void CXTPControlComboBoxList::f(int value)
{
    CXTPControlComboBoxListTarget* target = this->target;
    if (target)
    {
        CXTPControlComboBoxListProc proc = (CXTPControlComboBoxListProc)target->vtbl[95];
        proc(target, value);
    }
}
