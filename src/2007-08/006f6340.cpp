// from server: 100% by colin
struct CXTPPropertyGridInplaceEdit
{
    char pad[0x20];
    void* field_20;
    void f();
};

extern "C" void __stdcall sub_0062ff4a(void*);

void CXTPPropertyGridInplaceEdit::f()
{
    if (field_20 != 0)
        sub_0062ff4a(0);
}
