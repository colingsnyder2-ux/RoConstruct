// from server: 100% by colin
struct CXTPDialogBar
{
    char pad0[0x20];
    void* vtable_20;
    char pad1[0xd4 - 0x24];
    int field_d4;
    char pad2[0x178 - 0xd8];
    int field_178;
    CXTPDialogBar* construct();
};

extern "C" void __fastcall sub_670500(CXTPDialogBar* self);

CXTPDialogBar* CXTPDialogBar::construct()
{
    sub_670500(this);
    *(void**)this = (void*)0x7e0f94;
    *(void**)((char*)this + 0x20) = (void*)0x7e0f34;
    *(int*)((char*)this + 0xd4) = 0x1e;
    *(int*)((char*)this + 0x178) = 0;
    return this;
}
