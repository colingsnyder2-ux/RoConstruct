// from server: 100% by tester
struct S_func_00670bd0 {
    char pad[0xf8];
    int field_f8;
};

extern "C" S_func_00670bd0* __cdecl sub_00670bd0();

void __cdecl sub_00670c70(int value)
{
    S_func_00670bd0* p = sub_00670bd0();
    p->field_f8 = value;
}
