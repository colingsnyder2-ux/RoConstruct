// from server: 100% by colin
struct CXTPRibbonGroupControlPopup
{
    void* GetSomething();
    void* CreatePopup(void* param);
};

void* CXTPRibbonGroupControlPopup::CreatePopup(void* param)
{
    void* obj = GetSomething();
    void** vtable = *(void***)obj;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtable[0xe0 / 4];
    fn(obj, this, param);
    return obj;
}
