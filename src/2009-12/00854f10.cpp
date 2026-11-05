// from server: 100% by atomic.potato
struct CXTPTabClientWnd
{
    void* vtable;
    int pad[21];
    int field58;
    int field5c;
    void f();
};

void CXTPTabClientWnd::f()
{
    if (field58 != 0)
    {
        field58 = 0;
        field5c = 0;
    }
    ((void (__thiscall *)(CXTPTabClientWnd *))(*(void ***)this)[0x144 / 4])(this);
}
