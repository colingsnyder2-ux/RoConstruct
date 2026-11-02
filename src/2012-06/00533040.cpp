// from server: 31% by Intel
extern "C" int __stdcall sub_52D010(int, int, int, int, int);
extern "C" int __stdcall sub_6C1360();

struct VPlayerFactoryProduct {
    VPlayerFactoryProduct(int a1, int a2, int a3, int a4, int a5, int a6);
    int vftable;
    char pad[0x18];
    int field_1C;
    char pad2[0x10];
    int field_30;
    int field_34;
};

VPlayerFactoryProduct::VPlayerFactoryProduct(int a1, int a2, int a3, int a4, int a5, int a6)
{
    sub_52D010(a1, a2, a3, a4, a5);
    field_1C = sub_6C1360();
    vftable = 0xB70774;
    field_30 = a5;
    field_34 = a6;
}
