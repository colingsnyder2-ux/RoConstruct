// from server: 100% by colin
struct CXTColorPageCustom
{
    char pad[0x788];
    unsigned char field_788;
    char pad2[3];
    unsigned char field_78c;
    char pad3[3];
    unsigned char field_790;

    void sub_62feea(int);
    void sub_70e4a0(int, int);
    void func_70e9f0();
};

void CXTColorPageCustom::func_70e9f0()
{
    sub_62feea(1);
    unsigned int v = field_788;
    unsigned int mid = field_78c;
    unsigned int hi = field_790;
    unsigned int packed = ((mid << 8) | hi) << 8 | v;
    sub_70e4a0(packed, 0);
}
