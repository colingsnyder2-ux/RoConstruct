// from server: 100% by tester
struct CXTPControlComboBoxList {
    void* sub_6377b0();
    void* method(int);
};

void* CXTPControlComboBoxList::method(int arg) {
    void* p = sub_6377b0();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vtbl[0x1dc / 4];
    fn(p, this, arg);
    return p;
}
