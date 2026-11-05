// from server: 100% by colin
// roc 2007-08 006d1090  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d1090

extern "C" unsigned long (__stdcall *GetSysColorBrush)(int);

struct CXTPReportInplaceEdit {
    int field_0x88;
    void SetColor(int, int);
};

void CXTPReportInplaceEdit::SetColor(int a, int b)
{
    int brush = *(int*)((char*)this + 0x88);
    (*(void (__thiscall**)(int, int))(*(int*)a + 0x38))(a, brush);
    GetSysColorBrush(5);
}
