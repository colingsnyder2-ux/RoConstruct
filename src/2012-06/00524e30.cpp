// from server: 23% by atomic.potato
struct Inner {
    char pad0[0x24];
    char b24;
    char pad25[3];
    int d28;
    int d2c;
};

struct Outer {
    char pad0[0x24];
    Inner inner;
};

extern "C" bool __stdcall func_00880f30();
extern "C" void __stdcall func_007dd750();
extern "C" void __stdcall func_0051fd60();
extern "C" void __stdcall func_005238d0();

struct S {
    char pad0[0x24];
    Outer outer;
    char f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

char S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
    if (func_00880f30())
    {
        func_007dd750();
        return 0;
    }
    char local = 0;
    int v = *(int*)&local;
    func_0051fd60();
    outer.inner.b24 = local;
    outer.inner.d28 = v;
    outer.inner.d2c = v;
    func_005238d0();
    func_007dd750();
    return 1;
}
