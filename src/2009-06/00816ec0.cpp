// from server: 100% by tester
struct CXTPRibbonSystemPopupBarPage {
    void* GetSomething();
    void* CreatePage(void* p);
};

void* CXTPRibbonSystemPopupBarPage::CreatePage(void* p) {
    void* obj = GetSomething();
    void** vtbl = *(void***)obj;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0x1dc / 4];
    fn(obj, this, p);
    return obj;
}
