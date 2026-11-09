// from server: 100% by colin
struct CXTPRibbonBarControlQuickAccessPopup {
    void* f(int);
};

void* __stdcall g_6a8620();

void* CXTPRibbonBarControlQuickAccessPopup::f(int arg) {
    void* p = g_6a8620();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
