// from server: 100% by colin
struct VCXTPReportRows_CXTPHeapObjectT
{
    char pad_0000[0x20];
    int field_20;
    int field_24;
    char pad_0028[0x04];
    char field_2c[0x08];
    int field_34;
    char pad_0038[0x08];
    int field_40;

    void func_006641b0();
};

struct Sub2C
{
    void method(int, int);
};

extern "C" void __fastcall sub_00657410(int);

void VCXTPReportRows_CXTPHeapObjectT::func_006641b0()
{
    if (field_34 > 0)
        field_40 = 1;
    ((Sub2C*)field_2c)->method(0, -1);
    int v = field_20;
    field_24 = -1;
    sub_00657410(v);
}
