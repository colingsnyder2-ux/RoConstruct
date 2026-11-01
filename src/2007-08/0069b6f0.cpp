// from server: 100% by colin
struct CXTPPropertyGridView {
    void* sub_69AB30();
    void sub_63023E();
    void func(int a, int b);
};

void CXTPPropertyGridView::func(int a, int b) {
    void* p = sub_69AB30();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, int, int, int);
    ((Fn)vtbl[6])(p, 0, b, 1);
    sub_63023E();
}
