// from server: 100% by colin
struct CXTPReportInplaceEdit {
    char pad[0x54];
    int field_54;
    int field_58;
    char pad2[8];
    void* field_64;
    void OnFocus();
    void DoSomething();
};

void CXTPReportInplaceEdit::DoSomething()
{
    if (field_58 != 0 && field_64 != 0)
    {
        void** vtbl = *(void***)field_64;
        void (__thiscall *fn)(void*, int*) = (void (__thiscall *)(void*, int*))vtbl[0x120 / 4];
        fn(field_64, &field_54);
        OnFocus();
    }
}
