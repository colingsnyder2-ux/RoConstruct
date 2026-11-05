// from server: 54% by atomic.potato
extern "C" int __stdcall sub_80B2EA(int, int, int, int, int);
extern "C" void __stdcall sub_80B0AC(int, int);
extern "C" void __stdcall sub_65CC90(int, int, int, int);
extern "C" void __stdcall sub_A40A10();

struct S {
    char pad[0x28];
    int field28;
    int field2c;
    void func(int, int);
};

void S::func(int a, int b)
{
    int r = sub_80B2EA(0, 0xc12ef0, 0xc073f8, 0, a);
    if (r == 0) {
        sub_A40A10();
        sub_80B0AC(0xb989fc, 0xa5c10c);
    }
    sub_65CC90(r, field28, field2c, b + 4);
}
