// from server: 100% by colin
struct CXTPControlSelector {
    void* field0;
    void* func_0067f060();
    void* func_0067f0d0(void* arg);
};

void* CXTPControlSelector::func_0067f0d0(void* arg)
{
    void* p = func_0067f060();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = (Fn)vtbl[0x38];
    fn(p, this, arg);
    return p;
}
