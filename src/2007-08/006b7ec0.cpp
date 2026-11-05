// from server: 100% by tester
struct CXTPControlGallery
{
    char pad_0x0[0x178];
    int field_0x178;
    char pad_0x17c[0x54];
    int field_0x1d0;

    int sub_006b3590();
    void sub_006b7d80(int, int);
    int sub_0071d5a0(int, int);
    void sub_0063a690(int);
    void sub_00670e90(int, int);
    void func_006b7ec0(int, int);
};

void CXTPControlGallery::func_006b7ec0(int a, int b)
{
    if (sub_006b3590())
    {
        sub_00670e90(a, b);
        return;
    }

    sub_006b7d80(a, b);

    int r = ((CXTPControlGallery*)((char*)this + 0x178))->sub_0071d5a0(a, b);
    if (r != field_0x1d0)
    {
        field_0x1d0 = r;
        sub_0063a690(1);
    }
}
