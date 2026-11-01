// from server: 100% by colin
struct CXTPControlToolbars {
    CXTPControlToolbars* func_0067de50();
    CXTPControlToolbars* func_0067dec0(int);
};

CXTPControlToolbars* CXTPControlToolbars::func_0067dec0(int arg)
{
    CXTPControlToolbars* p = func_0067de50();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(CXTPControlToolbars*, CXTPControlToolbars*, int) = (void (__thiscall *)(CXTPControlToolbars*, CXTPControlToolbars*, int))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
