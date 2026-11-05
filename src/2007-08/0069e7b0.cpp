// from server: 100% by colin
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
extern "C" void* __cdecl sub_0069e740();
extern "C" void __cdecl sub_00630b8c(void*, int, int);

struct CXTPPropertyGridItemEnum
{
    char pad[0xd0];
    void* field_d0;
    void SetTheme();
};

void CXTPPropertyGridItemEnum::SetTheme()
{
    void* h = GetModuleHandleA("UXTHEME.DLL");
    CXTPPropertyGridItemEnum* p = (CXTPPropertyGridItemEnum*)sub_0069e740();
    if (h != p->field_d0)
    {
        p->field_d0 = h;
        sub_00630b8c(p, 0, 0xd0);
    }
}
