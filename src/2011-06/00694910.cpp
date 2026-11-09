// from server: 56% by atomic.potato
struct S {
    char pad0[0x28];
    int field28;
    int field2c;
    int f(int, int);
};

extern "C" int __stdcall sub_80B2EA(int, int, int, int, int);
extern "C" int __stdcall sub_80B0AC(int, int);
extern "C" int __stdcall sub_688E60(int, int, int, int);
extern "C" void __stdcall sub_A40A10(int);

int S::f(int a, int b)
{
    int r = sub_80B2EA(a, 0, 0xC3943C, 0xC073F8, 0);
    if (r == 0) {
        sub_A40A10(0xA5C10C);
        sub_80B0AC(0xB989FC, 0);
    }
    return sub_688E60(r, field28, field2c, b + 4);
}
