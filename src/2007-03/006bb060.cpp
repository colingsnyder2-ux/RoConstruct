// from server: 100% by tester
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