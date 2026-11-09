// from server: 100% by colin
struct CXTPRibbonTabPopupToolBar
{
    char pad[0x260];
    void* field_260;
    void* method_150(void*);
};

void* CXTPRibbonTabPopupToolBar::method_150(void* arg)
{
    void* p = field_260;
    void** vtbl = *(void***)p;
    void* (__thiscall *fn)(void*, void*) = (void* (__thiscall *)(void*, void*))vtbl[0x150 / 4];
    fn(p, arg);
    return arg;
}
