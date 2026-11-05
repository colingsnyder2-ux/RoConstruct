// from server: 100% by colin
struct CXTPControlPopupColor
{
    void* GetColorPopup();
    void* GetSite();
};

void* CXTPControlPopupColor::GetColorPopup()
{
    return 0;
}

void* CXTPControlPopupColor::GetSite()
{
    return 0;
}

extern "C" void* __fastcall sub_6725F0(CXTPControlPopupColor* self);

void* __fastcall sub_672660(CXTPControlPopupColor* self, int, int arg)
{
    void* p = sub_6725F0(self);
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, int);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, self, arg);
    return p;
}
