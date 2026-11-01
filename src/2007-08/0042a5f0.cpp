// from server: 83% by colin
struct CLuaHtmlView
{
    void* field_0;
    int field_4;
    void* field_8;
    void* func_0042a5f0(void* arg);
};

void* CLuaHtmlView::func_0042a5f0(void* arg)
{
    void* p = field_0;
    void* q;
    if (p != 0)
        q = (char*)p + 4;
    else
        q = 0;
    void** vtbl = *(void***)field_8;
    typedef void* (__thiscall *Fn)(void*, void*, void*);
    Fn fn = (Fn)vtbl[4];
    fn(field_8, q, arg);
    return arg;
}
