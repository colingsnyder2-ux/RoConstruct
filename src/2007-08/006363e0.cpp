// from server: 100% by colin
struct CXTPControlComboBoxList {
    char pad[0x5c];
    int field_5c;
    void sub_635af0(int);
    void sub_63094c();
    void func();
};

void CXTPControlComboBoxList::func() {
    sub_635af0(field_5c + 0x1bc);
    sub_63094c();
}
