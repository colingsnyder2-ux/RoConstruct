// from server: 100% by tester
struct CXTPPopupToolBar {
    void* sub_67A3D0();
    void* method_67A440(void* arg);
};

void* CXTPPopupToolBar::method_67A440(void* arg) {
    void* result = sub_67A3D0();
    void** vtable = *(void***)result;
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = (Fn)vtable[0x1dc / 4];
    fn(result, this, arg);
    return result;
}
