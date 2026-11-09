// from server: 59% by atomic.potato
extern "C" void __stdcall sub_80B2EA();
extern "C" void __stdcall sub_80B0AC();
extern "C" void __stdcall sub_A40A10();

struct S {
    char pad[0x28];
    void (__stdcall *fn)(int);
    int field2c;
    void f(int, int);
};

void S::f(int a, int b) {
    int r = 0;
    r = ((int (__stdcall *)(int, int, int, int, int))sub_80B2EA)(a, 0, 0xc073f8, 0xc1b168, 0);
    if (r == 0) {
        sub_A40A10();
        sub_80B0AC();
    }
    fn(field2c + r);
}
