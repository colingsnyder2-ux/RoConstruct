// from server: 100% by colin
struct CXTPToolBar {
    void* sub_64F170();
    void* method_64F1E0(void* arg);
};

void* CXTPToolBar::method_64F1E0(void* arg) {
    void* p = sub_64F170();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0x1c8 / 4];
    fn(p, this, arg);
    return p;
}
