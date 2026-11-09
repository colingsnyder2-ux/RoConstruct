// from server: 14% by atomic.potato
struct S_func_0071b160 {
    char pad0[0x2c];
    char field_2c[0x28];
    int field_54;
    char pad58[0x6c];
    int field_c4;
    void f(int, int, int);
};

extern "C" void __stdcall func_006ca9f0();
extern "C" int __stdcall func_007adde0();
extern "C" void __stdcall func_007f50b6();
extern "C" unsigned int __stdcall func_006755e0();
extern "C" void __stdcall func_0071aef0();
extern "C" void __stdcall func_007e5b60();
extern "C" void __stdcall func_00719d10();
extern "C" void __stdcall func_0071a650();
extern "C" void __stdcall func_007ade10();
extern "C" void __stdcall func_006cae30();

void S_func_0071b160::f(int a, int b, int c)
{
    func_006ca9f0();
    int v = func_007adde0();
    float fv = (float)v * *(float*)&c;
    func_007f50b6();
    int n = (int)fv;
    int m = 1;
    int* p = (n > 1) ? &n : &m;
    int count = *p;
    unsigned int d = func_006755e0();
    int ebp = field_54 / (int)d;
    func_0071aef0();
    func_007e5b60();
    for (int i = count; i > 0; --i) {
        func_00719d10();
        func_0071a650();
        field_54++;
    }
    func_007ade10();
    func_006cae30();
}
