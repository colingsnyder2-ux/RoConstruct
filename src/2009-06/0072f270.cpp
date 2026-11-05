// from server: 100% by tester
struct CXTPCommandBar
{
    void* m_pData;
};

struct CXTPCommandBarSite
{
    void* m_pVtbl;
};

extern "C" void* __fastcall sub_645820(CXTPCommandBar* self);

void* __fastcall sub_645890(CXTPCommandBar* self, int, void* arg)
{
    CXTPCommandBarSite* site = (CXTPCommandBarSite*)sub_645820(self);
    void** vtbl = (void**)site->m_pVtbl;
    typedef void (__thiscall *Fn)(CXTPCommandBarSite*, CXTPCommandBar*, void*);
    Fn fn = (Fn)vtbl[0x1dc / 4];
    fn(site, self, arg);
    return site;
}
