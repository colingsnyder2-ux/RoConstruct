// from server: 100% by colin
struct CXTPControlTabWorkspace {
    void* sub_68BA90();
    void* method_68BB00(int);
};

void* CXTPControlTabWorkspace::method_68BB00(int arg) {
    void* p = sub_68BA90();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, int);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, this, arg);
    return p;
}
