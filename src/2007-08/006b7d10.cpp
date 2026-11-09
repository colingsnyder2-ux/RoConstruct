// from server: 100% by colin
struct CXTPControlGallery {
    void* sub_6b7ca0();
    void* method_6b7d10(int);
};

void* CXTPControlGallery::method_6b7d10(int arg) {
    void* p = sub_6b7ca0();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, int);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, this, arg);
    return p;
}
