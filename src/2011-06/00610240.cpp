// from server: 48% by atomic.potato
extern "C" int __stdcall sub_80B2EA(int, int, int, int, int);
extern "C" void __stdcall sub_80B0AC(int, int);
extern "C" int __stdcall sub_6219C0(int, int, int, int);
extern "C" void __stdcall sub_A40A10(int);

struct S {
    char pad[0x28];
    int field28;
    int field2c;
    int f(int);
};

int S::f(int a) {
    int r = sub_80B2EA(a, 0, 0xc073f8, 0xc4a034, 0);
    if (r == 0) {
        sub_A40A10(0xa5c10c);
        sub_80B0AC(0xb989fc, 0);
    }
    return sub_6219C0(r, field28, field2c, a + 4);
}
