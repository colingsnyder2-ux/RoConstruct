// from server: 47% by colin
struct CLuaHtmlView
{
    void* vtable;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;

    CLuaHtmlView(void* (__stdcall *fn)(void*, void*), void* arg, void* arg2);
};

CLuaHtmlView::CLuaHtmlView(void* (__stdcall *fn)(void*, void*), void* arg, void* arg2)
{
    vtable = (void*)0x78a208;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    if (fn != 0)
    {
        field_c = arg2;
        field_4 = fn;
        field_8 = fn(0, arg);
    }
    field_10 = 0;
    if (fn != 0)
    {
        fn((void*)1, arg);
    }
}
