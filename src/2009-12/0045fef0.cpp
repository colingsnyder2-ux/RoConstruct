// from server: 61% by atomic.potato
struct CRobloxView
{
    char unused[0x210];
    void* field_210;
    int f();
};

int CRobloxView::f()
{
    if (field_210)
    {
        typedef void (__thiscall *Function)(void*);
        Function function = (Function)(*(unsigned long*)(*(unsigned long*)field_210 + 0x68));
        function(field_210);
        field_210 = 0;
        return f();
    }
    return 0;
}
