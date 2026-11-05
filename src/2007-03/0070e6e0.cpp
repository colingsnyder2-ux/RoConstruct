// from server: 100% by tester
struct CXTPRibbonTabPopupToolBar
{
    char pad[0x24c];
    void* field_260;
    void* method_00717a60(void* arg);
};

void* CXTPRibbonTabPopupToolBar::method_00717a60(void* arg)
{
    void* p = field_260;
    void** vtbl = *(void***)p;
    void* fn = vtbl[0x154 / 4];
    ((void (__thiscall*)(void*, void*))fn)(p, arg);
    return arg;
}