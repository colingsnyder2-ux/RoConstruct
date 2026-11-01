// from server: 40% by Intel
struct EnumDesc {
    int field_2C;
    char pad_30[96];
    int* field_90;

    int f(int arg1, int* arg2);
};

extern "C" void __stdcall sub_4015a0(int, int);
extern "C" int __cdecl sub_771070();
extern "C" void __cdecl sub_76E5F0(int*);

int EnumDesc::f(int arg1, int* arg2) {
    int v;
    if (arg1 < field_2C) {
        v = field_90[arg1];
    }
    sub_4015a0(0x7710D0, 0xE4860C);
    int eax = sub_771070();
    *arg2 = eax;
    sub_76E5F0(arg2 + 1);
    return arg1 < field_2C;
}
