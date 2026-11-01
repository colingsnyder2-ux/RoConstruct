// from server: 100% by colin
struct CXTPControlComboBox {
    void* sub_638610();
    void* method(void* arg);
};

void* CXTPControlComboBox::method(void* arg) {
    CXTPControlComboBox* self = this;
    CXTPControlComboBox* p = (CXTPControlComboBox*)sub_638610();
    void** vtbl = *(void***)p;
    void (__thiscall* fn)(void*, void*, void*) = (void (__thiscall*)(void*, void*, void*))vtbl[0xe0 / 4];
    fn(p, self, arg);
    return p;
}
