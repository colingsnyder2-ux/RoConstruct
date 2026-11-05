// from server: 100% by atomic.potato
struct CXTPControlOleItems
{
    void* field_0;
    void* func_0067e200();
    void* func_0067e270(void* arg);
};

void* CXTPControlOleItems::func_0067e270(void* arg)
{
    void* p = func_0067e200();
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = (Fn)vtbl[0xe0 / 4];
    fn(p, this, arg);
    return p;
}
