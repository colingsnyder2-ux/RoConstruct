// from server: 100% by colin
struct CXTPDockingPaneWindowSelect
{
    void* vtable;
    int field_4;
    char pad_8[0x1c];
    int field_24;
    int field_28;
    CXTPDockingPaneWindowSelect* construct();
};

struct Sub_006DC6F0
{
    void method(int n);
};

CXTPDockingPaneWindowSelect* CXTPDockingPaneWindowSelect::construct()
{
    vtable = (void*)0x7d9604;
    ((Sub_006DC6F0*)&pad_8[0])->method(0xa);
    field_28 = 0;
    field_4 = 0;
    field_24 = 0;
    return this;
}
