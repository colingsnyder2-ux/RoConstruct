// from server: 100% by colin
struct S_005b8ed0 {
    char pad[0xe8];
    int field_e8;
    void method(int);
};

void S_005b8ed0::method(int arg)
{
    if (field_e8 != arg) {
        field_e8 = arg;
        extern void __stdcall sub_00444710(int);
        sub_00444710(0x8c65a0);
    }
}
