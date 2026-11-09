// from server: 100% by colin
struct CXTPRibbonControlSystemButton {
    void* f(unsigned int a1);
};

extern "C" void* __fastcall sub_00719cb0(void* self);

void* CXTPRibbonControlSystemButton::f(unsigned int a1)
{
    void* p = sub_00719cb0(this);
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, unsigned int);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, this, a1);
    return p;
}
