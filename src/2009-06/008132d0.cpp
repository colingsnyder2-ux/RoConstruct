// from server: 100% by tester
struct CXTPRibbonTabPopupToolBar {
    char pad[0x278];
    void* field_278;
    void* Method(void* arg);
};

void* CXTPRibbonTabPopupToolBar::Method(void* arg) {
    void* p = field_278;
    void** vtbl = *(void***)p;
    typedef void* (__thiscall *Fn)(void*, void*);
    Fn fn = (Fn)vtbl[0x15c / 4];
    fn(p, arg);
    return arg;
}
