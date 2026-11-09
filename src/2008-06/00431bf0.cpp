// from server: 100% by colin
struct CDataModelPropGrid
{
    char pad[0xf8];
    char field_f8;
    char pad2;
    char field_fa;
    void sub_6a1052(int, int, int);
    void sub_4318b0();
    void sub_6a096e(int);
    void func_431bf0(int, int, int);
};

void CDataModelPropGrid::func_431bf0(int a, int b, int c)
{
    sub_6a1052(a, b, c);
    if (field_f8 != 0 && field_fa == 0 && a != 0)
    {
        sub_4318b0();
        sub_6a096e(9);
    }
}
