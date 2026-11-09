// from server: 23% by atomic.potato
struct S {
    char pad0[0x18];
    int field18;
    char pad1[0x8];
    int field24;
    char pad2[0x4];
    int field2c;
    int method();
};

extern "C" void __stdcall func_006ca9f0();
extern "C" void __stdcall func_006cae30();
extern "C" void __stdcall func_006ccfc0();
extern "C" unsigned int __stdcall func_007addd0();
extern "C" void __stdcall func_0090f21c();

int S::method()
{
    int* esi = (int*)field18;
    int eax = field2c;
    func_006ca9f0();
    int i = 0;
    int count = func_007addd0();
    if (count > 0) {
        do {
            func_0090f21c();
            func_0090f21c();
            func_0090f21c();
            func_0090f21c();
            func_0090f21c();
            int j = 0;
            if (esi[4] > 0) {
                do {
                    func_006ccfc0();
                    j++;
                } while (j < esi[4]);
            }
            i++;
            count = func_007addd0();
        } while (i < count);
    }
    func_006cae30();
    return 0;
}
