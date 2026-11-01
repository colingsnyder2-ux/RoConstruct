// from server: 100% by colin
struct CXTPControlCustom {
    void* func_006f5a10();
    void* func_006f5a80(void* param);
};

void* CXTPControlCustom::func_006f5a80(void* param)
{
    void* p = func_006f5a10();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, CXTPControlCustom*, void*);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, this, param);
    return p;
}
