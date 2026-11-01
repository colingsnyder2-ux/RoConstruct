// from server: 100% by tester
struct CPatchedControlComboBox {
    char pad[0x1d8];
    int field_1cc;
    int sub_637300();
    int sub_637320();
    void setValue(int);
};

void CPatchedControlComboBox::setValue(int value)
{
    int current = sub_637320();
    if (current == value && this->field_1cc == value)
        return;

    this->field_1cc = value;
    int obj = sub_637300();
    if (obj != 0) {
        int* vtbl = *(int**)obj;
        int (__thiscall *fn)(void*, int) = (int (__thiscall *)(void*, int))vtbl[0x220 / 4];
        fn((void*)obj, value);
    }
    int* vtbl2 = *(int**)this;
    void (__thiscall *fn2)(void*) = (void (__thiscall *)(void*))vtbl2[0x164 / 4];
    fn2(this);
}
