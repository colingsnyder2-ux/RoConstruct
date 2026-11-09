// from server: 100% by tester
struct CWrapperView {
    void Dispatch(int);
};

void CWrapperView::Dispatch(int a) {
    typedef void (__thiscall *Fn)(void *, int);
    char *p = (char *)a;
    Fn fn = *(Fn *)(*(char **)p + 0xc);
    fn(p, 0x8ad216);
}