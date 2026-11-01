// from server: 100% by colin
struct CXTPRibbonControlSystemPopupBarButton
{
    void* GetSomething();
    void* CreateClone(int arg);
};

extern void* __fastcall sub_71A1A0(void* self);

void* CXTPRibbonControlSystemPopupBarButton::CreateClone(int arg)
{
    void* p = sub_71A1A0(this);
    void** vtbl = *(void***)p;
    void* (__thiscall *fn)(void*, void*, int) = (void* (__thiscall *)(void*, void*, int))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
