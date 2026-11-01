// from server: 100% by colin
extern "C" void __stdcall sub_006710B0(int, int);

struct CXTPControlPopupColor
{
    char pad[0x178];
    int field_178;
    void sub_00719130(int, int);
};

void CXTPControlPopupColor::sub_00719130(int a, int b)
{
    sub_006710B0(a, b);
    *(int*)((char*)this + 0x178) = *(int*)((char*)a + 0x178);
}
